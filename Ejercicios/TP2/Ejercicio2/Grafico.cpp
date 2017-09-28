/*
 * Grafico.cpp
 *
 *  Created on: 22/09/2017
 *      Author: franco
 */

#include "Grafico.h"

Grafico::Grafico()
{
	// TODO Auto-generated constructor stub
	mensajeComienzo();
	inicializarGrafico();

}

Grafico::~Grafico() {
	// TODO Auto-generated destructor stub
	cout << "Grafico borrado" ;
	delete Recta;
}

void Grafico::ingresarValoresPuntos() {
	float iniX,iniY,finX,finY;
	cout << "Ingrese la coordena X del punto inicial" << endl;
	cin  >> iniX;
	cout << "Ingrese la corrdena Y del punto inicial" << endl;
	cin >> iniY;
	cout << "Ingrese la coordena X del punto final" << endl;
	cin >> finX;
	cout << "Ingrese la corrdena Y del punto final" << endl;
	cin >> finY;
	seleccionDeCaracter(iniX,iniY,finX,finY);
}

void Grafico::seleccionDeCaracter(float iniX,float iniY,float finX,float finY) {
	char simbolo;
	cout << "Ingrese el caracter para graficar, sino de Enter" << endl;
	cin.ignore();
	simbolo=cin.get();
	if(simbolo != '\n'){
		Recta=new Segmento(simbolo,iniX,iniY,finX,finY);
		cout << "sin enter";
	}else{
		Recta=new Segmento(iniX,iniY,finX,finY);
		cout << "con enter";
	}
}

void Grafico::dibujoDeLinea() {
	int actualx,actualy;
	if(Recta->getPendiente() > 1){
		actualx=(int)Recta->getPuntoInicialX();
		actualy=(int)Recta->getPuntoInicialY();
		int cont=0;
		while (actualx != Recta->getPuntoFinalX() && actualy != Recta->getPuntoFinalY()){
			while (cont < Recta->getPendiente()){
				actualy=actualy +1;
				tabla[actualy][actualx]=Recta->getSimbolo();
				cont++;
			}
			//actualy=actualy + 1;
			actualx=actualx + 1;
			tabla[actualy][actualx]=Recta->getSimbolo();
			cont=0;
		}
	}else{
		Recta->setPendiente(true);
		actualx=Recta->getPuntoInicialX();
		actualy=Recta->getPuntoInicialY();
		int cont=0;
		while (actualx != Recta->getPuntoFinalX() && actualy != Recta->getPuntoFinalY()){
			while (cont < Recta->getPendiente()){
				actualx=actualx +1;
				tabla[actualy][actualx]=Recta->getSimbolo();
				cont++;
			}
			actualy=actualy + 1;
			//actualx=actualx + 1;
			tabla[actualy][actualx]=Recta->getSimbolo();
			cont=0;
		}
	}
}
void Grafico::imprimirGrafico() {
	cout << endl << "GRAFICO " << endl;
	for (int i = 21; i >= 0; i--) {
		for (int j = 0; j < 74; j++) {
			cout << tabla[i][j];
		}
		cout << endl;
	}
}

void Grafico::mensajeComienzo() {
	cout << "Inicializando Programa..." << endl;
	ingresarValoresPuntos();
}

void Grafico::inicializarGrafico() {
	tabla=new char* [22];
	for (int i = 0; i <22; i++) {
		tabla[i]=new char [74];
	}
	for (int i = 0; i < 22; i++ ){
		for (int j = 0; j < 74; j++){
			tabla[i][j]=' ';
		}
	}
	tabla[(int)Recta->getPuntoInicialY()][(int)Recta->getPuntoInicialX()]=Recta->getSimbolo();
	tabla[(int)Recta->getPuntoFinalY()][(int)Recta->getPuntoFinalX()]=Recta->getSimbolo();
}
