/*
 * MovilElemental.h
 *
 *  Created on: 21/09/2017
 *      Author: franco
 */

#include "Trayectoria.h"

#ifndef MOVILELEMENTAL_H_
#define MOVILELEMENTAL_H_

class MovilElemental {
	public:
		MovilElemental();
		virtual ~MovilElemental();
		MovilElemental(string);
		MovilElemental(string,int);
		string getIdentificacion();
		void setIdentificacion(string);
		int getCargaBateria();
		void agregarASecuencia(string);
		string mostrarSecuencia(int);
		int tamanoSecuencia();
		void distanciaTotal(int);
		int mostrarDistanciaTotal();
	private:
        string identificacion;
        Trayectoria *ptrTrayecto;
        int cargaBateria;
};

#endif /* MOVILELEMENTAL_H_ */

