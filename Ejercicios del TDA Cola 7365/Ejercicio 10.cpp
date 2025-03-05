/*Jhostin Quispe 7365
Permitir el ingreso de varios números enteros, y generar una cola 
ordenada con los divisores primos de cada uno de ellos
*/

#include <iostream>
#include "Cola.h"
#define FIN 999999
using namespace std;

// Prototipos de funciones recursivas
void leerNumerosYGenerarDivisores(Cola *cola);
void generarDivisoresPrimos(Cola *cola, int numero, int divisor);
bool esPrimo(int numero, int divisor);
void ordenarCola(Cola *cola, int indice, int n);
Tipo encontrarMinimo(Cola *cola, int inicio, int fin, int &indiceMinimo);
void imprimirCola(Cola cola);

int main() {
    system("color f0");
    Cola cola; 
	int n;
    cout << "Ejercicio 10" << endl;
    leerNumerosYGenerarDivisores(&cola); 

    n = cola.tamanioCola();
    ordenarCola(&cola, 0, n); 

    cout << "Contenidos de la Cola Ordenada" << endl;
    imprimirCola(cola); 

    return 0;
}

void leerNumerosYGenerarDivisores(Cola *cola) {
    Tipo valor;

    cout << endl << "Ingrese un valor a incluir en la Cola." << endl;
    cout << "Finalice con [" << FIN << "]: ";
    cin >> valor;

    if (valor != FIN) {
        generarDivisoresPrimos(cola, valor, 2); 
        leerNumerosYGenerarDivisores(cola); 
    }
}

void generarDivisoresPrimos(Cola *cola, int numero, int divisor) {
    if (divisor <= numero) {
        if (numero % divisor == 0 && esPrimo(divisor, 2)) {
            cola->insertar(divisor);
        }
        generarDivisoresPrimos(cola, numero, divisor + 1); 
    }
}

bool esPrimo(int numero, int divisor) {
    if (divisor * divisor > numero) {
        return true;
    }
    if (numero % divisor == 0) {
        return false;
    }
    return esPrimo(numero, divisor + 1);
}

void ordenarCola(Cola *cola, int indice, int n) {
    int indiceMinimo;
	if (indice < n - 1) {
        indiceMinimo = indice;
        Tipo minimo = encontrarMinimo(cola, indice, n, indiceMinimo);
        Tipo temp = cola->getVec(indice);
        cola->setVec(minimo, indice);
        cola->setVec(temp, indiceMinimo);
        ordenarCola(cola, indice + 1, n); 
    }
}

Tipo encontrarMinimo(Cola *cola, int inicio, int fin, int &indiceMinimo) {
    int siguienteIndice;
    Tipo minimoRestante;
	if (inicio == fin - 1) {
        return cola->getVec(inicio);
    }

    siguienteIndice = inicio + 1;
    minimoRestante = encontrarMinimo(cola, siguienteIndice, fin, indiceMinimo);

    if (cola->getVec(inicio) < minimoRestante) {
        indiceMinimo = inicio;
        return cola->getVec(inicio);
    } else {
        return minimoRestante;
    }
}

void imprimirCola(Cola cola) {
    if (!cola.colaVacia()) {
        cout << endl << "> " << cola.quitar();
        imprimirCola(cola); 
    }
}

