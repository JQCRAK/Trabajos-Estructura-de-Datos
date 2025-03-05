/*Pilas02.cpp
Programa que apila elementos numericos enteros y genera dos nuevas
pilas una que contiene calores pares y otra valores impares
*/
using namespace std;
#include <iostream>
#include "Pila.h"
#define FIN 999999



int main(){   		//programa pincipal
	system("color f0");
	Pila p;				//instancia de un objeto de tipo pila
	
	Pila par,impar; 			//pilas de respuesta

	void leerPila(Pila *a);     //prototipo de lecturra de valores
	void imprimirPila(Pila b); //prototipo de impresion de valores
	void clasificarPila(Pila a, Pila *pp, Pila *pi);				//prototipo de clasificacion de valores original
	
	leerPila(&p);
	clasificarPila(p,&par,&impar);							//llamado ala funcion;
	cout <<endl<<"Pila de Valores Pares"<<endl;
	imprimirPila(par);
	cout <<endl<<"Pila de Valores Impares"<<endl;
	imprimirPila(impar);
	cout <<endl<<"La pila contiene "<<p.tamanioPila()<<" elementos";
	
}



	void leerPila(Pila *a){     //lecturra de valores
 	Tipo vl;					//var de lectura
	 cout <<endl<<"Ingrese un valor a apilar, finalice con ["<<FIN<<"]: ";
	 cin >> vl; 	 					//lectura
	 
	 if(vl!=FIN){
	 a->push(vl)	;				//insercion de un elemento en la ppila
	 leerPila(a);					//iillamado recursiva
	 
	 }
	}
	
	void imprimirPila(Pila b){ //impresion de valores
	Tipo vl;					//valor obetendio de la fila
	if (!b.pilaVacia()){
		vl=b.pop();      //guardar valor extraido de pil en vl
		cout <<endl<< " > "<<vl;
		imprimirPila(b);                //llamado recursivo
	}
	}
	
void clasificarPila(Pila a, Pila *pp, Pila *pi){
	Tipo vl;					//valor obetendio de la fila
	
	if (!a.pilaVacia()){
		vl=a.pop();      //guardar valor extraido de pil en vl
		clasificarPila(a,pp,pi);                //llamado recursivo1
		if (vl %2 ==0){ 		//vl es par
			pp->push(vl);			//anadir vl a pila de pares
		}else{
			pi->push(vl);			//anadir a pila de impares
		}
		
		
	}
	
	
	
}
