using namespace std;

#include <iostream>
#include "GrafoMatriz.h"
#include "Utilidades.h"
#include "Lista.h"
#define FIN "FIN"
#define INFINITO 9999

void leerGrafoM(GrafoMatriz* g);    // prototipo de funci�n de ingreso de v�rtices de un grafo
void imprimirGrafoM(GrafoMatriz g); // prototipo de funci�n de imprimir v�rtices de un grafo
void dijkstra(GrafoMatriz& g, int origen); // prototipo de funci�n para el algoritmo de Dijkstra

int main() { // programa principal
    system("color f0");

    int n;

    cout << endl << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO: " << endl;
    n = leerN(1, 20); // solicitar al usuario definici�n de tama�o de datos a procesar
    Lista l;

    GrafoMatriz g(n); // crear un grafo con n v�rtices

    cout << endl << "INGRESO DE VERTICES" << endl;
    leerGrafoM(&g);

    cout << endl << "IMPRESION DE VERTICES" << endl;
    imprimirGrafoM(g);

    cout << endl << "EJECUTANDO ALGORITMO DE DIJKSTRA" << endl;
    dijkstra(g, 0); // Ejecutar Dijkstra desde el v�rtice 0

    return 0;
}

void leerGrafoM(GrafoMatriz* g) { // funci�n de ingreso de v�rtices de un grafo
    TipoG val;

    for (int i = 0; i < g->getMaxVerts(); i++) { // ciclo de conteo de v�rtices
        cout << endl << "Ingrese valor del vertice [" << g->getNumVerts() << "] :";
        cin >> val; // lectura
        g->nuevoVertice(val); // ingreso del nuevo v�rtice al grafo
    }

    // Arcos
    for (int i = 0; i < g->getMaxVerts(); i++) { // ciclo de recorrido de v�rtices
        Vertice aux; // v�rtice auxiliar para impresi�n
        int cant; // cantidad de arcos
        aux = g->getVertice(i);
        cout << endl << " > VERTICE: " << aux.getDato();
        cout << endl << "   Cantidad de arcos de Salida: ";
        cant = leerN(0, g->getMaxVerts() - 1);

        for (int j = 1; j <= cant; j++) { // ciclo de recorrido de cada arco de salida
            TipoG vl;
            cout << endl << "   Vertice de destino: ";
            cin >> vl; // lectura
            int peso;
            cout << endl << "    Peso del arco: ";
            peso = leerN(0, 100);
            g->setArco(aux.getDato(), vl, peso);
        }
    }
}

void imprimirGrafoM(GrafoMatriz g) { // funci�n de imprimir v�rtices de un grafo
    for (int i = 0; i < g.getMaxVerts(); i++) { // ciclo de conteo de v�rtices
        Vertice aux; // v�rtice auxiliar para impresi�n
        aux = g.getVertice(i);
        cout << endl << " > " << aux.getDato();

        // impresi�n de arcos
        for (int j = 0; j < g.getMaxVerts(); j++) {
            Vertice aux2; // v�rtice auxiliar para impresi�n
            aux2 = g.getVertice(j);

            if (g.adyacente(i, j)) {
                cout << endl << "    Adyacente con: " << aux2.getDato();
                cout << endl << "---------------> Peso: " << g.getArco(i, j);
            }
        }
    }
}

void dijkstra(GrafoMatriz& g, int origen) {
    int n = g.getMaxVerts();
    int dist[n]; 
    bool visitado[n]; 
    int prev[n];

    // Inicializaci�n
    for (int i = 0; i < n; i++) {
        dist[i] = INFINITO;
        visitado[i] = false;
        prev[i] = -1;
    }
    dist[origen] = 0;

    for (int i = 0; i < n; i++) {
        // Encontrar el v�rtice con la distancia m�nima que no haya sido visitado
        int u = -1;
        int minDist = INFINITO;
        for (int j = 0; j < n; j++) {
            if (!visitado[j] && dist[j] < minDist) {
                u = j;
                minDist = dist[j];
            }
        }

        if (u == -1) break; // todos los v�rtices alcanzables ya fueron visitados

        visitado[u] = true;

        // Actualizar distancias de los vecinos del v�rtice seleccionado
        for (int v = 0; v < n; v++) {
            if (g.adyacente(u, v) && !visitado[v]) {
                int alt = dist[u] + g.getArco(u, v);
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                }
            }
        }
    }

    // Imprimir resultados
    for (int i = 0; i < n; i++) {
        if (dist[i] == INFINITO) {
            cout << "No hay camino desde " << origen << " a " << i << endl;
        } else {
            cout << "Distancia m�s corta desde " << origen << " a " << i << " es " << dist[i] << endl;
            cout << "Camino: ";
            int v = i;
            while (v != -1) {
                cout << v << " ";
                v = prev[v];
            }
            cout << endl;
        }
    }
}


