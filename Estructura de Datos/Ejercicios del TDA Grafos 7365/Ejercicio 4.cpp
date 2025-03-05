/*Jhostin Quipe 7365
Resolver este requerimiento: Una persona quiere recorrer un museo. 
Su idea es hacer un recorrido bastante lógico: empezar en una sala (al azar), 
luego ir a una adyacente a ésta, luego a una adyacente a la segunda (si no fue visitada aún), 
y así hasta recorrer todas las salas. Cuando no tiene más salas adyacentes para visitar (porque ya fueron todas visitadas),
simplemente vuelve por donde vino buscando otras salas adyacentes. 
Teniendo un grafo que representa el mapa del museo (donde los vértices son salas, y los arcos (v, w) 
indican que las salas v y w se encuentran conectadas). Implementar un programa que devuelva una lista con 
un recorrido posible de la idea de aquella persona para visitar las salas del museo.	
*/
using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "Pila.h"
#include "Utilidades.h"

int main() {
    system("color f0");

    // Prototipos de funciones
	void leerG(GrafoLista* g);
	void leerA(GrafoLista* g);
	void imprimirG(GrafoLista g);
	void recorrerM(GrafoLista& g, TipoG inicio);

    int numVertices;

    cout << endl << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO: " << endl;
    numVertices = leerN(1, 20); // Solicitar al usuario definicion de tamanio de datos a procesar

    GrafoLista g(numVertices); // Crear un grafo con numVertices vertices

    cout << endl << "INGRESO DE VERTICES" << endl;
    leerG(&g);

    cout << endl << "IMPRESION DE VERTICES" << endl;
    imprimirG(g);

    cout << endl << "RECORRIDO DEL MUSEO: " << endl;
    TipoG inicio;
    cout << "Ingrese el vertice inicial: ";
    cin >> inicio;
    recorrerM(g, inicio);

    return 0;
}

void leerA(GrafoLista* g) {
    for (int i = 0; i < g->getMaxVerts(); i++) {
        Vertice v = g->getVertice(i);
        int numArcos;
        cout << endl << " > VERTICE: " << v.getDato();
        cout << endl << "   Cantidad de arcos de Salida: ";
        numArcos = leerN(0, g->getMaxVerts() - 1);

        for (int j = 0; j < numArcos; j++) {
            TipoG destino;
            cout << endl << "   Vertice de destino: ";
            cin >> destino;
            g->setArco(v.getDato(), destino);
        }
    }
}

void leerG(GrafoLista* g) {
    TipoG valor;

    for (int i = 0; i < g->getMaxVerts(); i++) {
        cout << endl << "Ingrese valor del vertice [" << g->getNumVerts() << "] :";
        cin >> valor;
        g->nuevoVertice(valor);
    }

    leerA(g);
}

void imprimirG(GrafoLista g) {
    for (int i = 0; i < g.getMaxVerts(); i++) {
        Vertice v = g.getVertice(i);
        cout << endl << " Vertice: " << v.getDato();

        ListaG lista = g.listaAdyacencia(i);
        NodoG* nodo = lista.getPrimero();
        while (nodo != NULL) {
            cout << endl << " -------------->>: " << nodo->getDato();
            nodo = nodo->getPunt();
        }
    }
}

void recorrerM(GrafoLista& g, TipoG inicio) {
    int numVerts = g.getMaxVerts();
    bool* visitados = new bool[numVerts];
    for (int i = 0; i < numVerts; ++i) {
        visitados[i] = false;
    }

    Pila pila;
    pila.push(g.getNumVertice(inicio));
    visitados[g.getNumVertice(inicio)] = true;
    cout << inicio << " ";

    while (!pila.pilaVacia()) {
        int verticeActual = pila.cimaPila(); // Obtener el vertice en la cima de la pila
        ListaG adyacentes = g.listaAdyacencia(verticeActual);
        NodoG* nodo = adyacentes.getPrimero();
        bool encontrado = false;

        while (nodo != NULL) {
            int verticeAdyacente = g.getNumVertice(nodo->getDato());
            if (!visitados[verticeAdyacente]) {
                pila.push(verticeAdyacente);
                visitados[verticeAdyacente] = true;
                cout << nodo->getDato() << " ";
                encontrado = true;
                break;
            }
            nodo = nodo->getPunt();
        }

        if (!encontrado) {
            pila.pop(); // Eliminar el vertice si no se encontraron adyacentes no visitados
        }
    }

    delete[] visitados;
    cout << endl;
}

