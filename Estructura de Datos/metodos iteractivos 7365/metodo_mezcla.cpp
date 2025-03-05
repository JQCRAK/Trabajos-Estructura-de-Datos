#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Obtenemos el tamaño del arreglo del usuario
    int n;
    void merge(vector<int>& arr, int left, int mid, int right);
    void mergeSort(vector<int>& arr, int left, int right);
    
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
    
    // Ordenamos el arreglo usando Merge Sort
    mergeSort(arr, 0, arr.size() - 1);
    
    // Mostramos el arreglo ordenado
    cout << "Arreglo ordenado con Merge Sort: ";
    // Usamos un bucle for tradicional para mostrar los elementos del arreglo ordenado
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


void merge(vector<int>& arr, int left, int mid, int right) {
    // Calculamos los tamaños de las sublistas izquierda y derecha
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    // Creamos sublistas izquierda y derecha
    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);
    
    // Copiamos los elementos a las sublistas
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    
    // Fusionamos las sublistas de vuelta al arreglo original
    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copiamos los elementos restantes de la sublista izquierda (si los hay)
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    // Copiamos los elementos restantes de la sublista derecha (si los hay)
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    // Si el rango de la lista es válido
    if (left < right) {
        // Calculamos el punto medio
        int mid = left + (right - left) / 2;
        
        // Ordenamos las mitades izquierda y derecha recursivamente
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Fusionamos las mitades ordenadas
        merge(arr, left, mid, right);
    }
}
