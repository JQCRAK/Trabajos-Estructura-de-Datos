/*Jhostin Quispe 7365
Ingresar una lista y modificar sus valores, sumando a cada uno la cantidad de digitos que posee
*/

using namespace std;
#include <iostream>
#include "Lista.h"
#define FIN 99999			

void ingresarLista(Lista *l);		
void imprimirLista(Nodo *pri);		
int contarDigitos(Tipo valor);
void modificarListaRecursiva(Nodo *pri);

int main(){
	system("color f0");
	Lista l;			
	cout << endl << "Ejercicio 3";
	ingresarLista(&l);					
	cout << endl << "Contenido de la Lista";
	imprimirLista(l.getPrimero());					
	
	modificarListaRecursiva(l.getPrimero());
	
	cout << endl << "Lista modificada";
	imprimirLista(l.getPrimero());					

	return 0;
}

void ingresarLista(Lista *l){			
	Tipo vl;							
	
	cout << endl << "Ingrese un valor para lista. Finalice con [" << FIN <<"]: ";
	cin >> vl;
	
	if(vl != FIN){				
		l->insertarAlFinal(vl);			
		ingresarLista(l);
	}
}

void imprimirLista(Nodo *pri){		

	if(pri!=NULL){		
		cout << endl << "> " << pri->getDato();
		imprimirLista(pri->getPunt());
	}
}

int contarDigitos(Tipo valor) {
    if (valor < 10) {
        return 1;
    } else {
        return 1 + contarDigitos(valor / 10);
    }
}

void modificarListaRecursiva(Nodo *pri) {
    if (pri != NULL) {
        Tipo valor = pri->getDato();
        int digitos = contarDigitos(valor);
        valor += digitos;
        pri->setDato(valor);
        modificarListaRecursiva(pri->getPunt());
    }
}
