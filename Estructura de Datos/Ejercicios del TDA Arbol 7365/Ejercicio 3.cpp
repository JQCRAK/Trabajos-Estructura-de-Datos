/* Jhostin Quispe 
Determinar el valor numéricamente menor más cercano a la hoja más alejada de la raíz de un AB ingresado
*/

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

void encontrar(NodoBinario* nodo, int& vlMC, int nvlA, int& nvlML, bool& encontrado); 
int main() {
    system("color f0");

    ArbolBinario arbol; 
    int vlMC = 0; 
    int nvlML = 0;
    bool encontrado = false;
    
    cout << "Ejercicio 3" << endl;
    cout << "Ingreso de valores para el arbol binario";
    arbol.leer(); 
    cout << endl << "Visualizacion del arbol binario" << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0); 

    encontrar(arbol.getRaiz(), vlMC, 0, nvlML, encontrado);

    if (!encontrado) {
        cout << endl << "No se encontraron hojas en el arbol";
    } else {
        cout << endl << "El nivel mas alejado de la raiz es: " << nvlML;
        cout << endl << "El valor menor mas cercano a la hoja: " << vlMC;
    }

    return 0;
}

void encontrar(NodoBinario* nodo, int& vlMC, int nvlA, int& nvlML, bool& encontrado) {
    if (nodo == NULL) {
        return;
    }
    if (nodo->getIzq() == NULL && nodo->getDer() == NULL) {
        if (nvlA > nvlML) {
            nvlML = nvlA;
            vlMC = nodo->getDato();
            encontrado = true; 
        }
        else if (nvlA == nvlML && nodo->getDato() < vlMC) {
            vlMC = nodo->getDato();
        }
        return;
    }

    encontrar(nodo->getIzq(), vlMC, nvlA + 1, nvlML, encontrado);
    encontrar(nodo->getDer(), vlMC, nvlA + 1, nvlML, encontrado);
}


