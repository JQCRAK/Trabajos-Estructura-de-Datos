#include <iostream>
#include <string>
#include "Pila.h"
using namespace std;

// Función recursiva para ingresar noticias en la pila
void ingresarNoticiasRecursiva(Pila &pila, int num_noticias) {
    if (num_noticias == 0) {
        return; // Caso base: no hay más noticias por ingresar
    }

    string noticia;
    cout << "Ingrese la noticia #" << num_noticias << ": ";
    getline(cin, noticia);

    // Llamada recursiva para ingresar las noticias restantes
    ingresarNoticiasRecursiva(pila, num_noticias - 1);

    // Coloca la nueva noticia en la parte superior de la pila
    pila.push(noticia);
}

// Función para verificar y agregar una noticia relevante a la pila
	void agregarNoticiaRelevante(Pila &pila) {
	    string respuesta;
	    cout << "\n¿Hay una noticia relevante? (si/no): ";
	    cin >> respuesta;
	    cin.ignore();
	
	    if (respuesta == "si") {
	        string relevante;
	        cout << "Ingrese la palabra o frase relevante: ";
	        getline(cin, relevante);
	
	        // Desapilar todas las noticias existentes
	        Pila temp;
	        while (!pila.pilaVacia()) {
	            temp.push(pila.pop());
	        }
	
	        // Agregar la noticia relevante en la parte superior de la pila
	        pila.push(relevante);
	
	        // Volver a apilar las noticias originales
	        while (!temp.pilaVacia()) {
	            pila.push(temp.pop());
	        }
	    }
	}


// Función para imprimir las noticias de la pila en el orden correcto
// Función recursiva para imprimir las noticias de la pila en el orden correcto
void imprimirNoticias(Pila &pila) {
    // Verificar si la pila está vacía (caso base)
    if (pila.pilaVacia()) {
        return;
    }

    // Desapilar el elemento en la parte superior de la pila y guardarlo temporalmente
    string noticia = pila.pop();

    // Llamar recursivamente para imprimir las noticias restantes en la pila
    imprimirNoticias(pila);

    // Imprimir el elemento desapilado
    cout << noticia << endl;

    // Volver a apilar el elemento en la parte superior de la pila
    pila.push(noticia);
}



int main() {
    Pila pila;
    int num_noticias;

    cout << "Ingrese la cantidad de noticias: ";
    cin >> num_noticias;
    cin.ignore();

    ingresarNoticiasRecursiva(pila, num_noticias);

    agregarNoticiaRelevante(pila);

    cout << "\nLas noticias en la pila son:\n";
    imprimirNoticias(pila);

    return 0;
}
