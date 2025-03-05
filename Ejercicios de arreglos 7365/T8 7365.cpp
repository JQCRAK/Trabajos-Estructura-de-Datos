/* Jhostin Quispe 7365
Generar un listado ordenado de números enteros comprendidos entre 
los valores A y B cuya disposición de dígitos se lea igual de 
izquierda a derecha como de derecha a izquierda.
*/
#include <iostream>
#define MAX 100
using namespace std;

int leerN(int li, int ls);
void generarPalindromicos(int A, int B);

int main() {
    system("Color f1");
    int n1, n2;
    
	
    cout << "Inicio de A"<<endl;
    n1 = leerN(1, 100);
    
    cout << "Fin de B"<<endl;
    n2 = leerN(n1, 100);
    
    cout << "Numeros Generados"<<endl;
    generarPalindromicos(n1, n2);

    
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

void generarPalindromicos(int A, int B) {
    if (A > B) {
        return;
    }
    cout << A << " ";
    generarPalindromicos(A + 1, B);
    if (A < B) {
        cout << A << " ";
    }
}

