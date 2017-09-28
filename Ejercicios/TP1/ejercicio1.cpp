#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Prototipos de funciones
int generarRandom(int max, int min, int aleatorio);
int cantPares(int variable, int pares);
int cantImpares(int variable, int impares);
int cantMenoresA(int variable, int cantMenores);

int main(void) {
    int count=1000;     //cantidad de numeros aleatorios
    int numeroRandom=0;

    int pares=0;       //Cantidad de pares,
    int impares=0;     //impares
    int cantMenores=0; // y menores a un valor

    srand(time(NULL));

    for (int i = 0; i < count ; i++){
        numeroRandom=generarRandom(9300,6300,numeroRandom);   //llamada a funciones
        pares=cantPares(numeroRandom,pares);                  //que modifican los
        impares=cantImpares(numeroRandom,impares);            //distintos contadores
        cantMenores=cantMenoresA(numeroRandom,cantMenores);
        //std::cout << numeroRandom << std::endl;
    }//end for

    //Mostrar mensajes y varibles por pantalla
    cout << "cantidad de numeros menores" << endl;
        cout << cantMenores << endl;
    cout << "pares" << endl;
        cout << pares << endl;
    cout << "impares" << endl;
        cout << impares << endl;

    return 0;
}//end main

//genera numero aleatorio contenido en [min,max]
int generarRandom(int max, int min, int aleatorio){
    aleatorio= min + rand()%((max+1)-min);
    return aleatorio;
}
//recibe una variable, analiza si es par e incrementa un contador de pares
int cantPares(int variable, int pares){
    if(variable%2 == 0){
        pares++;
    }
    return pares;
}
//incrementa un contador en funcion si variable es impar
int cantImpares(int variable, int impares){
    if(variable%2 != 0){
        impares++;
    }
    return impares;
}
//analiza si variable es menor a 7000 e incrementa un contador
int cantMenoresA(int variable, int cantMenores){
    if(variable < 7000){
        cantMenores++;
    }
    return cantMenores;
}
