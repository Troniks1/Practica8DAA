/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     Algorithm.cpp                                      =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/Algorithm.hpp"
#include <math.h>

/*------------------------------------------------*/

/**
* @brief    Construye una nueva instancia.
*/
Algorithm::Algorithm(){
}

/**
* @brief    Destruye el objeto.
*/
Algorithm::~Algorithm(){
}

/**
* @brief    Consigue la solución.
*
* @return   La solución.
*/
std::vector<Vertex> Algorithm::get_Solution(void) const{
    return solutions_;
}

/**
* @brief    Consigue la diversidad.
*
* @return   La diversidad.
*/
float Algorithm::get_Diversity(void) const{
    return diversity_;
}

/**
* @brief    Consigue el tamaño de la solución.
*
* @return   El tamaño de la solución.
*/
int Algorithm::get_SolutionSize(void) const{
    return solutionSize_;
}

/**
* @brief    Consigue el vector de vértices libres.
*
* @return   El vector de vértices libres.
*/
std::vector<Vertex>& Algorithm::get_FreeVertex(void){
    return freeVertex_;
}

/**
* @brief    Establece la solución.
*
* @param[in]    solution    La solución.
*/
void Algorithm::set_Solution(std::vector<Vertex> solution){
    solutions_ = solution;
}

/**
* @brief    Establece la diversidad.
*
* @param[in]    diversity   La diversidad.
*/
void Algorithm::set_Diversity(float diversity){
    diversity_ = diversity;
}

/**
* @brief    Establece el vector de vértices libres.
*
* @param[in]    freeVertex  El vector de vértices libres.
*/
void Algorithm::set_FreeVertex(std::vector<Vertex> freeVertex){
    freeVertex_.clear();
    freeVertex_.resize(freeVertex.size());
    for(int i = 0; i < freeVertex.size(); i++){
        freeVertex_[i] = freeVertex[i];
    }
}

/**
* @brief    Establece el tamaño de la solución.
*
* @param[in]    size    El tamaño.
*/
void Algorithm::set_SolutionSize(int size){
    solutionSize_ = size;
}

/**
* @brief    Ejecuta el algoritmo.
*
* @param    graph   El grafo.
*/
void Algorithm::runAlgorithm(Graph& graph, Chrono& chrono){
}

/**
* @brief    Muestra un resultado.
*
* @param    os  El flujo de salida.
* @param    chrono  El chroono.
*
* @return   El flujo de salida.
*/
std::ostream& Algorithm::printResult(std::ostream& os, Chrono& chrono){
    assert(get_Solution().size() > 0);
    os << std::endl << "CPU Time: " << chrono.get_Seconds(5) << " seconds.";
    os << std::endl << "Solución: { ";
    for(int i = 0; i < get_Solution().size() -1; i++){
        os << get_Solution()[i].get_Number() << ", ";
    }
    os << get_Solution()[get_Solution().size() -1].get_Number() << " }" << std::endl;
    os << "Valor de Diversidad: " << get_Diversity() << std::endl;
    return os;
}

/**
* @brief    Consigue la diversidad de un vector de vértices.
*
* @param    vertex  El vector.
*
* @return   La diversidad.
*/
float Algorithm::findDiversity(std::vector<Vertex>& vertex){
    float diversity = 0.0;
    for(int i = 0; i < (vertex.size() -1); i++){
        for(int j = i +1; j < vertex.size(); j++){
            float tmp = 0.0;
            for(int k = 0; k < vertex[0].get_Coordinates().size(); k++){
                tmp += pow((vertex[i].get_Coordinates()[k] - vertex[j].get_Coordinates()[k]), 2);
            }
            diversity += sqrt(tmp);
        }
    }
    return diversity;
}

/**
* @brief    Calcula el centro de gravedad de un vector dado.
*
* @param    vertex  El vector.
*
* @return   El centro de gravedad.
*/
Vertex Algorithm::generateGravityCenter(std::vector<Vertex>& vertex){
    std::vector<float> gravityCenter;
    gravityCenter.resize(vertex[0].get_Coordinates().size());
    for (int i = 0; i < gravityCenter.size(); i++) {
        gravityCenter[i] = 0;
        for (int j = 0; j < vertex.size(); j++) {
            gravityCenter[i] += vertex[j].get_Coordinates()[i];
        }
        gravityCenter[i] /= vertex.size();
    }
    Vertex gravity;
    for (int i = 0; i < gravityCenter.size(); i++) {
    	gravity.addCoordinate(gravityCenter[i]);
    }
	return gravity;
}

/**
* @brief    Encuentra el vértice mas alejado del centro de gravedad.
*
* @param    vertex  El vector de vértices.
* @param    gravityCenter   El centro de gravedad.
*
* @return   El numero del vértice.
*/
int Algorithm::findFurthestFromGravityCenter(std::vector<Vertex>& vertex, Vertex& gravityCenter){
    int number = 0;
    float diversity_ = STARTMEAN;
    for(int i = 0; i < vertex.size(); i++){
        std::vector<Vertex> tmp;
        tmp.resize(2);
        tmp[0] = gravityCenter;
        tmp[1] = vertex[i];
        float diversity = findDiversity(tmp);
        if(diversity_ < diversity){
            number = i;
            diversity_ = diversity;
        }
    }
    return number;
}

/**
* @brief    Consigue la posicion en el vector de un vértice dado.
*
* @param    vertex  El vector de vértices.
* @param[in]    vertexNum   El numero del vector.
*
* @return   La posición del vértice.
*/
int Algorithm::getPositionFromVector(std::vector<Vertex>& vertex, int vertexNum){
    for(int i = 0; i < vertex.size(); i++){
        if(vertex[i].get_Number() == vertexNum){
            return i;
        }
    }
    return -1;
}

/**
* @brief    Añade un vértice al vector y lo borra del vector de vértices libres.
*
* @param    vertex  El vector de vértices.
* @param[in]    vertexNum   El número del vector.
*/
void Algorithm::addition(std::vector<Vertex>& vertex, int& vertexNum){
    vertex.push_back(get_FreeVertex()[vertexNum]);
    freeVertex_.erase(freeVertex_.begin() + vertexNum);
}

/**
 * @brief      Intercambia un vértice con otro.
 *
 * @param      vertex         El vector de vértices.
 * @param[in]  vertexNum      El número del vector.
 * @param[in]  freeVertexNum  El número del vector de vértices libres.
 */
void Algorithm::swap (std::vector<Vertex>& vertex, int& vertexNum, int& freeVertexNum) {
	addition(vertex, freeVertexNum);
	extraction(vertex, vertexNum);
}

/**
 * @brief      Extrae un vértice del vector dado y lo introduce en el vector de vértices libres.
 *
 * @param      vertex     El vector de vértices.
 * @param      vertexNum  El número del vector.
 */
void Algorithm::extraction (std::vector<Vertex>& vertex, int& vertexNum) {
	freeVertex_.push_back(vertex[vertexNum]);
	vertex.erase(vertex.begin() + vertexNum);
}

/**
 * @brief      Consigue un vértice random del vector.
 *
 * @param[in]  vector   El vector.
 *
 * @return     El vértice random.
 */
int Algorithm::getRandomVertex (std::vector<Vertex>& vector) {
	if (vector.size() > 0) {
		int num = rand() % vector.size();
		return num;
	}
	else {
		return -1;
	}
}