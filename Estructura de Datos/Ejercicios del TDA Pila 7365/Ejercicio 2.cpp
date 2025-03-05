/*Autor Jhostin Quispe 7365
Ejercicio 2
Calcular la suma de los elementos de una pila
*/
#include <iostream>
#include "Pila.h"
#define FIN 999999

using namespace std;

int main() {
    system("color f0");
    Pila a;
    void leerPila(Pila *a);
	void imprimirPila(Pila b);
	int sumaPila(Pila b); // Se agrega la declaración de la función para calcular la suma

    cout << "\tSuma de la pila";
    leerPila(&a);
    imprimirPila(a);
    cout <<endl;
    cout <<"\tResultados......"<<endl;
    cout << "La suma de los elementos de la pila es: " << sumaPila(a) << endl; // Se llama a la función sumaPila

    return 0;
}

void leerPila(Pila *a) {
    Tipo vl;
    cout << endl << "Ingrese un valor a apilar, finalice con [" << FIN << "]: ";
    cin >> vl;
    if (vl != FIN) {
        a->push(vl);
        leerPila(a);
    }
}

void imprimirPila(Pila b) {
    Tipo vl;
    if (!b.pilaVacia()) {
        vl = b.pop();
        cout << endl << " > " << vl;
        imprimirPila(b);
    }
}

int sumaPila(Pila b) {
    if (b.pilaVacia()) {
        return 0; // Si la pila está vacía, la suma es cero
    } else {
        Tipo elemento = b.pop();
        return elemento + sumaPila(b); // Retorna el elemento actual más la suma del resto de la pila
    }
}

