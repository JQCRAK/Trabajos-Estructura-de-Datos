/*
    determinar la diferencia entre grado de entrada y grado de salida
    y ordenarlos
*/

using namespace std;

#include <iostream>
#include "GrafoMatriz.h"
#include "Utilidades.h"
#include "Lista.h"
#define FIN "FIN"

int main(){		//programa principal
	
	system("color f0");
	
	void leerGrafoM(GrafoMatriz* g);	//prototipo de funcion de ingreso de vertices de un grafo
	void imprimirGrafoM(GrafoMatriz g);	//prototipo de funcion de impirmir de vertices de un grafo
    void determinarGradoEntrada(GrafoMatriz g);	//prototipo de funcion de determinar grado de entrada de un vertice
	void determinarGradoSalida(GrafoMatriz g);	//prototipo de funcion de determinar grado de salida de un vertice
    void GenerarListaVAislados(GrafoMatriz g, Lista *l);	//prototipo de funcion de determinar grado de salida de un vertice
    void imprimirVerticesAislados(Nodo* act, GrafoMatriz g);	//prototipo de funcion de determinar grado de salida de un vertice
    
    int n;

	cout << endl << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO: " << endl;
	n=leerN(1,20);		//solicitar al usuario definicion de tamanio de datos a procesar
    Lista l;


	GrafoMatriz g(n);	//crear un grafo con n vertices
	
	cout << endl << "INGRESO DE VERTICES" << endl;
	leerGrafoM(&g);
	
	cout << endl << "IMPRESION DE VERTICES" << endl;
	imprimirGrafoM(g);

    cout << endl << "\nDETERMINAR EL GRADO DE ENTRADA";
    determinarGradoEntrada(g);
    cout << endl << "\nDETERMINAR EL GRADO DE SALIDA";
    determinarGradoSalida(g);
    cout << endl << "\nDETERMINAR LA DIFERENCIA DE GRADOS";
    GenerarListaVAislados(g, &l);
	imprimirVerticesAislados(l.getPrimero(),g);


}

void leerGrafoM(GrafoMatriz* g){	//funcion de ingreso de vertices de un grafo
	
	TipoG val;
	
	for (int i = 0 ; (i<g->getMaxVerts()); i++){	//ciclo de conteo de vertices 
		
		cout << endl << "Ingrese valor del vertice [" <<g->getNumVerts()<<"] :";
		cin >> val;		//lectura
		g->nuevoVertice(val);		//ingreso del nuevo vertice al grafo
	}
	
	//Arcos
	for (int i = 0 ; (i<g->getMaxVerts() ); i++){	//ciclo de recorrido de vertices
		
		Vertice aux; 	//vertice auxiliar para impresion
		int cant; 		//cantidad de arcos
		aux = g->getVertice(i);
		cout << endl << " > VERTICE: " << aux.getDato();
		cout << endl << "   Cantidad de arcos de Salida: ";
		cant = leerN(0, g->getMaxVerts()-1);
		
		for(int j=1 ; (j<=cant) ; j++){		//ciclo de recorrido de cada arco de salida
			
			TipoG vl;
			cout << endl << "   Vertice de destino: ";
			cin >> vl;						//lectura
			int peso;
			cout << endl << "	Peso del arco: ";
			peso = leerN(0,100);
			g->setArco(aux.getDato(),vl, peso);
			
		}
	}
}

void imprimirGrafoM(GrafoMatriz g){	//prototipo de funcion de impirmir de vertices de un grafo}
	
	for (int i = 0 ; (i<g.getMaxVerts() ); i++){	//ciclo de conteo de vertices 
		
		Vertice aux; 	//vertice auxiliar para impresion
		aux = g.getVertice(i);
		cout << endl << " > " << aux.getDato();
		
		//impresion de arcos
		for ( int j = 0 ; (j<g.getMaxVerts()) ; j++){ 	
			
			Vertice aux2; 	//vertice auxiliar para impresion
			aux2 = g.getVertice(j);
			
			if(g.adyacente(i,j)){
				
				cout << endl << "	Adyacente con: "<< aux2.getDato();
				cout<<endl<<"---------------> Peso: "<< g.getArco(i,j);
			}
		}
	}
}

void determinarGradoSalida(GrafoMatriz g){
    cout << endl << "GRADO DE SALIDA DE CADA VERTICE" << endl;
    for (int i = 0 ; (i<g.getMaxVerts() ); i++){	//ciclo de conteo de vertices
        int cArc = 0;
        for(int j = 0; (j < g.getMaxVerts()); j++){ //recorrido de cada una de las columnas de la matriz
            if (g.getArco(i,j) != 0xFFFF){
                cArc++;
            }
        }
        cout << endl << " El vertice " << g.getVertice(i).getDato() << " Grado de salida: " << cArc;

    }

}

//determinar e grado de entrada

void determinarGradoEntrada(GrafoMatriz g){
    cout << endl << "GRADO DE ENTRADA DE CADA VERTICE" << endl;
    for (int i = 0 ; (i<g.getMaxVerts() ); i++){	//ciclo de conteo de vertices
        int cArc = 0;
        for(int j = 0; (j < g.getMaxVerts()); j++){ //recorrido de cada una de las columnas de la matriz
            if (g.getArco(j,i) != 0xFFFF){
                cArc++;
            }
        }
        cout << endl << " El vertice " << g.getVertice(i).getDato() << " Grado de entrada: " << cArc;

    }	
}

void GenerarListaVAislados(GrafoMatriz g, Lista *l){
    bool enc = false;
	for (int i = 0; (i < g.getMaxVerts()); i++){
		for(int j = 0; (j < g.getMaxVerts()); j++){
			if (g.getArco(i,j) !=0xFFFF || g.getArco(j,i) !=0xFFFF){
				enc = true;
			}
		}
		if (!enc){
			l->insertarAlFinal(i);
		}
	}
}

 void imprimirVerticesAislados(Nodo* act, GrafoMatriz g){
	if(act != NULL){
		cout << endl << "	> " << act->getDato()<<" " <<g.getVertice(act->getDato()).getDato();
		imprimirVerticesAislados(act->getPunt(),g);
	}
 
 }
