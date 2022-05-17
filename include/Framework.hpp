/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     Framework.hpp                                      =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "graph.hpp"
#include "Chrono.hpp"
#include "Algorithm.hpp"
#include "GreedyAlgorithm.hpp"
#include "GraspAlgorithm.hpp"
#include "LocalSearchAlgorithm.hpp"
#include "BranchingAndPruningAlgorithm.hpp"

/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <string>

/*------------------------------------------------*/

/**
* @brief    Esta clase describe un FrameWork.
*/
class FrameWork {

    private:
        Graph graph_;
        std::string textFile_;
        Algorithm* algorithm_;
        Chrono chrono_;
        int solutionSize_;

    public:
        // Constructores y Destructor.
        FrameWork();
        FrameWork (std::string textFile);
        virtual ~FrameWork();

        // Setters y Getters.
        Graph get_Graph(void) const;
        std::string get_TextFile(void) const;
        Algorithm* get_Algorithm(void) const;
        Chrono get_Chrono(void) const;
        int get_SolutionSize(void) const;

        void set_Graph(Graph graph);
        void set_TextFile(std::string textFile);
        void set_Algorithm(Algorithm* algorithm);
        void set_Chrono (Chrono chrono);
        void set_SolutionSize(int size);

        //Funciones.
        void initialize(void);
        void executeFrameWork(void);
        int printMenu(void);
};