/*
Programa que permite presentar un comentario en pantalla
Autor: Jhostin Quispe 7365
Fecha: 02/04/2024
*/
#include <iostream>			 //archivo de cabizera con funciones de lectura e impresion

using namespace std;        // definir el espacio de nombres en el que se desea trabajar

int main(){                //definicion del programa principal
	
	
	system("color f5");
	int val;                              // declaracion de una variable
	int _contarDigitos(int num);         // prototipo de la funcion
	
	
	
	cout << endl<< "\tIngrese un numero: " <<endl;
	cin >> val;                         //lectura del valor
	
	cout << endl<< "El valor ingresado es: " << val <<endl;	
	
	cout << endl<< "El numero Posee " << _contarDigitos(val) << " digitos"<< endl;
}                          // fin del programa principal

int _contarDigitos(int num){    // de la funcion
	int count = 0;        //contador

    do {                   // ciclo de conteo
        num /= 10;         // eliminar un digito
        count++;           // conteo 
    } while (num != 0);     // repetir mientras el numero posea digitos
    
    return count;           // devolver respuesta
}
