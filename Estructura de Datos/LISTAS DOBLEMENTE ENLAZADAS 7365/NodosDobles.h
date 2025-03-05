#ifndef NODODOBLE_H
#define NODODOBLE_H

#include <iostream>

class NodoDoble {
private:
    int dato; // Dato almacenado en el nodo
    NodoDoble* anterior; // Puntero al nodo anterior
    NodoDoble* siguiente; // Puntero al nodo siguiente
    NodoDoble* izquierda; // Puntero al nodo a la izquierda
    NodoDoble* derecha; // Puntero al nodo a la derecha

public:
    // Constructor
    NodoDoble(int _dato, NodoDoble* _anterior = NULL, NodoDoble* _siguiente = NULL) : dato(_dato), anterior(_anterior), siguiente(_siguiente), izquierda(NULL), derecha(NULL) {}

    // Métodos para acceder y modificar los atributos
    int obtenerDato() const { return dato; }
    void establecerDato(int nuevoDato) { dato = nuevoDato; }

    NodoDoble* obtenerAnterior() const { return anterior; }
    void establecerAnterior(NodoDoble* nuevoAnterior) { anterior = nuevoAnterior; }

    NodoDoble* obtenerSiguiente() const { return siguiente; }
    void establecerSiguiente(NodoDoble* nuevoSiguiente) { siguiente = nuevoSiguiente; }

    NodoDoble* obtenerIzquierda() const { return izquierda; }
    void establecerIzquierda(NodoDoble* nuevoIzquierda) { izquierda = nuevoIzquierda; }

    NodoDoble* obtenerDerecha() const { return derecha; }
    void establecerDerecha(NodoDoble* nuevoDerecha) { derecha = nuevoDerecha; }

};

#endif

