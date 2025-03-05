/*Autor Jhostin Quispe 7365
Ejercicio 10
Permitir el ingreso de una pila de valores, proceder a intercalar sus valores de inicio y final 
(primero, último, segundo, penúltimo, tercero, antepenúltimo, etc.)
*/
#include <iostream>
#include "Pila.h"
#define FIN 999999

using namespace std;

void leerPila(Pila *a);
void intercalarValores(Pila &pila);
void intercalarRecursivo(Pila &pila, Pila &temp, bool par);
void vaciarTemp(Pila &pila, Pila &temp);
void imprimirPila(Pila &pila);

int main() {
    system("color f0");
    Pila a;

    cout << "Pila 1: " << endl;
    leerPila(&a);
    imprimirPila(a);

    intercalarValores(a);

    cout << "\nPila con valores intercalados: " << endl;
    imprimirPila(a);

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

void intercalarValores(Pila &pila) {
    Pila temp;
    bool par = true; // Indicador para alternar entre primero y último, segundo y penúltimo, etc.
    intercalarRecursivo(pila, temp, par);
}

void intercalarRecursivo(Pila &pila, Pila &temp, bool par) {
    if (!pila.pilaVacia()) {
        Tipo valor = pila.pop();
        if (par) {
            temp.push(valor);
        } else {
            Tipo tempValor = temp.pop();
            pila.push(valor);
            pila.push(tempValor);
        }
        intercalarRecursivo(pila, temp, !par);
    } else {
        vaciarTemp(pila, temp);
    }
}

void vaciarTemp(Pila &pila, Pila &temp) {
    if (!temp.pilaVacia()) {
        Tipo valor = temp.pop();
        vaciarTemp(pila, temp);
        pila.push(valor);
    }
}

void imprimirPila(Pila &pila) {
    if (!pila.pilaVacia()) {
        Tipo vl = pila.pop();
        cout <<endl<< " > " << vl;
        imprimirPila(pila);
        pila.push(vl); 
    }
}

