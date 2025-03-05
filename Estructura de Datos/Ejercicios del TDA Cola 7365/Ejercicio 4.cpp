/*Jhostin Quispe 7365
Ingresar ordenadamente los valores en una cola
*/

#include <iostream>
#include "Cola.h"
#define FIN 999999

using namespace std;

// Prototipos de funciones
void insertarOrdenadoRecursivo(Cola *c, Tipo valor, int orden);
void imprimirColaRecursivo(Cola c);

int main() {
    system("color f0");
    Cola cola; 
	cout << endl << "Ejercicio 4";
    insertarOrdenadoRecursivo(&cola, INT_MIN, 0); 

    cout <<endl<< "Contenido de la Cola"<<endl;
    imprimirColaRecursivo(cola);

    return 0;
}


void insertarOrdenadoRecursivo(Cola *c, Tipo valor, int orden) {
    Tipo valorAnterior = valor; 
    cout <<endl<< "Ingrese valores en orden. Finalice con [" << FIN << "]: ";
    cin >> valor;
    if (valor != FIN) {
        if (valor >= valorAnterior) {
            insertarOrdenadoRecursivo(c, valor, orden + 1);
            c->insertar(valor); 
        } else {
            cout << endl<<"Error!!!!:"<<endl;
			cout<<" El valor ingresado no esta en orden al anterior.";
            insertarOrdenadoRecursivo(c, valorAnterior, orden);
        }
    }
}

void imprimirColaRecursivo(Cola c) {
    if (!c.colaVacia()) {
        Tipo valor = c.quitar();
        cout <<endl<<" >" <<valor ;
        imprimirColaRecursivo(c);
        c.insertar(valor); 
    }
}


