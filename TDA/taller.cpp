#include <iostream>
#include <string>
#include "Pila.h"
using namespace std;
int main() {
    Pila pila;
    int num_noticias;
    void ingresarNoticiasRecursiva(Pila &pila, int num_noticias);
	void agregarNoticiaRelevanteRecursiva(Pila &pila);
	void imprimirNoticiasRecursiva(Pila &pila);

    cout << "Ingrese la cantidad de noticias: ";
    cin >> num_noticias;
    cin.ignore();

    ingresarNoticiasRecursiva(pila, num_noticias);
    agregarNoticiaRelevanteRecursiva(pila);

    cout << "\nLas noticias en la pila son:\n";
    imprimirNoticiasRecursiva(pila);

    return 0;
}

void ingresarNoticiasRecursiva(Pila &pila, int num_noticias) {
    if (num_noticias == 0) {
        return; 
    }
    string noticia;
    cout << "Ingrese la noticia #" << num_noticias << ": ";
    getline(cin, noticia);
    ingresarNoticiasRecursiva(pila, num_noticias - 1);
    pila.push(noticia);
}

void agregarNoticiaRelevanteRecursiva(Pila &pila) {
    string respuesta;
    cout << "\n¿Hay una noticia relevante? (si/no): ";
    cin >> respuesta;
    cin.ignore();

    if (respuesta == "si") {
        string relevante;
        cout << "Ingrese la palabra o frase relevante: ";
        getline(cin, relevante);
        if (!pila.pilaVacia()) {
            string temp = pila.pop();
            agregarNoticiaRelevanteRecursiva(pila);
            pila.push(temp);
        }
        pila.push(relevante);
    }
}

void imprimirNoticiasRecursiva(Pila &pila) {
    if (pila.pilaVacia()) {
        return;
    }

    string noticia = pila.pop();
    imprimirNoticiasRecursiva(pila);
    cout << noticia << endl;
    pila.push(noticia);
}



