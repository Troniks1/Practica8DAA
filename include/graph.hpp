/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     graph.hpp                                          =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <iostream>
#include <vector>
#include <fstream>

/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "vertex.hpp"

/*------------------------------------------------*/

/**
* @brief Esta clase describe un grapfo.
*/
class Graph {

    private:
        std::vector<Vertex> vertex_;
        std::string textFile_;
        int vertexNum_;
        int coordinatesNum_;

    public:
        //Constructores y Destructor.
        Graph();
        Graph(std::string textFile);
        ~Graph();

        //Setters y Getters.
        std::vector<Vertex> get_Vertex(void) const;
        std::string get_TextFile(void) const;
        int get_VertexNum(void) const;
        int get_CoordinatesNum(void) const;

        void set_Vertex (std::vector<Vertex> vertex);
		void set_TextFile (std::string textFile);
		void set_VertexNum (int vertexNum);
		void set_CoordinatesNum (int coordinatesNum);
        
        //Funciones.
        void generateGraph(void);

        //Escritura.
        void printGraph(void);
};