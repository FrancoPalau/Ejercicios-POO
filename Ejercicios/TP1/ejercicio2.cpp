#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Prototipos
double degToRad(double valor);
double f1(double grados,double A,double F1);
double f2(double grados,double B,double C,double F2);
void obtenerConstantes(double vecConst[]);
void mostrarResultados(int angulo,double f1, double f2);
void encabezado();

int main() {
    double F1,F2;
    double vecConst[3];
    cout << fixed << setprecision(2);   //mostrar solo dos decimales
    obtenerConstantes(vecConst);
    encabezado();
    for (int i = 0; i <= 360; i=i+30) {  //iteramos de [0°-360°]
        F1=f1(i,vecConst[0],F1);
        F2=f2(i,vecConst[1],vecConst[2],F2);
        mostrarResultados(i,F1,F2);
    }
    return 0;
}//end main

//toma un valor en grados y lo pasa a radianes
double degToRad(double valor){
    const double PI=3.14159265;
    return valor*PI/180;
}
double f1(double grados,double A,double F1){
    return F1=A*sin(degToRad(grados));
}
double f2(double grados,double B,double C,double F2){
    return F2=C+B*cos(degToRad(grados));
}
void obtenerConstantes(double vecConst[]){
    cout << "Introduzca A" << endl;
    cin >> vecConst[0];
    cout << "Introduzca B" << endl;
    cin >> vecConst[1];
    cout << "Introduzca C" << endl;
    cin >> vecConst[2];
}
void mostrarResultados(int angulo,double f1, double f2){
    cout << setw(4) << angulo << setw(21) << f1 << setw(18) << f2 << endl;
}
void encabezado(){
    cout << endl;
    cout << "Angulo" << setw(18) << "F1" << setw(18) << "F2" << endl
         << "======" << setw(18) << "==" << setw(18) << "==" << endl;
}
