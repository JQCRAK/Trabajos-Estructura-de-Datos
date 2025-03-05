/*Arbol04
Implementa el TDA Arbol con metodo recursivo para contar nodos con valores iguales en ramas izquierda y derecha
*/
//permita calcular el prodemio de todos los valores
using namespace std;
#include <iostream>
#include "ArbolBinario.h"


int main(){
  system("color f0");
  ArbolBinario a;
  int contIguales = 0;
  int contNodos = 0;
  int sumaValores = 0;

  void calcularPromedio(NodoBinario nodo);
  void calcularPromedio(NodoBinario *nodo, int &contNodos, int &sumaValores);
  void recorrerArbol(ArbolBinario b);						//prototipo de la funcion que o,plementa los
  cout << endl << "Ingreso de valores para el AB";
  a.leer();
  cout << endl << "El TDA ingresado posee " << a.contarNodos(a.getRaiz()) << " nodos";
  //if()
  //cout << endl << "Nodos con valores iguales en ramas izquierda y derecha: " << a.contarNodosIguales(a.getRaiz(), contIguales);
	cout<< endl<< "VISUALIZACION DEL ARBOL BINARIO ";
	a.imprimirABSimple(a.getRaiz());
	cout<< endl<< "VISUALIZACION DEL ARBOL BINARIO JERARQUICO "<<endl;
	a.imprimirABJerarquia(a.getRaiz(),0);
	cout <<endl<<"VISUALIZACION NODOS HOJA"<<endl;
	a.verHojas(a.getRaiz());
	cout <<endl<<"EL PROMEDIO DEL TODOS LOS NODOS"<<endl;
	calcularPromedio(a.getRaiz(), contNodos, sumaValores);
  	if (contNodos > 0) {
   	 cout << "Promedio de valores: " << (double) sumaValores / contNodos;
  } else {
    cout << "No hay nodos en el arbol, no se puede calcular el promedio";
  }
  cout <<endl<< "Recorridos en el arbol "<<endl;
  recorrerArbol(a);
  return 0;
}

void calcularPromedio(NodoBinario *nodo, int &contNodos, int &sumaValores){
  if (nodo != NULL){
    contNodos++;
    sumaValores += nodo->getDato();
    calcularPromedio(nodo->getIzq(), contNodos, sumaValores);
    calcularPromedio(nodo->getDer(), contNodos, sumaValores);
  }
}

void recorrerArbol(ArbolBinario b){				//funcion que implementa los recorridos 
	cout<<endl<<"Recorrido en Preorden";
	b.recorrerEnPreorden();						//llamado al metodo publoco del recorrido del preorden dentro de una clases privada
}
