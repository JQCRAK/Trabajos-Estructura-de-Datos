/* Jhostin Quispe 7365
Permitir el ingreso de un arreglo que contendrá una lista de estudiantes, 
y otro arreglo para contener sus calificaciones. Presentar un listado de 
los N estudiantes con mejores calificaciones (en caso de requerir ordenamientos, 
emplear el método de selección).
*/
#include <iostream>
#define MAX 100
using namespace std;

int main() {
    system("Color f1");
    string nombres[MAX];
    float calificaciones[MAX];
    int n, N;
    int leerN(int li, int ls);
	void leerEstudiantes(int n, string nombres[], float calificaciones[], int i = 0);
	void intercambiar(float &a, float &b);
	void intercambiarNombres(string &a, string &b);
	int encontrarMaximo(float calificaciones[], int n, int i);
	void ordenarSeleccion(float calificaciones[], string nombres[], int n, int i = 0);
	void imprimirTopN(int n, string nombres[], float calificaciones[], int N, int i = 0);
	
    cout << "Ingrese Datos "<<endl;
    n = leerN(1, MAX);
    leerEstudiantes(n, nombres, calificaciones);

    cout << "Ingrese el numero para el Top de mejores calificaciones que desea ver: ";
    cin >> N;
    
    // Ordenar las calificaciones y los nombres usando el metodo de seleccion
    ordenarSeleccion(calificaciones, nombres, n);

    // Imprimir el listado de los N estudiantes con mejores calificaciones
    imprimirTopN(n, nombres, calificaciones, N);
    
    return 0;
}

// Funcion para leer la longitud del arreglo
int leerN(int li, int ls) {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    if (n < li || n > ls) {
        cout << "Longitud no valida. Intente nuevamente." << endl;
        return leerN(li, ls);
    }
    return n;
}

// Funcion para leer los nombres de los estudiantes y sus calificaciones
void leerEstudiantes(int n, string nombres[], float calificaciones[], int i = 0) {
    if (i < n) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> nombres[i];
        cout << "Ingrese la calificacion de " << nombres[i] << ": ";
        cin >> calificaciones[i];
        leerEstudiantes(n, nombres, calificaciones, i + 1);
    }
}

// Funcion para intercambiar dos elementos del arreglo
void intercambiar(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

// Funcion para intercambiar dos elementos del arreglo (para nombres)
void intercambiarNombres(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

// Funcion para encontrar el índice del elemento maximo
int encontrarMaximo(float calificaciones[], int n, int i) {
    if (i == n - 1) {
        return i;
    }
    int max = encontrarMaximo(calificaciones, n, i + 1);
    return (calificaciones[i] > calificaciones[max]) ? i : max;
}

// Funcion para ordenar por el metodo de seleccion
void ordenarSeleccion(float calificaciones[], string nombres[], int n, int i = 0) {
    if (i < n - 1) {
        int max = encontrarMaximo(calificaciones, n, i);
        if (max != i) {
            intercambiar(calificaciones[i], calificaciones[max]);
            intercambiarNombres(nombres[i], nombres[max]);
        }
        ordenarSeleccion(calificaciones, nombres, n, i + 1);
    }
}

// Funcion para imprimir el listado de los N estudiantes con mejores calificaciones
void imprimirTopN(int n, string nombres[], float calificaciones[], int N, int i = 0) {
    if (i < N) {
        cout << nombres[i] << ": " << calificaciones[i] << endl;
        imprimirTopN(n, nombres, calificaciones, N, i + 1);
    }
}


