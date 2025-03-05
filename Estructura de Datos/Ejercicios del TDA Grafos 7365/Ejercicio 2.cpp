/*Jhostin Quispe 7365
Determinar los vértices que se encuentran a exactamente N arcos de distancia del vértice V 
(n y V deben ser ingresados por el usuario).
*/

using namespace std;

#include <iostream>
#include "GrafoMatriz.h"
#include "Utilidades.h"
#include "Lista.h"
#define FIN "FIN"

// Prototipos de funciones
void leerGrafoM(GrafoMatriz* g, int i);
void leerArcos(GrafoMatriz* g, int i, int j, int cant);
void imprimirGrafoM(GrafoMatriz g, int i);
void imprimirArcos(GrafoMatriz g, int i, int j);
void encontrarVerticesNArcos(GrafoMatriz g, TipoG vertice, int N, int actualN, bool* visitados, TipoG* resultado, int& resCount);

int main() { // Programa principal
    system("color f0");

    int n;
    cout << endl << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO: " << endl;
    n = leerN(1, 20); // Solicitar al usuario definicion de tamanio de datos a procesar
    Lista l;

    GrafoMatriz g(n); // Crear un grafo con n vertices

    cout << endl << "INGRESO DE VERTICES" << endl;
    leerGrafoM(&g, 0);

    cout << endl << "IMPRESION DE VERTICES" << endl;
    imprimirGrafoM(g, 0);

    TipoG V;
    int N;
    cout << endl << "INGRESE EL VÉRTICE INICIAL: ";
    cin >> V;
    cout << endl << "INGRESE LA DISTANCIA (N): ";
    N = leerN(1, n);

    bool* visitados = new bool[n];
    TipoG* resultado = new TipoG[n];
    int resCount = 0;

    for (int i = 0; i < n; ++i) {
        visitados[i] = false;
    }

    encontrarVerticesNArcos(g, V, N, 0, visitados, resultado, resCount);

    cout << endl << "VÉRTICES A EXACTAMENTE " << N << " ARCOS DE DISTANCIA DEL VÉRTICE " << V << ":";
    for (int i = 0; i < resCount; ++i) {
        cout << " - " << resultado[i];
    }

    delete[] visitados;
    delete[] resultado;
}

void leerGrafoM(GrafoMatriz* g, int i) { // Funcion de ingreso de vertices de un grafo
    if (i >= g->getMaxVerts()) {
        leerArcos(g, 0, 0, 0);
        return;
    }

    TipoG val;
    cout << endl << "Ingrese valor del vertice [" << g->getNumVerts() << "] :";
    cin >> val; // Lectura
    g->nuevoVertice(val); // Ingreso del nuevo vertice al grafo

    leerGrafoM(g, i + 1);
}

void leerArcos(GrafoMatriz* g, int i, int j, int cant) {
    if (i >= g->getMaxVerts()) return;
    if (j == 0) {
        Vertice aux = g->getVertice(i);
        cout << endl << " > VERTICE: " << aux.getDato();
        cout << endl << "   Cantidad de arcos de Salida: ";
        cant = leerN(0, g->getMaxVerts() - 1);
    }
    if (j >= cant) {
        leerArcos(g, i + 1, 0, 0);
        return;
    }

    TipoG vl;
    cout << endl << "   Vertice de destino: ";
    cin >> vl; // Lectura
    g->setArco(g->getVertice(i).getDato(), vl);

    leerArcos(g, i, j + 1, cant);
}

void imprimirGrafoM(GrafoMatriz g, int i) { // Funcion de impresion de vertices de un grafo
    if (i >= g.getMaxVerts()) return;

    Vertice aux = g.getVertice(i);
    cout << endl << " > " << aux.getDato();

    imprimirArcos(g, i, 0);
    imprimirGrafoM(g, i + 1);
}

void imprimirArcos(GrafoMatriz g, int i, int j) {
    if (j >= g.getMaxVerts()) return;

    Vertice aux2 = g.getVertice(j);
    if (g.adyacente(i, j)) {
        cout << endl << "    Adyacente con: " << aux2.getDato();
    }
    imprimirArcos(g, i, j + 1);
}

void encontrarVerticesNArcos(GrafoMatriz g, TipoG vertice, int N, int actualN, bool* visitados, TipoG* resultado, int& resCount) {
    if (actualN == N) {
        resultado[resCount++] = vertice;
        return;
    }

    int index = g.getNumVertice(vertice);
    if (index == -1) return;

    visitados[index] = true;

    for (int j = 0; j < g.getMaxVerts(); ++j) {
        if (g.adyacente(index, j) && !visitados[j]) {
            encontrarVerticesNArcos(g, g.getVertice(j).getDato(), N, actualN + 1, visitados, resultado, resCount);
        }
    }

    visitados[index] = false;
}

