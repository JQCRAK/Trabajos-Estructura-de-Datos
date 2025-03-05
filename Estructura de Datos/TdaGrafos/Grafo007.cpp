/*Listas de adyacencia
Grafo 007.cpp
determinar adyacentes en un grafo ingresado es decir tener a,b,c tener adyacencia en todos los caminos por ejemplo
en este caso tiene dos caminos a,b,c, entoces saldria a,b,c que son adyaentes ya que tienes conexiones entre a,b,c
*/


using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "Utilidades.h"
#include "Lista.h"
#define FIN "FIN"

int main(){		//programa principal
	
	system("color f0");
	int n;
	Lista l;
	
	
	void leerGrafoL(GrafoLista* g);	//prototipo de funcion de ingreso de vertices de un grafo
	void imprimirGrafoL(GrafoLista g);	//prototipo de funcion de impirmir de vertices de un grafo
    void determinarGradoEntrada(GrafoLista g);	//prototipo de funcion de determinar grado de entrada de un vertice
	void determinarGradoSalida(GrafoLista g);	//prototipo de funcion de determinar grado de salida de un vertice
    void GenerarListaVAislados(GrafoLista g, Lista *l);	//prototipo de funcion de determinar grado de salida de un vertice
    void imprimirVerticesAislados(Nodo* act, GrafoLista g);	//prototipo de funcion de determinar grado de salida de un vertice
    void imprimirListasAdyacencia(GrafoLista g); //prototipo de la nueva función
	cout << endl << "CANTIDAD DE VERTICES A INGRESAR EN EL GRAFO: " << endl;
	n=leerN(1,20);		//solicitar al usuario definicion de tamanio de datos a procesar


	GrafoLista g(n);	//crear un grafo con n vertices
	
	cout << endl << "INGRESO DE VERTICES" << endl;
	leerGrafoL(&g);
	

}

void leerGrafoL(GrafoLista* g){	//funcion de ingreso de vertices de un grafo
	
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

void imprimirGrafoL(GrafoLista g){	//prototipo de funcion de impirmir de vertices de un grafo}
	
	for (int i = 0 ; (i<g.getMaxVerts() ); i++){	//ciclo de conteo de vertices 
		
		Vertice aux; 	//vertice auxiliar para impresion
		aux = g.getVertice(i);
		cout << endl << " Vertice: " << aux.getDato();
		//impresion de arcos
		ListaG l;						//cerar un objeto lista de adyacencia 
		l = g.listaAdyacencia(i);			//asignar a l la lista que ocupa posicion de arreglo en la lista
		NodoG* act;					//apuntador para recorre lista de adacencia del vertice
		act=l.getPrimero();
		while(act!=NULL){			//ciclo que se repite mientras apuntador null
			cout<<endl<<" -------------->>: "<<act->getDato();
			cout<<endl<<"  ------------->> Peso: "<< act->getPeso();
			act = act->getPunt();
		}
	}	
}

void determinarGradoSalida(GrafoLista g){
    cout << endl << "GRADO DE SALIDA DE CADA VERTICE" << endl;
    for (int i = 0 ; (i<g.getMaxVerts() ); i++){	//ciclo de conteo de vertices
        int cArc = 0;
        
		
		
		for(int j = 0; (j < g.getMaxVerts()); j++){ //recorrido de cada una de las columnas de la matriz
            if (g.adyacente(i,j)){
                cArc++;
            }
        }
        cout << endl << " El vertice " << g.getVertice(i).getDato() << " Grado de salida: " << cArc;

    }

}

//determinar e grado de entrada

void determinarGradoEntrada(GrafoLista g){
    cout << endl << "GRADO DE ENTRADA DE CADA VERTICE" << endl;
    for (int i = 0 ; (i<g.getMaxVerts() ); i++){	//ciclo de conteo de vertices
        int cArc = 0;
        for(int j = 0; (j < g.getMaxVerts()); j++){ //recorrido de cada una de las columnas de la matriz
            if (g.adyacente(j,i)){
                cArc++;
            }
        }
        cout << endl << " El vertice " << g.getVertice(i).getDato() << " Grado de entrada: " << cArc;

    }	
}

void GenerarListaVAislados(GrafoLista g, Lista *l){
    bool enc = false;
	for (int i = 0; (i < g.getMaxVerts()); i++){
		for(int j = 0; (j < g.getMaxVerts()); j++){
			if (g.adyacente(j,i) || g.adyacente(i,j)){
				enc = true;
			}
		}
		if (!enc){
			l->insertarAlFinal(i);
		}
	}
}

 void imprimirVerticesAislados(Nodo* act, GrafoLista g){
	if(act != NULL){
		cout << endl << "	> " << act->getDato()<<" " <<g.getVertice(act->getDato()).getDato();
		imprimirVerticesAislados(act->getPunt(),g);
	}
 
 }
 
bool esGrafoCompleto(GrafoLista g) {
    int numVerts = g.getNumVerts();
    for (int i = 0; i < numVerts; i++) {
        for (int j = 0; j < numVerts; j++) {
            if (i != j && !g.adyacente(i, j)) {
                return false;
            }
        }
    }
    return true;
}




