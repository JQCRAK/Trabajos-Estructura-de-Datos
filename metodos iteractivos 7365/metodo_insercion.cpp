#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Obtenemos el tamaño del arreglo del usuario
    int n;
    void insertionSort(vector<int>& arr);
    
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    
    // Creamos un vector para el arreglo
    vector<int> arr(n);
    
    // Solicitamos al usuario ingresar los elementos del arreglo
    cout << "Ingrese los elementos del arreglo: ";
    for (int i = 0; i < n; i++) {
    	cout <<endl<< "Ingrese el dato en la posicion ["<<i+1<<"]: ";
        cin >> arr[i];
    }
    
    // Ordenamos el arreglo usando Insertion Sort
    insertionSort(arr);
    
    // Mostramos el arreglo ordenado
    cout << "Arreglo ordenado con Insertion Sort: ";
    // Usamos un bucle for tradicional para mostrar los elementos del arreglo ordenado
    for (int i = 0; i < n; i++) {
    	cout <<endl<< "Ordenado por Insertion Sort ["<<i+1<<"]: ";
        cout << arr[i];
    }
    cout << endl;
    return 0;
}

void insertionSort(vector<int>& arr) {
    // Iteramos desde el segundo elemento hasta el final
    for (int i = 1; i < arr.size(); i++) {
        // Guardamos el elemento actual
        int key = arr[i];
        int j = i - 1;
        
        // Movemos los elementos mayores que la clave a una posición adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insertamos la clave en su posición correcta
        arr[j + 1] = key;
    }
}

