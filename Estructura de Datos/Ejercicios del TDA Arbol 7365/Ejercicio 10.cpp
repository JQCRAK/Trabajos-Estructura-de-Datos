/* Jhostin Quispe 7365
Permitir el ingreso de varios AB y determinar cuáles, entre ellos son 
LLENOS (no hay nodos que tengan un solo nodo descendiente), 
COMPLETOS (hasta el nivel n-1 todos los nodos son llenos, 
y en el nivel n todos los nodos hoja ocupan las posiciones mas a la izquierda) 
y DEGENERADOS (solo existe un nodo hoja, y todos los demás nodos solo tienen un nodo descendiente)
*/

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

void ingresarABs(int cantidad, ArbolBinario arboles[], int indice = 0);
void leerAB(ArbolBinario *abb);
void imprimirAB(ArbolBinario abb);
void verDatosAB(ArbolBinario abb);
void verificarABs(ArbolBinario AB, int indice);
void inorderTraversal(NodoBinario* root, bool A[], int i);
bool esCompleto(NodoBinario* root, int n);
bool esDegenerado(NodoBinario* r);

int main() {					

    ArbolBinario a;	
    ArbolBinario* arboles;	
    int n;
    
    cout << "Ejercicio 9" << endl;
    cout << "Ingresar el numero de AB a realizar los procesos: ";
    cin >> n;
    arboles = new ArbolBinario[n]; 

    cout << endl << "Verficar el arbol si es: " << endl;
    ingresarABs(n, arboles);

    delete[] arboles;
    cout << endl;
}

void leerAB(ArbolBinario *abb) {
    abb->leer();				
}

void imprimirAB(ArbolBinario abb) {
    cout << endl << "Impresion simple del arbol binario" << endl << endl;
    abb.imprimirABSimple(abb.getRaiz());	
	
    cout << endl << "Impresion jerarquia del arbol binario" << endl << endl;
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

void inorderTraversal(NodoBinario* root, bool A[], int i) {
    if (root == NULL) return;
    inorderTraversal(root->getIzq(), A, 2*i + 1);
    A[i] = true;
    inorderTraversal(root->getDer(), A, 2*i + 2);
}

bool esCompleto(NodoBinario* root, int n) {
    void inorderTraversal(NodoBinario* root, bool A[], int i);
    if (root == NULL) return true;
    bool vect[n];
    inorderTraversal(root, vect, 0);
    for (int i = 0; i < n; i++){
        if (!vect[i]) return false;
    }
    return true;
}

bool esDegenerado(NodoBinario* r) {
    if (r == NULL || (r->getIzq() == NULL && r->getDer() == NULL)) {
        return true;
    }
    if (r->getIzq() && r->getDer()) {
        return false;
    }
    if (r->getIzq()) {
        return esDegenerado(r->getIzq());
    } else {
        return esDegenerado(r->getDer());
    }
}

void verificarABs(ArbolBinario AB, int indice) {
    cout << endl << "EL AB " << indice << " es:" << endl;
    cout << (AB.arbolLleno(AB.getRaiz()) ? " SI " : " NO ") << " es un AB lleno" << endl;
    cout << (esCompleto(AB.getRaiz(), AB.contarNodos(AB.getRaiz())) ? " SI " : " NO ") << " es un AB completo" << endl;
    cout << (esDegenerado(AB.getRaiz()) ? " SI " : " NO ") << " es un AB degenerado" << endl << endl;
}

void ingresarABs(int cantidad, ArbolBinario arboles[], int indice) {
    if (indice < cantidad) {
        cout << endl << "Leer arbol binario " << indice + 1 << endl;
        leerAB(&arboles[indice]);
        verDatosAB(arboles[indice]);
        cout << endl << endl << "Imprimir arbol binario " << indice + 1 << endl;
        imprimirAB(arboles[indice]);
        verificarABs(arboles[indice], indice + 1);
        ingresarABs(cantidad, arboles, indice + 1);
    }
}

