/*Autor Jhostin Quispe 7365
Ejercicio 5	
Implementar el ordenamiento por inserción en una pila
*/
#include <iostream>
#include "Pila.h"
#define FIN 999999

using namespace std;

void leerPila(Pila *a);
void imprimirPila(Pila b);
void ordenamientoInsercion(Pila &p);
void insertarEnOrden(Pila &p, Tipo elemento);

int main() {
    system("color f0");
    Pila a;

    cout << "Ordenar por Inserción" << endl;
    leerPila(&a);
    cout << endl<<"Pila desordenada: " << endl;
    imprimirPila(a);

    ordenamientoInsercion(a);

    cout << endl<<"Pila ordenada: " << endl;
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
        cout<<endl << " > " << vl;
        imprimirPila(b);
        b.push(vl);
    }
}

void ordenamientoInsercion(Pila &p) {
    if (!p.pilaVacia()) {
        Tipo temp = p.pop();
        ordenamientoInsercion(p);
        insertarEnOrden(p, temp);
    }
}

void insertarEnOrden(Pila &p, Tipo elemento) {
    if (p.pilaVacia() || p.cimaPila() <= elemento) {
        p.push(elemento);
    } else {
        Tipo temp = p.pop();
        insertarEnOrden(p, elemento);
        p.push(temp);
    }
}

