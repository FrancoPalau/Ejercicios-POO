/*
 * MovilElemental.cpp
 *
 *  Created on: 21/09/2017
 *      Author: franco
 */

#include "MovilElemental.h"

MovilElemental::MovilElemental() {
	identificacion="Generico";
	cargaBateria=500;
	ptrTrayecto=new Trayectoria();
}

MovilElemental::MovilElemental(string nombre){
	setIdentificacion(nombre);
	cargaBateria=500;
	ptrTrayecto=new Trayectoria();
}

MovilElemental::MovilElemental(string nombre, int distInicial){
	setIdentificacion(nombre);
	cargaBateria=500;
	ptrTrayecto=new Trayectoria(distInicial);
}

MovilElemental::~MovilElemental() {
	cout << "destruido";
	delete ptrTrayecto;
}

string MovilElemental::getIdentificacion(){
	return identificacion;
}

void MovilElemental::setIdentificacion(string nombre){
	identificacion=nombre;
}

int MovilElemental::getCargaBateria(){
	return cargaBateria;
}
void MovilElemental::agregarASecuencia(string nuevoPaso){
	ptrTrayecto->secuencia.push_back(nuevoPaso);
}

string MovilElemental::mostrarSecuencia(int i){
	return ptrTrayecto->secuencia[i];
}

int MovilElemental::tamanoSecuencia(){
	return ptrTrayecto->secuencia.size();
}

void MovilElemental::distanciaTotal(int distActual){
	ptrTrayecto->setDistanciaTotal(distActual);
}
int MovilElemental::mostrarDistanciaTotal(){
	return ptrTrayecto->getDistaciaTotal();
}
