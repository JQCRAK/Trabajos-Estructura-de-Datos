/*Jhostin Quispe 7365
Permitir el ingreso de una cadena de caracteres y ordenar los caracteres de cada palabra encontrada
*/

#include <iostream>
#include <cstring>
#include "Cola.h"
#define MAX  100

using namespace std;

void almacenarEnCola(Cola &cola, const char *palabra);
void ordenarLetrasEnPalabra(Cola &cola);

int main() {
    system("color f0");
    Cola colaPalabras;
    char frase[MAX];
    
    cout << endl << "Ejercicio 3";
    cout <<endl<< "Ingrese una frase. Finalice con [.]: ";
    cin.getline(frase, MAX, '.');

    char palabra[MAX];
    int longitud = strlen(frase);
    int inicio = 0;
    
    for (int i = 0; i <= longitud; ++i) {
        if (frase[i] == ' ' || frase[i] == '\0') {
            int fin = i - 1;
            if (frase[i] == '\0') fin = i; 
            int index = 0;
            for (int j = inicio; j <= fin; ++j) {
                palabra[index++] = frase[j];
            }
            palabra[index] = '\0'; 
            almacenarEnCola(colaPalabras, palabra);
            inicio = i + 1; 
        }
    }
    ordenarLetrasEnPalabra(colaPalabras);
    cout << endl << "Frase con letras de cada palabra ordenadas: ";
    while (!colaPalabras.colaVacia()) {
        char letra = colaPalabras.quitar();
        cout << letra;
    }
    cout << endl;

    return 0;
}

void almacenarEnCola(Cola &cola, const char *palabra) {
    int longitud = strlen(palabra);
    for (int i = 0; i < longitud; ++i) {
        cola.insertar(palabra[i]);
    }
    cola.insertar(' '); 
}

void ordenarLetrasEnPalabra(Cola &cola) {
    Cola colaTemp;
    while (!cola.colaVacia()) {
        char caracter = cola.quitar();
        colaTemp.insertar(caracter);
    }
    Cola colaOrdenada;
    Cola colaPalabra;
    while (!colaTemp.colaVacia()) {
        char caracter = colaTemp.quitar();
        if (caracter != ' ') {
            colaPalabra.insertar(caracter);
        } else {
            char letrasOrdenadas[MAX];
            int indice = 0;
            while (!colaPalabra.colaVacia()) {
                letrasOrdenadas[indice++] = colaPalabra.quitar();
            }
            for (int i = 0; i < indice - 1; ++i) {
                for (int j = 0; j < indice - i - 1; ++j) {
                    if (letrasOrdenadas[j] > letrasOrdenadas[j + 1]) {
                        char temp = letrasOrdenadas[j];
                        letrasOrdenadas[j] = letrasOrdenadas[j + 1];
                        letrasOrdenadas[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < indice; ++i) {
                colaOrdenada.insertar(letrasOrdenadas[i]);
            }
            colaOrdenada.insertar(' ');
        }
    }
    while (!colaOrdenada.colaVacia()) {
        char caracter = colaOrdenada.quitar();
        cola.insertar(caracter);
    }
}


