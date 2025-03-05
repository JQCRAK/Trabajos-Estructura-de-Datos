/*Jhostin Quispe 7365
Calcular la suma de los nodos pares y la suma de los nodos impares de una lista ingresada
*/

#include <iostream>
#include "Lista.h"
#define FIN 99999			

using namespace std;

void ingresarLista(Lista *l);		
void imprimirLista(Nodo *pri);
int sumaNodosPares(Nodo *pri);
int sumaNodosImpares(Nodo *pri);

int main(){
	system("color f0");
	Lista l;
	int sumaPares,sumaImpares;			
    cout << endl << "Ejercicio 10";
	ingresarLista(&l);					
	cout << endl << "Contenido de la Lista";
	imprimirLista(l.getPrimero());	

	sumaPares = sumaNodosPares(l.getPrimero());
	sumaImpares = sumaNodosImpares(l.getPrimero());

	cout << endl << "La suma de los nodos pares es: " << sumaPares;
	cout << endl << "La suma de los nodos impares es: " << sumaImpares;

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
	if(pri != NULL){		
		cout << endl << "> " << pri->getDato();
		imprimirLista(pri->getPunt());
	}
}

int sumaNodosPares(Nodo *pri) {
    if (pri == NULL) {
        return 0; 
    }

    int suma = (pri->getDato() % 2 == 0) ? pri->getDato() : 0;

    return suma + sumaNodosPares(pri->getPunt());
}

int sumaNodosImpares(Nodo *pri) {
    if (pri == NULL) {
        return 0; 
    }

    int suma = (pri->getDato() % 2 != 0) ? pri->getDato() : 0;

    return suma + sumaNodosImpares(pri->getPunt());
}
