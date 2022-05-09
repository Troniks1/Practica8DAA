/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     Chrono.hpp                                         =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*------------  DECLARACIÓN DE FUNCIONES  ------------*/

#pragma once

/*-------------------------------------------------*/
/*------------  DECLARACIÓN DE LIBRERÍAS  ------------*/

#include <chrono>
#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>

/*------------------------------------------------*/

class Chrono{

    private:
        //Atributos.
        std::chrono::time_point<std::chrono::system_clock> startClock_;
        std::chrono::time_point<std::chrono::system_clock> endClock_;
        int totalTime_;
        time_t startTime_;
        time_t endTime_;

    public:
        //Constructor y Destructor.
        Chrono();
        ~Chrono();

        //Setters y Getters.
        std::chrono::time_point<std::chrono::system_clock> get_StartClock(void) const;
        std::chrono::time_point<std::chrono::system_clock> get_EndClock(void) const;
        int get_TotalTime(void) const;
        time_t get_StartTime(void) const;
        time_t get_EndTime(void) const;

        void set_StartClock(std::chrono::time_point<std::chrono::system_clock> startClock);
        void set_EndClock(std::chrono::time_point<std::chrono::system_clock> endClock);
        void set_TotalTime(int totalTime);
        void set_StartTime(void);
        void set_EndTime(void);

        //Funciones.
        void restartChrono(void);
        void startChrono(void);
        void stopChrono(void);
        void pauseChrono(void);
        void resumeChrono(void);

        //Funciones para devolver el tiempo.
        float get_Seconds(void);
        float get_Seconds(int decimalAmmount);
        float get_MilliSeconds(void);
        float get_MilliSeconds(int decimalAmmount);
        float get_MicroSeconds(void);
        std::string get_Time(void);
};