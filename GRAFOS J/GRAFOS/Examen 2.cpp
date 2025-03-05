/*	Jhostin Quispe 7365
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

int main() { // Programa principal
    system("color f0");
    int n;
    Lista l;

    cout << endl << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO: " << endl;
    n = leerN(1, 20); // Solicitar al usuario definición de tamaño de datos a procesar

    GrafoLista g(n); // Crear un grafo con n vértices

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

    for (int i = 0; i < g->getMaxVerts(); i++) {
        Vertice aux = g->getVertice(i);
        cout << endl << " > VERTICE: " << aux.getDato();
        cout << endl << "   Cantidad de arcos de Salida: ";
        int cant = leerN(0, g->getMaxVerts() - 1);
        leerArcosRecursiva(g, i, 1, cant, aux);
    }
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
    int count = 1;

    ListaG adyacentes = g.listaAdyacencia(v); // Obtener lista de adyacencia
    NodoG* act = adyacentes.getPrimero();

    while (act != NULL) {
        TipoG adyacente = act->getDato();
        int adyacenteIndex = g.getNumVertice(adyacente);
        if (!visitado[adyacenteIndex]) {
            count += contarAlcanzables(g, adyacenteIndex, visitado);
        }
        act = act->getPunt();
    }
    return count;
}

void contarAlcanzablesDesdeTodos(GrafoLista& g, int alcanzables[]) {
    int n = g.getMaxVerts();
    for (int i = 0; i < n; ++i) {
        bool visitado[n] = {false};
        alcanzables[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                bool visitadoTemp[n] = {false};
                int count = contarAlcanzables(g, j, visitadoTemp) - 1; // No contar el propio vértice
                if (visitadoTemp[i]) {
                    alcanzables[i]++;
                }
            }
        }
    }
}

void ordenarVerticesPorAlcanzables(GrafoLista& g) {
    int n = g.getMaxVerts();
    int alcanzables[n];
    int indices[n];

    contarAlcanzablesDesdeTodos(g, alcanzables);

    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }

    // Ordenar en orden descendente por cantidad de vértices alcanzables usando un algoritmo de burbuja
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (alcanzables[j] < alcanzables[j+1]) {
                swap(alcanzables[j], alcanzables[j+1]);
                swap(indices[j], indices[j+1]);
            }
        }
    }

    // Imprimir resultados
    for (int i = 0; i < n; ++i) {
        cout << "V" << indices[i] + 1 << ": alcanzable desde " << alcanzables[i] << " vertices" << endl;
    }
}
