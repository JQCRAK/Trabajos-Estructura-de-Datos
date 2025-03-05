/*Jhostin Quispe 7365
Eliminar el nodo que se encuentra a N posiciones del ultimo nodo de una lista ingresada. 
Permitir la repeticion del proceso hasta que se ingrese el marcador de fin.
*/

#include <iostream>
#include "Lista.h"
#define FIN 99999 
using namespace std;

int main() {
    system("color f0");
    Lista miLista;
    
    void agregarElementos(Lista &miLista);
    void imprimirElementos(Nodo *inicio);
    Nodo* encontrarNodoDesdeElFinal(Nodo* nodo, int n, int& contador);
    Nodo* eliminarNodoDesdeElFinal(Nodo* nodo, int n, int& contador);
    void removerNodo(Lista &miLista, int n);
    void gestionarLista(Lista &miLista);
    cout << endl << "Ejercicio 6";

    agregarElementos(miLista);
    cout << endl << "Contenido de la lista:" << endl;
    imprimirElementos(miLista.getPrimero());

    gestionarLista(miLista);

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

void imprimirElementos(Nodo *inicio) {
    if (inicio != NULL) {
        cout << endl << "> " << inicio->getDato();
        imprimirElementos(inicio->getPunt());
    }
}

Nodo* buscarNodoDesdeElFinal(Nodo* nodo, int n, int& contador) {
    if (nodo == NULL) {
        contador = 0;
        return NULL;
    }

    Nodo* siguiente = buscarNodoDesdeElFinal(nodo->getPunt(), n, contador);
    contador++;

    if (contador == n) {
        return nodo;
    }

    return siguiente;
}

Nodo* suprimirNodoDesdeElFinal(Nodo* nodo, int n, int& contador) {
    if (nodo == NULL) {
        return NULL;
    }

    Nodo* siguiente = suprimirNodoDesdeElFinal(nodo->getPunt(), n, contador);
    contador++;

    if (contador == n) {
        Nodo* temporal = nodo->getPunt();
        delete nodo;
        return temporal;
    }

    nodo->setPunt(siguiente);
    return nodo;
}

void removerNodo(Lista &miLista, int n) {
    int contador = 0;
    miLista.setPrimero(suprimirNodoDesdeElFinal(miLista.getPrimero(), n, contador));
}

void gestionarLista(Lista &miLista) {
    int N;
    cout << endl << "Ingrese N para eliminar el nodo a N posiciones del final ";
    cout <<endl<<"Finalizar " << FIN << " para terminar: ";
    cin >> N;

    if (N == FIN) {
        return;
    }

    removerNodo(miLista, N);

    cout << endl << "Lista Nueva:";
    imprimirElementos(miLista.getPrimero());

    gestionarLista(miLista);
}
