/* Jhostin Quispe 7365
Ingresar valores en un arreglo, entre los cuales se podrán admitir hasta un máximo
de N repeticiones para cada valor. En caso de requerirlo, emplee ordenamiento 
por inserción y búsqueda binaria.
*/
#include <iostream>

#define MAX 100
using namespace std;

int leerN(int li, int ls);
void leerNums(int n, int numero[], int maxRepeticiones, int i = 0);
bool verificarRepetido(int numero[], int num, int maxRepeticiones, int i, int repeticiones = 0);
void imprimirArreglo(int numero[], int n, int i = 0);

int main() {
    system("Color f1");
    int numero1[MAX];
    int n1,n2;
    
    cout << "Repeticciones de un valor "<<endl;
    n1 = leerN(1, 100);
    cout << "Cuantas veces quieres que se repita un numero: ";
    cin >> n2;
    leerNums(n1, numero1,n2);
    
    cout << endl<<"Arreglo ingresado:" << endl;
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

void leerNums(int n, int numero[], int maxRepeticiones, int i) {
    if (i < n) {
        cout << "Ingrese el número " << i + 1 << ": ";
        int num;
        cin >> num;

        if (verificarRepetido(numero, num, maxRepeticiones, i)) {
            numero[i] = num;
            leerNums(n, numero, maxRepeticiones, i + 1);
        } else {
            cout << "Ya se han ingresado el máximo de repeticiones permitido para este número." << endl;
            leerNums(n, numero, maxRepeticiones, i); // Volver a solicitar el número
        }
    }
}

bool verificarRepetido(int numero[], int num, int maxRepeticiones, int i, int repeticiones) {
    if (i < 0) {
        return true;
    }

    if (numero[i] == num) {
        ++repeticiones;
        if (repeticiones >= maxRepeticiones) {
            return false;
        }
    }

    return verificarRepetido(numero, num, maxRepeticiones, i - 1, repeticiones);
}

void imprimirArreglo(int numero[], int n, int i) {
    if (i < n) {
        cout << numero[i] << " ";
        imprimirArreglo(numero, n, i + 1);
    }
}


