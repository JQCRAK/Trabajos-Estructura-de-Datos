//Generar una lista con los valores de cada nivel de un AB ingresado por el usuario
#include <iostream>
#include "ArbolBinario.h"
#include "Lista.h"
using namespace std;
int main() {
    ArbolBinario arbol;
    cout << "Ingreso del Arbol Binario:" << endl;
    arbol.leer();
    Lista listaNiveles;
    void generarListaNiveles(ArbolBinario arbol, Lista &listaNiveles);
    generarListaNiveles(arbol, listaNiveles);
  bool imprimirNivel(NodoBinario *raiz, int nivel, Lista &listaNiveles);
    cout << "Lista de valores por niveles:" << endl;
    Nodo *actual = listaNiveles.getPrimero();
    while (actual != NULL) {
        cout << actual->getDato() ;
        actual = actual->getPunt();
    }

    return 0;
}
bool imprimirNivel(NodoBinario *raiz, int nivel, Lista &listaNiveles) {
    if (raiz == NULL) {
        return false;
    }

    if (nivel == 1) {
        listaNiveles.insertarAlFinal(raiz->getDato());
        return true;
    }

    bool izquierda = imprimirNivel(raiz->getIzq(), nivel - 1, listaNiveles);
    bool derecha = imprimirNivel(raiz->getDer(), nivel - 1, listaNiveles);

    return izquierda || derecha;
}
void generarListaNiveles(ArbolBinario arbol, Lista &listaNiveles) {
    if (arbol.esVacio()) {
        return;
    }

    NodoBinario *raiz = arbol.getRaiz();
    int nivel = 1;

    while (imprimirNivel(raiz, nivel, listaNiveles)) {
        nivel++;
    }
}


