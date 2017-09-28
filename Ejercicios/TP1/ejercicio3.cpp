#include <iostream>
#include <iomanip>
using namespace std;

//Prototipos
int obtenerN();
void crearMatrizOriginal(int N, int **matrizOriginal);
void hallarMatrizResultado(int N, int **matrizOriginal, int **matrizNueva);
void mostrarTabla(int N,int **matriz,int **matrizNueva);
void liberarMemoria(int N,int **matrizOriginal,int **matrizNueva);

int main() {
    int N=obtenerN();
    //creacion dinamica de la matriz original
    int **matriz;
    matriz=new int* [N];
    for (int i = 0; i <N; i++) {
        matriz[i]=new int [N];
    }
    //Creacion dinamica de la matriz resultado
    int **matrizNueva;
    matrizNueva=new int *[N];
    for (int i = 0; i <N; i++) {
        matrizNueva[i]=new int [N];
    }

    crearMatrizOriginal(N,matriz);
    hallarMatrizResultado(N,matriz,matrizNueva);
    mostrarTabla(N,matriz,matrizNueva);
    liberarMemoria(N,matriz,matrizNueva);
    return 0;
}//end main

int obtenerN(){
    /*Esta funcion pide un valor por pantalla y lo retorna*/
    int N;
    cout << "Ingrese N" << endl;
    cin >> N;
    return N;
}
void crearMatrizOriginal(int N, int **matrizOriginal){
    /*Esta funcion pide los valores de la matriz por pantalla*/
    cout << "Ingrese las componentes de la matriz NxN" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrizOriginal[i][j];
        }
    }
}
void hallarMatrizResultado(int N, int **matrizOriginal, int **matrizNueva){
    /*Esta funcion toma dos matrices como entradas, y calcula para cada celda del triángulo inferior
    de la matrizOrigina la diferencia entre la sumatoria de los valores de la
    columna y la sumatoria de los valores de la fila a la cual pertenece.
    La matrizNueva tendrá 1 (unos) en la diagonal y 0 (ceros) en el triángulo superior.*/
    int *vecFila=new int[N];
    int *vecCol=new int[N];
    int sumaFila=0;
    int sumaCol=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sumaFila=sumaFila + matrizOriginal[i][j];
            sumaCol=sumaCol + matrizOriginal[j][i];
        }
        vecFila[i]=sumaFila;
        vecCol[i]=sumaCol;
        sumaFila=0;
        sumaCol=0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i>j){
                matrizNueva[i][j]=vecCol[j]-vecFila[i];
            }else if(i == j){
                matrizNueva[i][j]=1;
            }else{
                matrizNueva[i][j]=0;
            }
        }
    }
    delete[] vecFila;
    delete[] vecCol;
}
void mostrarTabla(int N,int **matrizOriginal,int **matrizNueva){
    /*Esta matriz muestra las dos matrices en forma tabular*/
    cout << "matriz Original" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) <<matrizOriginal[i][j];
        }
        cout << endl;
    }
    cout << "matriz Nueva" << endl;
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << matrizNueva[i][j];
        }
        cout << endl;
    }
}
void liberarMemoria(int N,int **matrizOriginal,int **matrizNueva){
    /*Esta funcion libera la memoria de las dos matrices utilizadas*/
    for (int i = 0; i < N; i++) {
        delete[] matrizOriginal[i];
        delete[] matrizNueva[i];
    }
    delete[] matrizOriginal;
    delete[] matrizNueva;
}
