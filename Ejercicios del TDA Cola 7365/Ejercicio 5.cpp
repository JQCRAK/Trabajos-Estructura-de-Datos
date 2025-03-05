/*Jhostin Quispe 7365
Encontrar la unión entre varias TDA colas ingresadas
*/

#include <iostream>
#include "Cola.h"
#define FIN 999999

using namespace std;

void leerColas(Cola colas[], int i, int numColas);
void leerCola(Cola *c);
void imprimirColaRecursivo(Cola c);
void encontrarUnionRecursivo(const Cola colas[], int numColas, Cola &union_colas, int index);
void insertarCola(Cola &destino, Cola &origen);

int main() {
    system("color f0");
    int n;
    cout << "Ingrese cuantas colas va ingresar: ";
    cin >> n;

    Cola *colas = new Cola[n];

    leerColas(colas, 0, n); 

    Cola union_colas; 
    encontrarUnionRecursivo(colas, n, union_colas, 0); 

    cout << endl << "Union de colas:" << endl;
    imprimirColaRecursivo(union_colas);

    return 0;
}

void leerColas(Cola colas[], int i, int numColas) {
    if (i < numColas) {
        cout << endl << "Ingrese valores para la cola " << i + 1 << ":";
        leerCola(&colas[i]);
        leerColas(colas, i + 1, numColas);
    }
}

void leerCola(Cola *c) {
    Tipo vl;
    cout << endl << "Ingrese un valor a incluir en el TDA Cola." << endl;
    cout << "Finalice con [" << FIN << "]: ";
    cin >> vl;
    if (vl != FIN) {
        c->insertar(vl);
        leerCola(c); 
    }
}

void imprimirColaRecursivo(Cola c) {
    if (!c.colaVacia()) {
        cout << endl << "> " << c.frenteCola();
        c.quitar(); 
        imprimirColaRecursivo(c); 
    }
}

void encontrarUnionRecursivo(const Cola colas[], int numColas, Cola &union_colas, int i) {
    if (i < numColas) {
        Cola copia = colas[i]; 
        insertarCola(union_colas, copia); 
        encontrarUnionRecursivo(colas, numColas, union_colas, i + 1); 
    }
}


void insertarCola(Cola &destino, Cola &origen) {
    if (!origen.colaVacia()) {
        destino.insertar(origen.quitar()); 
        insertarCola(destino, origen); 
    }
}

