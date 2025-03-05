/*Cola01.cpp
	Programa que inserta y visualiza elementos 
	de un TDA cola
*/

using namespace std;
#include <iostream>
#include "Cola.h"
#define FIN 999999

int main(){
	system("color f0");
	Cola a;			//instanciar el objeto del TDA
	
	void leerCola(Cola *c);	//prototipo de funcion ingreso del TDA
	void imprimirCola(Cola c);	//prototipo de la funcion (la funcion imprimir no modifica el vector, po eso es por valor)
	
	leerCola(&a);			//llamados
	cout <<endl<<"Contenidos del TDA Cola";
	imprimirCola(a);		//llamado a impresion 
	
}

void leerCola(Cola *c){		//funcion ingreso del TDA
	Tipo vl;				//var de lectura
	
	cout << endl << "Ingrese un valor a incluir en el TDA Cola. Finalice con [" << FIN <<"]: ";
	cin >> vl;
	
	if(vl != FIN){			//usr aun desea ingresar valores al TDA
		c->insertar(vl);			//llamado al metodo de inserccion de nuevo elemento 
		leerCola(c);			//llamado recursivo 
	}
}

void imprimirCola(Cola c){
	if(!c.colaVacia()){				//aun hay elementos en el tda
	cout << endl<<"> "<<c.quitar();
	imprimirCola(c);				//lalamdo recursivo 
		
	}
		
}
