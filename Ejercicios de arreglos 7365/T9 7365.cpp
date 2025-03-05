/* Jhostin Quispe 7365
Permitir el ingreso de varios números en un arreglo, y 
modificar el orden de los mismos de forma tal que los N 
últimos valores pasen a ser los primeros
*/
#include <iostream>

#define MAX 100
using namespace std;

int main() {
    system("Color f1");
    int numero1[MAX];
    int n1,n2;
    
    int leerN(int li, int ls);
	void leerNums(int n, int numero[], int i = 0);
	void modificarOrden(int numero[], int n, int m, int i = 0);
	
    cout << "Modificar el orden "<<endl;
    n1 = leerN(1, 100);
    leerNums(n1, numero1);
    cout << "Ingrese el valor de n para hacer la modificacion: ";
    n2= leerN(1,n1);
    
	cout << "Vector Modificado" << endl;
	modificarOrden(numero1, n1, n1 - n2);
	
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

void modificarOrden(int numero[], int n, int m, int i = 0) {
    if (i < n) {
        cout << numero[(m + i) % n] << " ";
        modificarOrden(numero, n, m, i + 1);
    } else {
        cout << endl;
    }
}
