#include<iostream>
#define MAX 10
/*programa de ordenamiento 
*/
using namespace std;

int leerN(int li, int ls);
void leerVector(int a[], int n1);
void imprimirVector(int b[], int n2);
void contarDigitosVector(int c[], int n3);
void ordenaeVector(int *d, int n4);
void ordenarpares(int e[],n5);
int main() {
    system("color f0");
    int v[MAX];
    int n;
    n = leerN(1, MAX);
    
    cout << endl << "INGRESO DE VALORES AL ARREGLO";
    leerVector(v, n);
    cout << endl << "IMPRESION DE VALORES DESDE EL ARREGLO";
    imprimirVector(v, n);
    cout << endl << "Imprimir ordenadar descente";
    ordenaeVector(v, n);
    cout << endl << "Imprimir numero pares de forma descente";
    ordenarpares(v,n);
    contarDigitosVector(v, n);
    
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
    for (int i = n2 - 1; i >= 0; i--) {
        cout << endl << "Valor posicion [" << i << "]: " << b[i];
    }
}

void contarDigitosVector(int c[], int n3) {
    for (int i = 0; i < n3; i++) {
        int num = c[i];
        int cdp = 0, cdi = 0;
        while (num > 0) {
            int digito = num % 10;
            if (digito % 2 == 0)
                cdp++;
            else
                cdi++;
            num /= 10;
        }
        cout << endl << "En el valor posicion [" << i << "]: " << c[i] << " hay " << cdp << " digitos pares y " << cdi << " digitos impares.";
    }
}


void ordenaeVector(int *d, int n4){            //ordenamiento
	for(int i=0;(i<=n4-2); i++){              //ciclo de determinar 
		for(int j=(i+1); (j<=n4-1); j++)           // ciclo determinar 
		if(d[i]>d[j]){                            // pivate mayor a su comparacion
			int aux = d[i];
			d[i]= d[j];			
			d[j]=aux;
		}
	}
	
}

void ordenarpares(int e[],n5){
	for(int i=0;(i<=n5-2); i++){              //ciclo de determinar 
		for(int j=(i+1); (j<=n4-1); j++)           // ciclo determinar 
		int cdp = 0;
        if(){                            // pivate mayor a su comparacion
			int aux = d[i];
			d[i]= d[j];			
			d[j]=aux;
		}
	}
}



/*
if(d[i]>d[j]){                            // pivate mayor a su comparacion
			int aux = d[i];
			d[i]= d[j];			
			d[j]=aux;
		}
*/
