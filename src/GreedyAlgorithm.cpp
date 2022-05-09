/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     GreedyAlgorithm.cpp                                =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/GreedyAlgorithm.hpp"

/*------------------------------------------------*/

/**
* @brief    Construye una nueva instancia.
*/
GreedyAlgorithm::GreedyAlgorithm(){
}

/**
* @brief    Destruye el objeto.
*/
GreedyAlgorithm::~GreedyAlgorithm(){
}

/**
* @brief    Ejecuta el Algoritmo Greedy.
*
* @param    graph   EL Grafo.
*/
void GreedyAlgorithm::runAlgorithm(Graph& graph, Chrono& chrono){
    chrono.startChrono();
    std::vector<Vertex> solution;
    set_FreeVertex(graph.get_Vertex());
    Vertex gravityCenter;
    gravityCenter = generateGravityCenter(get_FreeVertex());
    do{
        int candidate = findFurthestFromGravityCenter(get_FreeVertex(), gravityCenter);
        addition(solution, candidate);
        gravityCenter = generateGravityCenter(solution);
    } while (solution.size() < get_SolutionSize());
    set_Solution(solution);
    set_Diversity(findDiversity(solution));
    chrono.stopChrono();
}