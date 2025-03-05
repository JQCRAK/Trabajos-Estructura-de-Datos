//Jhostin Quispe 7365

using namespace std;

#include <iostream>
#include "GrafoMatriz.h"
#include "Utilidades.h"
#include "Lista.h"
#define FIN "FIN"

// Prototipos de funciones
void mostrarMenu();
void leerGrafo(GrafoMatriz &g);
void imprimirGrafo(GrafoMatriz &g);
void aplicarAnclaje(GrafoMatriz &g);
void aplicarReframing(GrafoMatriz &g);
void procesarComando(string comando, GrafoMatriz &g);

int main() {
    system("color f0");

    int n;
    cout << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO: ";
    n = leerN(1, 20);   // Solicitar al usuario definicion de tamaño de datos a procesar

    GrafoMatriz g(n);   // Crear un grafo con n vertices

    cout << endl << "INGRESO DE VERTICES" << endl;
    leerGrafo(g);

    cout << endl << "=== Simulador de PNL ===" << endl;
    mostrarMenu();    // Mostrar el menu inicial

    string comando;
    do {
        cout << endl << "Ingrese un comando (o '" << FIN << "' para terminar): ";
        cin >> comando;

        if (comando == FIN) {
            break;  // Terminar el bucle si se ingresa FIN
        }

        procesarComando(comando, g);  // Procesar el comando ingresado
    } while (true);

    cout << "Programa terminado." << endl;

    return 0;
}

void mostrarMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Mostrar Grafo" << endl;
    cout << "2. Aplicar Tecnica PNL: Anclaje" << endl;
    cout << "3. Aplicar Tecnica PNL: Reframing" << endl;
    cout << "4. Salir" << endl;
    cout << "=================" << endl;
}

void leerGrafo(GrafoMatriz &g) {
    TipoG val;

    for (int i = 0; i < g.getMaxVerts(); ++i) {
        cout << "Ingrese valor del vertice [" << g.getNumVerts() << "]: ";
        cin >> val;
        g.nuevoVertice(val);
    }

    // Ingreso de arcos
    for (int i = 0; i < g.getMaxVerts(); ++i) {
        Vertice aux = g.getVertice(i);
        int cant;

        cout << " > Vertice: " << aux.getDato() << endl;
        cout << "   Cantidad de arcos de salida: ";
        cant = leerN(0, g.getMaxVerts() - 1);

        for (int j = 0; j < cant; ++j) {
            TipoG vl;
            int peso;

            cout << "   Vertice de destino: ";
            cin >> vl;

            cout << "   Peso del arco: ";
            peso = leerN(0, 100);

            g.setArco(aux.getDato(), vl, peso);
        }
    }
}

void imprimirGrafo(GrafoMatriz &g) {
    for (int i = 0; i < g.getMaxVerts(); ++i) {
        Vertice aux = g.getVertice(i);
        cout << " > " << aux.getDato() << endl;

        for (int j = 0; j < g.getMaxVerts(); ++j) {
            if (g.adyacente(i, j)) {
                Vertice aux2 = g.getVertice(j);
                cout << "   Adyacente con: " << aux2.getDato();
                cout << "   Peso: " << g.getArco(i, j) << endl;
            }
        }
    }
}

void aplicarAnclaje(GrafoMatriz &g) {
    cout << endl << "Aplicando tecnica de PNL: Anclaje..." << endl;
    cout << "Seleccione dos vertices para aplicar el anclaje:" << endl;

    int v1, v2;
    cout << "Ingrese el primer vertice: ";
    v1 = leerN(0, g.getNumVerts() - 1);
    cout << "Ingrese el segundo vertice: ";
    v2 = leerN(0, g.getNumVerts() - 1);

    g.setArco(g.getVertice(v1).getDato(), g.getVertice(v2).getDato(), 1);
    g.setArco(g.getVertice(v2).getDato(), g.getVertice(v1).getDato(), 1);

    cout << "Anclaje aplicado entre los vértices " << g.getVertice(v1).getDato() << " y " << g.getVertice(v2).getDato() << "." << endl;
}

void aplicarReframing(GrafoMatriz &g) {
    cout << endl << "Aplicando tecnica de PNL: Reframing..." << endl;
    cout << "Seleccione un vertice para aplicar el reframing:" << endl;

    int v;
    cout << "Ingrese el vertice: ";
    v = leerN(0, g.getNumVerts() - 1);

    for (int j = 0; j < g.getMaxVerts(); ++j) {
        if (g.adyacente(v, j)) {
            int pesoActual = g.getArco(v, j);
            g.setArco(g.getVertice(v).getDato(), g.getVertice(j).getDato(), pesoActual + 10);
        }
    }

    cout << "Reframing aplicado al vertice " << g.getVertice(v).getDato() << "." << endl;
}

void procesarComando(string comando, GrafoMatriz &g) {
    if (comando == "1") {
        cout << endl << "IMPRESION ACTUAL DEL GRAFO" << endl;
        imprimirGrafo(g);
    } else if (comando == "2") {
        aplicarAnclaje(g);
    } else if (comando == "3") {
        aplicarReframing(g);
    } else if (comando == "4") {
        cout << endl << "Saliendo del programa." << endl;
    } else {
        cout << "Comando no reconocido. Intentalo de nuevo." << endl;
    }
}

