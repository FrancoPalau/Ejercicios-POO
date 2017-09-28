#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

//Prototipos
void leerDimensionesSector(int *filas, int *columnas);
void leerValores(int **matriz,char abecedario[]);
void analizarFotograma(int **matriz,char **matrizEstrellas,int filas,int columnas);
void mostrarTabla(int **matriz,char **matrizEstrellas,int filas,int columnas,char abecedario[]);
void inicializaMatriz(int **matriz,int filas,int columnas);
void inicializaMatrizEstrellas(char **matrizEstrellas,int filas, int columnas);
int agregarValores(char letra,int fila,int valor,int **matriz,int continuar,char abecedario[]);
void escrituraArchivo(int **matriz,int filas,int columnas);
void liberarMemoria(int **matriz,char **matrizEstrellas,int filas);

int main() {
    char abecedario[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";  //abecedario que se utilizara para
    int filas;                                        //saber que letra corresponde a cada columna
    int columnas;
    leerDimensionesSector(&filas,&columnas);
    //creacion dinamica de la matriz con valores del fotograma
    int **matriz;
    matriz=new int* [filas];
    for (int i = 0; i <filas; i++) {
        matriz[i]=new int [columnas];
    }
    //creacion dinamica de la matriz con estrellas
    char **matrizEstrellas;
    matrizEstrellas=new char* [filas];
    for (int i = 0; i <filas; i++) {
        matrizEstrellas[i]=new char [columnas];
    }
    inicializaMatriz(matriz,filas,columnas);
    inicializaMatrizEstrellas(matrizEstrellas,filas,columnas);
    leerValores(matriz,abecedario);
    analizarFotograma(matriz,matrizEstrellas,filas,columnas);
    mostrarTabla(matriz,matrizEstrellas,filas,columnas,abecedario);
    escrituraArchivo(matriz,filas,columnas);
    liberarMemoria(matriz,matrizEstrellas,filas);
    return 0;
}//end main()

void leerDimensionesSector(int *filas, int *columnas){
    /*Esta funcion lee el tamaño del sector que se analiza
      IMPORTANTE: las variables son pasadas por referencia*/
    cout << "Ingrese las filas del sector" << endl;
    cin >> *filas;
    cout << "Ingrese las columnas del sector" << endl;
    cin >> *columnas;
}//end leerDimensionesSector()
void leerValores(int **matriz, char abecedario[]){
    /*Esta funcion lee una letra correspondiente a una columna,
      un numero correspondiente a una fila, y un valor correspondiente
      a lo registrado por el fotometro,y pasa estos valores a otra funcion
      que los guarda en la matriz de entrada*/
    char letra;
    int fila;
    int valor;
    int continuar=1;
    while(continuar){                     //Va a terminar solo cuando el operador de un 0
        cout << "INGRESAR DATOS" << endl
             << "Ingrese letra correspondiente a la columna en el rango de [A-Z]" << endl;
        cin >> letra;
        cout << "Ingrese numero correspondiente a la fila en el rango de [1-9]" << endl;
        cin >> fila;
        cout << "Ingrese valor del fotometro en el rango de [0-20]" << endl;
        cin >> valor;
        continuar=agregarValores(letra,fila,valor,matriz,continuar,abecedario);
    }
}//end leerValores()
int agregarValores(char letra,int fila,int valor,int **matriz,int continuar,char abecedario[]){
    /*Esta funcion recibe una letra correspondiente a una columna,
      un numero correspondiente a una fila, y un valor correspondiente
      a lo registrado por el fotometro, y asiga este valor a la matriz
      de entrada, segun la columna y fila.
      Retorna un 1 si se quiere seguir cargando datos,
      caso contrario retorna un 0 */
    bool noEncontrado=true;
    int i=0;
    int columna;
    while(noEncontrado){              //Este while convierte el valor de columna dado con letra
        if(abecedario[i]==letra){     //en un numero correspondiente al indice que dicha letra
            columna=i;                //tiene en el abecedario(sin Ñ)
            noEncontrado=false;
        }
        i++;
    }
    matriz[fila-1][columna]=valor;
    cout << "continuar? (SI=1 NO=0) " << endl;
    cin >> continuar;
    return continuar;
}//end agregarValores()
void analizarFotograma(int **matriz,char **matrizEstrellas,int filas,int columnas){
    /*Esta funcion recibe una matriz con los datos del fotograma
      y marca un '*' en la matrizEstrellas en el cuadrate donde
      encuentre una estrella.Supone que hay una estrella en el sector (i, j) si:
      _el punto no se encuentra en las orillas de la fotografía
         (primera o última fila o columna)
      _(A[i, j] + A[i -1, j] + A[i +1, j] + A[i, j -1] + A[i, j +1]) > 30
         (siendo A mi matriz de entrada con los valores del fotograma)*/
    int calculo=0;
    for (int i = 1; i < filas-1; i++) {
        for (int j = 1; j < columnas-1; j++) {
            calculo=matriz[i][j]+matriz[i -1][j] + matriz[i +1][j] + matriz[i][j -1] + matriz[i][j +1];
            if(calculo > 30){
                matrizEstrellas[i][j]='*';
            }
        }
    }
}//end analizarFotograma()
void mostrarTabla(int **matriz,char **matrizEstrellas,int filas,int columnas,char abecedario[]){
    /*Esta funcion muestra dos matrices en forma tabular
      la primera contiene los valores cargados por el usuario
      la segunda muestra en que cuadrantes se ha encontrado una estrella*/
    cout << "Tabla A: valores fotograma " << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << setw(4) <<matriz[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << "Tabla B: estrellas encontradas " << endl;
    cout << " ";
    for (int i = 0; i < columnas; i++) {              //Imprime la letra de cada columna
        cout << setw(4) <<abecedario[i];
    }
    cout << endl;
    cout << 1;                                       //imprimo el indice "1" afuera del for
    for (int i = 0; i < filas; i++) {                //y seguidamente los valores de de la fila 1
        for (int j = 0; j < columnas; j++) {         //y asi sucesivamente
            cout << setw(4) << matrizEstrellas[i][j];
        }
        if(i<(filas-1)){            //el (-1) se pone para que en la ultima fila imprima solo endl
            cout << endl << i+2;   //el i+2 es porque el 1 se imprimio arriba del for, y a su vez
        }else                      //el rango es [1-9], no de [0-8]
            cout << endl;
    }
}//end mostrarTabla()
void inicializaMatriz(int **matriz,int filas,int columnas){
    /*Esta funcion recibe una matriz
      e incializa todas sus componentes en 0*/
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j]=0;
        }
    }

}//end inicializaMatriz()
void inicializaMatrizEstrellas(char **matrizEstrellas,int filas, int columnas){
    /*Esta funcion recibe una matriz de caracteres y
      la inicializa llena de caracters espacio*/
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizEstrellas[i][j]=' ';
        }
    }
}//end inicializaMatrizEstrellas()
void escrituraArchivo(int **matriz,int filas,int columnas){
    /*Esta funcion escribe los valores de la matriz de entrada
      en un archivo*/
    //el constructor de ofstream abre el archivo
    ofstream archivoDatosFotograma( "datos.dat", ios::app );
    //ios::app para adjuntar datos al final de un archivo
    //(sin modificar los datos que ya estén en el archivo)

    // sale del programa si no puede crear el archivo
    if ( !archivoDatosFotograma ){ // operador ! sobrecargado
        cerr << "No se pudo abrir el archivo" << endl;
        exit( 1 );
    }
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            archivoDatosFotograma << setw(4) << matriz[i][j];
        }
        archivoDatosFotograma << endl;
    }
    archivoDatosFotograma << endl;

}
void liberarMemoria(int **matriz,char **matrizEstrellas,int filas){
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
        delete[] matrizEstrellas[i];
    }
    delete[] matriz;
    delete[] matrizEstrellas;
}
