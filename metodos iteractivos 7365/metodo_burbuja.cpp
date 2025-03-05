#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Obtenemos el tamaño del arreglo del usuario
    int n;
    void bubbleSort(vector<int>& arr);
    
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    
    // Creamos un vector para el arreglo
    vector<int> arr(n);
    
    // Solicitamos al usuario ingresar los elementos del arreglo
    cout << "Ingrese los elementos del arreglo";
    for (int i = 0; i < n; i++) {
    	cout <<endl<< "Ingrese el dato en la posicion ["<<i+1<<"]: ";
        cin >> arr[i];
    }
    
    // Ordenamos el arreglo usando Bubble Sort
    bubbleSort(arr);
    
    // Mostramos el arreglo ordenado
    cout << "Arreglo ordenado con Bubble Sort: ";
    // Usamos un bucle for tradicional para mostrar los elementos del arreglo ordenado
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void bubbleSort(vector<int>& arr) {
    // Obtenemos el tamaño del arreglo
    int n = arr.size();
    
    // Iteramos sobre cada elemento
    for (int i = 0; i < n - 1; i++) {
        // Bandera para verificar si se ha realizado algún intercambio
        bool swapped = false;
        
        // Iteramos a través del arreglo
        for (int j = 0; j < n - i - 1; j++) {
            // Si el elemento actual es mayor que el siguiente, intercambiamos
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Si no se realizó ningún intercambio, el arreglo ya está ordenado
        if (!swapped) {
            break;
        }
    }
}
