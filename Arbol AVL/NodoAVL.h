#ifndef NODOAVL_H
#define NODOAVL_H

#include <iostream>
#include <algorithm> // Para std::max

class NodoAVL {
public:
    int clave;
    int valor;
    int altura;
    NodoAVL* izquierdo;
    NodoAVL* derecho;

    // Constructor
    NodoAVL(int clave, int valor) : clave(clave), valor(valor), altura(1), izquierdo(NULL), derecho(NULL) {}

    // Destructor (si es necesario)
    ~NodoAVL() {
        // Implementación del destructor si se requiere
    }

    // Función para obtener la altura de un nodo (nullptr tiene altura 0)
    int obtenerAltura(NodoAVL* nodo) {
        if (nodo == NULL) return 0;
        return nodo->altura;
    }

    // Función para obtener el factor de balance de un nodo
    int obtenerFactorBalance(NodoAVL* nodo) {
        if (nodo == NULL) return 0;
        return obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho);
    }

    // Función para actualizar la altura de un nodo basado en las alturas de sus hijos
    void actualizarAltura() {
        altura = 1 + std::max(obtenerAltura(izquierdo), obtenerAltura(derecho));
    }

    // Rotación a la derecha
    NodoAVL* rotacionDerecha(NodoAVL* y) {
        NodoAVL* x = y->izquierdo;
        NodoAVL* T2 = x->derecho;

        // Realizar rotación
        x->derecho = y;
        y->izquierdo = T2;

        // Actualizar alturas
        y->actualizarAltura();
        x->actualizarAltura();

        // Devolver nueva raíz
        return x;
    }

    // Rotación a la izquierda
    NodoAVL* rotacionIzquierda(NodoAVL* x) {
        NodoAVL* y = x->derecho;
        NodoAVL* T2 = y->izquierdo;

        // Realizar rotación
        y->izquierdo = x;
        x->derecho = T2;

        // Actualizar alturas
        x->actualizarAltura();
        y->actualizarAltura();

        // Devolver nueva raíz
        return y;
    }

    // Función para imprimir el nodo (solo para depuración)
    void imprimir() {
        std::cout << "(" << clave << ", " << valor << ") ";
    }
};

#endif // NODOAVL_H
