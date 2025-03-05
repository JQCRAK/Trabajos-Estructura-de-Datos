/*Jhostin Quispe 7365
Permitir el ingreso de varios AB y determinar cuáles, entre ellos son 
SIMILARES (iguales estructuras, contenidos de los nodos distintas), 
EQUIVALENTES (similares, y los nodos contienen los mismos valores) 
y DISTINTOS (con estructuras distintas)
*/

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

void leerAB(ArbolBinario *abb);
void imprimirAB(ArbolBinario abb);
void verDatosAB(ArbolBinario abb);
void ingresarABs(int cantidad, ArbolBinario arboles[], int indice = 0);
void verificarABs(int cantidad, ArbolBinario arboles[], int indice = 0);
bool sonSimilares(NodoBinario* raiz1, NodoBinario* raiz2);
bool sonEquivalentes(NodoBinario* raiz1, NodoBinario* raiz2);
void verificarConOtrosABs(int cantidad, int indice, ArbolBinario arbol, ArbolBinario arboles[]);

int main() {					

    ArbolBinario a;
    ArbolBinario* Abinarios;
    int n;

    cout << "Ejercicio 9" << endl;
    cout << "Ingresar el numero de AB a realizar los procesos ";
    cin >> n;
    Abinarios = new ArbolBinario[n]; 
    ingresarABs(n, Abinarios);
    cout << endl << "Los arboles son: " << endl;
    verificarABs(n, Abinarios);

    delete[] Abinarios;
    cout << endl;
    return 0;
}

void leerAB(ArbolBinario *abb) {
    abb->leer();				
}

void imprimirAB(ArbolBinario abb) {
    cout << endl << "Impresion simple del arbol binario" << endl;
    abb.imprimirABSimple(abb.getRaiz());	
	
    cout << endl << "Impresion jerarquia del arbol binario" << endl;
    abb.imprimirABJerarquia(abb.getRaiz(), 0);	
}

void verDatosAB(ArbolBinario abb) {
    cout << endl << "Impresion de datos de arbol binario" << endl << endl;
    cout << endl << "El arbol " << (abb.esVacio() ? "SI" : "NO") << " esta vacio";
    cout << endl << "El arbol posee " << abb.contarNodos(abb.getRaiz()) << " nodos";
    cout << endl << "La altura del arbol es " << abb.calcularAltura(abb.getRaiz());
    if (!abb.esVacio()) {
        cout << endl << "El nodo raiz es: " << abb.getRaiz()->getDato();
    }
}

void ingresarABs(int cantidad, ArbolBinario arboles[], int indice) {
    void leerAB(ArbolBinario *abb);
    void imprimirAB(ArbolBinario abb);
    void verDatosAB(ArbolBinario abb);

    if (indice < cantidad) {
        cout << endl << "Leer arbol binario " << indice + 1 << endl;
        leerAB(&arboles[indice]);
        verDatosAB(arboles[indice]);
        cout << endl << endl << "Imprimir arbol binario " << indice + 1 << endl;
        imprimirAB(arboles[indice]);	
        ingresarABs(cantidad, arboles, indice + 1);
    }
}

bool sonSimilares(NodoBinario* raiz1, NodoBinario* raiz2) {
    if (raiz1 == NULL && raiz2 == NULL) {
        return true;
    }
    if (raiz1 == NULL || raiz2 == NULL) {
        return false;
    }
    return (sonSimilares(raiz1->getIzq(), raiz2->getIzq()) && sonSimilares(raiz1->getDer(), raiz2->getDer()));
}

bool sonEquivalentes(NodoBinario* raiz1, NodoBinario* raiz2) {
    if (raiz1 == NULL && raiz2 == NULL) {
        return true;
    }
    if (raiz1 == NULL || raiz2 == NULL) {
        return false;
    }
    return (raiz1->getDato() == raiz2->getDato() && sonEquivalentes(raiz1->getIzq(), raiz2->getIzq()) && sonEquivalentes(raiz1->getDer(), raiz2->getDer()));
}

void verificarConOtrosABs(int cantidad, int indice, ArbolBinario arbol, ArbolBinario arboles[]) {
    bool sonSimilares(NodoBinario* raiz1, NodoBinario* raiz2);
    bool sonEquivalentes(NodoBinario* raiz1, NodoBinario* raiz2);
    if (indice < cantidad) {
        cout << "Con el AB" << indice + 1 << endl;
        cout << endl << (sonSimilares(arbol.getRaiz(), arboles[indice].getRaiz()) ? " SI " : " NO ") << " son similares" << endl ;
        cout << (sonEquivalentes(arbol.getRaiz(), arboles[indice].getRaiz()) ? " SI " : " NO ") << " son equivalentes" << endl ;
        cout << (sonSimilares(arbol.getRaiz(), arboles[indice].getRaiz()) ? " NO " : " SI ") << " son distintos" << endl ;
        verificarConOtrosABs(cantidad, indice + 1, arbol, arboles);
    }
}

void verificarABs(int cantidad, ArbolBinario arboles[], int indice) {
    void verificarConOtrosABs(int cantidad, int indice, ArbolBinario arbol, ArbolBinario arboles[]);
    if (indice < cantidad) {
        if (indice < cantidad - 1) cout << endl << "El AB " << indice + 1 << endl;
        verificarConOtrosABs(cantidad, indice + 1, arboles[indice], arboles);
        verificarABs(cantidad, arboles, indice + 1);
    }
}
 

