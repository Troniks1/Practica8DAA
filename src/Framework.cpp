/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     Framework.cpp                                      =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/Framework.hpp"

/*------------------------------------------------*/

/**
* @brief    Construye una nueva instancia.
*/
FrameWork::FrameWork(){   
}

/**
* @brief    Construye una nueva instancia.
*
* @param[in]    textFile    El fichero de texto.
*/
FrameWork::FrameWork(std::string textFile){
    set_TextFile(textFile);
}

/**
* @brief    Destuye el objeto.
*/
FrameWork::~FrameWork(){
}

/**
* @brief Consigue el grafo.
*
* @return   El grafo.
*/
Graph FrameWork::get_Graph(void) const{
    return graph_;
}

/**
* @brief    Consigue el fichero de texto.
*
* @return   El fichero de texto.
*/
std::string FrameWork::get_TextFile(void) const{
    return textFile_;
}

/**
* @brief    Consigue el algoritmo.
*
* @return   EL algoritmo.
*/
Algorithm* FrameWork::get_Algorithm(void) const{
    return algorithm_;
}

/**
* @brief    Consigue el Chrono.
*
* @return   El Chrono.
*/
Chrono FrameWork::get_Chrono(void) const{
    return chrono_;
}

/**
* @brief    Consigue el tamaño de la solución.
*
* @return   El tamaño de la solución.
*/
int FrameWork::get_SolutionSize(void) const{
    return solutionSize_;
}

/**
* @brief    Establece el grafo.
*
* @param[in]    graph   El grafo.
*/
void FrameWork::set_Graph(Graph graph){
    graph_ = graph;
}

/**
* @brief    Establece el fichero de texto.
*
* @param[in]    textFile    El fichero de texto.
*/
void FrameWork::set_TextFile(std::string textFile){
    textFile_ = textFile;
}

/**
* @brief    Establece el algoritmo.
*
* @param[in]    algorithm   El algoritmo.
*/
void FrameWork::set_Algorithm(Algorithm* algorithm){
    algorithm_ = algorithm;
}

/**
* @brief    Establece el chrono.
*
* @param[in]    chrono  El chrono.
*/
void FrameWork::set_Chrono(Chrono chrono){
    chrono_ = chrono;
}

/**
* @brief    Establece el tamaño de la solución.
*
* @param[in]    size    El tamaño de la solución.
*/
void FrameWork::set_SolutionSize(int size){
    solutionSize_ = size;
}

/**
* @brief Inicializa el objeto.
*/
void FrameWork::initialize(void){
    graph_.set_TextFile(get_TextFile());
    graph_.generateGraph();
    graph_.printGraph();
    int choice = printMenu();
    switch (choice){
        case 1:
            algorithm_ = new GreedyAlgorithm();
            break;

        case 2:
            algorithm_ = new LocalSearchAlgorithm();
            break;
        
        case 3:
            int RLC, iterations;
            std::cout << std::endl << "Introduce el tamaño deseado para la LRC: " <<std::endl;
            std::cin >> RLC;
            std::cout << std::endl << "Introduce el número de iteraciones deseado: " << std::endl;
            std::cin >> iterations;
            algorithm_ = new GraspAlgorithm(RLC, iterations);
            break;

        case 4:
			int strategy;
			std::cout << std::endl << "Select the strategy mode:\n\t0. Expands the node with the lowest upperBound\n\t1. Expands the deepest node " << std::endl;
			std::cin >> strategy;
			algorithm_ = new BranchingAndPruningAlgorithm(strategy);
			break;
        
        case 0:
            std::cout << std::endl << "Aborting Program . . ." << std::endl;
            exit(0);
            break;

        default:
            std::cout << std::endl << "Error Seleccionando Algoritmo" << std::endl;
            exit(0);
            break;
    }
}

/**
* @brief Ejecuta el algoritmo seleccionado.
*/
void FrameWork::executeFrameWork(void){
    std::cout << std::endl << "Selecciona el tamaño de la solución: " << std::endl;
    int aux;
    std::cin >> aux;

    algorithm_ -> set_SolutionSize(aux);
    algorithm_ -> runAlgorithm(graph_, chrono_);
    algorithm_ -> printResult(std::cout, chrono_);
}

/**
* @brief Muestra un menú.
*
* @return   La opción seleccinada.
*/
int FrameWork::printMenu(void){
    std::cout << std::endl << "Selecciona uno de los siguientes algoritmos: ";
	std::cout << std::endl << "\t 1. Greedy Algorithm.";
	std::cout << std::endl << "\t 2. Local Search Algorithm";
	std::cout << std::endl << "\t 3. GRASP Algorithm";
    std::cout << std::endl << "\t 4. BranchingAndPruning Algorithm";
	std::cout << std::endl << "\t 0. Abort program";
	std::cout << std::endl;
	int selector;
	std::cin >> selector;
	return selector;
}