/*Jhostin Quispe 7365
Calcular la diferencia existente entre el N-ésimo elemento de una cola, y los valores precedentes a este
*/

#include <iostream>
#include "Cola.h"
#define FIN 999999

using namespace std;

// Prototipos de funciones recursivas
void leerCola(Cola *c);
void imprimirCola(Cola c);
int calcularDiferencia(Cola c, int n, int i, int suma);

int main() {
    system("color f0");
    Cola a;    
    int n,diferencia;
    
    cout << endl << "Ejercicio 9";
    leerCola(&a);
    cout << endl << "Contenidos del TDA Cola";
    imprimirCola(a);

    cout << endl << "Ingrese la posicion N para calcular la diferencia: ";
    cin >> n;

    diferencia = calcularDiferencia(a, n, 0, 0);
    cout << "La diferencia es: " << diferencia << endl;

    return 0;
}

void leerCola(Cola *c) {
    Tipo valor;
    cout << endl << "Ingrese un valor para agregar en la Cola." << endl;
    cout << "Finalice con [" << FIN << "]: ";
    cin >> valor;
    if (valor != FIN) {
        c->insertar(valor);
        leerCola(c);
    }
}

void imprimirCola(Cola c) {
    if (!c.colaVacia()) {
        cout << endl << "> " << c.quitar();
        imprimirCola(c);
    }
}

int calcularDiferencia(Cola c, int n, int i, int suma) {
    if (i == n - 1) {
        return c.frenteCola() - suma;
    } else {
        suma += c.quitar();
        return calcularDiferencia(c, n, i + 1, suma);
    }
}


