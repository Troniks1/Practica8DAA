/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     GreedyAlgorithm.hpp                                =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "Framework.hpp"

/*------------------------------------------------*/

class GreedyAlgorithm : public Algorithm{

    public:
        //Constructor y Destructor.
        GreedyAlgorithm();
        virtual ~GreedyAlgorithm();

        //Funciones.
        void runAlgorithm (Graph& graph, Chrono& chrono);
};