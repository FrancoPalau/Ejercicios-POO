/*
 * Punto.h
 *
 *  Created on: 22/09/2017
 *      Author: franco
 */


#ifndef PUNTO_H_
#define PUNTO_H_

#include <iostream>
using namespace std;

class Punto {
	public:
		Punto();
		Punto(float,float);
		virtual ~Punto();
		float getCoordenadaX();
		void setCoordenadaX(float);
		float getCoordenadaY();
		void setCoordenadaY(float);
	private:
		float coordenadaX;
		float coordenadaY;
};

#endif /* PUNTO_H_ */
