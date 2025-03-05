
using namespace std;
#include <iostream>
#include "ArbolB.h"


int main() {
    // Crear un árbol B para almacenar números (grado 3)
    ArbolB arbolNumeros(3);

    // Insertar números en el árbol
    arbolNumeros.insertar(10);
    arbolNumeros.insertar(5);
    arbolNumeros.insertar(7);
    arbolNumeros.insertar(20);
    arbolNumeros.insertar(12);
    arbolNumeros.insertar(15);
    arbolNumeros.insertar(3);
    arbolNumeros.insertar(9);

    // Buscar algunos números
    int numeroBuscar = 15;
    if (arbolNumeros.buscar(numeroBuscar)) {
        cout << "El número " << numeroBuscar << " está presente en el árbol.\n";
    } else {
        cout << "El número " << numeroBuscar << " no está presente en el árbol.\n";
    }

    numeroBuscar = 25;
    if (arbolNumeros.buscar(numeroBuscar)) {
        cout << "El número " << numeroBuscar << " está presente en el árbol.\n";
    } else {
        cout << "El número " << numeroBuscar << " no está presente en el árbol.\n";
    }

    // Recorrer el árbol en inorden
    cout << "Recorrido inorden del árbol B:\n";
    arbolNumeros.recorrerInorden();

    return 0;
}

