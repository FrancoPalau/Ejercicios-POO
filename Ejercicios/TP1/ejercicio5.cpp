#include <iostream>
using namespace std;
//Prototipos
void recibeMes(char mes[]);
void convierteMinus(char mes[], char mayus[], char minus[]);
bool analizaMes(char mes[],string meses[],int numeroMes[],int cantDiasMes[],bool flag);
void mensajeAlerta(bool flag);

int main() {
    //declaracion de variable
    bool flag=false;     //booleano que determina si se reconocio el mes (true) o no(false)
    char mes[20];         //array donde se almacena el mes ingresado
    char mayus[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";   //abecedario en mayuscula
    char minus[]="abcdefghijklmnopqrstuvwxyz";   //y en minuscula
    string meses[12]={"enero","febrero","marzo","abril","mayo","junio","julio",
                      "agosto","septiembre","octubre","noviembre","diciembre"};   //array con los nombres
                                                                                  //de los meses
    int numeroMes[12]={1,2,3,4,5,6,7,8,9,10,11,12};       //array con el numero de cada mes
    int cantDiasMes[12]={31,28,31,30,31,30,31,31,30,31,30,31};  //array con la cantida de dias de cada mes

    while(!flag){            //el programa va a seguir corriendo hasta que se reconzca el mes-->(flag=true)
        recibeMes(mes);
        convierteMinus(mes,mayus,minus);
        flag=analizaMes(mes,meses,numeroMes,cantDiasMes,flag);
        mensajeAlerta(flag);
    }
    return 0;
}

void recibeMes(char mes[]){
    /*esta funcion recibe un array de chars y le
      pide al usuario que ingrese un mes, luego
      guarda esa entrada en el array*/
    cout << "Ingrese el nombre del mes" << endl;
    cin >> mes;
}
void convierteMinus(char mes[], char mayus[], char minus[]){
    /*Esta funcion recibe una array de chars "mes"
      para convertir todas sus componentes a minusculas,
      esto lo hace comparando cada componente con dos arrays,
      "mayus" y "minus", que tienen el abecedario en mayuscula
      y minuscula respectivamente */
    int i=0;
    int j=0;
    while(mes[j] != '\0'){
        if((mes[j]==mayus[i]) || (mes[j]==minus[i])){
            mes[j]=minus[i];
            j++;
            i=-1;
        }
        i++;
    }
}
bool analizaMes(char mes[],string meses[],int numeroMes[],int cantDiasMes[],bool flag){
    /*Esta funcion compara el array "mes" con las
      componentes del array meses, si coincide devuelve
      un true, sino un false*/
    int i=0;
    while(flag==false && i<12){
        if(meses[i]==mes){
            cout << numeroMes[i] << endl;
            cout << cantDiasMes[i] << endl;
            flag=true;
        }
        i++;
    }
    return flag;
}
void mensajeAlerta(bool flag){
    /*Esta funcion imprime un mensaje de Error
    solo si no se reconocio el mes*/
    if(!flag){
        cout << "Error, nombre no reconocido" << endl;
    }
}
