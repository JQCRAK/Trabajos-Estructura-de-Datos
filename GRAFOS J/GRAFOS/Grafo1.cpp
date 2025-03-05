/* Grafo 0.cpp
	Implemeneta vertices de un grafo
	
*/

using namespace std;
#include <iostream>
#include "Vertice.h"
#define EXT 20				//cantidad maxima de vertices a procesar
#define FIN "FIN"			//marcador de fin

int main(){			//programa principal
	system("color f0");
	Vertice v[EXT];		//crear un arreglo de vertices para agruparlos
	int i = 0;			//contar posiciones del vector de vertices
	
	
	void leerVertices(Vertice v[], int* i);		//prototipo de la funcion que permite lectura de valores para el conjunto de vertices
	void imprimirVertices(Vertice v[], int i, int j);	//prototipo de la funcion que permite imprimir los valores para el conjunto de vertices
	void buscarVertices(Vertice v[], int i);					//prororipo de la funcion que permite buscar 
	leerVertices(v, &i);
	cout << endl<< "Valores contenidos en los vertices ingresados";
	imprimirVertices(v, i, 0);
	cout << endl<< "Busqueda de valores entre vertices";
	buscarVertices(v,i);
	
}


void leerVertices(Vertice v[], int* i){		//funcion que permite lectura de valores para el conjunto de vertices
	TipoG vl;
	
	cout << endl << "Valor a contener en el Vertice. Finalice con [" << FIN<<"]: ";
	cin >> vl;
	if(vl != FIN){
		v[*i].setNum(*i);
	
		v[*i].setDato(vl);				//actualizar el dato en el vertice	
		(*i)++;
		leerVertices(v, i);				//llamado recursivo
	}	
}
void imprimirVertices(Vertice v[], int i, int j){		//funcion que permite imprimir los valores para el conjunto de vertices
	
	if(j<i){			//caso base
		cout << endl << "El valor contenido en el vertice [" << v[j].getNum() <<"]: " <<v[j].getDato();
		imprimirVertices(v,i, j+1);
	}
	
}

void buscarVertices(Vertice v[], int i){							
	TipoG vl;
	bool enc;					//variable bandera
	
	cout << endl << "Valor a buscar en el Vertice. Finalice con [" << FIN<<"]: ";
	cin >> vl;
	if(vl != FIN){
		enc=false;
		for (int j=0;(j<i);j++)					//ciclo de recorrido del vector de vertices
		if(v[j].esIgualDato(vl)){
			enc=true;
		}
		if(enc){
			cout << endl<<"El valor "<<vl<<" SI existe entre los vertices. ";
		}else{
			cout << endl<<"El valor "<<vl<< " NO existe entre los vertices. ";
		}
		buscarVertices(v,i);
	}
}