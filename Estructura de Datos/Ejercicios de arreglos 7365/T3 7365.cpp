/* Jhostin Quispe 7365
Generar los N primeros términos de la serie de Fibonacci, . 
ubicarlos en un arreglo en el orden inverso al que fueron generados.
*/
#include <iostream>

#define MAX 100
using namespace std;

int main() {
    system("Color f1");
    int n;
    int numeros[MAX];
    void generarFibonacci(int n, int numeros[], int i = 0, int a = 0, int b = 1);
	void imprimirFibonacci(int n, int numeros[], int i = 0);
	cout << "Serie de Fibonacci"<<endl;
	cout << "Cuantos numeros quiere de la serie de finomach: ";
	cin >> n;
	
	generarFibonacci(n, numeros);

    cout << endl<<"Los " << n << " primeros terminos de la serie de Fibonacci en orden inverso son:" << endl;
    imprimirFibonacci(n, numeros);
}

// Funcion para generar los N primeros terminos de la serie de Fibonacci y ubicarlos en un arreglo en orden inverso
void generarFibonacci(int n, int numeros[], int i = 0, int a = 0, int b = 1) {
    if (i < n) {
        numeros[n - i - 1] = a; // Almacenar el término de Fibonacci en el orden inverso
        generarFibonacci(n, numeros, i + 1, b, a + b); // Generar el siguiente termino de Fibonacci
    }
}

// Funcion para imprimir los N terminos de la serie de Fibonacci
void imprimirFibonacci(int n, int numeros[], int i = 0) {
    if (i < n) {
        cout << numeros[i] << " ";
        imprimirFibonacci(n, numeros, i + 1);
    } else {
        cout << endl;
    }
}
