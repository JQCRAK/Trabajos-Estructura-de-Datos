
using namespace std;
#include <iostream>
#include "ArbolB.h"


int main() {
    // Crear un �rbol B para almacenar n�meros (grado 3)
    ArbolB arbolNumeros(3);

    // Insertar n�meros en el �rbol
    arbolNumeros.insertar(10);
    arbolNumeros.insertar(5);
    arbolNumeros.insertar(7);
    arbolNumeros.insertar(20);
    arbolNumeros.insertar(12);
    arbolNumeros.insertar(15);
    arbolNumeros.insertar(3);
    arbolNumeros.insertar(9);

    // Buscar algunos n�meros
    int numeroBuscar = 15;
    if (arbolNumeros.buscar(numeroBuscar)) {
        cout << "El n�mero " << numeroBuscar << " est� presente en el �rbol.\n";
    } else {
        cout << "El n�mero " << numeroBuscar << " no est� presente en el �rbol.\n";
    }

    numeroBuscar = 25;
    if (arbolNumeros.buscar(numeroBuscar)) {
        cout << "El n�mero " << numeroBuscar << " est� presente en el �rbol.\n";
    } else {
        cout << "El n�mero " << numeroBuscar << " no est� presente en el �rbol.\n";
    }

    // Recorrer el �rbol en inorden
    cout << "Recorrido inorden del �rbol B:\n";
    arbolNumeros.recorrerInorden();

    return 0;
}

