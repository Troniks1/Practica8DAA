/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     LocalSearchAlgorithm.hpp                           =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "Framework.hpp"

/*------------------------------------------------*/

class LocalSearchAlgorithm : public Algorithm{

    public:
        //Constructor y Destructor.
        LocalSearchAlgorithm();
        virtual ~LocalSearchAlgorithm();

        //Funciones.
        void runAlgorithm(Graph& graph, Chrono& chrono);
};