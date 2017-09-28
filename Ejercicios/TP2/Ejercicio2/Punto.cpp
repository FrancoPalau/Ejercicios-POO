/*
 * Punto.cpp
 *
 *  Created on: 22/09/2017
 *      Author: franco
 */

#include "Punto.h"

Punto::Punto() {
	setCoordenadaX(0);
	setCoordenadaY(0);
}

Punto::Punto(float x, float y) {
	setCoordenadaX(x);
	setCoordenadaY(y);
}

Punto::~Punto() {
	// TODO Auto-generated destructor stub
	cout << "Punto eliminado" ;
}

float Punto::getCoordenadaX() {
	return coordenadaX;
}

void Punto::setCoordenadaX(float x) {
	if(x >= 0 && x < 74 ){
		coordenadaX=x;
	}
}

float Punto::getCoordenadaY() {
	return coordenadaY;
}

void Punto::setCoordenadaY(float y) {
	if(y >= 0 && y < 22){
		coordenadaY=y;
	}
}
