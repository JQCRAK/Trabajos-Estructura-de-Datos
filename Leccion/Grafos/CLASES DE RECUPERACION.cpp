/*Determinar el rango mas grande de valores consecutivos
autor: JHOSTIN
*/

using namespace std;
#include <iostream>
#include "Utilidades.h"
#define MAX 20

int main(){
	system("color f5");
	//int v[MAX];				//vector de valores
	int* v;						//declaracion del apuntador a los elementos del arreglo
	int n;						//cantidad de valores a procesar
	
	void leerValores(int v[], int n);
	//void OrdenamientoBurbujaV(int v[], int n);
	void OrdenamientoBurbujaV(int v[], int n, int i);
	void imprimirValores(int v[], int n);
	//void determinarConsecutivo(int v[], int n);
	
	void determinarConsecutivos(int v[], int n, int i);
	
	
	cout << endl<< "Cantidad de valores a procesar: ";
	n=leeN(1, MAX);
	v = new int [n];
	leerValores(v,n-1);
	//OrdenamientoBurbujaV(v,n);
	OrdenamientoBurbujaV(v,n,0);
	imprimirValores(v,n-1);	
	//determinarConsecutivo(v,n);
	determinarConsecutivos(v,n,0);					
	return 0;
}



void leerValores(int v[], int n){			//funcion que permite el ingreso de valores al 
	if(n >= 0){							//posicion actual existe en el arreglo
		leerValores(v, n-1);				//llamado recrsivo
		cout << endl<< "Ingrese un valor ["<< n<<"]: ";
		cin >> v[n];
	}
}
/*
void OrdenamientoBurbujaV(int v[], int n){
	 for(int i=0; (i<n-1); i++){
	 	for(int j=(i+1);(j<n);j++){
	 		if(v[i]>v[j]){				//pivote mayor elemento comparado
	 			int aux = v[i];
	 			v[i]=v[j];
	 			v[j]=aux;
			 }
		 }
	 }
}*/

//consejo para cambiar de for a recursividad cada ciclo una funcion
void seleccionarPareja(int v[], int n, int j, int i){			//selecionar pos del elemento con que se compara
	if (j<n){
		if(v[i]>v[j]){				//pivote mayor elemento comparado
	 		int aux = v[i];
	 		v[i]=v[j];
	 		v[j]=aux;
		}
		seleccionarPareja(v,n,j+1,i);			//llamado recursivo 	
	}
}
void OrdenamientoBurbujaV(int v[], int n, int i){				//odenamiento recursivo
	if( i < n-1){												//caso base; i aun no alcanza el penultimo
		seleccionarPareja(v,n,i+1,i);				//llamado al proceso de comparacion
		OrdenamientoBurbujaV(v,n,i+1);				//llamado recursivo
	}
	
}

void imprimirValores(int v[], int n){			//funcion que permite el ingreso de valores al 
	if(n >= 0){							//posicion actual existe en el arreglo
		imprimirValores(v, n-1);				//llamado recrsivo
		cout << endl<< "Ingrese un valor ["<< n<<"]: "<<v[n];
	}
}
/*
void determinarConsecutivo(int v[], int n) {
    int pi = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] - v[i + 1] != -1 && v[i] - v[i + 1] != 1) {
            int pf = i;
            if (pi != pf) {
                cout << endl << "Valores consecutivos distributivos entre pos " << pi << " y pos " << pf;
            }
            pi = i + 1;
        }
    }
    if (pi < n - 1) {
        cout << endl << "Valores consecutivos distributivos entre pos " << pi << " y pos " << n - 1;
    }
}
*/
void determinarConsecutivos(int v[], int n, int i){
	int pi=0;
	if (i<n-1){
		if (v[i] - v[i + 1] != -1 && v[i] - v[i + 1] != 1) {
            int pf = i;
            if (pi != pf) {
                cout << endl << "Valores consecutivos distributivos entre pos " << pi << " y pos " << pf;
            }
            pi = i + 1;
        }
        if (pi < n - 1) {
        cout << endl << "Valores consecutivos distributivos entre pos " << pi << " y pos " << n - 1;
    	determinarConsecutivos(v,n,i+1);
		}
	}
}
