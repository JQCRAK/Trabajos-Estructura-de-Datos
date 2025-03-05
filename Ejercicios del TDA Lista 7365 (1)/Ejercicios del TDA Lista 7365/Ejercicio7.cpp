/*Jhostin Quispe 7365
Determinar si los elementos de una lista guardan una distribucion correspondiente a la serie de fibonacci 
(en caso de estarlo, indicar el tipo de orden encontrado: ascendente o descendentemente)
*/

#include <iostream>
#include "Lista.h"
#define FIN 99999 

using namespace std;

int main() {
    system("color f0");
    Lista miLista;

    void agregarElementos(Lista &miLista);
    void mostrarElementos(Nodo *inicio);
    bool esFibonacci(Nodo *inicio);
    bool esAscendente(Nodo *inicio);
    cout << endl << "Ejercicio 7";
    cout << endl << "Agregar elementos a la lista: ";
    agregarElementos(miLista);

    cout << endl << "Contenido de la lista:";
    mostrarElementos(miLista.getPrimero());

    if (esFibonacci(miLista.getPrimero())) {
        cout << endl << "Los elementos de la lista 'SI' siguen una secuencia de la serie de Fibonacci";
        if (esAscendente(miLista.getPrimero())) {
            cout << endl << "El orden es ascendente";
        } else {
            cout << endl << "El orden es descendente";
        }
    } else {
        cout << endl << "Los elementos 'NO' siguen una secuencia de la serie de Fibonacci";
    }

    return 0;
}

void agregarElementos(Lista &miLista) {
    Tipo valor;
    cout << endl << "Ingrese un valor para la lista. Finalice con [" << FIN << "]: ";
    cin >> valor;

    if (valor != FIN) {
        miLista.insertarAlFinal(valor);
        agregarElementos(miLista);
    }
}

void mostrarElementos(Nodo *inicio) {
    if (inicio != NULL) {
        cout << endl << "> " << inicio->getDato();
        mostrarElementos(inicio->getPunt());
    }
}

bool verificarFibonacci(Nodo *inicio, int a, int b) {
    if (inicio == NULL) {
        return true;
    }
    
    int c = inicio->getDato();
    
    if (c != a + b) {
        return false;
    }
    
    return verificarFibonacci(inicio->getPunt(), b, c);
}

bool esFibonacci(Nodo *inicio) {
    if (inicio == NULL || inicio->getPunt() == NULL) {
        return false;
    }
    
    return verificarFibonacci(inicio->getPunt()->getPunt(), inicio->getDato(), inicio->getPunt()->getDato());
}

bool esAscendente(Nodo *inicio) {
    if (inicio == NULL || inicio->getPunt() == NULL) {
        return true;
    }
    
    int a = inicio->getDato();
    int b = inicio->getPunt()->getDato();
    
    if (a < b) {
        return esAscendente(inicio->getPunt());
    } else if (a > b) {
        return false;
    } else {
        return esAscendente(inicio->getPunt());
    }
}
