#include <iostream>
#include <cstring>
#include "Pila.h" // Incluir el archivo de encabezado que contiene la definición de la clase Pila
#define EXT 50

using namespace std;

bool esPalindromo(char cad[], int longitud);

int main() {
    char cad[EXT];

    cout << "Ingrese la frase: ";
    cin.getline(cad, EXT, '.');

    if (esPalindromo(cad, strlen(cad))) {
        cout << "La frase ingresada es un palindromo." << endl;
    } else {
        cout << "La frase ingresada no es un palindromo." << endl;
    }

    return 0;
}

bool esPalindromo(char cad[], int longitud) {
    Pila pilaNormal;
    Pila pilaInversa;

    // Guardar en la pila de manera ordenada y de manera inversa usando dos bucles for
    for (int i = 0; i < longitud; ++i) {
        pilaNormal.push(cad[i]);
    }

    for (int i = longitud - 1; i >= 0; --i) {
        pilaInversa.push(cad[i]);
    }

    // Comparar las pilas para determinar si son palíndromos
    while (true) {
        if (pilaNormal.pop() != pilaInversa.pop()) {
            return false; // Si hay una diferencia, no es palíndromo
        }
        if (pilaNormal.pilaVacia()) {
            break; // Si pilaNormal está vacía, salir del bucle
        }
    }
    
    // Si ambos bucles terminan y no se encontraron diferencias, entonces es palíndromo
    return true;
}

