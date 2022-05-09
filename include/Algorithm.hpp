/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     Algorithm.hpp                                      =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once 
#include "graph.hpp" 
#include "Chrono.hpp"
#define STARTMEAN -9999999;

/*------------------------------------------------*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <string>
#include <algorithm>

/*------------------------------------------------*/

class Algorithm {

	private:
		std::vector<Vertex> solutions_;
		float diversity_;
		std::vector<Vertex> freeVertex_;
		int solutionSize_;

	public:
		// Constructor y Destructor.
		Algorithm ();
		virtual ~Algorithm ();

		// Setters y Getters.
		std::vector<Vertex> get_Solution (void) const;
		float get_Diversity (void) const;
		std::vector<Vertex>& get_FreeVertex (void);
		int get_SolutionSize (void) const;

		void set_Solution (std::vector<Vertex> solution);
		void set_Diversity (float diversity);
		void set_FreeVertex (std::vector<Vertex> freeElements);
		void set_SolutionSize (int size);

		// Funciones
		virtual void runAlgorithm (Graph& graph, Chrono& chrono);
		std::ostream& printResult (std::ostream& os, Chrono& chrono);
		float findDiversity (std::vector<Vertex>& vertex);
		Vertex generateGravityCenter (std::vector<Vertex>& vertex);
		int findFurthestFromGravityCenter (std::vector<Vertex>& vertex, Vertex& gravityCenter);
		int getPositionFromVector (std::vector<Vertex>& vertex, int vertexNum);

		// Estructuras de entorno.
		void addition (std::vector<Vertex>& vertex, int& vertexNum);
		void swap (std::vector<Vertex>& vertex, int& vertexNum, int& freeVertexNum);
		void extraction (std::vector<Vertex>& vertex, int& vertexNum);
		int getRandomVertex (std::vector<Vertex>& vector);
};