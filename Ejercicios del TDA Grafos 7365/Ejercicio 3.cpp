/*Jhostin 7365
Resolver este requerimiento: Supóngase que se cuenta con un grafo que modela un ecosistema. 
En dicho grafo, cada vértice es una especie, y cada arco (v, w) indica que v es depredador natural de w. 
Considerando la horrible tendencia del ser humano por llevar a la extinción especies, algo que puede 
interesar es saber si existe alguna especie que, si llegara a desaparecer, rompería todo el ecosistema: 
quienes la depredan no tienen un sustituto (y, por ende, pueden desaparecer también) y/o quienes eran depredados 
por esta ya no tienen amenazas, por lo que crecerán descontroladamente. Implementar un programa que permita ingresar 
el grafo de dichas características y devuelva una lista de todas las especies que cumplan lo antes mencionado.
*/

using namespace std;

#include <iostream>
#include "GrafoLista.h"
#include "Utilidades.h"
#include "Lista.h"
#define FIN "FIN"

// Prototipos de funciones
void leerGrafoL(GrafoLista* g);
void leerArcos(GrafoLista* g);
void imprimirGrafoL(GrafoLista g);
void encontrarEspeciesCriticas(GrafoLista g);

bool esDepredadorSinSustituto(GrafoLista& g, int depredador);
bool esPresaSinAmenaza(GrafoLista& g, int presa);

int main() { // Programa principal
    system("color f0");
    int n;

    cout << endl << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO: " << endl;
    n = leerN(1, 20); // Solicitar al usuario definicion de tamanio de datos a procesar

    GrafoLista g(n); // Crear un grafo con n vertices

    cout << endl << "INGRESO DE VERTICES" << endl;
    leerGrafoL(&g);

    cout << endl << "IMPRESION DE VERTICES" << endl;
    imprimirGrafoL(g);

    cout << endl << "ESPECIES CRITICAS QUE ROMPERIAN EL ECOSISTEMA: " << endl;
    encontrarEspeciesCriticas(g);

    return 0;
}

void leerGrafoL(GrafoLista* g) { // Funcion de ingreso de vertices de un grafo
    TipoG val;

    for (int i = 0; i < g->getMaxVerts(); i++) { // Ciclo de conteo de vertices 
        cout << endl << "Ingrese valor del vertice [" << g->getNumVerts() << "] :";
        cin >> val; // Lectura
        g->nuevoVertice(val); // Ingreso del nuevo vertice al grafo
    }

    leerArcos(g);
}

void leerArcos(GrafoLista* g) {
    for (int i = 0; i < g->getMaxVerts(); i++) { // Ciclo de recorrido de vertices
        Vertice aux = g->getVertice(i);
        int cant; // Cantidad de arcos
        cout << endl << " > VERTICE: " << aux.getDato();
        cout << endl << "   Cantidad de arcos de Salida: ";
        cant = leerN(0, g->getMaxVerts() - 1);

        for (int j = 0; j < cant; j++) { // Ciclo de recorrido de cada arco de salida
            TipoG vl;
            cout << endl << "   Vertice de destino: ";
            cin >> vl; // Lectura
            g->setArco(aux.getDato(), vl);
        }
    }
}

void imprimirGrafoL(GrafoLista g) { // Funcion de impresion de vertices de un grafo
    for (int i = 0; i < g.getMaxVerts(); i++) { // Ciclo de conteo de vertices 
        Vertice aux = g.getVertice(i);
        cout << endl << " Vertice: " << aux.getDato();

        // Impresion de arcos
        ListaG l = g.listaAdyacencia(i);
        NodoG* act = l.getPrimero();
        while (act != NULL) { // Ciclo que se repite mientras apuntador no es null
            cout << endl << " -------------->>: " << act->getDato();
            act = act->getPunt();
        }
    }
}

bool esDepredadorSinSustituto(GrafoLista& g, int depredador) {
    for (int i = 0; i < g.getMaxVerts(); ++i) {
        if (g.adyacente(depredador, i)) {
            // Verificar si hay otro depredador para la presa i
            bool tieneOtroDepredador = false;
            for (int j = 0; j < g.getMaxVerts(); ++j) {
                if (j != depredador && g.adyacente(j, i)) {
                    tieneOtroDepredador = true;
                    break;
                }
            }
            if (!tieneOtroDepredador) {
                return true;
            }
        }
    }
    return false;
}

bool esPresaSinAmenaza(GrafoLista& g, int presa) {
    for (int i = 0; i < g.getMaxVerts(); ++i) {
        if (g.adyacente(i, presa)) {
            // Verificar si hay otro depredador para la presa
            bool tieneOtroDepredador = false;
            for (int j = 0; j < g.getMaxVerts(); ++j) {
                if (j != i && g.adyacente(j, presa)) {
                    tieneOtroDepredador = true;
                    break;
                }
            }
            if (!tieneOtroDepredador) {
                return true;
            }
        }
    }
    return false;
}

void encontrarEspeciesCriticas(GrafoLista g) {
    for (int i = 0; i < g.getMaxVerts(); ++i) {
        if (esDepredadorSinSustituto(g, i) || esPresaSinAmenaza(g, i)) {
            cout << g.getVertice(i).getDato() << " ";
        }
    }
    cout << endl;
}

