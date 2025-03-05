//Algoritmo Dijkstra incompleto
using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "Utilidades.h"
#include "Lista.h"

// Prototipos de funciones
void leerGrafoL(GrafoLista* g);
void imprimirGrafoL(GrafoLista g);
void dijkstra(GrafoLista& g, int inicio);

int main() {
    system("color f0");
    int n;

    cout << endl << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO: " << endl;
    n = leerN(1, 20);  // Solicitar al usuario la cantidad de vértices

    GrafoLista g(n);  // Crear un grafo con n vértices

    cout << endl << "INGRESO DE VERTICES" << endl;
    leerGrafoL(&g);

    cout << endl << "IMPRESION DE VERTICES" << endl;
    imprimirGrafoL(g);

    // Ejecutar el algoritmo de Dijkstra desde el vértice 0
    dijkstra(g, 0);

    return 0;
}

void leerGrafoL(GrafoLista* g) {
    string val;

    for (int i = 0; i < g->getMaxVerts(); ++i) {
        cout << endl << "Ingrese valor del vértice [" << g->getNumVerts() << "] :";
        cin >> val;
        g->nuevoVertice(val);
    }

    for (int i = 0; i < g->getMaxVerts(); ++i) {
        Vertice aux;
        int cant;
        aux = g->getVertice(i);
        cout << endl << " > VÉRTICE: " << aux.getDato();
        cout << endl << "   Cantidad de arcos de salida: ";
        cant = leerN(0, g->getMaxVerts() - 1);

        for (int j = 1; j <= cant; ++j) {
            string vl;
            cout << endl << "   Vértice de destino: ";
            cin >> vl;
            int peso;
            cout << endl << "   Peso del arco: ";
            peso = leerN(0, 100);
            g->setArco(aux.getDato(), vl, peso);
        }
    }
}

void imprimirGrafoL(GrafoLista g) {
    for (int i = 0; i < g.getMaxVerts(); ++i) {
        Vertice aux;
        aux = g.getVertice(i);
        cout << endl << " Vértice: " << aux.getDato();
        
        ListaG l;
        l = g.listaAdyacencia(i);
        NodoG* act;
        act = l.getPrimero();
        while (act != NULL) {
            cout << endl << " -------------->>: " << act->getDato();
            cout << endl << "  ------------->> Peso: " << act->getPeso();
            act = act->getPunt();
        }
    }
}

void dijkstra(GrafoLista& g, int inicio) {
    vector<int> distancias(g.getMaxVerts(), INT_MAX);  
    vector<bool> visitados(g.getMaxVerts(), false);    

    distancias[inicio] = 0;

    // Algoritmo de Dijkstra
    for (int count = 0; count < g.getMaxVerts() - 1; ++count) {
        int minDistancia = INT_MAX;
        int minIndex = -1;
        for (int v = 0; v < g.getMaxVerts(); ++v) {
            if (!visitados[v] && distancias[v] <= minDistancia) {
                minDistancia = distancias[v];
                minIndex = v;
            }
        }

        visitados[minIndex] = true;

        ListaG l = g.listaAdyacencia(minIndex);
        NodoG* act = l.getPrimero();
        while (act != nullptr) {
            int v = g.indice(act->getDato());  
            int peso = act->getPeso();
            if (!visitados[v] && distancias[minIndex] != INT_MAX && distancias[minIndex] + peso < distancias[v]) {
                distancias[v] = distancias[minIndex] + peso;
            }
            act = act->getPunt();
        }
    }

    cout << endl << "Distancias mínimas desde el vértice " << inicio << endl;
    for (int i = 0; i < g.getMaxVerts(); ++i) {
        cout << "Distancia más corta desde " << inicio << " a " << i << " es " << distancias[i] << endl;
    }
}

