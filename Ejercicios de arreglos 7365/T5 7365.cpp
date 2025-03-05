/* Jhostin Quispe 7365
Ingresar un arreglo cuyos valores deberán ser únicos (no admitir repeticiones).
*/
#include <iostream>

#define MAX 100
using namespace std;

int leerN(int li, int ls);
void leerNums(int n, int numero[], int i);
void imprimirArreglo(int numero[], int n);
int verificarRepetido(int numero[], int n, int num, int i);

int main() {
    system("Color f1");
    int numero1[MAX];
    int n1;
    
    cout << "Arreglo sin repeticiones: ";
    n1 = leerN(1, 100);
    leerNums(n1, numero1,0);
    
    cout << "Arreglo ingresado sin repeticiones: ";
    imprimirArreglo(numero1, n1);
    
    return 0;
}

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

void leerNums(int n, int numero[], int i) {
    if (i < n) {
        int num;
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> num;
        
        // Verifica si el número ya existe en el arreglo
        int repetido = verificarRepetido(numero, n, num, 0);
        if (repetido != -1) {
            cout << "El número ingresado ya existe en la posición " << repetido + 1 << " del arreglo. Ingrese otro número." << endl;
            leerNums(n, numero, i);
        } else {
            numero[i] = num;
            leerNums(n, numero, i + 1);
        }
    }
}

int verificarRepetido(int numero[], int n, int num, int i) {
    if (i == n) {
        return -1; // Si no se encuentra el número, devuelve -1
    }
    if (numero[i] == num) {
        return i; // Si el número se encuentra, devuelve la posición donde se encuentra
    }
    return verificarRepetido(numero, n, num, i + 1);
}

void imprimirArreglo(int numero[], int n) {
    if (n > 0) {
        cout << numero[0] << " ";
        imprimirArreglo(numero + 1, n - 1);
    }
}

