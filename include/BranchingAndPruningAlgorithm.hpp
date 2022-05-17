/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Maximum Diversity                       =
	=            File name:     BranchingAndPruningAlgorithm.hpp                   =
	=            Author:        Gabriel Melián Hernández                           =
	=                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "Framework.hpp"

/*------------------------------------------------*/

class BranchingAndPruningAlgorithm : public Algorithm {

	private:   
		float upperBound_;
		float lowerBound_;
		int strategy_;  // 0 -> Expande el nodo con la cota superior más pequeña.
						// 1 -> Expande el nodo mas profundo.
		std::vector<Vertex> tmpSolution_;
		std::vector<Vertex> possibleVertex_;
		std::vector<float> lowerBoundsVector_;
		std::vector<float> upperBoundsVector_;
		int generatedNodes_;

	public:
		// Constructores y Destructor.
		BranchingAndPruningAlgorithm ();
		BranchingAndPruningAlgorithm (int strategy);
		virtual ~BranchingAndPruningAlgorithm ();

		// Setters y Getters.
		float get_UpperBound (void) const;
		float get_LowerBound (void) const;
		int get_Strategy (void) const;
		std::vector<Vertex> get_TmpSolution (void) const;
		std::vector<Vertex> get_PossibleVertex (void) const;

		void set_UpperBound (float bound);
		void set_LowerBound (float bound);
		void set_Strategy (int strategy);
		void set_TmpSolution (std::vector<Vertex> tmp);
		void set_PossibleVertex (std::vector<Vertex> possibilities);

		// Funciones.
		void runAlgorithm (Graph& graph, Chrono& chrono);

	private:
		void expandNodeStrategy1 (std::vector<Vertex>& tmp, int pos, float diversity);
		void expandNodeStrategy0 (std::vector<Vertex> tmp, int pos);
		bool isValidSolution (std::vector<Vertex>& tmp);
		bool hasbetterUpperBound (std::vector<Vertex> tmp, int pos);
};