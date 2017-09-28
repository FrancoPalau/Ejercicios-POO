/*
 * testMovil.cpp
 *
 *  Created on: 21/09/2017
 *      Author: franco
 */

#include "MovilElemental.h"
#include <sstream>
#include <cstdio>
#include <ctime>
using namespace std;

int stringToNumber(string palabra);

int main() {

	time_t inicio, fin;
	MovilElemental *ptrAudi=new MovilElemental("A4");
	inicio = time(NULL);
	string direccionActual;
	string pasosActual;
	int terminar=1;

	while (terminar == 1){
		cout << "Ingrese una direccion [arriba,abajo,izquierda,derecha,adelante,atras]" << endl;
		cin >> direccionActual;
		ptrAudi->agregarASecuencia(direccionActual);
		cout << "Ingrese la cantidad de pasos a moverse" << endl;
		cin >> pasosActual;
		ptrAudi->agregarASecuencia(pasosActual);
		ptrAudi->distanciaTotal(stringToNumber(pasosActual));

		cout << "La secuencia de pasos es: " << endl;
		for(int i = 0; i < ptrAudi->tamanoSecuencia(); i++ ){
			cout << " " << ptrAudi->mostrarSecuencia(i);
		}
		cout << endl;
		cout << "La distancia total recorrida es: " << ptrAudi->mostrarDistanciaTotal() << endl;
		cout << endl <<"Desea continuar? SI=1 NO=0" << endl;
		cin >> terminar;
	}
	fin = time(NULL);
	cout << "Tiempo andando en segundos: " << difftime(fin, inicio) << endl;
	cout << "BYE!";
	delete ptrAudi;

	return 0;
}
int stringToNumber(string palabra){
	int result;
	stringstream convert(palabra);
	if ( !(convert >> result) )
		result = 0;
	return result;
}

/*
 * Dudas:
 * 		_ destructor de la clase trayectoria no se llama automaticamente
 * 		_ como hacer para que getSecuencia ande
 */
