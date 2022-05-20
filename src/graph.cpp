/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     graph.cpp                                          =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/graph.hpp"

/*------------------------------------------------*/

/**
* @brief    Construye una nueva instancia.
*/
Graph::Graph(){
}

/**
* @brief    Construye una nueva instancia.
*
* @param[in]    textFile    El fichero de texto.
*/
Graph::Graph(std::string textFile){
    set_TextFile(textFile);
}

/**
* @brief    Destruye el objeto.
*/
Graph::~Graph(){
}

/**
* @brief    Consigue el vector de vértices.
*
* @return   El vector de vértices.
*/
std::vector<Vertex> Graph::get_Vertex(void) const{
    return vertex_;
}

/**
* @brief    Consigue el fichero de texto.
*
* @return   El fichero de texto.
*/
std::string Graph::get_TextFile(void) const{
    return textFile_;
}

/**
* @brief    Consigue el número de vértices.
*
* @return   El número de vértices.
*/
int Graph::get_VertexNum(void) const{
    return vertexNum_;
}

/**
* @brief    Consigue el número de coordenadas.
*
* @return   El número de coordenadas.
*/
int Graph::get_CoordinatesNum(void) const{
    return coordinatesNum_;
}

/**
* @brief    Establece el vector de vértices.
*
* @param[in]    vertex  El vector de vértices.
*/
void Graph::set_Vertex(std::vector<Vertex> vertex){
    vertex_ = vertex;
}

/**
* @brief    Establece el fichero de texto.
*
* @param[in]    textFile    El fichero de texto.
*/
void Graph::set_TextFile(std::string textFile){
    textFile_ = textFile;
}

/**
* @brief Establece el número de vértices.
*
* @param[in]    vertexNum   El número de vértices.
*/
void Graph::set_VertexNum(int vertexNum){
    vertexNum_ = vertexNum;
}

/**
* @brief Establece el número de coordenadas.
*
* @param[in]    coordinatesNum  El número de coordenadas.
*/
void Graph::set_CoordinatesNum(int coordinatesNum){
    coordinatesNum_ = coordinatesNum;
}

/**
* @brief    Genera el grafo desde el fichero de texto que recibe el constructor.
*/
void Graph::generateGraph(void){
    std::ifstream textfile;
    textfile.open(get_TextFile());
    int readInt;
    float readFloat;
    if(textfile.is_open()){
        while(!textfile.eof()){
            textfile >> readInt;
            assert(readInt > 0);
            set_VertexNum(readInt);
            textfile >> readInt;
            assert(readInt > 0);
            set_CoordinatesNum(readInt);
            for (int i = 0; i< get_VertexNum(); i++){
                Vertex newVertex(i);
                for(int j = 0; j < get_CoordinatesNum(); j++){
                    textfile >> readFloat;
                    newVertex.addCoordinate(readFloat);
                }
                vertex_.push_back(newVertex);
            }
        }
        textfile.close();
    }
    else{
        std::cout << std::endl << "Error: No se encuentra el fichero de entrada." << std::endl;
        exit(0);
    }
}

/**
* @brief Muestra el grafo por la consola.
*/
void Graph::printGraph(void){
    char LETTERS[] = {'x', 'y', 'z', 'w', 't', 's'};
    for(int i = 0; i < vertex_.size(); i++){
        std::string node = vertex_[i].get_Name();
        node += "\n";
        for(int j= 0; j < get_CoordinatesNum(); j++){
            char tmp = LETTERS[j];
            node = node + "\t\tCoordinate " + LETTERS[j] + " -> " + std::to_string(vertex_[i].get_Coordinates()[j]) + '\n';
        }
        node += "\n";
        std::cout << node;
    }
}