/*Jhostin Quispe 7365
Implementar el algoritmo de busqueda binaria en una lista de valores previamente ingresada
*/

#include <iostream>
#include "Lista.h"
#define FIN 99999 
using namespace std;

int main() {
    system("color f0");  
    Lista miLista;             
    
	void agregarElementos(Lista &miLista);
	void mostrarElementos(Nodo *inicio);
	Nodo* obtenerNodo(Nodo* inicio, int pos);
	int obtenerTamano(Nodo* inicio);
	void ordenarLista(Nodo* inicio, Nodo* fin);
	Nodo* encontrarMin(Nodo* inicio, Nodo* fin);
	Nodo* encontrarNodoBinario(Nodo* inicio, int valor, int inicioIdx, int finIdx);
	void buscarValor(Lista &miLista);
    cout << endl << "Ejercicio 9";
    cout <<endl<< "Ingresar elementos a la lista: "; 
    agregarElementos(miLista);    

    cout << endl << "Contenido de la lista:" << endl;
    mostrarElementos(miLista.getPrimero());  

    if (!miLista.esVacia()) {  							
        ordenarLista(miLista.getPrimero(), NULL);  
    }

    cout << endl << "Contenido de la lista ordenada:" << endl;
    mostrarElementos(miLista.getPrimero());  

    buscarValor(miLista);  

    return 0;  
}

void agregarElementos(Lista &miLista) {
    Tipo vl;
    cout << endl << "Ingrese un valor para la lista. Finalice con [" << FIN << "]: ";
    cin >> vl; 

    if (vl != FIN) { 
        miLista.insertarAlFinal(vl); 
        agregarElementos(miLista);  
    }
}

void mostrarElementos(Nodo *inicio) {
    if (inicio != NULL) {  
        cout << endl << "> " << inicio->getDato();  
        mostrarElementos(inicio->getPunt());  			
    }
}

Nodo* obtenerNodo(Nodo* inicio, int pos) {
    if (pos == 0 || inicio == NULL) {  			
        return inicio;  			
    }
    return obtenerNodo(inicio->getPunt(), pos - 1);  				
}

int obtenerTamano(Nodo* inicio) {
    if (inicio == NULL) {  					
        return 0;  
    }
    return 1 + obtenerTamano(inicio->getPunt()); 		 
}

Nodo* encontrarMin(Nodo* inicio, Nodo* fin) {
    if (inicio->getPunt() == fin) {  				
        return inicio;  						
    }
    Nodo* min = encontrarMin(inicio->getPunt(), fin);  				
    return (inicio->getDato() < min->getDato()) ? inicio : min;  
}

void ordenarLista(Nodo* inicio, Nodo* fin) {
    if (inicio != fin) { 				 
        Nodo* min = encontrarMin(inicio, fin);  			
        if (min != inicio) {  				
            Tipo temp = inicio->getDato();  			
            inicio->setDato(min->getDato());
            min->setDato(temp);
        }
        ordenarLista(inicio->getPunt(), fin); 			
    }
}

Nodo* encontrarNodoBinario(Nodo* inicio, int valor, int inicioIdx, int finIdx) {
    if (inicioIdx > finIdx) {  					
        return NULL;  					
    }
    int medio = (inicioIdx + finIdx) / 2;  					
    Nodo* nodoMedio = obtenerNodo(inicio, medio); 				 
    if (nodoMedio == NULL) {  
        return NULL;  
    }
    if (nodoMedio->getDato() == valor) {  					
        return nodoMedio;  							
    } else if (nodoMedio->getDato() > valor) {  				
        return encontrarNodoBinario(inicio, valor, inicioIdx, medio - 1);  			
    } else {  						
        return encontrarNodoBinario(inicio, valor, medio + 1, finIdx);  			
    }
}

void buscarValor(Lista &miLista) {
    int valor;
    cout << endl << "Ingrese el valor a buscar: ";
    cin >> valor;  

    int tamano = obtenerTamano(miLista.getPrimero());  					
    Nodo* resultado = encontrarNodoBinario(miLista.getPrimero(), valor, 0, tamano - 1);  		

    if (resultado != NULL) {  
        cout << endl << "El valor " << valor << " fue encontrado en la lista.";  
    } else {  								
        cout << endl << "El valor " << valor << " no fue encontrado en la lista.";  
    }
}
