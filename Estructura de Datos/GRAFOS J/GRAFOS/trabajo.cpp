using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "GrafoMatriz.h"
#include "Utilidades.h"

// Funciones para el simulador de tráfico y transporte

// Función para simular el tráfico utilizando grafo representado con matriz de adyacencia
void simularTrafico(GrafoMatriz &grafo) {
    cout << "Simulación de tráfico utilizando grafo representado con matriz de adyacencia." << endl;
    // Ejemplo de cómo usar la ordenación topológica en tu simulación
    ordenamientoTopologicoMatriz(grafo);
    // Aquí puedes implementar la lógica específica para la simulación de tráfico
}

// Función para simular el transporte utilizando grafo representado con lista de adyacencia
void simularTransporte(GrafoLista &grafo) {
    cout << "Simulación de transporte utilizando grafo representado con lista de adyacencia." << endl;
    // Ejemplo de cómo usar la ordenación topológica en tu simulación
    ordenamientoTopologicoLista(grafo);
    // Aquí puedes implementar la lógica específica para la simulación de transporte
}

int main() {
    system("color f4");  // Configuración de la interfaz

    GrafoMatriz grafoMatriz;
    GrafoLista grafoLista;

    int n;

    // Ingreso de datos para el grafo representado por matriz de adyacencia
    cout << endl << "CANTIDAD DE VERTICES DEL GRAFO REPRESENTADO CON MATRIZ DE ADYACENCIA.";
    cout << endl << "---------------------------------------------------------------------------";
    cout << endl;
    n = leerN(1, 20);  // Lectura de cantidad de vértices del grafo
    cin.ignore();
    grafoMatriz = ingresarVerticesM(n);  // Función para ingresar los datos de los vértices

    ingresarArcosValorM(&grafoMatriz);  // Función para ingresar los arcos valorados del grafo
    imprimirGrafoM(grafoMatriz);  // Función para imprimir los datos del grafo

    // Simulación de tráfico
    simularTrafico(grafoMatriz);

    // Ingreso de datos para el grafo representado por lista de adyacencia
    cout << endl << "CANTIDAD DE VERTICES DEL GRAFO REPRESENTADO CON LISTA DE ADYACENCIA.";
    cout << endl;
    n = leerN(1, 20);  // Lectura de cantidad de vértices del grafo
    cin.ignore();
    grafoLista = ingresarVerticesL(n);  // Función para ingresar los datos de los vértices

    ingresarArcosValorL(&grafoLista);  // Función para ingresar los arcos valorados del grafo
    imprimirLista(grafoLista);  // Función para imprimir los datos del grafo

    // Simulación de transporte
    simularTransporte(grafoLista);

    cout << endl;
    system("pause");
}




