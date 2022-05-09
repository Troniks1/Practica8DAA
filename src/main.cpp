/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     main.cpp                                           =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/Framework.hpp"

/*------------------------------------------------*/

int main(int argc, char *argv[]){
    srand(time(NULL));
    if((argc != 2)){
        std::cout << std::endl << "Error en la entrada del programa." << std::endl;
        exit(0);
    }
    std::string fileName(argv[1]);
    FrameWork maxMeanDispersionProblem(fileName);
    maxMeanDispersionProblem.initialize();
    maxMeanDispersionProblem.executeFrameWork();
}