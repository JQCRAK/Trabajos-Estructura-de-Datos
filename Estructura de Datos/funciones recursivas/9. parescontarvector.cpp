#include<iostream>
#include<algorithm>


using namespace std;

int leerN(int li, int ls);
void leerVector(int a[], int n1);
void imprimirVector(int b[], int n2);
void contarDigitosVector(int c[], int n3);
void ordenarVectorPorPares(int v[], int n);
void imprimirPares(int b[], int n2);
void imprimirnumeroscomunes(int *e, n7);

int main() {
    system("color f0");
    int v[MAX];
    int n;
    n = leerN(1, MAX);
    
    cout << endl << "INGRESO DE VALORES AL ARREGLO";
    leerVector(v, n);
    cout << endl << "IMPRESION DE VALORES DESDE EL ARREGLO";
    imprimirVector(v, n);
    contarDigitosVector(v, n);
    ordenarVectorPorPares(v, n);
    
    cout << endl << "VECTOR ORDENADO POR CANTIDAD DE PARES:";
    imprimirVector(v, n);
    
    imprimirPares(v, n);
    cout << endl<< "Imprimir numeros comunes:";
    void imprimirnumeroscomunes(v, n);
    return 0;
}

void leerVector(int *a, int n1) {
    for (int i = 0; i < n1; i++) {
        cout << endl << "Ingrese valor para posicion [" << i << "]: ";
        cin >> a[i];
    }
}

int leerN(int li, int ls) {
    int vl;
    do {
        cout << endl << "Cantidad de valores a procesar [" << li << " .. " << ls << "]: ";
        cin >> vl;
    } while (vl < li || vl > ls);
    return vl;
}

void imprimirVector(int b[], int n2) {
    for (int i = 0; i < n2; i++) {
        cout << endl << "Valor posicion [" << i << "]: " << b[i];
    }
}

void contarDigitosVector(int c[], int n3) {
    int pares = 0;
    for (int i = 0; i < n3; i++) {
        int num = c[i];
        while (num > 0) {
            int digito = num % 10;
            if (digito % 2 == 0)
                pares++;
            num /= 10;
        }
    }
    cout << endl << "Total de numeros pares en el vector: " << pares << endl;
}

bool compararPorCantidadDePares(int a, int b) {
    int pares_a = 0, pares_b = 0;
    int temp_a = a, temp_b = b;
    while (temp_a > 0) {
        if (temp_a % 2 == 0)
            pares_a++;
        temp_a /= 10;
    }
    while (temp_b > 0) {
        if (temp_b % 2 == 0)
            pares_b++;
        temp_b /= 10;
    }
    return pares_a < pares_b;
}

void ordenarVectorPorPares(int v[], int n) {
    sort(v, v + n, compararPorCantidadDePares);
}

void imprimirPares(int b[], int n2) {
    cout << endl << "Números pares en orden ascendente:";
    for (int i = 0; i < n2; i++) {
        if (b[i] % 2 == 0) {
            cout << endl << "Valor posicion [" << i << "]: " << b[i];
        }
    }
}

void imprimirnumeroscomunes(int *e, n7){
	for(int i=0;(i<=n7-2); i++){              //ciclo de determinar 
		for(int j=(i+1); (j<=n4-1); j++)           // ciclo determinar 
		
	}
}




