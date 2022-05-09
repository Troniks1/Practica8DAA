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
    set_RLC(RLC);
    set_Iterations(iterations);
}

/**
* @brief    Destruye el objeto.
*/
GraspAlgorithm::~GraspAlgorithm(){
}

/**
* @brief    Consigue la RLC.
*
* @return   La RLC.
*/
int GraspAlgorithm::get_RLC(void) const{
    return RLC_;
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
* @brief    Establece la RLC.
*
* @param[in]    RLC La RLC.
*/
void GraspAlgorithm::set_RLC(int RLC){
    RLC_ = RLC;
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
    std::vector<Vertex> solution;
    set_FreeVertex(graph.get_Vertex());
    //Fase Constructiva.
    do{
        int candidate = getRandomVertex(get_FreeVertex());
        addition(solution, candidate);
    }while( solution.size() < get_SolutionSize());
    //Fase de Mejora.
    int counter = 0;
    float diversity = findDiversity(solution);
    do{
        std::vector<Vertex> tmpSolution = solution;
        std::vector<Vertex> RLCvector;
        generateRLC(RLCvector, tmpSolution);
        int candidateIntroduce = getRandomVertex(RLCvector);
        int candidateExtract = getRandomVertex(tmpSolution);
        //Swap
        tmpSolution.erase(tmpSolution.begin() + candidateExtract);
        tmpSolution.push_back(RLCvector[candidateIntroduce]);
        float tmpDiversity = findDiversity(tmpSolution);
        if(tmpDiversity > diversity){
            int pos = getPositionFromVector(get_FreeVertex(), RLCvector[candidateIntroduce].get_Number());
            if(pos != -1){
                diversity = tmpDiversity;
                swap(solution, candidateExtract, pos);
            }
        }
        counter++;
    }while(counter < get_Iterations());
    set_Solution(solution);
    set_Diversity(findDiversity(solution));
    chrono.stopChrono();
}

/**
* @brief    Genera una RLC.
*
* @param    RLC La RLC.
* @param[in]    solution    La solución.
*/
void GraspAlgorithm::generateRLC(std::vector<Vertex>& RLC, std::vector<Vertex>& solution){
    std::vector<Vertex> tmpSolution;
    std::vector<float> diversities;
    int diversity = findDiversity(solution);
    for(int i = 0; i < get_FreeVertex().size(); i ++){
        std::vector<Vertex> tmp = solution;
        tmp.push_back(get_FreeVertex()[i]);
        int tmpDiversity = findDiversity(tmp);
        if(tmpDiversity > diversity){
            tmpSolution.push_back(get_FreeVertex()[i]);
            diversities.push_back(tmpDiversity);
        }
    }
    while(tmpSolution.size() >= get_RLC()){
        int pos = 0;
        float min = diversities[0];
        for(int i = 1; i < tmpSolution.size(); i++){
            if(diversities[i] < min){
                min = diversities[i];
                pos = 1;
            }
        }
        tmpSolution.erase(tmpSolution.begin() + pos);
    }
    RLC = tmpSolution;
}