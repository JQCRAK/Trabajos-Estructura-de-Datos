/* Jhostin Quispe
Determinar el valor mayor de cada nivel de un AB
*/

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

void encontrarMaximosPorNi(NodoBinario* nodo, int nivel, int& maximoNivelActual); 

int main() {
    system("color f0");
    ArbolBinario arbol;
    int maximoNivel;  

    cout << "Ejercicio 2" << endl;
    cout << "Ingreso de valores para el arbol binario";
    arbol.leer();
    cout << endl << "Visualizacion del arbol binario" << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);
    cout << endl << "Valores maximos por nivel:" << endl;
    maximoNivel = INT_MIN;
    encontrarMaximosPorNivel(arbol.getRaiz(), 1, maximoNivel);

    return 0;
}

void encontrarMaximosPorN(NodoBinario* nodo, int nivel, int& maximoNivelActual) {
    if (nodo == NULL) {
        return;
    }

    if (nivel > maximoNivelActual) {
        maximoNivelActual = nodo->getDato();
        cout << "Nivel " << nivel << ": " << maximoNivelActual << endl;
    } else {
    	
        if (nodo->getDato() > maximoNivelActual) {
            maximoNivelActual = nodo->getDato();
            cout << "Nivel " << nivel << ": " << maximoNivelActual << endl;
        }
    }

    encontrarMaximosPorN(nodo->getIzq(), nivel + 1, maximoNivelActual);
    encontrarMaximosPorN(nodo->getDer(), nivel + 1, maximoNivelActual);
}

