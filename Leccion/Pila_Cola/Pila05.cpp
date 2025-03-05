/*Pila05
Programa hacer la diferencia 

*/

/*Pila04
Autor: Jhostin 
Programar que permite el ingreso de n pilas
de valores y determinar la diferencia entre ellas
*/
using namespace std;
#include <iostream>
#include "Pila.h"
#include "Utilidades.h"
#define FIN 999999

int main(){   		//programa pincipal
	system("color f0");
	int n;
	Pila r;				//instancia de un objeto de tipo pila
	void ingresarNPilas(int n, Pila *r);//ptotipo de la funcion que instrument el ingreso de N pila

	void imprimirPila(Pila b); //prototipo de impresion de valores

	n=leeN(2,20);					//ingreso de cantidad de pilas a procesar
	ingresarNPilas(n,&r);					//llamado a ingreso de n pilas
	cout<< "Pila de diferencia: ";
	imprimirPila(r);
	
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
	
void leerPila(Pila *a){     //lecturra de valores
 	Tipo vl;					//var de lectura
	 cout <<endl<<"Ingrese un valor a apilar, finalice con ["<<FIN<<"]: ";
	 cin >> vl; 	 					//lectura
	 
	 if(vl!=FIN){
	 a->push(vl)	;				//insercion de un elemento en la ppila
	 leerPila(a);					//iillamado recursiva
	 
	 }
	}
void pasarValores(Pila *b, Pila *r){						//b es pila destino , 
	if(!r->pilaVacia()){ 									//pil;a origen tiene elementos
		b->push(r->pop());						//eXTRAER UN ELEMENTO 
		pasarValores(b,r);					//Paso de los siguiente elementos del pila origen
	}
}
void ingresarNPilas(int n, Pila *r){			//protipo que 
	Pila a,b;									//nstaciar en Pila a
	
	if(n>=1){							//aun se debe ingresar un Pila
		cout <<"Ingreso de Pila: "<<endl;
		leerPila(&a);
		pasarValores(&b,r);				//respuesta en b						//transfirir los valores de pila respuesta de b
		calcularDiferencia(a,b,r);
		calcularDiferencia(b,a,r);
		ingresarNPilas(n-1,r);				//llamado recursivo de siuiente pila
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

	
	
