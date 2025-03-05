/* Jhostin Quispe 7365
Permitir el ingreso completo de valores en un arreglo, 
y eliminar de este aquellos valores que se encuentren repetidos
*/
#include <iostream>

#define MAX 100
using namespace std;

int leerN(int li, int ls);
void leerNums(int n, int numero[], int i = 0);
void eliminarRepetidos(int numero[], int& n, int i = 0, int j = 0);
void imprimirArreglo(int numero[], int n, int i = 0);

int main() {
    system("Color f1");
    int numero1[MAX];
    int n1;
    
    cout << "Eliminar numeros repetidos de un vector "<<endl;
    n1 = leerN(1, 100);
    leerNums(n1, numero1);
    cout <<endl<< "Arreglo ingresado:" << endl;
    imprimirArreglo(numero1, n1);
    
    eliminarRepetidos(numero1, n1);

    cout << endl<< "Arreglo sin elementos repetidos:" << endl;
    imprimirArreglo(numero1, n1);
    
    return 0;
}

int leerN(int li, int ls) {
    int n;
    cout << "Longitud del vector: ";
    cin >> n;

    if (n < li || n > ls) {
        cout << "Longitud no valida. Intente nuevamente." << endl;
        return leerN(li, ls);
    }
    return n;
}

void leerNums(int n, int numero[], int i) {
    if (i < n) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numero[i];
        leerNums(n, numero, i + 1);
    }
}

void eliminarRepetidos(int numero[], int& n, int i, int j) {
    if (i >= n) {
        return;
    }

    if (j < n) {
        if (i != j && numero[i] == numero[j]) {
            numero[j] = numero[n - 1];
            --n;
            eliminarRepetidos(numero, n, i, j);
        } else {
            eliminarRepetidos(numero, n, i, j + 1);
        }
    } else {
        eliminarRepetidos(numero, n, i + 1, i + 1);
    }
}

void imprimirArreglo(int numero[], int n, int i) {
    if (i < n) {
        cout << numero[i] << " ";
        imprimirArreglo(numero, n, i + 1);
    }
}
