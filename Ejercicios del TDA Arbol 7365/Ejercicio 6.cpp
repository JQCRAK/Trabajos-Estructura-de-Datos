/*Jhostin Quispe 7365
Permitir el ingreso de N valores por parte del usuario, y proceder a generar todos los ABB posibles construidos a partir de los mismos.
*/

using namespace std;
#include <iostream>
#include "ArbolBinario.h"
#define FIN 99999

void leerVals(int vals[], int& n);
NodoBinario* insNodoRec(NodoBinario* r, int v);
NodoBinario* insNodosRec(NodoBinario* r, int vals[], int n, int raiz, int idx);
void genABB(int vals[], int n, int raiz);
void genArboles(int vals[], int n, int idx);
void imprABB(ArbolBinario& abb, int raiz);

int main() {
    system("color f0");
    int vals[100];
    int n = 0;
    
    cout << "Ejercicio 6" << endl;
    cout << "Ingrese los valores (finalice con " << FIN << "):" << endl;
    leerVals(vals, n);

    cout << "Todos los ABB posibles:" << endl;
    genArboles(vals, n, 0);

    return 0;
}

void leerVals(int vals[], int& n) {
    int val;
    cout << "Ingrese el dato: ";
    cin >> val;
    if (val != FIN) {
        vals[n++] = val;
        leerVals(vals, n);
    }
}

NodoBinario* insNodoRec(NodoBinario* r, int v) {
    if (r == NULL) {
        r = new NodoBinario(v);
    } else {
        if (v < r->getDato()) {
            r->setIzq(insNodoRec(r->getIzq(), v));
        } else if (v > r->getDato()) {
            r->setDer(insNodoRec(r->getDer(), v));
        }
    }
    return r;
}

NodoBinario* insNodosRec(NodoBinario* r, int vals[], int n, int raiz, int idx) {
    if (idx < n) {
        if (vals[idx] != raiz) {
            r = insNodoRec(r, vals[idx]);
        }
        r = insNodosRec(r, vals, n, raiz, idx + 1);
    }
    return r;
}

void genABB(int vals[], int n, int raiz) {
    ArbolBinario abb;
    abb.insertarNodo(raiz);
    insNodosRec(abb.getRaiz(), vals, n, raiz, 0);
    imprABB(abb, raiz);
}

void genArboles(int vals[], int n, int idx) {
    if (idx >= n) {
        return;
    }
    genABB(vals, n, vals[idx]);
    genArboles(vals, n, idx + 1);
}

void imprABB(ArbolBinario& abb, int raiz) {
    cout << "Raiz " << raiz << ":" << endl;
    abb.imprimirABJerarquia(abb.getRaiz(), 0);
    cout << endl;
}





