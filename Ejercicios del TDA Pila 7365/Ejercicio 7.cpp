/*Autor Jhostin Quispe 7365
Ejercicio 7
Insertar N elementos en las posiciones centrales de una pila
*/
#include <iostream>
#include "Pila.h"
#define FIN 999999

using namespace std;

void leerPila(Pila *a);
void insertarEnCentro(Pila &pila, int elementosAInsertar, int posicionesCentro);
void imprimirPila(Pila b);

int main() {
    system("color f0");
    Pila a;
    int elementosAInsertar, tamanioPila, posicionesCentro;

    cout << "Ingresar valor en el centro de la pila: " << endl;
    leerPila(&a);
    imprimirPila(a);
    cout << endl << "Ingrese la cantidad de elementos a insertar en el centro: ";
    cin >> elementosAInsertar;

    tamanioPila = a.tamanioPila();
    posicionesCentro = (tamanioPila % 2 == 0) ? tamanioPila / 2 : (tamanioPila + 1) / 2;

    insertarEnCentro(a, elementosAInsertar, posicionesCentro);

    cout << endl << "La pila después de insertar elementos en el centro:";
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

void imprimirPila(Pila b) {
    Tipo vl;
    if (!b.pilaVacia()) {
        vl = b.pop();
        cout << endl << " > " << vl;
        imprimirPila(b);
    }
}

void extraerElementos(Pila& pila, Pila& pilaTemporal, int posicionesCentro) {
    if (pila.tamanioPila() > posicionesCentro) {
        pilaTemporal.push(pila.pop());
        extraerElementos(pila, pilaTemporal, posicionesCentro);
    }
}

void insertarElementos(Pila& pila, Pila& pilaTemporal) {
    if (!pilaTemporal.pilaVacia()) {
        pila.push(pilaTemporal.pop());
        insertarElementos(pila, pilaTemporal);
    }
}

void insertarEnCentro(Pila& pila, int elementosAInsertar, int posicionesCentro) {
    if (elementosAInsertar > 0) {
        Tipo elemento;
        cout << "Ingrese el elemento a insertar en el centro " << posicionesCentro + 1 << ": ";
        cin >> elemento;

        Pila pilaTemporal;												
        extraerElementos(pila, pilaTemporal, posicionesCentro);		
        pila.push(elemento);										
        insertarElementos(pila, pilaTemporal);					

        insertarEnCentro(pila, elementosAInsertar - 1, posicionesCentro + 1);  		
    }
}



