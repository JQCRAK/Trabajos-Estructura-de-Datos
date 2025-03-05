/*Jhostin Quispe
Imprimir todos los caminos que van desde la raíz a cada una de las hojas de un AB ingresado
*/

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

void imprimirCaminos(ArbolBinario& arbol);
void imprimirCaminosRec(NodoBinario* nodo, int camino[], int lenCamino, int& numCamino);
int contarHojas(NodoBinario* nodo);
void imprimirCamino(int camino[], int lenCamino);

int main() {
    system("color f0");

    ArbolBinario arbol;
    
    cout << "Ejercicio 8" << endl;
    cout << "Ingreso de valores para el AB";
    arbol.leer();
    cout << endl << "Visualizacion del AB " << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    cout << endl << "Caminos desde la raiz a cada hoja:" << endl;
    imprimirCaminos(arbol);

    return 0;
}

void imprimirCaminos(ArbolBinario& arbol) {
    NodoBinario* raiz = arbol.getRaiz();
    int camino[100]; 
    int numCamino = 1;

    cout << "El arbol tiene ";
    int numHojas = contarHojas(raiz);
    if (numHojas == 1) {
        cout << "1 hoja y el camino es:" << endl;
    } else {
        cout << numHojas << " hojas y los caminos son:" << endl;
    }
    
    imprimirCaminosRec(raiz, camino, 0, numCamino);
}

void imprimirCaminosRec(NodoBinario* nodo, int camino[], int lenCamino, int& numCamino) {
    if (nodo == NULL) {
        return;
    }
    camino[lenCamino] = nodo->getDato();
    lenCamino++;
    if (nodo->getIzq() == NULL && nodo->getDer() == NULL) {
        cout << "Camino " << numCamino << ": ";
        imprimirCamino(camino, lenCamino);
        cout << endl;
        numCamino++;
    } else {
        imprimirCaminosRec(nodo->getIzq(), camino, lenCamino, numCamino);
        imprimirCaminosRec(nodo->getDer(), camino, lenCamino, numCamino);
    }
}

int contarHojas(NodoBinario* nodo) {
    if (nodo == NULL) {
        return 0;
    }
    if (nodo->getIzq() == NULL && nodo->getDer() == NULL) {
        return 1;
    }
    return contarHojas(nodo->getIzq()) + contarHojas(nodo->getDer());
}

void imprimirCamino(int camino[], int lenCamino) {
    if (lenCamino <= 0) {
        return;
    }
    cout << camino[0];
    if (lenCamino > 1) {
        cout << " - ";
    }
    imprimirCamino(camino + 1, lenCamino - 1);
}

