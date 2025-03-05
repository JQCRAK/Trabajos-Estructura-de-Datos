/*	Jhostin Quispe 7365
Resolver este requerimiento: La teoría de los 6 grados de separación dice que cualquier persona 
en la Tierra puede estar conectado a cualquier otra persona del planeta a través de una cadena de 
conocidos que no tiene más de cinco intermediarios (conectando a ambas personas con solo seis enlaces). 
Suponiendo que se tiene un grafo G en el que cada vértice es una persona y cada arista conecta gente 
que se conoce: Implementar un programa para comprobar si se cumple tal teoría para todo el conjunto 
de personas representadas en el grafo G.
*/
using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "Utilidades.h"
#include "Cola.h"

using namespace std;

int main() {
    system("color f0");
    
    // Prototipos de funciones
    void leerG(GrafoLista* g);
    void imprimirG(GrafoLista g);
    bool comprobar6G(GrafoLista& g);
    int n;

    cout << endl << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO:";
    n = leerN(1, 20); // Definici�n de tama�o de datos a procesar

    GrafoLista g(n); // Crear un grafo con n v�rtices

    cout << endl << "INGRESO DE VERTICES" << endl;
    leerG(&g);

    cout << endl << "INGRESO DE ARCOS" << endl;
    for (int i = 0; i < g.getMaxVerts(); i++) {
        Vertice v = g.getVertice(i);
        int cant;
        cout << " > VERTICE: " << v.getDato() << endl;
        cout << "   Cantidad de arcos de Salida: ";
        cant = leerN(0, g.getMaxVerts() - 1);

        for (int j = 0; j < cant; j++) {
            TipoG dest;
            cout << "   Vertice de destino: ";
            cin >> dest;
            g.setArco(v.getDato(), dest);
        }
    }

    cout << endl << "IMPRESION DE VERTICES" << endl;
    imprimirG(g);

    cout << endl << "COMPROBACION DE LA TEORIA DE LOS 6 GRADOS DE SEPARACION:";
    if (comprobar6G(g)) {
        cout << endl << "La teoria de los 6 grados de separacion se cumple para el grafo dado";
    } else {
        cout << endl << "La teoria de los 6 grados de separacion NO se cumple para el grafo dado";
    }

    return 0;
}

void leerG(GrafoLista* g) {
    TipoG val;

    for (int i = 0; i < g->getMaxVerts(); i++) {
        cout << "Ingrese valor del vertice [" << i << "] :";
        cin >> val;
        g->nuevoVertice(val);
    }
}

void imprimirG(GrafoLista g) {
    for (int i = 0; i < g.getMaxVerts(); i++) {
        Vertice v = g.getVertice(i);
        cout << " Vertice: " << v.getDato() << endl;

        ListaG lista = g.listaAdyacencia(i);
        NodoG* nodo = lista.getPrimero();
        while (nodo != NULL) {
            cout << " -------------->>: " << nodo->getDato() << endl;
            nodo = nodo->getPunt();
        }
    }
}

bool comprobar6G(GrafoLista& g) {
    int numVerts = g.getNumVerts();

    for (int i = 0; i < numVerts; i++) {
        Cola q;
        bool* vis = new bool[numVerts];
        int* dist = new int[numVerts];

        for (int j = 0; j < numVerts; j++) {
            vis[j] = false;
            dist[j] = -1;
        }

        q.insertar(i);
        vis[i] = true;
        dist[i] = 0;

        while (!q.colaVacia()) {
            int vAct = q.quitar();

            ListaG ady = g.listaAdyacencia(vAct);
            NodoG* nodo = ady.getPrimero();

            while (nodo != NULL) {
                int vAdy = g.getNumVertice(nodo->getDato());
                if (!vis[vAdy]) {
                    q.insertar(vAdy);
                    vis[vAdy] = true;
                    dist[vAdy] = dist[vAct] + 1;
                }
                nodo = nodo->getPunt();
            }
        }

        for (int j = 0; j < numVerts; j++) {
            if (dist[j] == -1 || dist[j] > 6) {
                delete[] vis;
                delete[] dist;
                return false;
            }
        }

        delete[] vis;
        delete[] dist;
    }

    return true;
}









