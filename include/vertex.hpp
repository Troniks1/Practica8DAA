/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     vertex.hpp                                          =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE LIBRERÍAS  ----------*/

#include <cassert>
#include <string>
#include <vector>

/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once

/*------------------------------------------------*/

/**
* @brief    Esta clase describe un vector.
*/
class Vertex{

    private:
    
        int number_;
        std::string name_;
        std::vector<float> coordinates_;

    public:
        //Constructores y Desctructor.
        Vertex();
        Vertex(int number);
        ~Vertex();

        //Setters y Getters.
        int get_Number(void) const;
        std::string get_Name(void) const;
        std::vector<float> get_Coordinates(void) const;

        void set_Number(int number);
        void set_Name(std::string name);
        void set_Coordinates(std::vector<float> coordinates);

        //Sobrecarga de Operadores.
        void operator=(const Vertex& vertex);

        //Funciones.
        void generateName(void);
        void addCoordinate(float coordinate);
        void setCoordinate(int position, float number);
};
