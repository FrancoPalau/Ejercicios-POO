/*
 * Trayectoria.cpp
 *
 *  Created on: 21/09/2017
 *      Author: franco
 */

#include "Trayectoria.h"

Trayectoria::Trayectoria(){
	distanciaTotal=0;
}

Trayectoria::Trayectoria(int distInicial){
	distanciaTotal=distInicial;
}

Trayectoria::~Trayectoria() {
	cout << "yo tbm!";
}

void Trayectoria::setDistanciaTotal(int disAct){
	if(disAct > 0){
		distanciaTotal=distanciaTotal + disAct;
	}
}

int Trayectoria::getDistaciaTotal(){
	return distanciaTotal;
}

vector<string> Trayectoria::getSecuencia(){
	return secuencia;
}
