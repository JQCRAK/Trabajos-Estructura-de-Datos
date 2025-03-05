/* Jhostin Quispe
Generar una lista con los nodos externos de un árbol previamente ingresado
*/

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

void encontrarHojas(NodoBinario* nodo);  

int main() {
    system("color f0");
    ArbolBinario arbol;
    
    cout << "Ejercicio 1"<<endl;
    cout << "Ingreso de valores para el arbol binario";
    arbol.leer();
    cout << endl << "Visualizacion del arbol binario" << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    cout << endl << "Hojas del arbol binario: ";
    encontrarHojas(arbol.getRaiz());
    cout << endl;

    return 0;
}

void encontrarHojas(NodoBinario* nodo) {
    if (nodo == NULL) {
        return;
    }
    if (nodo->getIzq() == NULL && nodo->getDer() == NULL) {
        cout << nodo->getDato() << " ";
    }
    encontrarHojas(nodo->getIzq());
    encontrarHojas(nodo->getDer());
}

