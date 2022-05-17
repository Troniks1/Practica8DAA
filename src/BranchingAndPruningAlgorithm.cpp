/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     BranchingAndPruningAlgorithm.cpp                   =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/BranchingAndPruningAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Construye una nueva instancia.
 */
BranchingAndPruningAlgorithm::BranchingAndPruningAlgorithm () {
}

/**
 * @brief      Construye una nueva instancia.
 *
 * @param[in]  strategy  La estrategia.
 */
BranchingAndPruningAlgorithm::BranchingAndPruningAlgorithm (int strategy) {
	set_Strategy(strategy);
}

/**
 * @brief      Destruye el objeto.
 */
BranchingAndPruningAlgorithm::~BranchingAndPruningAlgorithm () {
}

/**
 * @brief      Consigue la cosa superior.
 *
 * @return     La cota superior.
 */
float BranchingAndPruningAlgorithm::get_UpperBound (void) const {
	return upperBound_;
}

/**
 * @brief      Consigue la cota inferior.
 *
 * @return     La cota inferior.
 */
float BranchingAndPruningAlgorithm::get_LowerBound (void) const {
	return lowerBound_;
}

/**
 * @brief      Consigue la estrategia.
 *
 * @return     La estrategia.
 */
int BranchingAndPruningAlgorithm::get_Strategy (void) const {
	return strategy_;
}

/**
 * @brief      Consigue la solución temporal.
 *
 * @return     La solución temporal.
 */
std::vector<Vertex> BranchingAndPruningAlgorithm::get_TmpSolution (void) const {
	return tmpSolution_;
}

/**
 * @brief      Consigue el vector posible.
 *
 * @return     El vector posible.
 */
std::vector<Vertex> BranchingAndPruningAlgorithm::get_PossibleVertex (void) const {
	return possibleVertex_;
}

/**
 * @brief      Establece la cota superior.
 *
 * @param[in]  bound  La cota.
 */
void BranchingAndPruningAlgorithm::set_UpperBound (float bound) {
	upperBound_ = bound;
}

/**
 * @brief      Establece la cota inferior.
 *
 * @param[in]  bound  La cota.
 */
void BranchingAndPruningAlgorithm::set_LowerBound (float bound) {
	lowerBound_ = bound;
}

/**
 * @brief      Establece la estrategia.
 *
 * @param[in]  strategy  La estrategia.
 */
void BranchingAndPruningAlgorithm::set_Strategy (int strategy) {
	strategy_ = strategy;
}

/**
 * @brief      Establece la solución temporal.
 *
 * @param[in]  tmp   El nuevo valor.
 */
void BranchingAndPruningAlgorithm::set_TmpSolution (std::vector<Vertex> tmp) {
	tmpSolution_ = tmp;
}

/**
 * @brief      Establece el vector posible.
 *
 * @param[in]  possibilities  Las posibilidades.
 */
void BranchingAndPruningAlgorithm::set_PossibleVertex (std::vector<Vertex> possibilities) {
	possibleVertex_ = possibilities;
}

/**
 * @brief      Ejecuta el algoritmo de ramificación y poda.
 *
 * @param      graph  El grafo.
 */
void BranchingAndPruningAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	std::cout << std::endl << "Selecciona la cota inferior: ";
	float aux;
	std::cin >> aux;
	lowerBoundsVector_.resize(get_SolutionSize());
	upperBoundsVector_.resize(get_SolutionSize());	
	for (int i = 0; i < get_SolutionSize(); i++) {
		lowerBoundsVector_[i] = 0.0;
		upperBoundsVector_[i] = 0.0;
	}
	lowerBoundsVector_[get_SolutionSize() - 1] = aux;
	generatedNodes_ = 0;
	chrono.startChrono();
	set_PossibleVertex(graph.get_Vertex());
	set_LowerBound(aux);
	set_Strategy(1);
	std::vector<Vertex> initial;
	if (get_Strategy() == 1) {
		for (int i = 0; i < possibleVertex_.size(); i++) {
			expandNodeStrategy1(initial, i, 0.0);	
		}
	}
	else {
		expandNodeStrategy0(initial, 0);	
	}
	set_Solution(tmpSolution_);
	set_Diversity(findDiversity(tmpSolution_));
	chrono.stopChrono();
	std::cout << std::endl << "Generated nodes -> " << generatedNodes_ << std::endl;
}

/**
 * @brief      Expande el nodo mas profundo, estrategia 1.
 *
 * @param[in]  tmp        La solución temporal.
 * @param[in]  pos        La posición.
 * @param[in]  diversity  La diversidad.
 */
void BranchingAndPruningAlgorithm::expandNodeStrategy1 (std::vector<Vertex>& tmp, int pos, float diversity) {
	if ((tmp.size() > get_SolutionSize())) {
		return;
	}
	else if (tmp.size() < get_SolutionSize()){
		std::vector<Vertex> newTmp = tmp;
		newTmp.push_back(possibleVertex_[pos]);
		float newDiversity = findDiversity(newTmp);
		if (newDiversity >= diversity) {
			if (newDiversity >= lowerBoundsVector_[tmp.size() - 1]) {
				generatedNodes_++;
			}
			lowerBoundsVector_[tmp.size() - 1] = newDiversity;
			for (int i = pos; i < possibleVertex_.size(); i++) {
				expandNodeStrategy1(newTmp, i, newDiversity);
			}
		}
	}
	else {
		if (isValidSolution(tmp) && (diversity >= get_LowerBound())) {
			set_LowerBound(diversity);
			set_TmpSolution(tmp);
		}
	}
}

/**
 * @brief      Expande el nodo con la cota superior mas baja, estrategia 0.
 *
 * @param[in]  tmp   El temporal.
 * @param[in]  pos   La posición.
 */
void BranchingAndPruningAlgorithm::expandNodeStrategy0 (std::vector<Vertex> tmp, int pos) {
	generatedNodes_++;
	if ((tmp.size() > get_SolutionSize())) {
		return;
	}
	else if (tmp.size() < get_SolutionSize()){
		if (hasbetterUpperBound(tmp, pos) == true) {
			tmp.push_back(possibleVertex_[pos]);
			expandNodeStrategy0(tmp, pos + 1);
		}
		expandNodeStrategy0(tmp, pos + 1);
	}
	else {
		float diversity  = findDiversity(tmp);
		if (isValidSolution(tmp) && (diversity >= get_LowerBound())) {
			set_LowerBound(diversity);
			set_TmpSolution(tmp);
		}
	}
}

/**
 * @brief      Determina si la solucióm temporal es una solución factible o no.
 *
 * @param      tmp   El temporal.
 *
 * @return     Verdadero si la solución es una solución factible, falso en caso contrario.
 */
bool BranchingAndPruningAlgorithm::isValidSolution (std::vector<Vertex>& tmp) {
	for (int i = 0; i < (tmp.size() - 1); i++) {
		int aux = tmp[i].get_Number();
		for (int j = (i + 1); j < tmp.size(); j++) {
			if (tmp[j].get_Number() == aux) {
				return false;
			}
		}
	}
	return true;
}

/**
 * @brief      Busca si el vector dado tiene una mejor cota superior.
 *
 * @param[in]  tmp   El temporal.
 * @param[in]  pos   La posición.
 *
 * @return     Verdadero si la solución temporal tiene una cota superior mejor que la actual guardada, falso en caso contrario.
 */
bool BranchingAndPruningAlgorithm::hasbetterUpperBound (std::vector<Vertex> tmp, int pos) {
	std::vector<Vertex> newTmp = tmp;
	for (int i = pos; i < possibleVertex_.size(); i++) {
		tmp.push_back(possibleVertex_[i]);
	}
	float tmpDiversity = findDiversity(tmp);
	for (int i = pos + 1; i < possibleVertex_.size(); i++) {
		newTmp.push_back(possibleVertex_[i]);
	}
	float newTmpDiversity = findDiversity(newTmp);
	if (tmpDiversity < newTmpDiversity) {
		if (tmpDiversity < get_UpperBound()) {
			set_UpperBound(tmpDiversity);
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	} 
}
