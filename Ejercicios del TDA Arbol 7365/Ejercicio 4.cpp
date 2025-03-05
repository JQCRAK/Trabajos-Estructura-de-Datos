/* Jhostin Quispe 
Imprimir el subárbol que tiene como nodo raíz el valor menor de un AB ingresado
*/

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

void encontrarMin(NodoBinario* nodo, NodoBinario*& minimo);
void imprimirE(int nivel);
void imprimirSubA(NodoBinario* nodo, int nivel);

int main() {
    system("color f0");

    ArbolBinario arbol;
    cout << "Ejercicio 3" << endl;
    cout << endl << "Ingreso de valores para el AB";
    arbol.leer();
    cout << endl << "Visualizacion del AB " << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    NodoBinario* minimo = NULL;
    encontrarMin(arbol.getRaiz(), minimo);

    if (minimo != NULL) {
        cout << endl << "El subarbol con raiz en el valor minimo [" << minimo->getDato() << "] es:" << endl;
        imprimirSubA(minimo, 0);
    } else {
        cout << endl << "No hay arbol";
    }

    return 0;
}

void encontrarMin(NodoBinario* nodo, NodoBinario*& minimo) {
    if (nodo == NULL) {
        return;
    }

    if (minimo == NULL || nodo->getDato() < minimo->getDato()) {
        minimo = nodo;
    }

    encontrarMin(nodo->getIzq(), minimo);
    encontrarMin(nodo->getDer(), minimo);
}

void imprimirE(int nivel) {
    if (nivel <= 0) {
        return;
    }
    cout << "   ";
    imprimirE(nivel - 1);
}

void imprimirSubA(NodoBinario* nodo, int nivel) {
    if (nodo == NULL) {
        return;
    }

    imprimirE(nivel);
    cout << nodo->getDato() << endl;

    imprimirSubA(nodo->getIzq(), nivel + 1);
    imprimirSubA(nodo->getDer(), nivel + 1);
}

