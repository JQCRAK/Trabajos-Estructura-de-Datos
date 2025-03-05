/*Jhostin Quispe 7365
Calcular el ABB resultante de la unión de 2 ABB originales, previamente ingresados
*/

using namespace std;
#include <iostream>
#include "ArbolBinario.h"
#define FIN 99999  

void leer(ArbolBinario* arbol);
void insertarOrden(NodoBinario* nodo, ArbolBinario* arbol);
void unir(ArbolBinario* arbol1, ArbolBinario* arbol2, ArbolBinario* arbolUnion);

int main() {
    system("color f0");

    ArbolBinario arbol1;
    ArbolBinario arbol2;
    ArbolBinario arbolUnion;
    
    cout << "Ejercicio 7" << endl;
    cout << "Ingresar el primer ABB" << endl;
    leer(&arbol1);

    cout << "Ingresar el segundo ABB" << endl;
    leer(&arbol2);

    unir(&arbol1, &arbol2, &arbolUnion);

    cout << "Arbol 1:" << endl;
    arbol1.imprimirABJerarquia(arbol1.getRaiz(), 0);
    cout << "Arbol 2:" << endl;
    arbol2.imprimirABJerarquia(arbol2.getRaiz(), 0);
    cout << "Arbol Union:" << endl;
    arbolUnion.imprimirABJerarquia(arbolUnion.getRaiz(), 0);

    return 0;
}

void leer(ArbolBinario* arbol) {
    Tipo val;
    cout << "Ingrese un valor a insertar al ABB" << endl; 
    cout << "Finalice con [" << FIN << "]: ";
    cin >> val;

    if (val != FIN) {
        arbol->insertarNodo(val);
        leer(arbol);
    }
}

void insertarOrden(NodoBinario* nodo, ArbolBinario* arbol) {
    if (nodo != NULL) {
        insertarOrden(nodo->getIzq(), arbol);
        arbol->insertarNodo(nodo->getDato());
        insertarOrden(nodo->getDer(), arbol);
    }
}

void unir(ArbolBinario* arbol1, ArbolBinario* arbol2, ArbolBinario* arbolUnion) {
    insertarOrden(arbol1->getRaiz(), arbolUnion);
    insertarOrden(arbol2->getRaiz(), arbolUnion);
}

