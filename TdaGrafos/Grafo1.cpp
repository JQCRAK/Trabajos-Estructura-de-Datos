/*Grafo01.cpp
Implementra varios vertices de un grafo 
*/


using namespace std;
#include <iostream>
#include "Vertice.h"
#define EXT 20
#define FIN "FIN"					//marcador de fin para terminar el programa 


int main(){						//programa principal 
	system("color f0");
	Vertice v[EXT];			//crear un arreglo de EXT vertices 
	TipoG vl;				//variable de lectura
	int i=0;				//contar posiciones del vector de vertices
	void leerVertices(Vertice v[], int *i);			//prototipo de la funcion que permite la lectura de valores para conjubntos de vertices
	void imprimirVertices(Vertice v[], int i);			//prototipo de la funcion que permite la imprimir de valores para conjubntos de vertices
	
	leerVertices(v,&i);
	imprimirVertices(v, i);
}



	void leerVertices(Vertice v[], int* i){			//prototipo de la funcion que permite la lectura de valores para conjubntos de vertices
	TipoG vl;
		
	cout << endl<<"Valor a contener en el vertice, Finalice con ["<<FIN<<"]: ";
	cin >> vl;
	
	if (vl != "FIN"){
		v[*i].setNum(*i);	
		v[*i].setDato(vl);
		(*i)++,
		leerVertices(v, i);	
	}	
	
	}
	
	
	
	
	
	void imprimirVertices(Vertice v[], int i){		//prototipo de la funcion que permite la imprimir de valores para conjubntos de vertices
		for(int j=0;j<i;j++){					//cilo del recorrido del vector 
		cout << endl<<"Valor a contener en el vertice ["<<v[j].getNum()<<"]: "<<v[j].getDato();
		}
	}
