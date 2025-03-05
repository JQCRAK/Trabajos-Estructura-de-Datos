/*
Jhostin Quispe 7365
Angel Guaño 7337
*/

//Archivo de cabecera de lectura y escritura
#include <iostream>
#define MAX 10
using namespace std;

//Funcion principal
int main() {
    system ("color F4");
	cout<<"		Ejercicio de Autonomo"<<endl;
	int v[MAX];						// Dimensionar arreglo
	int n;
    // Prototipos de funciones
	int leerN(int li, int ls);                    // prototipo de funcion que permite saber cuantos valores se procesaran
	void leerVector(int a[], int n);              //prototipo de funcion que permite leeer el vector
	void vectorSumaCero(int a[], int n);          //prototipo de funcion que permite resolver el ejercicio
	
    n = leerN(1, MAX);                            // valor retornado por la funcion y saber la longitud del vector
	cout<< endl<< "Ingreso de valores al arreglo"<<endl;            
	leerVector(v, n);                                    //llama la funcion que permite leer el vector enviando la longitud del vector
    
    cout << endl << "Salida:" << endl;
    vectorSumaCero(v, n);                              // llama ala funcion que muestre sub-arreglos que contengan valores contiguos cuya suma sea cero. 

    return 0;
}

int leerN(int li, int ls){
	int n;
	do {
	    cout << endl << "Cantidad de valores a procesar [" << li << "..." << ls << "]: ";
	    cin >> n;
    } while (n < li || n > ls);
    
	return n;
}

void leerVector(int a[], int n1) {
	for (int i = 0; i < n1; i++) {
		cout <<endl<< "-> Ingrese un valor para la posicion [" << i + 1 << "]: ";
		cin >> a[i];
	}	
}

void vectorSumaCero(int *a, int n) {
    int cantidad = 0;

    for (int i = 0; i < n; i++) {
        int suma = 0;
        for (int j = i; j < n; j++) {
            suma += a[j];
            if (suma == 0) {
                cout << "[";
                for (int k = i; k <= j; k++) {
                    cout << a[k];
                    if (k < j) {
                        cout << ", ";
                    }
                }
                cout << "]" << endl;
                cantidad++;
            }
        }
    }

    if (cantidad == 0) {
        cout << "No existen sub-arreglos con suma cero" << endl;
    }
}
