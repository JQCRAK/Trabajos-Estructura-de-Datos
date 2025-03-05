/*
Programa que permite presentar un comentario en pantalla
Autor: Jhostin Quispe 7365
Fecha: 02/04/2024
*/
#include <iostream>			 //archivo de cabizera con funciones de lectura e impresion

using namespace std;        // definir el espacio de nombres en el que se desea trabajar

int main(){                //definicion del programa principal
	
	
	system("color f0");
	int val;                                     // declaracion de una variable
	int cdp, cdi;                             // cantidad de digitos impares e pares
	int _contarDigitos(int num, int *cp, int *ci);         // prototipo de la funcion (parametros por referencia)
	
	cdp=cdi=0;                                 //inicializar contadores
	
	cout << endl<< "\tIngrese un numero: " <<endl;
	cin >> val;                         //lectura del valor
	
	cout << endl<< "El valor ingresado es: " << val <<endl;	
	
	cout << endl<< "El numero Posee " << _contarDigitos(val,&cdi,&cdp) << " digitos"<< endl;
	 cout << "Existe "<< cdp<<" digitos pares y "<< cdi<< " digitos impares"<<endl;
}                          // fin del programa principal

int _contarDigitos(int num, int *cp, int *ci){    // de la funcion
	int count = 0;        //contador
	int dig;
	
    do {                   // ciclo de conteo
    	dig = num %10;
    	
    	if (dig % 2 ==0){    // si el digito es divisible para 
    	(*cp)++;                // contar par
		}else{
			(*ci)++;            // contar impar
		}
    	
        num /= 10;         // eliminar un digito
        count++;           // conteo 
    } while (num != 0);     // repetir mientras el numero posea digitos
    
    return count;           // devolver respuesta
}
