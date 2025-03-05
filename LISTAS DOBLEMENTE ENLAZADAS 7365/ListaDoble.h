#ifndef LISTASDOBLES_H
#define LISTASDOBLES_H

#include "NodosDobles.h"
#include <iostream>

using namespace std;

class ListaDoble {
private:
    NodoDoble* inicio;
    NodoDoble* fin;

public:
    ListaDoble();
    ~ListaDoble();

    bool esVacia();
    void insertarAlFinal(int dato);
    void insertarAlInicio(int dato);
    void insertarEnPosicion(int dato, int posicion);
    bool eliminarAlInicio();
    bool eliminarAlFinal();
    bool eliminarEnPosicion(int posicion);
    void imprimirAdelante();
    void imprimirAtras();
    NodoDoble* obtenerInicio();
    NodoDoble* obtenerFin();
    NodoDoble* buscarElemento(int dato);
};

ListaDoble::ListaDoble() : inicio(NULL), fin(NULL) {}

ListaDoble::~ListaDoble() {
    NodoDoble* actual = inicio;
    while (actual != NULL) {
        NodoDoble* siguiente = actual->obtenerSiguiente();
        delete actual;
        actual = siguiente;
    }
}

bool ListaDoble::esVacia() {
    return inicio == NULL;
}

void ListaDoble::insertarAlFinal(int dato) {
    NodoDoble* nuevo = new NodoDoble(dato);
    if (esVacia()) {
        inicio = nuevo;
        fin = nuevo;
    } else {
        fin->establecerSiguiente(nuevo);
        nuevo->establecerAnterior(fin);
        fin = nuevo;
    }
}

void ListaDoble::insertarAlInicio(int dato) {
    NodoDoble* nuevo = new NodoDoble(dato);
    if (esVacia()) {
        inicio = nuevo;
        fin = nuevo;
    } else {
        nuevo->establecerSiguiente(inicio);
        inicio->establecerAnterior(nuevo);
        inicio = nuevo;
    }
}

void ListaDoble::insertarEnPosicion(int dato, int posicion) {
    if (posicion < 0) {
        cout << "Posición invalida." << endl;
        return;
    }
    if (posicion == 0) {
        insertarAlInicio(dato);
        return;
    }
    NodoDoble* actual = inicio;
    int contador = 0;
    while (actual != NULL && contador < posicion) {
        actual = actual->obtenerSiguiente();
        contador++;
    }
    if (actual == NULL) {
        cout << "Posicion fuera de rango." << endl;
        return;
    }
    NodoDoble* nuevo = new NodoDoble(dato);
    nuevo->establecerAnterior(actual->obtenerAnterior());
    nuevo->establecerSiguiente(actual);
    actual->obtenerAnterior()->establecerSiguiente(nuevo);
    actual->establecerAnterior(nuevo);
}

bool ListaDoble::eliminarAlInicio() {
    if (esVacia()) {
        cout << "La lista esta vacia." << endl;
        return false;
    }

    NodoDoble* temp = inicio;
    inicio = inicio->obtenerSiguiente();
    if (inicio != NULL) {
        inicio->establecerAnterior(NULL);
    } else {
        fin = NULL;
    }
    delete temp;
    return true;
}

bool ListaDoble::eliminarAlFinal() {
    if (esVacia()) {
        cout << "La lista esta vacia." << endl;
        return false;
    }

    NodoDoble* temp = fin;
    fin = fin->obtenerAnterior();
    if (fin != NULL) {
        fin->establecerSiguiente(NULL);
    } else {
        inicio = NULL;
    }
    delete temp;
    return true;
}

bool ListaDoble::eliminarEnPosicion(int posicion) {
    if (esVacia()) {
        cout << "La lista esta vacia." << endl;
        return false;
    }
    if (posicion < 0) {
        cout << "Posicion invalida." << endl;
        return false;
    }
    if (posicion == 0) {
        return eliminarAlInicio();
    }

    NodoDoble* actual = inicio;
    int contador = 0;
    while (actual != NULL && contador < posicion) {
        actual = actual->obtenerSiguiente();
        contador++;
    }

    if (actual == NULL) {
        cout << "Posicion fuera de rango." << endl;
        return false;
    }

    actual->obtenerAnterior()->establecerSiguiente(actual->obtenerSiguiente());
    if (actual->obtenerSiguiente() != NULL) {
        actual->obtenerSiguiente()->establecerAnterior(actual->obtenerAnterior());
    } else {
        fin = actual->obtenerAnterior();
    }
    delete actual;
    return true;
}

void ListaDoble::imprimirAdelante() {
    NodoDoble* actual = inicio;
    while (actual != NULL) {
        cout << actual->obtenerDato() << " ";
        actual = actual->obtenerSiguiente();
    }
    cout << endl;
}

void ListaDoble::imprimirAtras() {
    NodoDoble* actual = fin;
    while (actual != NULL) {
        cout << actual->obtenerDato() << " ";
        actual = actual->obtenerAnterior();
    }
    cout << endl;
}

NodoDoble* ListaDoble::obtenerInicio() {
    return inicio;
}

NodoDoble* ListaDoble::obtenerFin() {
    return fin;
}

NodoDoble* ListaDoble::buscarElemento(int dato) {
    NodoDoble* actual = inicio;
    while (actual != NULL) {
        if (actual->obtenerDato() == dato) {
            return actual;
        }
        actual = actual->obtenerSiguiente();
    }
    return NULL;
}

#endif 

