/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Maximum Diversity                       =
    =            File name:     Chrono.cpp                                         =
    =            Author:        Gabriel Melián Hernández                           =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*------------  DECLARACIÓN DE FUNCIONES  ------------*/

#include "../include/Chrono.hpp"

/*-------------------------------------------------*/

/**
* @brief Construye un nuevo Chrono.
*/
Chrono::Chrono(){
}

/**
* @brief Destruye el Chrono.
*/
Chrono::~Chrono(){
}

/**
* @brief Consigue el StartClock.
*
* @return El StartClock. 
*/
std::chrono::time_point<std::chrono::system_clock> Chrono::get_StartClock(void) const{
    return startClock_;
}

/**
 * @brief      Consigue el EndClock.
 *
 * @return     El EndClock.
 */
std::chrono::time_point<std::chrono::system_clock> Chrono::get_EndClock (void) const {
	return endClock_;
}

/**
* @brief Consigue el tiempo total.
*
* @return   El tiempo total.
*/
int Chrono::get_TotalTime(void) const{
    return totalTime_;
}

/**
* @brief Consigue el StartTime.
*
* @return El StartTime.
*/
time_t Chrono::get_StartTime(void) const{
    return startTime_;
}

/**
 * @brief      Consigue el EndTime.
 *
 * @return     El EndTime.
 */
time_t Chrono::get_EndTime (void) const {
	return endTime_;
}

/**
 * @brief      Establece el StartClock.
 *
 * @param[in]  startClock  El StartClock.
 */
void Chrono::set_StartClock (std::chrono::time_point<std::chrono::system_clock> startClock) {
	startClock_ = startClock;
}

/**
 * @brief      Establece el EndClock.
 *
 * @param[in]  endClock  El EndClock.
 */
void Chrono::set_EndClock (std::chrono::time_point<std::chrono::system_clock> endClock) {
	endClock_ = endClock;
}

/**
 * @brief      Establece el tiempo total.
 *
 * @param[in]  totalTime  El tiempo total.
 */
void Chrono::set_TotalTime (int totalTime) {
	totalTime_ = totalTime;
}

/**
 * @brief      Establece el tiempo de inicio.
 */
void Chrono::set_StartTime (void) {
	startTime_ = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

/**
 * @brief      Establece el tiempo final.
 */
void Chrono::set_EndTime (void) {
	endTime_ = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

/**
 * @brief      Reinicio el Chrono.
 */
void Chrono::restartChrono (void) {
	set_TotalTime(0);
}

/**
 * @brief      Empieza el chrono.
 */
void Chrono::startChrono (void) {
	restartChrono();
	set_StartTime();
	startClock_ = std::chrono::system_clock::now();
}

/**
 * @brief      Para el Chrono.
 */
void Chrono::stopChrono (void) {
	set_EndTime();
	endClock_ = std::chrono::system_clock::now();
	totalTime_ += std::chrono::duration_cast<std::chrono::microseconds>(endClock_ - startClock_).count();
}

/**
 * @brief      Pausa el chrono.
 */
void Chrono::pauseChrono (void) {
	stopChrono();
	totalTime_ += std::chrono::duration_cast<std::chrono::microseconds>(endClock_ - startClock_).count();
}

/**
 * @brief      Arranca de nuevo el chrono.
 */
void Chrono::resumeChrono (void) {
	startClock_ = std::chrono::system_clock::now();
}

/**
 * @brief      Consigue el tiempo en segundos.
 *
 * @return     Los segundos.
 */
float Chrono::get_Seconds (void) {
	float time = totalTime_ / 1000000;
	return time;
}

/**
 * @brief      Consigue el tiempo en segundos con decimales.
 *
 * @param[in]  decimalAmmount  La cantidad de decimales.
 *
 * @return     Los segundos.
 */
float Chrono::get_Seconds (int decimalAmmount) {
	float time = totalTime_;
	time /= 1000000;
	std::string aux = std::to_string(time);
	std::string copy = "";
	int counter = 0;
	bool decimals = false;
	for (int i = 0; i < aux.size(); i++) {
		if (aux[i] == '.') {
			decimals = true;
			copy[i] = aux[i];
		}
		else if (counter < decimalAmmount) {
			if (decimals == true) {
				counter++;
			}
			copy[i] = aux[i];
		}
		else {
			break;
		}
	}	
	time = stof(copy);
	return time;
}

/**
 * @brief      Consigue el tiempo en milisegundos.
 *
 * @return     Los milisegundos.
 */
float Chrono::get_MilliSeconds (void) {
	float time = totalTime_ / 1000;
	return time;
}

/**
 * @brief      Consigue el tiempo en milisegundos con decimales.
 *
 * @param[in]  decimalAmmount  La cantidad de decimales.
 *
 * @return     Los milisegundos.
 */
float Chrono::get_MilliSeconds (int decimalAmmount) {
	float time = totalTime_;
	time /= 1000;
	std::string aux = std::to_string(time);
	std::string copy = "";
	int counter = 0;
	bool decimals = false;
	for (int i = 0; i < aux.size(); i++) {
		if (aux[i] == '.') {
			decimals = true;
			copy[i] = aux[i];
		}
		else if (counter < decimalAmmount) {
			if (decimals == true) {
				counter++;
			}
			copy[i] = aux[i];
		}
		else {
			break;
		}
	}	
	time = stof(copy);
	return time;
}

/**
 * @brief      Consigue el tiempo en microsegundos.
 *
 * @return     Los microsegundos.
 */
float Chrono::get_MicroSeconds (void) {
	return totalTime_;
}

/**
 * @brief      Consigue el tiempo completo.
 *
 * @return     El tiempo.
 */
std::string Chrono::get_Time (void) {

}
