/*Pilas03.cpp
Programa que apila elementos numericos enteros y ordene ascendentemente
*/
using namespace std;
#include <iostream>
#include "Pila.h"
#define FIN 999999



int main(){   		//programa pincipal
	system("color f0");
	Pila p;				//instancia de un objeto de tipo pila
	

	void leerPila(Pila *a);     //prototipo de lecturra de valores
	void imprimirPila(Pila b); //prototipo de impresion de valores
	void ordenarPila(Pila *a);				//prototipo de orenar
	void insertarOrdenado(Pila *a, Tipo valor); 
	leerPila(&p);
	ordenarPila(&p);						//llamado ala funcion;
	cout <<endl<<"ordenado ascendentemnte"<<endl;
	imprimirPila(p);
	cout <<endl<<"La pila contiene "<<p.tamanioPila()<<" elementos";
	
}



	void leerPila(Pila *a){     //lecturra de valores
 	Tipo vl;					//var de lectura
	 cout <<endl<<"Ingrese un valor a apilar, finalice con ["<<FIN<<"]: ";
	 cin >> vl; 	 					//lectura
	 if(vl!=FIN){
	 a->push(vl);				//insercion de un elemento en la ppila
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
	
void insertarOrdenado(Pila *a, Tipo valor) {
	Tipo temp;
    if (a->pilaVacia() || a->getTop() <= valor) {
        a->push(valor);
    } else {
        temp = a->pop();
        insertarOrdenado(a, valor);
        a->push(temp);
    }
}

void ordenarPila(Pila *a) {
    if (!a->pilaVacia()) {
        Tipo valor = a->pop();
        ordenarPila(a);
        insertarOrdenado(a, valor);
    }
}

