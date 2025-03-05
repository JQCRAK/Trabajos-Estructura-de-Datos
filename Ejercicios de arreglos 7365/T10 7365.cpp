/* Jhostin Quispe 7365
Ingresar varios valores en un arreglo, y ubicar los valores positivos en la sección 
inicial del mismo, ordenados ascendentemente. Los valores negativos se deberán ubicar 
en la sección final del mismo, ordenados descendentemente.
*/
#include <iostream>

#define MAX 100
using namespace std;


int main() {
    system("Color f1");
    int numero1[MAX];
    int n1;
    void intercambiar(int& a, int& b);
	void ordenarAscendentemente(int numero[], int n, int i = 0);
	void ordenarDescendentemente(int numero[], int n, int i = 0);
	int leerN(int li, int ls);
	void leerNums(int n, int numero[], int i);
	void imprimirNumeros(int numero[], int n, int i = 0);
	int moverNegativosAlFinal(int numero[], int n, int i = 0, int j = 0);

    cout << "Ordenar los numeros positivos ascendentemente y negativos descendentemente "<<endl;
    n1 = leerN(1, 100);
    leerNums(n1, numero1,0);
    
     // Mover los negativos al final
    int primer_negativo = moverNegativosAlFinal(numero1, n1);

    // Ordenar positivos ascendentemente
    ordenarAscendentemente(numero1, primer_negativo);

    // Ordenar negativos descendentemente
    ordenarDescendentemente(numero1 + primer_negativo, n1 - primer_negativo);

    // Imprimir el resultado
    cout << "Imprimiendo Resultados " << endl;
    imprimirNumeros(numero1, n1);
    
    return 0;
}

void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void ordenarAscendentemente(int numero[], int n, int i = 0) {
    if (i < n - 1) {
        ordenarAscendentemente(numero, n, i + 1);
        if (numero[i] > numero[i + 1]) {
            intercambiar(numero[i], numero[i + 1]);
            ordenarAscendentemente(numero, n, i);
        }
    }
}

void ordenarDescendentemente(int numero[], int n, int i = 0) {
    if (i < n - 1) {
        ordenarDescendentemente(numero, n, i + 1);
        if (numero[i] < numero[i + 1]) {
            intercambiar(numero[i], numero[i + 1]);
            ordenarDescendentemente(numero, n, i);
        }
    }
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

void imprimirNumeros(int numero[], int n, int i = 0) {
    if (i < n) {
        cout << numero[i] << " ";
        imprimirNumeros(numero, n, i + 1);
    } else {
        cout << endl;
    }
}

int moverNegativosAlFinal(int numero[], int n, int i = 0, int j = 0) {
    if (i < n) {
        if (numero[i] < 0) {
            intercambiar(numero[i], numero[j]);
            ++j;
        }
        moverNegativosAlFinal(numero, n, i + 1, j);
    }
    return j;
}

