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
        int iterations_;
        int RLCGC_;

    public:
        //Constructores y Destructor.
        GraspAlgorithm();
        GraspAlgorithm(int RLC, int iterations);
        virtual ~GraspAlgorithm();

        //Setters y Getters.
        int get_RLCGC(void);
        void set_RLCGC(int RLC);
        int get_Iterations(void) const;
        void set_Iterations(int iterations);

        //Funciones.
        void runAlgorithm(Graph& graph, Chrono& chrono);

    private:
        //Funciones.
        void generateRLCGC(std::vector<int>& RLCGCvector, std::vector<Vertex>& solution, Vertex& gravityCenter);
};