/*
 * Segmento.cpp
 *
 *  Created on: 22/09/2017
 *      Author: franco
 */

#include "Segmento.h"


Segmento::Segmento(float ix, float iy, float fx, float fy)
:inicio(),fin()
{
	setSimbolo('+');
	setPuntoInicial(ix,iy);
	setPuntoFinal(fx,fy);
	setPendiente(false);
}

Segmento::Segmento(char char1,float ix ,float iy, float fx, float fy) {
	setSimbolo(char1);
	setPuntoInicial(ix,iy);
	setPuntoFinal(fx,fy);
	setPendiente(false);
}

Segmento::~Segmento() {
	// TODO Auto-generated destructor stub
	cout << "Recta eliminada ";
}

void Segmento::setSimbolo(char char1) {
	simboloElegido=char1;
}

char Segmento::getSimbolo() {
	return simboloElegido;
}

void Segmento::setPuntoInicial(float x, float y) {
	inicio.setCoordenadaX(x);
	inicio.setCoordenadaY(y);
}

void Segmento::setPuntoFinal(float x, float y) {
	fin.setCoordenadaX(x);
	fin.setCoordenadaY(y);
}

float Segmento::getPuntoInicialX() {
	return inicio.getCoordenadaX();
}

float Segmento::getPuntoInicialY() {
	return inicio.getCoordenadaY();
}

float Segmento::getPuntoFinalX() {
	return fin.getCoordenadaX();
}

float Segmento::getPuntoFinalY() {
	return fin.getCoordenadaY();
}

void Segmento::setPendiente(bool inverso) {
	if (inverso){
		pendiente=(getPuntoFinalX()-getPuntoInicialX())/(getPuntoFinalY()-getPuntoInicialY());
	}else{
		pendiente=(getPuntoFinalY()-getPuntoInicialY())/(getPuntoFinalX()-getPuntoInicialX());
	}
}

int Segmento::getPendiente() {
	return pendiente;
}
