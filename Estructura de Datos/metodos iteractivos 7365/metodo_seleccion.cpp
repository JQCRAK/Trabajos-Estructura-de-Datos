#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Obtenemos el tamaño del arreglo del usuario
    int n;
    void selectionSort(vector<int>& arr);
    
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
    
    // Ordenamos el arreglo usando Selection Sort
    selectionSort(arr);
    
    // Mostramos el arreglo ordenado
    cout << "Arreglo ordenado con Selection Sort: ";
    // Usamos un bucle for tradicional para mostrar los elementos del arreglo ordenado
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void selectionSort(vector<int>& arr) {
    // Iteramos sobre cada elemento
    for (int i = 0; i < arr.size() - 1; i++) {
        // Encontramos el índice del elemento mínimo
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Intercambiamos el elemento mínimo con el elemento actual
        swap(arr[i], arr[minIndex]);
    }
}
