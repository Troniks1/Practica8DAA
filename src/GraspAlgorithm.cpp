/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     GraspAlgorithm.cpp                                 =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/GraspAlgorithm.hpp"
#include <time.h>

/*------------------------------------------------*/

/**
* @brief    Construye una nueva instancia.
*/
GraspAlgorithm::GraspAlgorithm(){
}

/**
* @brief    Construye una nueva instancia.
*/
GraspAlgorithm::GraspAlgorithm(int RLC, int iterations){
    set_RLCGC(RLC);
    set_Iterations(iterations);
}

/**
* @brief    Destruye el objeto.
*/
GraspAlgorithm::~GraspAlgorithm(){
}

/**
* @brief    Consigue la RLCGC.
*
* @return   La RLCGC.
*/
int GraspAlgorithm::get_RLCGC(void){
    return RLCGC_;
}

/**
* @brief    Consigue las iteraciones.
*
* @return   Las iteraciones.
*/
int GraspAlgorithm::get_Iterations(void) const{
    return iterations_;
}

/**
* @brief    Establece la RLCGC.
*
* @param[in]    RLCGC La RLCGC.
*/
void GraspAlgorithm::set_RLCGC(int RLC){
    RLCGC_ = RLC;
}

/**
* @brief    Establece las iteraciones.
*
* @param[in]    iterations  Las iteraciones.
*/
void GraspAlgorithm::set_Iterations(int iterations){
    iterations_ = iterations;
}

/**
* @brief    Ejecutra el algoritmo Grasp.
*
* @param    graph   El grafo.
*/
void GraspAlgorithm::runAlgorithm(Graph& graph, Chrono& chrono){
    chrono.startChrono();
    float tmpDiversity = 0.0;
    int counter = 0;
    std::vector<Vertex> tmpSolution;
    std::vector<Vertex> solution;
    while(counter < get_Iterations()){  
    set_FreeVertex(graph.get_Vertex());
    Vertex gravityCenter;
    gravityCenter = generateGravityCenter(get_FreeVertex());
    while(solution.size() < get_SolutionSize()){
        std::vector<int> RLCGCvector;
        std::vector<Vertex> prueba = get_FreeVertex();
        generateRLCGC(RLCGCvector, prueba, gravityCenter);
        int candidate = rand() % RLCGCvector.size();
        int elementAdded = RLCGCvector[candidate];
        addition(solution, elementAdded);
        gravityCenter = generateGravityCenter(solution);
    } 
    float diversity = findDiversity(solution);
    if(tmpDiversity < diversity){
        tmpDiversity = diversity;
        tmpSolution = solution;
        solution.clear();
        diversity = 0.0;
    }
    if(tmpDiversity > diversity){
        solution.clear();
        diversity = 0.0;
    }
    counter++;
    }
    set_Solution(tmpSolution);
    set_Diversity(findDiversity(tmpSolution));
    chrono.stopChrono();
}

/**
* @brief    Genera una RLCGC.
*
* @param    RLCGC La RLCGC.
* @param[in]    vertex    El vector de vértices.
*/
void GraspAlgorithm::generateRLCGC(std::vector<int>& RLCGC, std::vector<Vertex>& vertex, Vertex& gravityCenter){
    RLCGC.clear();
    int contador = 0;
    std::vector<Vertex> prueba = vertex;
    while(contador < get_RLCGC() ){
        
        int number = 0;
        float diversity_ = -9999999;
        for(int i = 0; i < prueba.size(); i++){
        std::vector<Vertex> tmp;
        tmp.resize(2);
        tmp[0] = gravityCenter;
        tmp[1] = prueba[i];
        float diversity = findDiversity(tmp);
        if(diversity_ < diversity){
            number = i;
            diversity_ = diversity;
        }
    }
    //std::cout << number << std::endl;
    prueba.erase(prueba.begin() + number);
    RLCGC.push_back(number);
    contador++;
    }
}