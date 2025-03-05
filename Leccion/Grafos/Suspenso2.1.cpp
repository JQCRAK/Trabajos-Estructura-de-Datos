/*Ordenar desc y asc por trios 

*/

using namespace std;
#include <iostream>
#include "Pila.h"
#define FIN 999

void leerPila(Pila* p);
void imprimirPila(Pila p);
void ordenarSegmentado(Pila* p);
void ordenarSegmentadoAux(Pila* p, Pila* aux, bool ascendente);
void ordenarSegmento(Pila* p, Pila* aux, int n, bool ascendente);
void insertarOrdenadoAsc(Pila* aux, Tipo elemento);
void insertarOrdenadoDesc(Pila* aux, Tipo elemento);
void transferirPila(Pila* origen, Pila* destino);

int main() {
    system("color f5");
    Pila p;

    leerPila(&p);

    cout << endl << "VALORES INGRESADOS A LA PILA:" << endl;
    imprimirPila(p);

    ordenarSegmentado(&p);

    cout << endl << "VALORES ORDENADOS EN SEGMENTOS:" << endl;
    imprimirPila(p);

    return 0;
}

void leerPila(Pila* p) {
    Tipo vl;
    cout << endl << "Ingrese un valor: ";
    cin >> vl;
    if (vl != FIN) {
        p->push(vl);
        leerPila(p);
    }
}

void imprimirPila(Pila p) {
    if (!p.pilaVacia()) {
        Tipo vl = p.pop();
        imprimirPila(p);
        cout << ">" << vl << endl;
        p.push(vl);  // Volvemos a insertar el elemento para mantener la pila original
    }
}

void ordenarSegmentado(Pila* p) {
    Pila aux;
    ordenarSegmentadoAux(p, &aux, true);
    transferirPila(&aux, p);  // Transferir todos los elementos de la pila auxiliar a la pila original
}

void ordenarSegmentadoAux(Pila* p, Pila* aux, bool ascendente) {
    if (!p->pilaVacia()) {
        ordenarSegmento(p, aux, 3, ascendente);  // Ordenar segmento actual
        ordenarSegmentadoAux(p, aux, !ascendente);
    }
}

void ordenarSegmento(Pila* p, Pila* aux, int n, bool ascendente) {
    if (n > 0 && !p->pilaVacia()) {
        Tipo valor = p->pop();
        ordenarSegmento(p, aux, n - 1, ascendente);
        if (ascendente) {
            insertarOrdenadoAsc(aux, valor);
        } else {
            insertarOrdenadoDesc(aux, valor);
        }
    }
}

void insertarOrdenadoAsc(Pila* aux, Tipo elemento) {
    if (aux->pilaVacia() || aux->cimaPila() <= elemento) {
        aux->push(elemento);
    } else {
        Tipo temp = aux->pop();
        insertarOrdenadoAsc(aux, elemento);
        aux->push(temp);
    }
}

void insertarOrdenadoDesc(Pila* aux, Tipo elemento) {
    if (aux->pilaVacia() || aux->cimaPila() >= elemento) {
        aux->push(elemento);
    } else {
        Tipo temp = aux->pop();
        insertarOrdenadoDesc(aux, elemento);
        aux->push(temp);
    }
}

void transferirPila(Pila* origen, Pila* destino) {
    if (!origen->pilaVacia()) {
        Tipo valor = origen->pop();
        transferirPila(origen, destino);
        destino->push(valor);
    }
}

