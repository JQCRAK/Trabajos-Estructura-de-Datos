#ifndef ARBOLB_H
#define ARBOLB_H

#include "Nodo.h"
#include <iostream>

// Clase Árbol B
class ArbolB {
private:
    BTreeNode* root; // Puntero a la raíz del árbol
    int grado;       // Grado mínimo del árbol
    
    // Funciones privadas recursivas para operaciones en árbol B
    void insertarRecursivo(BTreeNode* nodo, int clave);
    void eliminarRecursivo(BTreeNode* nodo, int clave);
    bool buscarRecursivo(BTreeNode* nodo, int clave);
    void recorrerInordenRecursivo(BTreeNode* nodo);
    
    // Otras funciones privadas
    void dividirHijo(BTreeNode* padre, int indiceHijo);
    void fusionarHijos(BTreeNode* padre, int indiceHijo);
    void pedirPrestadoDeAnterior(BTreeNode* nodo, int indiceHijo);
    void pedirPrestadoDeSiguiente(BTreeNode* nodo, int indiceHijo);
    void eliminarDeHoja(BTreeNode* nodo, int indiceClave);
    void eliminarDeNoHoja(BTreeNode* nodo, int indiceClave);
    int encontrarClaveEnNodo(BTreeNode* nodo, int clave);
    void llenarNodo(BTreeNode* nodo, int indiceClave);
    
public:
    // Constructor
    ArbolB(int grado);
    
    // Destructor
    ~ArbolB();
    
    // Funciones públicas para operaciones en árbol B
    void insertar(int clave);
    void eliminar(int clave);
    bool buscar(int clave);
    void recorrerInorden();
};

// Implementación de los métodos públicos y privados

// Constructor: inicializa el árbol B con el grado especificado
ArbolB::ArbolB(int grado) {
    this->root = NULL;
    this->grado = grado;
}

// Destructor: libera la memoria de todos los nodos del árbol B
ArbolB::~ArbolB() {
    // Lógica para liberar la memoria de manera recursiva
}

// Función privada recursiva para insertar una clave en el árbol B
void ArbolB::insertarRecursivo(BTreeNode* nodo, int clave) {
    int i = nodo->num_keys - 1;

    if (nodo->leaf) {
        // Insertar clave en un nodo hoja
        while (i >= 0 && clave < nodo->keys[i]) {
            nodo->keys[i + 1] = nodo->keys[i];
            i--;
        }
        nodo->keys[i + 1] = clave;
        nodo->num_keys++;
    } else {
        // Encontrar hijo adecuado para insertar la clave
        while (i >= 0 && clave < nodo->keys[i])
            i--;

        // Verificar si el hijo encontrado está lleno
        if (nodo->children[i + 1]->num_keys == 2 * grado - 1) {
            dividirHijo(nodo, i + 1);

            // Determinar qué mitad del nodo dividido contiene la nueva clave
            if (clave > nodo->keys[i + 1])
                i++;
        }
        insertarRecursivo(nodo->children[i + 1], clave);
    }
}

// Función pública para insertar una clave en el árbol B
void ArbolB::insertar(int clave) {
    if (root == NULL) {
        root = new BTreeNode(true);
        root->keys[0] = clave;
        root->num_keys = 1;
    } else {
        if (root->num_keys == 2 * grado - 1) {
            BTreeNode* nuevoNodo = new BTreeNode(false);
            nuevoNodo->children[0] = root;
            dividirHijo(nuevoNodo, 0);

            int i = 0;
            if (nuevoNodo->keys[0] < clave)
                i++;
            insertarRecursivo(nuevoNodo->children[i], clave);

            root = nuevoNodo;
        } else {
            insertarRecursivo(root, clave);
        }
    }
}

// Función privada recursiva para eliminar una clave del árbol B
void ArbolB::eliminarRecursivo(BTreeNode* nodo, int clave) {
    int indiceClave = encontrarClaveEnNodo(nodo, clave);

    // La clave a eliminar está presente en este nodo
    if (indiceClave < nodo->num_keys && nodo->keys[indiceClave] == clave) {
        if (nodo->leaf) {
            eliminarDeHoja(nodo, indiceClave);
        } else {
            eliminarDeNoHoja(nodo, indiceClave);
        }
    } else {
        // Si este nodo es un nodo hoja, entonces la clave no está presente en el árbol
        if (nodo->leaf) {
            std::cout << "La clave " << clave << " no está presente en el árbol.\n";
            return;
        }

        // La clave a eliminar está posiblemente presente en el subárbol enraizado con el último hijo de este nodo
        // Por lo tanto, se asegura que este sea el último hijo antes de proceder con la recursión
        bool esUltimoHijo = (indiceClave == nodo->num_keys);

        // Si el hijo donde se espera que esté la clave tiene menos de t claves, rellenamos ese hijo
        if (nodo->children[indiceClave]->num_keys < grado)
            llenarNodo(nodo, indiceClave);

        // Si el último hijo ha sido fusionado, debe tener sido fusionado
        if (esUltimoHijo && indiceClave > nodo->num_keys)
            eliminarRecursivo(nodo->children[indiceClave - 1], clave);
        else
            eliminarRecursivo(nodo->children[indiceClave], clave);
    }
}

// Función pública para eliminar una clave del árbol B
void ArbolB::eliminar(int clave) {
    if (!root) {
        std::cout << "El árbol está vacío\n";
        return;
    }

    eliminarRecursivo(root, clave);

    // Si el nodo raíz tiene 0 claves, hacer que su hijo único sea el nuevo nodo raíz si existe
    if (root->num_keys == 0) {
        BTreeNode* temp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->children[0];

        delete temp;
    }
}

// Función privada recursiva para buscar una clave en el árbol B
bool ArbolB::buscarRecursivo(BTreeNode* nodo, int clave) {
    int i = 0;
    while (i < nodo->num_keys && clave > nodo->keys[i])
        i++;

    // Si la clave actual es igual a la clave deseada, se ha encontrado la clave
    if (i < nodo->num_keys && clave == nodo->keys[i])
        return true;

    // Si es un nodo hoja, la clave no está presente en el árbol
    if (nodo->leaf)
        return false;

    // Recurrir al hijo apropiado
    return buscarRecursivo(nodo->children[i], clave);
}

// Función pública para buscar una clave en el árbol B
bool ArbolB::buscar(int clave) {
    if (!root) {
        std::cout << "El árbol está vacío\n";
        return false;
    }

    return buscarRecursivo(root, clave);
}

// Función privada recursiva para recorrer en inorden el árbol B
void ArbolB::recorrerInordenRecursivo(BTreeNode* nodo) {
    if (nodo != NULL) {
        int i;
        for (i = 0; i < nodo->num_keys; i++) {
            // Recorrer el subárbol enraizado con el i-ésimo hijo
            recorrerInordenRecursivo(nodo->children[i]);
            
            // Imprimir la clave actual
            std::cout << nodo->keys[i] << " ";
        }
        
        // Recorrer el último hijo
        recorrerInordenRecursivo(nodo->children[i]);
    }
}

// Función pública para recorrer en inorden el árbol B
void ArbolB::recorrerInorden() {
    if (!root) {
        std::cout << "El árbol está vacío\n";
        return;
    }

    recorrerInordenRecursivo(root);
    std::cout << "\n";
}

// Función privada para dividir un hijo de un nodo
void ArbolB::dividirHijo(BTreeNode* padre, int indiceHijo) {
    BTreeNode* hijo = padre->children[indiceHijo];
    BTreeNode* nuevoNodo = new BTreeNode(hijo->leaf);
    nuevoNodo->num_keys = grado - 1;

    for (int i = 0; i < grado - 1; i++)
        nuevoNodo->keys[i] = hijo->keys[i + grado];

    if (!hijo->leaf) {
        for (int i = 0; i < grado; i++)
            nuevoNodo->children[i] = hijo->children[i + grado];
    }

    hijo->num_keys = grado - 1;

    for (int i = padre->num_keys; i >= indiceHijo + 1; i--)
        padre->children[i + 1] = padre->children[i];

    padre->children[indiceHijo + 1] = nuevoNodo;

    for (int i = padre->num_keys - 1; i >= indiceHijo; i--)
        padre->keys[i + 1] = padre->keys[i];

    padre->keys[indiceHijo] = hijo->keys[grado - 1];
    padre->num_keys++;
}

// Función privada para fusionar un hijo de un nodo con otro hijo
void ArbolB::fusionarHijos(BTreeNode* padre, int indiceHijo) {
    BTreeNode* hijo = padre->children[indiceHijo];
    BTreeNode* hermano = padre->children[indiceHijo + 1];

    hijo->keys[grado - 1] = padre->keys[indiceHijo];

    for (int i = 0; i < hermano->num_keys; i++)
        hijo->keys[i + grado] = hermano->keys[i];

    if (!hijo->leaf) {
        for (int i = 0; i <= hermano->num_keys; i++)
            hijo->children[i + grado] = hermano->children[i];
    }

    for (int i = indiceHijo + 1; i < padre->num_keys; i++)
        padre->keys[i - 1] = padre->keys[i];

    for (int i = indiceHijo + 2; i <= padre->num_keys; i++)
        padre->children[i - 1] = padre->children[i];

    hijo->num_keys += hermano->num_keys + 1;
    padre->num_keys--;

    delete hermano;
}

// Función privada para pedir prestado una clave de un hijo anterior de un nodo
void ArbolB::pedirPrestadoDeAnterior(BTreeNode* nodo, int indiceHijo) {
    BTreeNode* hijo = nodo->children[indiceHijo];
    BTreeNode* hermano = nodo->children[indiceHijo - 1];

    for (int i = hijo->num_keys - 1; i >= 0; i--)
        hijo->keys[i + 1] = hijo->keys[i];

    if (!hijo->leaf) {
        for (int i = hijo->num_keys; i >= 0; i--)
            hijo->children[i + 1] = hijo->children[i];
    }

    hijo->keys[0] = nodo->keys[indiceHijo - 1];

    if (!nodo->leaf)
        hijo->children[0] = hermano->children[hermano->num_keys];

    nodo->keys[indiceHijo - 1] = hermano->keys[hermano->num_keys - 1];

    hijo->num_keys++;
    hermano->num_keys--;
}

// Función privada para pedir prestado una clave de un hijo siguiente de un nodo
void ArbolB::pedirPrestadoDeSiguiente(BTreeNode* nodo, int indiceHijo) {
    BTreeNode* hijo = nodo->children[indiceHijo];
    BTreeNode* hermano = nodo->children[indiceHijo + 1];

    hijo->keys[hijo->num_keys] = nodo->keys[indiceHijo];

    if (!hijo->leaf)
        hijo->children[hijo->num_keys + 1] = hermano->children[0];

    nodo->keys[indiceHijo] = hermano->keys[0];

    for (int i = 1; i < hermano->num_keys; i++)
        hermano->keys[i - 1] = hermano->keys[i];

    if (!hermano->leaf) {
        for (int i = 1; i <= hermano->num_keys; i++)
            hermano->children[i - 1] = hermano->children[i];
    }

    hijo->num_keys++;
    hermano->num_keys--;
}

// Función privada para eliminar una clave de un nodo hoja
void ArbolB::eliminarDeHoja(BTreeNode* nodo, int indiceClave) {
    for (int i = indiceClave + 1; i < nodo->num_keys; i++)
        nodo->keys[i - 1] = nodo->keys[i];

    nodo->num_keys--;
}

// Función privada para eliminar una clave de un nodo no hoja
void ArbolB::eliminarDeNoHoja(BTreeNode* nodo, int indiceClave) {
    int clave = nodo->keys[indiceClave];

    if (nodo->children[indiceClave]->num_keys >= grado) {
        int predecesor = nodo->children[indiceClave]->keys[nodo->children[indiceClave]->num_keys - 1];
        eliminarRecursivo(nodo->children[indiceClave], predecesor);
        nodo->keys[indiceClave] = predecesor;
    } else if (nodo->children[indiceClave + 1]->num_keys >= grado) {
        int sucesor = nodo->children[indiceClave + 1]->keys[0];
        eliminarRecursivo(nodo->children[indiceClave + 1], sucesor);
        nodo->keys[indiceClave] = sucesor;
    } else {
        fusionarHijos(nodo, indiceClave);
        eliminarRecursivo(nodo->children[indiceClave], clave);
    }
}

// Función privada para encontrar la posición de una clave en un nodo
int ArbolB::encontrarClaveEnNodo(BTreeNode* nodo, int clave) {
    int indice = 0;
    while (indice < nodo->num_keys && nodo->keys[indice] < clave)
        ++indice;
    return indice;
}

// Función privada para llenar un hijo que tiene menos de t claves
void ArbolB::llenarNodo(BTreeNode* nodo, int indiceClave) {
    if (indiceClave != 0 && nodo->children[indiceClave - 1]->num_keys >= grado)
        pedirPrestadoDeAnterior(nodo, indiceClave);
    else if (indiceClave != nodo->num_keys && nodo->children[indiceClave + 1]->num_keys >= grado)
        pedirPrestadoDeSiguiente(nodo, indiceClave);
    else {
        if (indiceClave != nodo->num_keys)
            fusionarHijos(nodo, indiceClave);
        else
            fusionarHijos(nodo, indiceClave - 1);
    }
}

#endif // ARBOLB_H

