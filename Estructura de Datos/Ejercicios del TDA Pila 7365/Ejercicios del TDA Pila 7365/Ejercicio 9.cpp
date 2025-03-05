/*Autor Jhostin Quispe 7365
Ejercicio 9
Permitir el ingreso de una Pila de valores, y desplazar de sus valores N posiciones 
(considere valores positivos y negativos).
*/
#include <iostream>
#include "Pila.h"
#define MAX 99999

using namespace std;

int main() {
	system("color f0");
    Pila p;
    Pila pTemp;
    int nDesplazamiento;
    
    void leerPila(Pila &p);
    void imprimirPilaRecursiva(Pila& p);
    void desplazarPila(Pila& p, int nDesplazamiento);

    cout <<endl<< "Despalzar los valores";
    leerPila(p);

    
    cout <<endl<< "Ingrese el numero de posiciones a desplazar: ";
    cin >> nDesplazamiento;

    desplazarPila(p, nDesplazamiento);
}

void leerPila(Pila &p){     
Tipo vl;					
	cout <<endl<<"Ingrese un valor a apilar, finalice con ["<<MAX<<"]: ";
	cin >> vl; 	 					
	if(vl!=MAX){
		p.push(vl)	;				
		leerPila(p);					
	}
}

void imprimirPilaRecursiva(Pila& p) {
    if (p.pilaVacia()) {
        return;
    }

    int elemento = p.pop();
    cout <<endl<< elemento;
    imprimirPilaRecursiva(p);
    p.push(elemento);
}

void desplazarPila(Pila& p, int nDes) {
    if (nDes == 0) {
        cout <<endl<< "La pila despues de desplazar es: ";
        imprimirPilaRecursiva(p);
        cout << endl;
        return;
    }

    int elemento = p.pop();
    desplazarPila(p, nDes - 1);
    p.push(elemento);
}

