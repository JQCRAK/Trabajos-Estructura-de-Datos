//Elabore una funsion recursiva que dado un arbol binario de busqueda, devuelva un conjunto de N valores cuya suma sea igual a SUM. Ejemplo 
//Si N = 3 y SUM 20
//ENTRADA: 10, -15, 20, -40, 0, 15, 50
//RESPUESTA: -40, 10, 50

using namespace std;
#include <iostream>
#include "ArbolBinario.h"
#define FIN 99999

void leer(ArbolBinario* abb);
bool findSumSet(NodoBinario* root, int N, int SUM, Tipo* result, int& count);
void findNValuesWithSum(ArbolBinario* abb, int N, int SUM);
void imprimirResultado(Tipo* result, int N, int index);

int main() {
    system("color f0");
    ArbolBinario arbol;
    Tipo vlMin,vlMax,rango;
    cout << "Ejercicio 5" << endl;
    cout << "Ingresar valores del ABB" << endl;
    leer(&arbol);
    cout << endl << "Visualizacion del ABB " << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    int N, SUM;
    cout << endl << "Ingrese el valor de N: ";
    cin >> N;
    cout << "Ingrese el valor de SUM: ";
    cin >> SUM;

    findNValuesWithSum(&arbol, N, SUM);

    return 0;
}

void leer(ArbolBinario* abb) {
    Tipo vl;
    cout << endl << "Ingrese un valor a insertar al ABB. Finalice con [" << FIN << "]: ";
    cin >> vl;
    if (vl != FIN) {
        abb->insertarNodo(vl);
        leer(abb);
    }
}

bool findSumSet(NodoBinario* root, int N, int SUM, Tipo* result, int& count) {
    if (root == NULL) {
        return false;
    }

    result[count] = root->getDato();
    count++;

    if (N == 1 && root->getDato() == SUM) {
        return true;
    }

    if (findSumSet(root->getIzq(), N - 1, SUM - root->getDato(), result, count)) {
        return true;
    }

    if (findSumSet(root->getDer(), N - 1, SUM - root->getDato(), result, count)) {
        return true;
    }

    if (findSumSet(root->getIzq(), N, SUM, result, count - 1)) {
        return true;
    }

    if (findSumSet(root->getDer(), N, SUM, result, count - 1)) {
        return true;
    }

    count--;
    return false;
}

void imprimirResultado(Tipo* result, int N, int index) {
    if (index == N) {
        return;
    }
    cout << result[index] << " ";
    imprimirResultado(result, N, index + 1);
}

void findNValuesWithSum(ArbolBinario* abb, int N, int SUM) {
    Tipo* result = new Tipo[N];
    int count = 0;
    if (findSumSet(abb->getRaiz(), N, SUM, result, count)) {
        cout << "Respuesta: ";
        imprimirResultado(result, N, 0);
        cout << endl;
    } else {
        cout << "No se encontró solución." << endl;
    }
    delete[] result;
}
