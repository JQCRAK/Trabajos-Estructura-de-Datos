/*Jhostin Quispe 7365
Formar una lista con los valores pares y otra con valores impares de una lista ingresada
*/

using namespace std;
#include <iostream>
#include "Lista.h"
#define FIN 99999  

void ingresarLista(Lista* l);
void imprimirLista(Nodo* pri);
void separarParesImpares(Nodo* pri, Lista* pares, Lista* impares);

int main() {
    system("color f0");
    Lista l,pares,impares;
    
    cout << endl << "Ejercicio 2";
    ingresarLista(&l);
    cout << endl << "Contenido de la Lista";
    imprimirLista(l.getPrimero());

    separarParesImpares(l.getPrimero(), &pares, &impares);

    cout << endl << "Lista de valores pares";
    imprimirLista(pares.getPrimero());

    cout << endl << "Lista de valores impares";
    imprimirLista(impares.getPrimero());

    return 0;
}

void ingresarLista(Lista* l) {  
    Tipo vl;  

    cout << endl << "Ingrese un valor para lista. Finalice con [" << FIN << "]: ";
    cin >> vl;

    if (vl != FIN) {  
        l->insertarAlFinal(vl);  
        ingresarLista(l); 
    }
}

void imprimirLista(Nodo* pri) { 
    if (pri != NULL) {  
        cout << endl << "> " << pri->getDato();
        imprimirLista(pri->getPunt());  
    }
}

void separarParesImpares(Nodo* pri, Lista* pares, Lista* impares) {
    if (pri != NULL) {
        if (pri->getDato() % 2 == 0) {
            pares->insertarAlFinal(pri->getDato());  
        } else {
            impares->insertarAlFinal(pri->getDato());  
        }
        separarParesImpares(pri->getPunt(), pares, impares);  
    }
}
