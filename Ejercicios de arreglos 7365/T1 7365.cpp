/* Jhostin Quispe 7365
Ingresar dos arreglos, ordenar el primero ascendentemente por el método de selección, 
el segundo descendentemente por el método de inserción. 
Proceder a intercalar ordenadamente los dos arreglos iniciales.
*/
#include <iostream>

#define MAX 100
using namespace std;



int main() {
    system("Color f1");
    int numero1[MAX], numero2[MAX], resultado[MAX * 2];
    int n1, n2;
    
    int leerN(int li, int ls);
	void leerNums(int n, int numero[], int i = 0);
	void imprimir(int n, int numeros[], int i = 0);
	void intercambiar(int &a, int &b);
	int encontrarMinimo(int numeros[], int n, int i, int mini);
	void ordenarSeleccion(int numeros[], int n, int i = 0);
	void insertar(int numeros[], int n, int indice);
	void ordenarInsercion(int numeros[], int n, int i = 1);
	void intercalar(int arr1[], int n1, int arr2[], int n2, int resultado[], int i = 0, int j = 0, int k = 0);
	void ordenar(int arr[], int n, int i = 0);
	
    cout << "Ingrese la longitud del primer vector "<<endl;
    n1 = leerN(1, 100);
    leerNums(n1, numero1);
    
    cout << "Ingrese la longitud del segundo vector "<<endl;
    n2 = leerN(1, 100);
    leerNums(n2, numero2);
    
    cout << endl<<"Ordenando primer vector por metodo de seleccion" << endl;
    ordenarSeleccion(numero1, n1);
    cout << "Arreglo 1 ordenado ascendentemente: ";
    imprimir(n1, numero1);

    cout <<endl<< "Ordenando segundo vector por metodo de insercion" << endl;
    ordenarInsercion(numero2, n2);
    cout << "Arreglo 2 ordenado descendentemente: ";
    imprimir(n2, numero2);

    cout <<endl<<"Intercalando arreglos" << endl;
    intercalar(numero1, n1, numero2, n2, resultado);

    cout << "Ordenando arreglo intercalado" << endl;
    ordenar(resultado, n1 + n2);
    cout << "Arreglo intercalado ordenado: ";
    imprimir(n1 + n2, resultado);
    
    
    return 0;
}

//Funcion para leer la longitud del vector
int leerN(int li, int ls) {
    int n;
    cout << "Longitud del vector: ";
    cin >> n;

    if (n < li || n > ls) {
        cout << "Longitud no válida. Intente nuevamente." << endl;
        return leerN(li, ls);
    }
    return n;
}

//Funcion para que lee los numero en el arreglo
void leerNums(int n, int numero[], int i) {
    if (i < n) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numero[i];
        leerNums(n, numero, i + 1);
    }
}

// Función para imprimir el arreglo
void imprimir(int n, int numeros[], int i = 0) {
    if (i < n) {
        cout << numeros[i] << " ";
        imprimir(n, numeros, i + 1);
    } else {
        cout << endl;
    }
}

// Función para intercambiar dos elementos del arreglo
void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función para encontrar el índice del elemento mínimo
int encontrarMinimo(int numeros[], int n, int i, int mini) {
    if (i < n) {
        if (numeros[i] < numeros[mini]) {
            mini = i;
        }
        return encontrarMinimo(numeros, n, i + 1, mini);
    } else {
        return mini;
    }
}

// Función para ordenar por el método de selección
void ordenarSeleccion(int numeros[], int n, int i = 0) {
    if (i < n - 1) {
        int minI = encontrarMinimo(numeros, n, i + 1, i);
        intercambiar(numeros[i], numeros[minI]);
        ordenarSeleccion(numeros, n, i + 1);
    }
}

// Función para insertar un elemento en su posición correcta
void insertar(int numeros[], int n, int indice) {
    if (indice > 0 && numeros[indice - 1] < numeros[indice]) {
        intercambiar(numeros[indice], numeros[indice - 1]);
        insertar(numeros, n, indice - 1);
    }
}

// Función para ordenar por el método de inserción
void ordenarInsercion(int numeros[], int n, int i = 1) {
    if (i < n) {
        insertar(numeros, n, i);
        ordenarInsercion(numeros, n, i + 1);
    }
}

// Función para intercalar dos arreglos ordenados
void intercalar(int arr1[], int n1, int arr2[], int n2, int resultado[], int i = 0, int j = 0, int k = 0) {
    if (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            resultado[k] = arr1[i];
            intercalar(arr1, n1, arr2, n2, resultado, i + 1, j, k + 1);
        } else {
            resultado[k] = arr2[j];
            intercalar(arr1, n1, arr2, n2, resultado, i, j + 1, k + 1);
        }
    } else if (i == n1) {
        if (j < n2) {
            resultado[k] = arr2[j];
            intercalar(arr1, n1, arr2, n2, resultado, i, j + 1, k + 1);
        }
    } else {
        if (i < n1) {
            resultado[k] = arr1[i];
            intercalar(arr1, n1, arr2, n2, resultado, i + 1, j, k + 1);
        }
    }
}

// Función para ordenar el arreglo por el método de selección
void ordenar(int arr[], int n, int i = 0) {
    if (i < n - 1) {
        int minIndex = encontrarMinimo(arr, n, i + 1, i);
        intercambiar(arr[i], arr[minIndex]);
        ordenar(arr, n, i + 1);
    }
}
