using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "GrafoMatriz.h"
#include "Utilidades.h"

// Funciones para el simulador de tr�fico y transporte

// Funci�n para simular el tr�fico utilizando grafo representado con matriz de adyacencia
void simularTrafico(GrafoMatriz &grafo) {
    cout << "Simulaci�n de tr�fico utilizando grafo representado con matriz de adyacencia." << endl;
    // Ejemplo de c�mo usar la ordenaci�n topol�gica en tu simulaci�n
    ordenamientoTopologicoMatriz(grafo);
    // Aqu� puedes implementar la l�gica espec�fica para la simulaci�n de tr�fico
}

// Funci�n para simular el transporte utilizando grafo representado con lista de adyacencia
void simularTransporte(GrafoLista &grafo) {
    cout << "Simulaci�n de transporte utilizando grafo representado con lista de adyacencia." << endl;
    // Ejemplo de c�mo usar la ordenaci�n topol�gica en tu simulaci�n
    ordenamientoTopologicoLista(grafo);
    // Aqu� puedes implementar la l�gica espec�fica para la simulaci�n de transporte
}

int main() {
    system("color f4");  // Configuraci�n de la interfaz

    GrafoMatriz grafoMatriz;
    GrafoLista grafoLista;

    int n;

    // Ingreso de datos para el grafo representado por matriz de adyacencia
    cout << endl << "CANTIDAD DE VERTICES DEL GRAFO REPRESENTADO CON MATRIZ DE ADYACENCIA.";
    cout << endl << "---------------------------------------------------------------------------";
    cout << endl;
    n = leerN(1, 20);  // Lectura de cantidad de v�rtices del grafo
    cin.ignore();
    grafoMatriz = ingresarVerticesM(n);  // Funci�n para ingresar los datos de los v�rtices

    ingresarArcosValorM(&grafoMatriz);  // Funci�n para ingresar los arcos valorados del grafo
    imprimirGrafoM(grafoMatriz);  // Funci�n para imprimir los datos del grafo

    // Simulaci�n de tr�fico
    simularTrafico(grafoMatriz);

    // Ingreso de datos para el grafo representado por lista de adyacencia
    cout << endl << "CANTIDAD DE VERTICES DEL GRAFO REPRESENTADO CON LISTA DE ADYACENCIA.";
    cout << endl;
    n = leerN(1, 20);  // Lectura de cantidad de v�rtices del grafo
    cin.ignore();
    grafoLista = ingresarVerticesL(n);  // Funci�n para ingresar los datos de los v�rtices

    ingresarArcosValorL(&grafoLista);  // Funci�n para ingresar los arcos valorados del grafo
    imprimirLista(grafoLista);  // Funci�n para imprimir los datos del grafo

    // Simulaci�n de transporte
    simularTransporte(grafoLista);

    cout << endl;
    system("pause");
}




