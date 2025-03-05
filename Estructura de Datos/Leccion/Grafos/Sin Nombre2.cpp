/*  Jhostin Quispe 7365
Elaborar un programa recursivo en c++
que haciendo uso de los TDA`s analizadas en clases,
permita generar una lista de los vértices de un grafo ingresado
representando con Lista de Adyacencia ordenada descendentemente
en base a la cantidad de vértices desde los cuales es alcanzable
*/
using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "Utilidades.h"
#include "Lista.h"
#define FIN "FIN"

// Prototipos de funciones
void leerGrafoL(GrafoLista* g);
void imprimirGrafoL(GrafoLista g);
int contarAlcanzables(GrafoLista& g, int v, bool visitado[]);
void ordenarVerticesPorAlcanzables(GrafoLista& g);
void leerGrafoLRecursiva(GrafoLista* g, int i);
void leerArcosRecursiva(GrafoLista* g, int i, int j, int cant, Vertice aux);
void leerGrafoVerticesRecursiva(GrafoLista* g, int i);
void imprimirArcosRecursiva(NodoG* act);
void imprimirGrafoLRecursiva(GrafoLista g, int i);
int contarAlcanzablesRecursivo(GrafoLista& g, int v, bool visitado[]);
int contarAlcanzablesNodo(GrafoLista& g, NodoG* act, bool visitado[]);
void contarAlcanzablesDesdeTodos(GrafoLista& g, int alcanzables[], int i);
int contarAlcanzablesDesdeTodosRecursivo(GrafoLista& g, int i, int j);
void inicializarIndices(int indices[], int i, int n);
void ordenarBurbuja(int alcanzables[], int indices[], int n, int i);
void ordenarBurbujaInterna(int alcanzables[], int indices[], int n, int i, int j);
void imprimirResultados(GrafoLista& g, int alcanzables[], int indices[], int i);


int main() {
    system("color f0");
    int n;
    Lista l;

    cout << endl << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO: " << endl;
    n = leerN(1, 20);

    GrafoLista g(n);

    cout << endl << "INGRESO DE VERTICES" << endl;
    leerGrafoL(&g);

    cout << endl << "VERTICES ORDENADOS POR ALCANZABILIDAD" << endl;
    ordenarVerticesPorAlcanzables(g);

    return 0;
}

void leerGrafoLRecursiva(GrafoLista* g, int i) {
    if (i >= g->getMaxVerts()) {
        return;
    }

    TipoG val;
    cout << endl << "Ingrese valor del vértice [" << g->getNumVerts() << "] :";
    cin >> val;
    g->nuevoVertice(val);

    leerGrafoLRecursiva(g, i + 1);
}

void leerArcosRecursiva(GrafoLista* g, int i, int j, int cant, Vertice aux) {
    if (j > cant) {
        return;
    }

    TipoG vl;
    cout << endl << "   Vértice de destino: ";
    cin >> vl;
    int peso;
    cout << endl << "    Peso del arco: ";
    peso = leerN(0, 100);
    g->setArco(aux.getDato(), vl, peso);

    leerArcosRecursiva(g, i, j + 1, cant, aux);
}

void leerGrafoL(GrafoLista* g) {
    leerGrafoLRecursiva(g, 0);
    leerGrafoVerticesRecursiva(g, 0);
}

void leerGrafoVerticesRecursiva(GrafoLista* g, int i) {
    if (i >= g->getMaxVerts()) {
        return;
    }

    Vertice aux = g->getVertice(i);
    cout << endl << " > VERTICE: " << aux.getDato();
    cout << endl << "   Cantidad de arcos de Salida: ";
    int cant = leerN(0, g->getMaxVerts() - 1);
    leerArcosRecursiva(g, i, 1, cant, aux);

    leerGrafoVerticesRecursiva(g, i + 1);
}

void imprimirArcosRecursiva(NodoG* act) {
    if (act == NULL) {
        return;
    }

    cout << endl << " -------------->>: " << act->getDato();
    cout << endl << "  ------------->> Peso: " << act->getPeso();
    imprimirArcosRecursiva(act->getPunt());
}

void imprimirGrafoLRecursiva(GrafoLista g, int i) {
    if (i >= g.getMaxVerts()) {
        return;
    }

    Vertice aux = g.getVertice(i);
    cout << endl << " Vértice: " << aux.getDato();
    ListaG l = g.listaAdyacencia(i);
    NodoG* act = l.getPrimero();
    imprimirArcosRecursiva(act);

    imprimirGrafoLRecursiva(g, i + 1);
}

void imprimirGrafoL(GrafoLista g) {
    imprimirGrafoLRecursiva(g, 0);
}

int contarAlcanzables(GrafoLista& g, int v, bool visitado[]) {
    visitado[v] = true;
    return 1 + contarAlcanzablesRecursivo(g, v, visitado);
}

int contarAlcanzablesRecursivo(GrafoLista& g, int v, bool visitado[]) {
    ListaG adyacentes = g.listaAdyacencia(v);
    NodoG* act = adyacentes.getPrimero();
    return contarAlcanzablesNodo(g, act, visitado);
}

int contarAlcanzablesNodo(GrafoLista& g, NodoG* act, bool visitado[]) {
    if (act == NULL) {
        return 0;
    }

    TipoG adyacente = act->getDato();
    int adyacenteIndex = g.getNumVertice(adyacente);
    int count = 0;

    if (!visitado[adyacenteIndex]) {
        count = contarAlcanzables(g, adyacenteIndex, visitado);
    }

    return count + contarAlcanzablesNodo(g, act->getPunt(), visitado);
}

void contarAlcanzablesDesdeTodos(GrafoLista& g, int alcanzables[], int i) {
    if (i >= g.getMaxVerts()) {
        return;
    }

    alcanzables[i] = contarAlcanzablesDesdeTodosRecursivo(g, i, 0);
    contarAlcanzablesDesdeTodos(g, alcanzables, i + 1);
}

int contarAlcanzablesDesdeTodosRecursivo(GrafoLista& g, int i, int j) {
    if (j >= g.getMaxVerts()) {
        return 0;
    }

    if (i == j) {
        return contarAlcanzablesDesdeTodosRecursivo(g, i, j + 1);
    }

    bool visitadoTemp[g.getMaxVerts()] = {false};
    int count = contarAlcanzables(g, j, visitadoTemp) - 1; // No contar el propio vértice
    
    return (visitadoTemp[i] ? 1 : 0) + contarAlcanzablesDesdeTodosRecursivo(g, i, j + 1);
}

void ordenarVerticesPorAlcanzables(GrafoLista& g) {
    int n = g.getMaxVerts();
    int alcanzables[n];
    int indices[n];

    contarAlcanzablesDesdeTodos(g, alcanzables, 0);
    inicializarIndices(indices, 0, n);
    ordenarBurbuja(alcanzables, indices, n, 0);
    imprimirResultados(g, alcanzables, indices, 0);
}

void inicializarIndices(int indices[], int i, int n) {
    if (i >= n) {
        return;
    }
    indices[i] = i;
    inicializarIndices(indices, i + 1, n);
}

void ordenarBurbuja(int alcanzables[], int indices[], int n, int i) {
    if (i >= n - 1) {
        return;
    }
    ordenarBurbujaInterna(alcanzables, indices, n, i, 0);
    ordenarBurbuja(alcanzables, indices, n, i + 1);
}

void ordenarBurbujaInterna(int alcanzables[], int indices[], int n, int i, int j) {
    if (j >= n - i - 1) {
        return;
    }
    if (alcanzables[j] < alcanzables[j+1]) {
        swap(alcanzables[j], alcanzables[j+1]);
        swap(indices[j], indices[j+1]);
    }
    ordenarBurbujaInterna(alcanzables, indices, n, i, j + 1);
}

void imprimirResultados(GrafoLista& g, int alcanzables[], int indices[], int i) {
    if (i >= g.getMaxVerts()) {
        return;
    }
    cout << "V" << indices[i] + 1 << ": alcanzable desde " << alcanzables[i] << " vertices" << endl;
    imprimirResultados(g, alcanzables, indices, i + 1);
}
