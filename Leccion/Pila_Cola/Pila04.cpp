/*Pila04
Autor: Jhostin 
Programar que permite el ingreso de dos pilas
de valores y determinar la diferencia entre ellas
*/

using namespace std;
#include <iostream>
#include "Pila.h"
#define FIN 999999



int main(){   		//programa pincipal
	system("color f0");
	Pila a,b,r;				//instancia de un objeto de tipo pila
	

	void leerPila(Pila *a);     //prototipo de lecturra de valores
	void imprimirPila(Pila b); //prototipo de impresion de valores
	void calcularDiferencia(Pila a, Pila b, Pila *r); // prototipo que genera la respuesta
	cout <<"Pila 1: "<<endl;
	leerPila(&a);
	cout <<"Pila 2: "<<endl;
	leerPila(&b);
	calcularDiferencia(a,b,&r);
	calcularDiferencia(b,a,&r);
	cout <<"Pila 3 Diferencia: "<<endl;
	imprimirPila(r);
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
	bool existeEnPila(Tipo val, Pila b){				//funcion que busca un valor en una pila
	Tipo aux;			//auxiliar para contenet el top
		if(!b.pilaVacia()){						//aun no hay elementos en pial 
			aux=b.pop();						//extraer elemento de cima
			if(val == aux){					//parametro val es igual a aux
				return true;			//val fue encontrado en b
			}
			return existeEnPila(val,b);				//lamado recursivo
		}
		return false;							//valor por defecto
	}
	void calcularDiferencia(Pila a, Pila b, Pila *r){
	Tipo vl;					//valor obetendio de la fila
	if (!a.pilaVacia()){			//la pila aun contiene valores
		vl=a.pop();      //guardar valor extraido de pil en vl
		if(!existeEnPila(vl, b)){ 				//valor extrido no existe en otra fila
			r->push(vl);				//anadir el valor encontrado en la pila de respuesta
		}
		calcularDiferencia(a, b, r);                //llamado recursivo
	}	
	}
	
	
