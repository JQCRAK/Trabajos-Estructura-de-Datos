#include <iostream>
#include "Cola.h"
#define FIN 999999
using namespace std;

void leerCola(Cola *c);
void imprimirCola(Cola c);
void ordenarCola(Cola *c);
void insertarOrdenado(Cola *c, Tipo valor);
Cola ordenarColaAux(Cola *c);

int main() {
    system("color f0");
    Cola a;
    cout << endl << "Ejercicio 1";
    leerCola(&a);
    cout << endl << "Contenidos del TDA Cola antes de ordenar:";
    imprimirCola(a);
    ordenarCola(&a);
    cout << endl << "Contenidos del TDA Cola después de ordenar:";
    imprimirCola(a);
    return 0;
}

void leerCola(Cola *c) {
    Tipo vl;
    cout << endl << "Ingrese un valor a agregar en el TDA Cola." << endl;
    cout << "Finalice con [" << FIN << "]: ";
    cin >> vl;
    if (vl != FIN) {
        c->insertar(vl);
        leerCola(c);
    }
}

void imprimirCola(Cola c) {
    if (!c.colaVacia()) {
        Tipo valor = c.quitar();
        cout << endl << "> " << valor;
        imprimirCola(c);
        c.insertar(valor);  // Reinserta el elemento para no modificar la cola original
    }
}

void ordenarCola(Cola *c) {
    *c = ordenarColaAux(c);
}

Cola ordenarColaAux(Cola *c) {
    if (c->colaVacia()) {
        return Cola();
    }
    
    Tipo valor = c->quitar();
    Cola colaOrdenada = ordenarColaAux(c);
    insertarOrdenado(&colaOrdenada, valor);
    return colaOrdenada;
}

void insertarOrdenado(Cola *c, Tipo valor) {
    if (c->colaVacia() || valor <= c->quitar()) {
        c->insertar(valor);
        return;
    }
    
    Tipo temp = c->quitar();
    insertarOrdenado(c, valor);
    c->insertar(temp);
}
