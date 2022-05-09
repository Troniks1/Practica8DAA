/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     LocalSearchAlgorithm.cpp                           =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/LocalSearchAlgorithm.hpp"

/*------------------------------------------------*/

/**
* @brief    Construye una nueva instancia.
*/
LocalSearchAlgorithm::LocalSearchAlgorithm(){
}

/**
* @brief    Destruiye el objeto.
*/
LocalSearchAlgorithm::~LocalSearchAlgorithm(){
}

/**
* @brief    Ejecuta el algoritmo de búsqueda Local.
*
* @param    graph   El grafo.
*/
void LocalSearchAlgorithm::runAlgorithm(Graph& graph, Chrono& chrono){
    chrono.startChrono();
    std::vector<Vertex> solution;
    set_FreeVertex(graph.get_Vertex());
    //Fase Inicial.
    for(int i = 0; i < get_SolutionSize(); i++){
        addition(solution, i);
    }
    bool end = false;
    int counter = 0;
    float diversity = findDiversity(solution);
    //Fase de Mejora.
    do{
        std::vector<Vertex> tmp = solution;
        bool changed = false;
        for (int i = 0; i < get_FreeVertex().size(); i++){
            tmp.erase(tmp.begin() + counter);
            tmp.push_back(get_FreeVertex()[i]);
            float tmpDiversity = findDiversity(tmp);
            if(tmpDiversity > diversity){
                diversity = tmpDiversity;
                swap(solution, counter, i);
                changed = true;
            }
        }
        if(changed == true){
            counter = 0;
        }
        else{
            counter ++;
            if(counter > get_SolutionSize()){
                end = true;
            }
        }
    }while (end != true);
    set_Solution(solution);
    set_Diversity(findDiversity(solution));
    chrono.stopChrono();
}