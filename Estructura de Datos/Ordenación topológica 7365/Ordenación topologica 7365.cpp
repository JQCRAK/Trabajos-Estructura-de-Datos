/*Jhostin Quispe 7365
Ordenación topológica
*/

using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "GrafoMatriz.h"
#include "Utilidades.h"

// Funciones para trabajar con la representacion de grafo mediante matriz de adyacencia
GrafoMatriz ingresarVerticesMatriz(int n, int current = 0);
void ingresarArcosMatriz(GrafoMatriz *g, int vertice = 0, int arco = 0);
void imprimirGrafoMatriz(GrafoMatriz g, int vertice = 0, int adyacente = 0);
void ordenamientoTopologicoMatriz(GrafoMatriz &g);
void topoRecMatriz(GrafoMatriz &g, int v, bool *visitados, int *pila, int *tope);

// Funciones para trabajar con la representacion de grafo mediante lista de adyacencia
GrafoLista ingresarVerticesLista(int n, int current = 0);
void ingresarArcosLista(GrafoLista *g, int vertice = 0, int arco = 0);
void imprimirGrafoLista(GrafoLista g, int vertice = 0, NodoG *adyacente = NULL);
void ordenamientoTopologicoLista(GrafoLista &g);
void topoRecLista(GrafoLista &g, int v, bool *visitados, int *pila, int *tope);

// Funcion principal
int main() {

    GrafoMatriz a;
    GrafoLista b;
    int n;

    cout << "Ingrese la cantidad de vertices del grafo (Matriz de Adyacencia) ";
    n = leerN(1, 20);
    cin.ignore();
    a = ingresarVerticesMatriz(n);
    
    ingresarArcosMatriz(&a);
    imprimirGrafoMatriz(a);

    cout << "Ordenamiento Topologico (Matriz de Adyacencia): ";
    ordenamientoTopologicoMatriz(a);

    cout << "Ingrese la cantidad de vertices del grafo (Lista de Adyacencia): ";
    n = leerN(1, 20);
    cin.ignore();
    b = ingresarVerticesLista(n);

    ingresarArcosLista(&b);
    imprimirGrafoLista(b);

    cout << "Ordenamiento Topologico (Lista de Adyacencia): ";
    ordenamientoTopologicoLista(b);

}

// Funcion recursiva para ingresar los vertices del grafo representado con matriz de adyacencia
GrafoMatriz ingresarVerticesMatriz(int n, int current) {
    GrafoMatriz a(n);

    if (current < n) {
        TipoG aux;
        cout << endl<<"Ingrese el valor del vertice No. " << (current + 1) << ": ";
        cin >> aux;
        a.nuevoVertice(aux);
        ingresarVerticesMatriz(n, current + 1); // llamada recursiva
    }

    return a;
}

// Funcion recursiva para ingresar los arcos del grafo representado con matriz de adyacencia
void ingresarArcosMatriz(GrafoMatriz *g, int vertice, int arco) {
    int nv = g->getNumVerts();

    if (vertice < nv) {
        Vertice x = g->getVertice(vertice);

        if (arco == 0) {
            cout <<endl<< "Cantidad de arcos de salida del vertice " << x.getDato() << ": ";
        }

        int na = leerN(0, 10);
        cin.ignore();

        if (arco < na) {
            TipoG aux;
            int peso;
            cout << "Identificador del vertice destino: ";
            cin >> aux;
            cout << "Peso del arco: ";
            peso = leerN(0, 100);
            cin.ignore();
            g->setArco(x.getDato(), aux, peso);
            ingresarArcosMatriz(g, vertice, arco + 1); 
        } else {
            ingresarArcosMatriz(g, vertice + 1, 0);
        }
    }
}

// Funcion recursiva para imprimir el grafo representado con matriz de adyacencia
void imprimirGrafoMatriz(GrafoMatriz g, int vertice, int adyacente) {
    int nv = g.getNumVerts();

    if (vertice == 0 && adyacente == 0) {
        cout <<endl<< "MATRIZ DE ADYACENCIA\n";
    }

    if (vertice < nv) {
        Vertice x = g.getVertice(vertice);
        if (adyacente == 0) {
            cout <<endl<< "Vertice " << x.getDato() << ": ";
        }

        if (adyacente < nv) {
            if (g.adyacente(vertice, adyacente)) {
                Vertice y = g.getVertice(adyacente);
                cout << " -> " << y.getDato();
            }
            imprimirGrafoMatriz(g, vertice, adyacente + 1); 
        } else {
            cout << endl;
            imprimirGrafoMatriz(g, vertice + 1, 0); 
        }
    } else if (vertice == nv && adyacente == 0) {
        cout << "===============================================\n";
    }
}

// Funcion recursiva para el ordenamiento topologico en grafo representado con matriz de adyacencia
void topoRecMatriz(GrafoMatriz &g, int v, bool *visitados, int *pila, int *tope) {
    visitados[v] = true;

    for (int i = 0; i < g.getNumVerts(); i++) {
        if (g.adyacente(v, i) && !visitados[i]) {
            topoRecMatriz(g, i, visitados, pila, tope);
        }
    }

    pila[++(*tope)] = v;
}

// Funcion para realizar el ordenamiento topologico en grafo representado con matriz de adyacencia
void ordenamientoTopologicoMatriz(GrafoMatriz &g) {
    int nv = g.getNumVerts();
    bool *visitados = new bool[nv];
    int *pila = new int[nv];
    int tope = -1;

    for (int i = 0; i < nv; i++) {
        visitados[i] = false;
    }

    for (int i = 0; i < nv; i++) {
        if (!visitados[i]) {
            topoRecMatriz(g, i, visitados, pila, &tope);
        }
    }

    while (tope >= 0) {
        cout << g.getVertice(pila[tope]).getDato() << " ";
        tope--;
    }
    cout << endl;

    delete[] visitados;
    delete[] pila;
}

// Funcion recursiva para ingresar los vertices del grafo representado con lista de adyacencia
GrafoLista ingresarVerticesLista(int n, int current) {
    GrafoLista a(n);

    if (current < n) {
        TipoG aux;
        cout << "Ingrese el valor del vertice No. " << (current + 1) << ": ";
        cin >> aux;
        a.nuevoVertice(aux);
        ingresarVerticesLista(n, current + 1);
    }

    return a;
}

// Funcion recursiva para ingresar los arcos del grafo representado con lista de adyacencia
void ingresarArcosLista(GrafoLista *g, int vertice, int arco) {
    int nv = g->getNumVerts();

    if (vertice < nv) {
        Vertice x = g->getVertice(vertice);

        if (arco == 0) {
            cout << "Cantidad de arcos de salida del vertice " << x.getDato() << ": ";
        }

        int na = leerN(0, 10);
        cin.ignore();

        if (arco < na) {
            TipoG aux;
            int peso;
            cout << "Identificador del vertice destino: ";
            cin >> aux;
            cout << "Peso del arco: ";
            peso = leerN(0, 100);
            cin.ignore();
            g->setArco(x.getDato(), aux, peso);
            ingresarArcosLista(g, vertice, arco + 1); 
        } else {
            ingresarArcosLista(g, vertice + 1, 0);
        }
    }
}

// Funcion recursiva para imprimir el grafo representado con lista de adyacencia
void imprimirGrafoLista(GrafoLista g, int vertice, NodoG *adyacente) {
    int nv = g.getNumVerts();

    if (vertice == 0 && adyacente == NULL) {
        cout <<endl<< "LISTA DE ADYACENCIA\n";
    }

    if (vertice < nv) {
        Vertice x = g.getVertice(vertice);
        if (adyacente == NULL) {
            cout << "Vertice " << x.getDato() << ": ";
            adyacente = g.listaAdyacencia(vertice).getPrimero();
        }

        if (adyacente != NULL) {
            cout << " -> " << adyacente->getDato();
            imprimirGrafoLista(g, vertice, adyacente->getPunt()); 
        } else {
            cout << endl;
            imprimirGrafoLista(g, vertice + 1, NULL); 
        }
    } else if (vertice == nv && adyacente == NULL) {
        cout << "===============================================\n";
    }
}

// Funcion recursiva para el ordenamiento topologico en grafo representado con lista de adyacencia
void topoRecLista(GrafoLista &g, int v, bool *visitados, int *pila, int *tope) {
    visitados[v] = true;

    NodoG *adyacente = g.listaAdyacencia(v).getPrimero();
    while (adyacente != NULL) {
        TipoG datoAdyacente = adyacente->getDato();
        int w = g.getNumVertice(datoAdyacente);

        if (!visitados[w]) {
            topoRecLista(g, w, visitados, pila, tope);
        }
        adyacente = adyacente->getPunt(); 
    }

    pila[++(*tope)] = v;
}

// Funcion para realizar el ordenamiento topologico en grafo representado con lista de adyacencia
void ordenamientoTopologicoLista(GrafoLista &g) {
    int nv = g.getNumVerts();
    bool *visitados = new bool[nv];
    int *pila = new int[nv];
    int tope = -1;

    for (int i = 0; i < nv; i++) {
        visitados[i] = false;
    }

    for (int i = 0; i < nv; i++) {
        if (!visitados[i]) {
            topoRecLista(g, i, visitados, pila, &tope);
        }
    }

    while (tope >= 0) {
        cout << g.getVertice(pila[tope]).getDato() << " ";
        tope--;
    }
    cout << endl;

    delete[] visitados;
    delete[] pila;
}


