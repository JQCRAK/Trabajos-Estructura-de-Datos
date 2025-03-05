/*Autor Jhostin Quispe 7365
Ejercicio 8
Ingresar una frase y proceda a invertir el orden de las palabras, por medio del empleo de pilas
*/
#include <iostream>
#include <string.h>
#include "pila.h" 
#define MAX  100

using namespace std;

int main() {
	system("color f0");
    Pila pilaOrg;
    Pila pilaInv;
    char frase[MAX];
    
    void almacenarEnPila(Pila &pila, const char *frase, int indice);
    void invertirPila(Pila &pilaOrg, Pila &pilaInv);
    void imprimirPila(Pila &pila);
    

    cout <<endl<< "Ingrese una frase. Finalice con [.]: ";
    cin.getline(frase, MAX, '.');

    
    almacenarEnPila(pilaOrg, frase, 0);	

    invertirPila(pilaOrg, pilaInv);

    cout << endl << "Frase inversa: ";
    imprimirPila(pilaInv);
 

}

void almacenarEnPila(Pila &pila, const char *frase, int indice) {
    if (frase[indice] != '\0') {
        pila.push(frase[indice]);
        almacenarEnPila(pila, frase, indice + 1);
    }
}

void invertirPila(Pila &pilaOrg, Pila &pilaInv) {
    if (!pilaOrg.pilaVacia()) {
        char caracter = pilaOrg.pop();
        invertirPila(pilaOrg, pilaInv);
        pilaInv.push(caracter);
    }
}

void imprimirPila(Pila &pila) {
    if (!pila.pilaVacia()) {
        char caracter = pila.pop();
        cout << caracter; 
        imprimirPila(pila);
    }
}


