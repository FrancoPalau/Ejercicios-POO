/*
 * Segmento.h
 *
 *  Created on: 22/09/2017
 *      Author: franco
 */

#include "Punto.h"
#include <iostream>
using namespace std;

#ifndef SEGMENTO_H_
#define SEGMENTO_H_

class Segmento {
	public:
		Segmento(float,float,float,float);
		Segmento(char,float,float,float,float);
		virtual ~Segmento();
		void setSimbolo(char);
		char getSimbolo();
		void setPuntoInicial(float,float);
		void setPuntoFinal(float,float);
		float getPuntoInicialX();
		float getPuntoInicialY();
		float getPuntoFinalX();
		float getPuntoFinalY();
		void setPendiente(bool);
		int getPendiente();
	private:
		char simboloElegido;
		Punto inicio;
		Punto fin;
		int pendiente;
};

#endif /* SEGMENTO_H_ */
