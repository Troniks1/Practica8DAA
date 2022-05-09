/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     GraspAlgorithm.hpp                                 =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "Framework.hpp"

/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <chrono>
#include <ctime>

/*------------------------------------------------*/

class GraspAlgorithm : public Algorithm{

    private:
        int RLC_;
        int iterations_;

    public:
        //Constructores y Destructor.
        GraspAlgorithm();
        GraspAlgorithm(int RLC, int iterations);
        virtual ~GraspAlgorithm();

        //Setters y Getters.
        int get_RLC(void) const;
        int get_Iterations(void) const;
        void set_RLC(int RLC);
        void set_Iterations(int iterations);

        //Funciones.
        void runAlgorithm(Graph& graph, Chrono& chrono);

    private:
        //Funciones.
        void generateRLC(std::vector<Vertex>& RLCvector, std::vector<Vertex>& solution);
};