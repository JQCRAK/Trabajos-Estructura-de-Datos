/*Jhostin Quispe 7365
Intercambiar los valores contenidos en los nodos de una lista ingresada, 
de forma que aquellos que contenían originalmente valores pares, pasen a contener valores impares
*/

using namespace std;
#include <iostream>
#include "Lista.h"
#define FIN 99999			

void ingresarLista(Lista *l);		
void imprimirLista(Nodo *pri);		
void intercambiarParesImpares(Nodo *pri);

int main(){
	system("color f0");
	Lista l;			
	cout << endl << "Ejercicio 5";
	ingresarLista(&l);					
	cout << endl << "Contenido de la Lista";
	imprimirLista(l.getPrimero());					
	
	intercambiarParesImpares(l.getPrimero());
	
	cout << endl << "Lista con valores intercambiados";
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

void intercambiarParesImpares(Nodo *pri) {
    if (pri != NULL) {
        Tipo valor = pri->getDato();
        if (valor % 2 == 0) { 
            pri->setDato(valor + 1);
        }
        intercambiarParesImpares(pri->getPunt());
    }
}
