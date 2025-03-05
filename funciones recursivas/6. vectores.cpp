/*
Programa que permite gestionar un arreglo 
Autor:Anònimo
*/



//Archivo de cabecera con funciones de lectura y escritura
#include<iostream>
#define MAX 10			//definición de la cantidad máxima de elementos del arreglo
//espacio de nombres con el que se trabaja


using namespace std;

//Funcion principal
int main(){
	system("color f0");
	int v[MAX];
	int n; 							//cantidad de elementos a procesar
	int leerN(int li, int ls); 		//	prototipo de la función que permite definir la cantidad de elementos a profesor
	void leerVector(int a[], int n1);		//prototipo de la función que iingresa en un vector
	void imprimirVector(int b[], int n2);			//prototipo de la función que imprime un vector
	n = leerN(1,MAX);
	void contarDigitosVector(int c[], int n3);
	
	cout << endl <<"INGRESO DE VALORES AL ARREGLO";
	leerVector(v,n);
	cout << endl << "IMPRESION DE VALORES DESDE EL ARREGLO";
	imprimirVector(v,n);
	
	
		
	

}

void leerVector(int *a, int n1){
	for (int i=0; (i < n1); i++){		//ciclo de recorrido del arreglo
		cout << endl << "Ingrese valor para posicion [" << i << "]: ";
		cin >> a[i];
	}
}

int leerN(int li, int ls){
	int vl;
	
	do {
		cout << endl << "Cantidad de valores a procesar [" << li << " .. " << ls << "]: ";
		cin >> vl; 			//lectura
	}while((
	vl < li) || (vl > ls)); 		//repetir si vl está fuera 
	return vl;
}

void imprimirVector(int b[], int n2){
	for (int i=n2-1; (i >= 0); i--){		//ciclo de recorrido del arreglo
		cout << endl << "Valor posicion [" << i << "]: " << b[i];
	}
	
}

void contarDigitosVector(int c[], int n3){
	int cdp,cdi;
	
	for (int i=0; (i < n3); i++){		//ciclo de recorrido del arreglo
	cdp=cdi=0;
		cout << endl << "Valor posicion [" << i << "]: " << c[i];
		cout << endl << "Ese valor posee "<< cdp << "digitos pares y "<< cdi << "Numeros impares;";
	}
}



/*
	for(int i=0; (i < 10); i++){
		cout << endl << "Valor para posicion ["<< i<<"]"<<" = "<< v[i];
	}
	
	for(int i=0; (i >= 0); i--){
		cout << endl << "Valor para posicion en desendente ["<< i<<"]"<<" = "<< v[i];
	}*/

