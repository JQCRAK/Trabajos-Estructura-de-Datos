/* Grafo 2.cpp
	Implemeneta varios vertices de un grafo en vector dinamico	
*/

using namespace std;
#include <iostream>
#include "Utilidades.h"
#include "Vertice.h"
#define EXT 20				//cantidad maxima de vertices a procesar
#define FIN "FIN"			//marcador de fin

int main(){			//programa principal
	system("color f0");
	Vertice v[EXT];		//crear un arreglo de vertices para agruparlos
	int i = 0;			//contar posiciones del vector de vertices
	int n;				//cantidad de vertices a procesar
	
	void leerVertices(Vertice v[], int n);		//prototipo de la funcion que permite lectura de valores para el conjunto de vertices
	void imprimirVertices(Vertice v[], int i, int j);	//prototipo de la funcion que permite imprimir los valores para el conjunto de vertices
	void buscarVertices(Vertice v[], int i);					//prororipo de la funcion que permite buscar 
	
	cout<< endl<<"CANRIDAD DE VERTICES";
	n = leerN(1,20);			//solicitar al usuario definicion de cantidade de datos a procesar
	
	leerVertices(v,n-1);
	cout << endl<< "Valores contenidos en los vertices ingresados";
	imprimirVertices(v, n, 0);
	cout << endl<< "Busqueda de valores entre vertices";
	buscarVertices(v,i);
	
}


void leerVertices(Vertice v[], int n){		//funcion que permite lectura de valores para el conjunto de vertices

	if(n>= 0){
		leerVertices(v, n-1);				//llamado recursivo
		TipoG vl;
		cout << endl << "Valor a contener en el Vertice. Finalice con [" << FIN<<"]: ";
		cin >> vl;
		v[n].setNum(n);
		v[n].setDato(vl);				//actualizar el dato en el vertice			
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