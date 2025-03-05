/*Jhostin Quispe 7365
Encontrar el rango de una lista desordenada de valores ingresados
*/

#include <iostream>
#include "Lista.h"
#define FIN 99999  

using namespace std;

void ingresarLista(Lista* l);
void imprimirLista(Nodo* pri);
void calcularMinMax(Nodo* pri, Tipo& minimo, Tipo& maximo);
int calcularRango(Nodo* pri);

int main() {
    system("color f0");
    Lista l;
    cout << endl << "Ejercicio 1";
    ingresarLista(&l);
    cout << endl << "Contenido de la Lista";
    imprimirLista(l.getPrimero());

    int rango = calcularRango(l.getPrimero());
    cout << endl << "El rango de la lista es: " << rango << endl;

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

void calcularMinMax(Nodo* pri, Tipo& minimo, Tipo& maximo) {
    if (pri != NULL) {
        if (pri->getDato() < minimo) {
            minimo = pri->getDato();
        }
        if (pri->getDato() > maximo) {
            maximo = pri->getDato();
        }
        calcularMinMax(pri->getPunt(), minimo, maximo); 
    }
}

int calcularRango(Nodo* pri) {
    if (pri == NULL) {
        cout << "La lista está vacia" << endl;
        return 0;
    }

    Tipo minimo = pri->getDato();
    Tipo maximo = pri->getDato();
    calcularMinMax(pri, minimo, maximo);
    return maximo - minimo;
}
