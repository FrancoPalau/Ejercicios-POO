/*
 * Grafico.h
 *
 *  Created on: 22/09/2017
 *      Author: franco
 */

#include "Segmento.h"

#ifndef GRAFICO_H_
#define GRAFICO_H_

class Grafico {
	public:
		Grafico();
		virtual ~Grafico();
		void mensajeComienzo();
		void ingresarValoresPuntos();
		void seleccionDeCaracter(float,float,float,float);
		void inicializarGrafico();
		void dibujoDeLinea();
		void imprimirGrafico();

	private:
		Segmento *Recta;
		char **tabla;

};

#endif /* GRAFICO_H_ */
