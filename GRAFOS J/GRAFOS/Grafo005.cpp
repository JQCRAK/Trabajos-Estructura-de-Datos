/*
genera una lista de verticees aislados

*/






using namespace std;
#include <iostream>
#include "Utilidades.h"
#include "GrafoMatriz.h"
#define FIN "FIN"
#include "Lista.h"


int main() {			// programa principal
    system("color f0");
    int n;				// cantidad de vertices a procesar
    Lista l;

    void leerGrafoM(GrafoMatriz* g);			// prototipo de funcion de ingreso de datos del grafo
    void imprimirGrafoM(GrafoMatriz g);		// prototipo de funcion de visualizacion de datos del grafo
    void determinarGradoSalida(GrafoMatriz g);   		// prototipo de la funcion que deteminsa el grado de salida
    void determinarGradoEntrada(GrafoMatriz g);
    void generarListaAsilados(GrafoMatriz g, Lista *l);
    void imprimirVerticesAislados(Nodo* act);
	cout << endl << "CANTIDAD DE VERTICES";
    n = leerN(1, 20);			// solicitar al usuario definicion de cantidad de datos a procesar

    GrafoMatriz g(n);	// crear un grafo con n vertices

    leerGrafoM(&g);			// llamados
    imprimirGrafoM(g);
    determinarGradoSalida(g);
    determinarGradoEntrada(g);
    generarListaAsilados(g,&l);
    cout << endl<<"Vertices sin nada";
    imprimirVerticesAislados(l->getPrimero());
}


void leerGrafoM(GrafoMatriz* g){		//funcion que permite lectura de valores para el conjunto de vertices
	TipoG vl;						//var de lectura
	
	for(int i=0;i < g->getMaxVerts();i++){			//ciclo del conteo de vertices
		cout << endl << "Ingrese valor del vertice [" << g->getNumVerts() <<"]: ";
		cin >> vl;					//lectura
		g->nuevoVertice(vl);			//ingreso del nuevo vertice al grafo
	}
	
	//arcos
	for(int i=0;i < g->getMaxVerts();i++){				//ciclo de recorrido de los vertices
		Vertice aux;
		int ca;				//cantidad de arcos
		aux = g->getVertice(i);
		cout << endl<< " > " << aux.getDato();
		cout << endl << "Vertice: " << aux.getDato();
		cout << endl << "Cantidad de arcos de salida: ";
		ca = leerN(0,g->getMaxVerts());
		for(int j=1; j <= ca; j++){				//ciclo de conteo de recorrido de cada arco de salida
			TipoG vl;							//var de lectura
			cout << endl << "Vertice de Destion: ";
			cin >> vl;							//lectura
			g->setArco(aux.getDato(), vl);
		}
	}

}
void imprimirGrafoM(GrafoMatriz g){		//funcion que permite imprimir los valores para el conjunto de vertices
	cout <<endl<<"VERTICES DEL GRAFO";
	
	for(int i=0;i < g.getMaxVerts();i++){	
		Vertice aux;					//Vertice auxiliar para impresion
		aux = g.getVertice(i);
		cout << endl<< " > " << aux.getDato();
		//IMPRESION DE ARCOS
		for(int j=0;j < g.getMaxVerts();j++){	
			Vertice aux2;					//Vertice auxiliar para impresion
			aux2 = g.getVertice(j);
			if(g.adyacente(i,j)){
				cout <<endl<< " Adyacente con: " << aux2.getDato();
			}
		}
	}
}

void determinarGradoSalida(GrafoMatriz g){		//funcion de la funcion que deteminsa el graode de salida
	cout <<endl<<"Vertices del Grafo";

	for(int i=0;i<g.getMaxVerts();i++){
		int cArc =0;				//contador de arcos de salida
		for (int j=0;(j<g.getMaxVerts());j++){
			if (g.getArco(i,j)==1){					//si en la fila i la columna 
				cArc++;				//contar el arco de salida				
			}
		}	
		cout<<endl<<"El vertice "<<g.getVertice(i).getDato()<<" posee "<< cArc<<" arcos de Salida";	
	}

}


void determinarGradoEntrada(GrafoMatriz g){		//funcion de la funcion que deteminsa el grado de entrega
	cout <<endl<<"Vertices del Grafo";

	for(int i=0;i<g.getMaxVerts();i++){
		int cArc =0;				//contador de arcos de salida
		for (int j=0;(j<g.getMaxVerts());j++){
			if (g.getArco(j,i)==1){					//si en la fila i la columna 
				cArc++;				//contar el arco de salida				
			}
		}	
		cout<<endl<<"El vertice "<<g.getVertice(i).getDato()<<" posee "<< cArc<<" arcos de Entrada";	
	}

}

void generarListaAsilados(GrafoMatriz g, Lista *l){
	bool enc=false;				//var bandera 
	
	for (int i=0;(i<g.getMaxVerts());i++){
		for (int j=0;(j<g.getMaxVerts());j++){
			if(g.getArco(i,j)==1||g.getArco(j,i)==1){
				enc=true;	
			}
		}	
	}
	
	if(!enc){
		l->insertarAlFinal()l);
	}
}

void imprimirVerticesAislados(Nodo* act){
	if(act!=NULL){
		cout<<endl<<" > "<<act->getDato();
		imprimirVerticesAislados(act->getPunt())
	}
}


