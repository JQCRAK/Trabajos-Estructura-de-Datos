/*Autor Jhostin Quispe 7365
Ejercicio 1
Encontrar el máximo y mínimo elemento de una pila
*/
#include <iostream>
#include "Pila.h"
#define FIN 999999

using namespace std;

int main() {
    system("color f0");
    Pila a;
    int maximo = INT_MIN; // Inicializar el maximo con el valor minimo posible
    int minimo = INT_MAX; // Inicializar el minimo con el valor maximo posible
    
    void leerPila(Pila *a, int &maximo, int &minimo);
	void imprimirPila(Pila b);

    cout << "\tPila";
    leerPila(&a, maximo, minimo);
    cout << "Datos Ingresados " << endl;
    imprimirPila(a);
	cout << endl<<"\tResultados"<<endl;
    cout << "Máximo elemento de la pila: " << maximo << endl;
    cout << "Mínimo elemento de la pila: " << minimo << endl;

    return 0;
}

void leerPila(Pila *a, int &maximo, int &minimo) {
    Tipo vl;
    cout << endl << "Ingrese un valor a apilar, finalice con [" << FIN << "]: ";
    cin >> vl;
    if (vl != FIN) {
        a->push(vl);
        if (vl > maximo) maximo = vl; // Actualizar el maximo si el nuevo valor es mayor
        if (vl < minimo) minimo = vl; // Actualizar el minimo si el nuevo valor es menor
        leerPila(a, maximo, minimo);
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

