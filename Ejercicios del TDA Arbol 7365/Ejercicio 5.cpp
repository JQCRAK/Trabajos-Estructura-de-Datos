/* Jhostin Quispe
Calcular el rango (diferencia entre el valor mayor y el menor) de un ABB ingresado
*/

using namespace std;
#include <iostream>
#include "ArbolBinario.h"
#define FIN 99999

void leer(ArbolBinario* abb);
Tipo min(NodoBinario* nodo);
Tipo max(NodoBinario* nodo);
    
int main() {
    system("color f0");
    ArbolBinario arbol;
    Tipo vlMin,vlMax,rango;
    
    cout << "Ejercicio 5" << endl;
    cout << "Ingresar valores del ABB" << endl;
    leer(&arbol);	
    cout << endl << "Visualizacion del ABB " << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    if (arbol.getRaiz() != NULL) {
        vlMin = min(arbol.getRaiz());
        vlMax = max(arbol.getRaiz());
        rango = vlMax - vlMin;

        cout << endl << "El valor minimo en el ABB es: " << vlMin;
        cout << endl << "El valor maximo en el ABB es: " << vlMax;
        cout << endl << "El rango (entre el mayor y menor) es: " << rango;
    } else {
        cout << endl << "El arbol esta vacio";
    }
    
    return 0;
}

void leer(ArbolBinario* abb) {
    Tipo vl;
    cout << endl << "Ingrese un valor a insertar al ABB. Finalice con [" << FIN << "]: ";
    cin >> vl;
    if (vl != FIN) { 
        abb->insertarNodo(vl); 
        leer(abb);
    }
}

Tipo min(NodoBinario* nodo) { 
    if (nodo->getIzq() == NULL) {
        return nodo->getDato();
    }
    return min(nodo->getIzq());
}

Tipo max(NodoBinario* nodo) { 
    if (nodo->getDer() == NULL) {
        return nodo->getDato();
    }
    return max(nodo->getDer());
}

