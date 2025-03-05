/* Jhostin Quispe 7365
Determinar si un arreglo A está contenido completamente en otro arreglo B (o viceversa), 
ambos ingresados por el usuario. En caso de requerir aplicar procedimientos de búsqueda, 
emplee el algoritmo de búsqueda binaria.
*/
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;



int main() {
    system("Color f1");
    int numero1[MAX], numero2[MAX];
    int n1, n2;
    
    int leerN(int li, int ls);
	void leerNums(int n, int numero[], int i = 0);
	bool binarySearch(int arr[], int low, int high, int target); // Prototipo de la función

	bool contieneArreglo(int arr1[], int n1, int arr2[], int n2);

    cout << "Busqueda"<<endl;
    n1 = leerN(1, 100);
    n2=n1;
    cout << "Datos del primer vector A "<<endl;
    leerNums(n1, numero1);
    
    cout << "Datos del primer vector B"<<endl;
    leerNums(n2, numero2);
    
    
    if (contieneArreglo(numero1, n1, numero2, n2)) {
        cout << "El arreglo A esta contenido en el arreglo B." << endl;
    } else if (contieneArreglo(numero2, n2, numero1, n1)) {
        cout << "El arreglo B esta contenido en el arreglo A." << endl;
    } else {
        cout << "Ningun arreglo esta contenido en el otro." << endl;
    }

    
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

int binarySearch(int arr[], int low, int high, int target) {
    int mid = low + (high - low) / 2;
    if (low <= high) {
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            return binarySearch(arr, mid + 1, high, target);
        } else {
            return binarySearch(arr, low, mid - 1, target);
        }
    }
    return -1;
}

int contieneArreglo(int arr1[], int n1, int arr2[], int n2) {
    int i = 0;
    if (i < n1) {
        int idx = binarySearch(arr2, 0, n2 - 1, arr1[i]);
        if (idx != -1) {
            return 1; // Si algún elemento de A está en B, A está contenido en B
        }
    }
    if (i < n2) {
        int idx = binarySearch(arr1, 0, n1 - 1, arr2[i]);
        if (idx != -1) {
            return -1; // Si algún elemento de B está en A, B está contenido en A
        }
    }
    return 0; // Ningún arreglo está contenido en el otro
}
