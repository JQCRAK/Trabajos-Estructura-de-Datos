/*Autor Jhostin Quispe 7365
Ejercicio 6
Calcular el promedio de los elementos que ocupan las posiciones centrales de una pila
*/
#include <iostream>
#include "Pila.h"
#define FIN 999999

using namespace std;

void leerPila(Pila *a);     
void imprimirPila(Pila b); 
double calcularPromedioPila(Pila& pila);

int main() {			
    system("color f0");
    Pila a;    
    
    cout << "Promedio de pilas en el central " << endl;
    leerPila(&a);
    imprimirPila(a);
    
    double promedio = calcularPromedioPila(a);
    cout << endl<<"El promedio de los elementos de la pila es: " << promedio << endl;

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

double calcularPromedioPilaRecursivo(Pila& pila, int count, double sum) {
    if (pila.pilaVacia()) {
        return sum / count;
    }

    Tipo elemento = pila.pop();
    sum += elemento;
    return calcularPromedioPilaRecursivo(pila, count + 1, sum);
}

double calcularPromedioPila(Pila& pila) {
    if (pila.pilaVacia()) {
        return 0.0;
    }

    Pila pilaCopia = pila;
    return calcularPromedioPilaRecursivo(pilaCopia, 0, 0.0);
}

