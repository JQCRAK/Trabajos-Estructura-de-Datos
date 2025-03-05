/*
Calcular la union de dos TDA Cola 
Autor Jhostin Quispe 7365
*/
using namespace std;
#include <iostream>
#include "Cola.h"
#define FIN 999999

int main(){
	system("color f0");
	Cola a,b;			//instanciar el objeto del TDA
	
	void leerCola(Cola *c);	//prototipo de funcion ingreso del TDA
	void imprimirCola(Cola c);	//prototipo de la funcion (la funcion imprimir no modifica el vector, po eso es por valor)
	bool compararTdasCola(Cola a, Cola b);		//prototipo de la funcion que compara los dos tda
	cout <<endl<<"Primer TDA Cola";
	leerCola(&a);			//llamados
	imprimirCola(a);
	cout <<endl<<"Segundo TDA Cola";
	leerCola(&b);
	
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

