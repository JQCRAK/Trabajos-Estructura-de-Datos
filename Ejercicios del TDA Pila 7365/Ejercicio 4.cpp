/*Autor Jhostin Quispe 7365
Ejercicio 4
Ingresar una pila de elementos entre los cuales se admite únicamente hasta N valores repetidos 
(Si se alcanza dicho valor, se aceptarán solamente valores únicos).
*/
#include <iostream>
#include "Pila.h"
#define FIN 999999

using namespace std;

void leerPila(Pila *a, int n);
void imprimirPila(Pila b);
bool puedeRepetirRecursivo(Pila &p, Tipo elemento, int n, int contador);
int main() {
    system("color f0");
    int N;
    
	cout << "\tRepetir N: " << endl;
    cout << "Ingrese la cantidad maxima de repeticiones permitidas (N): ";
    cin >> N;

    Pila a;

    cout << "Datos Ingresados" << endl;
    leerPila(&a, N);
    imprimirPila(a);

    return 0;
}

void leerPila(Pila *a, int n) {
    Tipo vl;
    cout << "Ingrese un valor a apilar, finalice con [" << FIN << "]: ";
    cin >> vl;
    if (vl != FIN) {
        if (puedeRepetirRecursivo(*a, vl, n, 0)) {
            a->push(vl);
            leerPila(a, n);
        } else {
            cout << "El numero " << vl << " ya ha alcanzado su limite de repeticiones permitidas." << endl;
            leerPila(a, n);
        }
    }
}

void imprimirPila(Pila b) {
    Tipo vl;
    if (!b.pilaVacia()) {
        vl = b.pop();
        cout << endl << " > " << vl;
        imprimirPila(b);
        b.push(vl);
    }
}

bool puedeRepetirRecursivo(Pila &p, Tipo elemento, int n, int contador) {
    if (p.pilaVacia() || contador >= n) {
        return contador < n;
    }

    Tipo top = p.pop();
    bool result;
    if (top == elemento) {
        result = puedeRepetirRecursivo(p, elemento, n, contador + 1);
    } else {
        result = puedeRepetirRecursivo(p, elemento, n, contador);
    }
    p.push(top); // Restaurar el estado de la pila
    return result;
}


