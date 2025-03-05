#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoAVL.h"
#include <iostream>

class ArbolAVL {
private:
    NodoAVL* raiz;

    // Función para insertar un nodo en el árbol AVL
    NodoAVL* insertar(NodoAVL* nodo, int clave, int valor) {
        // Paso 1: Realizar la inserción en un árbol binario de búsqueda estándar
        if (nodo == NULL) {
            return new NodoAVL(clave, valor);
        }

        if (clave < nodo->clave) {
            nodo->izquierdo = insertar(nodo->izquierdo, clave, valor);
        } else if (clave > nodo->clave) {
            nodo->derecho = insertar(nodo->derecho, clave, valor);
        } else {
            // La clave ya existe, se puede manejar según el caso (aquí se sobrescribe)
            nodo->valor = valor;
            return nodo;
        }

        // Paso 2: Actualizar la altura del nodo actual
        nodo->actualizarAltura();

        // Paso 3: Obtener el factor de balance del nodo para verificar si se requiere reequilibrar
        int factorBalance = nodo->obtenerFactorBalance(nodo);

        // Caso 1: Rotación simple a la derecha (LL)
        if (factorBalance > 1 && clave < nodo->izquierdo->clave) {
            return nodo->rotacionDerecha(nodo);
        }

        // Caso 2: Rotación simple a la izquierda (RR)
        if (factorBalance < -1 && clave > nodo->derecho->clave) {
            return nodo->rotacionIzquierda(nodo);
        }

        // Caso 3: Rotación doble a la derecha (LR)
        if (factorBalance > 1 && clave > nodo->izquierdo->clave) {
            nodo->izquierdo = nodo->rotacionIzquierda(nodo->izquierdo);
            return nodo->rotacionDerecha(nodo);
        }

        // Caso 4: Rotación doble a la izquierda (RL)
        if (factorBalance < -1 && clave < nodo->derecho->clave) {
            nodo->derecho = nodo->rotacionDerecha(nodo->derecho);
            return nodo->rotacionIzquierda(nodo);
        }

        // El nodo está balanceado
        return nodo;
    }

    // Función para eliminar un nodo del árbol AVL
    NodoAVL* eliminar(NodoAVL* nodo, int clave) {
        // Paso 1: Realizar eliminación estándar de árbol binario de búsqueda
        if (nodo == NULL) return nodo;

        if (clave < nodo->clave) {
            nodo->izquierdo = eliminar(nodo->izquierdo, clave);
        } else if (clave > nodo->clave) {
            nodo->derecho = eliminar(nodo->derecho, clave);
        } else {
            // Nodo encontrado, proceder a eliminarlo
            if (nodo->izquierdo == NULL || nodo->derecho == NULL) {
                NodoAVL* temp = (nodo->izquierdo != NULL) ? nodo->izquierdo : nodo->derecho;

                // Caso 1: Nodo hoja o con un hijo
                if (temp == NULL) {
                    temp = nodo;
                    nodo = NULL;
                } else {
                    *nodo = *temp; // Copiar el contenido del hijo no nulo
                }
                delete temp;
            } else {
                // Caso 2: Nodo con dos hijos, encontrar el sucesor inorden
                NodoAVL* temp = encontrarMinimo(nodo->derecho);
                nodo->clave = temp->clave;
                nodo->derecho = eliminar(nodo->derecho, temp->clave);
            }
        }

        // Si el árbol tenía solo un nodo, devolverlo
        if (nodo == NULL) return nodo;

        // Paso 2: Actualizar la altura del nodo actual
        nodo->actualizarAltura();

        // Paso 3: Obtener el factor de balance del nodo para verificar si se requiere reequilibrar
        int factorBalance = nodo->obtenerFactorBalance(nodo);

        // Caso 1: Rotación simple a la derecha (LL)
        if (factorBalance > 1 && nodo->obtenerFactorBalance(nodo->izquierdo) >= 0) {
            return nodo->rotacionDerecha(nodo);
        }

        // Caso 2: Rotación simple a la izquierda (RR)
        if (factorBalance < -1 && nodo->obtenerFactorBalance(nodo->derecho) <= 0) {
            return nodo->rotacionIzquierda(nodo);
        }

        // Caso 3: Rotación doble a la derecha (LR)
        if (factorBalance > 1 && nodo->obtenerFactorBalance(nodo->izquierdo) < 0) {
            nodo->izquierdo = nodo->rotacionIzquierda(nodo->izquierdo);
            return nodo->rotacionDerecha(nodo);
        }

        // Caso 4: Rotación doble a la izquierda (RL)
        if (factorBalance < -1 && nodo->obtenerFactorBalance(nodo->derecho) > 0) {
            nodo->derecho = nodo->rotacionDerecha(nodo->derecho);
            return nodo->rotacionIzquierda(nodo);
        }

        // El nodo está balanceado
        return nodo;
    }

    // Función para encontrar el nodo con la clave mínima en un árbol dado
    NodoAVL* encontrarMinimo(NodoAVL* nodo) {
        NodoAVL* actual = nodo;
        while (actual->izquierdo != NULL) {
            actual = actual->izquierdo;
        }
        return actual;
    }

    // Función para buscar un nodo con una clave dada
    NodoAVL* buscar(NodoAVL* nodo, int clave) {
        if (nodo == NULL || nodo->clave == clave) {
            return nodo;
        }

        if (clave < nodo->clave) {
            return buscar(nodo->izquierdo, clave);
        }

        return buscar(nodo->derecho, clave);
    }

    // Funciones para recorridos inorden, preorden y postorden (para propósitos de depuración)
    void imprimirInOrder(NodoAVL* nodo) {
        if (nodo != NULL) {
            imprimirInOrder(nodo->izquierdo);
            std::cout << "(" << nodo->clave << ", " << nodo->valor << ") ";
            imprimirInOrder(nodo->derecho);
        }
    }

    void imprimirPreOrder(NodoAVL* nodo) {
        if (nodo != NULL) {
            std::cout << "(" << nodo->clave << ", " << nodo->valor << ") ";
            imprimirPreOrder(nodo->izquierdo);
            imprimirPreOrder(nodo->derecho);
        }
    }

    void imprimirPostOrder(NodoAVL* nodo) {
        if (nodo != NULL) {
            imprimirPostOrder(nodo->izquierdo);
            imprimirPostOrder(nodo->derecho);
            std::cout << "(" << nodo->clave << ", " << nodo->valor << ") ";
        }
    }

public:
    // Constructor
    ArbolAVL() : raiz(NULL) {}

    // Destructor
    ~ArbolAVL() {
        // Implementación de la función de destrucción si se requiere
    }

    // Función pública para insertar un nodo en el árbol AVL
    void insertar(int clave, int valor) {
        raiz = insertar(raiz, clave, valor);
    }

    // Función pública para eliminar un nodo del árbol AVL
    void eliminar(int clave) {
        raiz = eliminar(raiz, clave);
    }

    // Función pública para buscar un nodo con una clave dada
    NodoAVL* buscar(int clave) {
        return buscar(raiz, clave);
    }

    // Función pública para imprimir recorrido inorden (solo para depuración)
    void imprimirInOrder() {
        imprimirInOrder(raiz);
        std::cout << std::endl;
    }

    // Función pública para imprimir recorrido preorden (solo para depuración)
    void imprimirPreOrder() {
        imprimirPreOrder(raiz);
        std::cout << std::endl;
    }

    // Función pública para imprimir recorrido postorden (solo para depuración)
    void imprimirPostOrder() {
        imprimirPostOrder(raiz);
        std::cout << std::endl;
    }
};

#endif // ARBOLAVL_H

