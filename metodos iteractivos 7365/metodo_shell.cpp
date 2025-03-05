#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Obtenemos el tamaño del arreglo del usuario
    int n;
    void shellSort(vector<int>& arr);
    
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
    
    // Ordenamos el arreglo usando Shell Sort
    shellSort(arr);
    
    // Mostramos el arreglo ordenado
    cout << "Arreglo ordenado con Shell Sort: ";
    // Usamos un bucle for tradicional para mostrar los elementos del arreglo ordenado
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void shellSort(vector<int>& arr) {
    // Obtenemos el tamaño del arreglo
    int n = arr.size();
    
    // Inicializamos el intervalo (gap) como la mitad del tamaño del arreglo
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Recorremos el arreglo desde el índice igual al valor de gap hasta el final
        for (int i = gap; i < n; i++) {
            // Guardamos el elemento actual
            int temp = arr[i];
            int j;
            
            // Realizamos una inserción modificada con el intervalo gap
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Insertamos el elemento en su posición correcta
            arr[j] = temp;
        }
    }
}

