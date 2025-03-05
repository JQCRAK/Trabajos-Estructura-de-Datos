//Determinar de un vector el rango mas grande de valores consecutivos

using namespace std;
#include <iostream>
#include "Utilidades.h"
#define MAX 20

int main() {
    system("color f0");
    int* v;
    int n;
    
    void leerValores(int v[], int n);
    void ordenarValores(int v[], int n, int i);
    void imprimirValores(int v[], int n);
    void determinarConsecutivo(int v[], int n, int pos[][2], int& posCount, int start = 0, int i = 1);
    void encontrarRangoMasLargo(int v[], int pos[][2], int posCount, int& maxPi, int& maxPf, int& maxL, int i = 0);
    void imprimirRangoMasLargo(int v[], int start, int end);
    
    cout << endl << "CANTIDAD DE VALORES A PROCESAR: ";
    n = leeN(1, MAX);
    v = new int[n];
    leerValores(v, n - 1);
    ordenarValores(v, n, 0);
    imprimirValores(v, n - 1);

    int pos[MAX][2];
    int posCount = 0;
    determinarConsecutivo(v, n, pos, posCount);

    int maxPi = 0, maxPf = 0, maxL = 0;
    encontrarRangoMasLargo(v, pos, posCount, maxPi, maxPf, maxL);

    cout << endl << "Valores del rango mas largo: ";
    imprimirRangoMasLargo(v, maxPi, maxPf);

    delete[] v;
    return 0;
}

void leerValores(int v[], int n) {
    if (n >= 0) {
        leerValores(v, n - 1);
        cout << endl << "Ingrese un valor en la posicion[" << n << "]: ";
        cin >> v[n];
    }
}

void seleccionarPareja(int v[], int n, int j, int i) {
    if (j < n) {
        if (v[i] > v[j]) {
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
        seleccionarPareja(v, n, j + 1, i);
    }
}

void ordenarValores(int v[], int n, int i) {
    if (i < n - 1) {
        seleccionarPareja(v, n, i + 1, i);
        ordenarValores(v, n, i + 1);
    }
}

void imprimirValores(int v[], int n) {
    if (n >= 0) {
        imprimirValores(v, n - 1);
        cout << endl << "Valor en la posicion[" << n << "]: " << v[n];
    }
}

void determinarConsecutivo(int v[], int n, int pos[][2], int& posCount, int inicio = 0, int i = 1) {
    if (i == n) {
        if (i - inicio > 1) {
            pos[posCount][0] = inicio;
            pos[posCount][1] = i - 1;
            cout << endl << "Valores sucesivos consecutivos distribuidos entre pos " << inicio << " y posicion " << i - 1;
            posCount++;
        }
        return;
    }

    if (v[i] != v[i-1] + 1) {
        if (i - inicio > 1) {
            pos[posCount][0] = inicio;
            pos[posCount][1] = i - 1;
            cout << endl << "Valores sucesivos consecutivos distribuidos entre pos " << inicio << " y posicion " << i - 1;
            posCount++;
        }
        determinarConsecutivo(v, n, pos, posCount, i, i + 1);
    } else {
        determinarConsecutivo(v, n, pos, posCount, inicio, i + 1);
    }
}

void encontrarRangoMasLargo(int v[], int pos[][2], int posCount, int& maxPi, int& maxPf, int& maxL, int i = 0) {
    if (i == posCount) {
        return;
    }

    int length = pos[i][1] - pos[i][0] + 1;
    if (length > maxL) {
        maxL = length;
        maxPi = pos[i][0];
        maxPf = pos[i][1];
    }

    encontrarRangoMasLargo(v, pos, posCount, maxPi, maxPf, maxL, i + 1);
}

void imprimirRangoMasLargo(int v[], int start, int end) {
    if (start > end) {
        return;
    }
    cout << v[start] << " ";
    imprimirRangoMasLargo(v, start + 1, end);
}
