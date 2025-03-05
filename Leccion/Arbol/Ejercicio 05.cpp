/* Arbol04
	Implementa  recorridos en un TDA Arbol
*/
//calcular el valor mayor de un arbol

using namespace std;
#include <iostream>
#include "ArbolBinario.h"


int main(){
	system("color f0");
	ArbolBinario a;
		
	void determinarValorMayor(ArbolBinario b);	//prototipo de la funcion que implemneta los recorridos de un AB
	
	cout << endl << "Ingreso de valores para el AB";
	a.leer();
	//cout << endl << "El TDA ingresado posee " << a.contarNodos(a.getRaiz()) << " nodos";

	cout<< endl<< "VISUALIZACION DEL AB "<<endl;
	a.imprimirABSimple(a.getRaiz());
	cout <<endl<<"eL VALOR MAYOR ES: ";
a.verHojas(a.getRaiz());
}

