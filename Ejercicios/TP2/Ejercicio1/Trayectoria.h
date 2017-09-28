/*
 * Trayectoria.h
 *
 *  Created on: 21/09/2017
 *      Author: franco
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;


#ifndef TRAYECTORIA_H_
#define TRAYECTORIA_H_

class Trayectoria {
	public:
		Trayectoria();
		virtual ~Trayectoria();
		Trayectoria(int);
		void setDistanciaTotal(int);
		int getDistaciaTotal();
		vector<string> getSecuencia();
		vector<string> secuencia;
	private:
        int distanciaTotal;


};

#endif /* TRAYECTORIA_H_ */
