/*Jhostin Quispe 7365
Ordenar los valores de una lista de números en base a la cantidad de digitos que posee
*/

using namespace std;
#include <iostream>
#include "Lista.h"
#define FIN 99999			

void ingresarLista(Lista *l);		
void imprimirLista(Nodo *pri);		
int contarDigitos(Tipo valor);
void ordenarPorDigitosRecursivo(Nodo *pri);
Nodo* encontrarMinimo(Nodo *pri);
void intercambiar(Nodo *a, Nodo *b);

int main(){
	system("color f0");
	Lista l;			
    cout << endl << "Ejercicio 4";
	ingresarLista(&l);					
	cout << endl << "Contenido de la Lista";
	imprimirLista(l.getPrimero());					
	
	ordenarPorDigitosRecursivo(l.getPrimero());
	
	cout << endl << "Lista ordenada por cantidad de digitos";
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

void intercambiar(Nodo *a, Nodo *b) {
    Tipo temp = a->getDato();
    a->setDato(b->getDato());
    b->setDato(temp);
}

Nodo* encontrarMinimo(Nodo *pri) {
    if (pri == NULL) {
        return NULL;
    }
    Nodo *minimoResto = encontrarMinimo(pri->getPunt());
    if (minimoResto == NULL || contarDigitos(pri->getDato()) < contarDigitos(minimoResto->getDato())) {
        return pri;
    }
    return minimoResto;
}

void ordenarPorDigitosRecursivo(Nodo *pri) {
    if (pri != NULL) {
        Nodo *minimo = encontrarMinimo(pri);
        intercambiar(pri, minimo);
        ordenarPorDigitosRecursivo(pri->getPunt());
    }
}
