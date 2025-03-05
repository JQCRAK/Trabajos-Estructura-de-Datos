/*Jhostin Quispe 7365
Determinar la moda (el valor que aparece con mayor frecuencia) entre los elementos de una lista
*/

using namespace std;
#include <iostream>
#include "Lista.h"
#define FIN 99999			

void ingresarLista(Lista *l);
void imprimirLista(Nodo *pri);
int determinarModa(Nodo *pri);
int contarFrecuencia(Nodo *pri, Tipo val);
int encontrarMaxFrecuencia(Nodo *pri, Nodo *start, int maxFreq, Tipo &moda);

int main(){
    system("color f0");
    Lista l;
    int moda;
    cout << endl << "Ejercicio 8";
    ingresarLista(&l);
    cout << endl << "Contenido de la Lista";
    imprimirLista(l.getPrimero());

    moda = determinarModa(l.getPrimero());
    cout << endl << "La moda es: " << moda << endl;

    return 0;
}

void ingresarLista(Lista *l){
    Tipo vl;

    cout << endl << "Ingrese un valor para lista. Finalice con [" << FIN << "]: ";
    cin >> vl;

    if(vl != FIN){
        l->insertarAlFinal(vl);
        ingresarLista(l);
    }
}

void imprimirLista(Nodo *pri){
    if(pri != NULL){
        cout << endl << "> " << pri->getDato();
        imprimirLista(pri->getPunt());
    }
}

int determinarModa(Nodo *pri) {
    Tipo moda = pri->getDato();
    encontrarMaxFrecuencia(pri, pri, 0, moda);
    return moda;
}

int contarFrecuencia(Nodo *pri, Tipo val) {
    if (pri == NULL) {
        return 0;
    }
    return (pri->getDato() == val) + contarFrecuencia(pri->getPunt(), val);
}

int encontrarMaxFrecuencia(Nodo *pri, Nodo *start, int maxFreq, Tipo &moda) {
    if (start == NULL) {
        return maxFreq;
    }
    int freq = contarFrecuencia(pri, start->getDato());
    if (freq > maxFreq) {
        maxFreq = freq;
        moda = start->getDato();
    }
    return encontrarMaxFrecuencia(pri, start->getPunt(), maxFreq, moda);
}
