/*Autor Jhostin Quispe 7365
Ejercicio 3
Intercambiar, por parejas, los elementos de una pila previamente ingresada 
(primero con segundo, tercero con cuarto, etc).
*/
#include <iostream>
#include "Pila.h"
#define FIN 999999

using namespace std;

int main() {
    system("color f0");
    Pila a;
    
    void leerPila(Pila *a);
	void imprimirPila(Pila b);
	void intercambiarParejas(Pila &p, int indice = 0);
	 
    cout << "Intercambiar elementos: ";
    leerPila(&a);
    cout << "Datos Ingresados: ";
    imprimirPila(a);

    intercambiarParejas(a);
    cout << "\nPila con elementos intercambiados por parejas: " << endl;
    imprimirPila(a);

    return 0;
}

void leerPila(Pila *a) {
    Tipo vl;
    cout << endl << "Ingrese un valor a apilar, finalice con [" << FIN << "]: ";
    cin >> vl;
    if (vl != FIN) {
        a->push(vl);
        leerPila(a);
    }
}

void imprimirPila(Pila b) {
    Tipo vl;
    if (!b.pilaVacia()) {
        vl = b.pop();
        cout << endl << " > " << vl;
        imprimirPila(b);
    }
}

void intercambiarParejas(Pila &p, int indice) {
	Tipo elem1,elem2;
    // Si la pila tiene menos de 2 elementos o el indice está fuera de rango no se pueden intercambiar parejas
    if (p.tamanioPila() < 2 || indice >= p.tamanioPila() - 1) {
        return;
    }

    // Tomar los elementos en el indice actual e indice + 1
    elem1 = p.getVec(indice);
    elem2 = p.getVec(indice + 1);

    // Intercambiar los elementos
    p.setVec(elem2, indice);
    p.setVec(elem1, indice + 1);
    intercambiarParejas(p, indice + 2);
}

