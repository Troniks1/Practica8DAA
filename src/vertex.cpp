/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     vertex.cpp                                         =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/vertex.hpp"

/*------------------------------------------------*/

/**
* @brief    Construye una nueva instancia.
*/
Vertex::Vertex(){
    coordinates_.resize(0);
}

/**
* @brief    Construye una nueva instancia.
*
* @param[in]    number  El número.
*/
Vertex::Vertex(int number){
    assert(number >= 0);
    set_Number(number);
    coordinates_.resize(0);
    generateName();
}

/**
* @brief    Destruye el objeto.
*/
Vertex::~Vertex(){
    coordinates_.resize(0);
}

/**
* @brief    Consigue el número.
*
* @return   El número.
*/
int Vertex::get_Number(void) const{
    return number_;
}

/**
* @brief    Consigue el nombre.
*
* @return   El nombre.
*/
std::string Vertex::get_Name(void) const{
    return name_;
}

/**
* @brief    Consigue las coordenadas.
*
* @return   Las coordenadas.
*/
std::vector<float> Vertex::get_Coordinates(void) const{
    return coordinates_;
}

/**
* @brief    Establece el número.
*
* @param[in]    number  El número.
*/
void Vertex::set_Number(int number){
    number_ = number;
}

/**
* @brief    Establece el nombre.
*
* @param[in]    name    El nombre.
*/
void Vertex::set_Name(std::string name){
    name_ = name;
}

/**
* @brief    Establece las coordenadas.
*
* @param[in]    coordinates Las coordenadas.
*/
void Vertex::set_Coordinates(std::vector<float> coordinates){
    coordinates_.clear();
    coordinates_.resize(coordinates.size());
    for(int i = 0; i < coordinates.size(); i++){
        coordinates_[i] = coordinates[i];
    }
}

/**
* @brief    Operador =.
*
* @param[in]    vertex  El Vector.
*/
void Vertex::operator=(const Vertex& vertex){
    set_Name(vertex.get_Name());
    set_Number(vertex.get_Number());
    set_Coordinates(vertex.get_Coordinates());
}

/**
* @brief    Genera el nombre del vector.
*/
void Vertex::generateName(void){
    std::string name = "Vertex ";
    name += std::to_string(get_Number());
    set_Name(name);
}

/**
* @brief    Añade una coordenada al vector de coordenadas.
*
* @param[in]    coordinate  La coordenada.
*/
void Vertex::addCoordinate(float coordinate){
    coordinates_.push_back(coordinate);
}

/**
* @brief    Establece una coordenada.
*
* @param[in]    position    La posición.
* @param[in]    number      El número.
*/
void Vertex::setCoordinate(int position, float number){
    coordinates_[position] = number;
}
