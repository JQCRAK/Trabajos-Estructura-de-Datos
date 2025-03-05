/*Jhostin Quispe 7365
Determinar el vértice que posee el mayor grado de entrada y el vértice que posee el mayor grado de salida 
dentro de un grafo ingresado por el usuario.
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
void encontrarGrados(GrafoMatriz g, int i, int j, int &maxEntrada, int &maxSalida, TipoG &verticeMaxEntrada, TipoG &verticeMaxSalida, int *entradas, int *salidas);

int main(){ // Programa principal
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

    int maxEntrada = -1, maxSalida = -1;
    TipoG verticeMaxEntrada, verticeMaxSalida;
    int entradas[g.getMaxVerts()] = {0};
    int salidas[g.getMaxVerts()] = {0};

    encontrarGrados(g, 0, 0, maxEntrada, maxSalida, verticeMaxEntrada, verticeMaxSalida, entradas, salidas);

    cout << endl << "VERTICE CON MAYOR GRADO DE ENTRADA: " << verticeMaxEntrada << " (Grado: " << maxEntrada << ")";
    cout << endl << "VERTICE CON MAYOR GRADO DE SALIDA: " << verticeMaxSalida << " (Grado: " << maxSalida << ")";
}

void leerGrafoM(GrafoMatriz* g, int i){ // Funcion de ingreso de vertices de un grafo
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

void leerArcos(GrafoMatriz* g, int i, int j, int cant){
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
    int peso;
    cout << endl << "    Peso del arco: ";
    peso = leerN(0, 100);
    g->setArco(g->getVertice(i).getDato(), vl, peso);

    leerArcos(g, i, j + 1, cant);
}

void imprimirGrafoM(GrafoMatriz g, int i){ // Funcion de impresion de vertices de un grafo
    if (i >= g.getMaxVerts()) return;

    Vertice aux = g.getVertice(i);
    cout << endl << " > " << aux.getDato();

    imprimirArcos(g, i, 0);
    imprimirGrafoM(g, i + 1);
}

void imprimirArcos(GrafoMatriz g, int i, int j){
    if (j >= g.getMaxVerts()) return;

    Vertice aux2 = g.getVertice(j);
    if (g.adyacente(i, j)) {
        cout << endl << "    Adyacente con: " << aux2.getDato();
        cout << endl << "---------------> Peso: " << g.getArco(i, j);
    }
    imprimirArcos(g, i, j + 1);
}

void encontrarGrados(GrafoMatriz g, int i, int j, int &maxEntrada, int &maxSalida, TipoG &verticeMaxEntrada, TipoG &verticeMaxSalida, int *entradas, int *salidas) {
    int n = g.getMaxVerts();

    if (i >= n) {
        for (int k = 0; k < n; ++k) {
            if (entradas[k] > maxEntrada) {
                maxEntrada = entradas[k];
                verticeMaxEntrada = g.getVertice(k).getDato();
            }
            if (salidas[k] > maxSalida) {
                maxSalida = salidas[k];
                verticeMaxSalida = g.getVertice(k).getDato();
            }
        }
        return;
    }

    if (j >= n) {
        encontrarGrados(g, i + 1, 0, maxEntrada, maxSalida, verticeMaxEntrada, verticeMaxSalida, entradas, salidas);
        return;
    }

    if (g.adyacente(j, i)) {
        entradas[i]++;
    }
    if (g.adyacente(i, j)) {
        salidas[i]++;
    }

    encontrarGrados(g, i, j + 1, maxEntrada, maxSalida, verticeMaxEntrada, verticeMaxSalida, entradas, salidas);
}

