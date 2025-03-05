/*Jhostin Quispe 7365
Calcular el coeficiente de variación entre los elementos de una cola de valores ingresados
*/

#include <iostream>
#include <cmath>
#include "Cola.h"
#define FIN 999999
using namespace std;

// Prototipos de funciones recursivas
void leerCola(Cola *c);
void imprimirCola(Cola c);
float calcularMedia(Cola c, int n, float suma);
float calcularDesviacionE(Cola c, int n, float media, float suma);
float calcularCoeficienteV(float media, float desviacionE);

int main() {
    system("color f0");
    Cola a;
    int n;
    float suma,media,desviacionE,coeficienteV;
    cout << endl << "Ejercicio 8";
    leerCola(&a);
    cout << endl << "Contenidos del TDA Cola";
    imprimirCola(a);

    n = a.tamanioCola();
    suma = 0;
    media = calcularMedia(a, n, suma);
    desviacionE = calcularDesviacionE(a, n, media, 0);
    coeficienteV = calcularCoeficienteV(media, desviacionE);

    cout << endl << "El coeficiente de variacion es: " << coeficienteV << endl;

    return 0;
}

void leerCola(Cola *c) {
    Tipo valor;
    cout << endl << "Ingrese un valor para agregar en el TDA Cola." << endl;
    cout << "Finalice con [" << FIN << "]: ";
    cin >> valor;
    if (valor != FIN) {
        c->insertar(valor);
        leerCola(c);
    }
}

void imprimirCola(Cola c) {
    if (!c.colaVacia()) {
        cout << endl << "> " << c.quitar();
        imprimirCola(c);
    }
}

float calcularMedia(Cola c, int n, float suma) {
    if (!c.colaVacia()) {
        suma += c.frenteCola();
        c.quitar();
        return calcularMedia(c, n, suma);
    } else {
        return suma / n;
    }
}

float calcularDesviacionE(Cola c, int n, float media, float suma) {
    if (!c.colaVacia()) {
        float elemento = c.frenteCola();
        suma += pow((elemento - media), 2);
        c.quitar();
        return calcularDesviacionE(c, n, media, suma);
    } else {
        return sqrt(suma / n);
    }
}

float calcularCoeficienteV(float media, float desviacionE) {
    return (desviacionE * 100) / media;
}


