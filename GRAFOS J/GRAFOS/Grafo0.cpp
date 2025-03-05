/* Grafo 0.cpp
	Implemeneta vertices de un grafo
*/

using namespace std;
#include <iostream>
#include "Vertice.h"

int main(){			//programa principal
	system("color f0");
	Vertice v1, v2;		//instanciar un vertice v1
	TipoG vl; 		//variable de lectura
	
	v1.setNum(0);
	v2.setNum(1);
	cout << endl << "Valor a contener en el Vertice [" <<v1.getNum() <<"]: ";
	cin >> vl;
	v1.setDato(vl);				//actualizar el dato en el vertice
	
	cout << endl << "Valor a contener en el Vertice [" <<v2.getNum() <<"]: ";
	cin >> vl;
	v2.setDato(vl);	
	
	
	cout << endl << "El valor contenido en el vertice [" << v1.getNum() <<"]: " <<v1.getDato();
	cout << endl << "El valor contenido en el vertice [" << v2.getNum() <<"]: " <<v2.getDato();
}