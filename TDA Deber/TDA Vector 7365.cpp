/*
TA01
EMmple el TDA Vector*/

using namespace std;


#include <iostream>
#include "Vector.h"
#include "Utilidades.h"



int main(){ //programa principal
	int valB2;
	int valorBuscado;
	int nuevoElemento;
	
	system("color f0");
	Vector a; 				//crea una instancia del TDA Vector
	cout << endl<< "El Vector a tiene  "<<a.getN() <<" elementos..."<<endl;
	a.setN(leeN(1,EXT));  		//actualiza el estadi del atributo n del objeti 
	cout << endl<< "El Vector a tiene  "<<a.getN() <<" elementos...";
	a.leerVector(a.getN()-1);
	cout << endl<<"Imprimir Metodo Insercion"<<endl;  
	a.metodoI(a.getN()-1);
	a.ImprimirVector(a.getN()-1);
	cout << endl<<"Imprimir Metodo ShellSort"<<endl;
	a.shellSort(a.getN() / 2);                              // Utilizando el gap inicial como n/2
    a.ImprimirVector(a.getN() - 1);   
	cout << endl<<"Imprimir Metodo Burbuja"<<endl;
	a.Burbuja(a.getN()-1);
	a.ImprimirVector(a.getN()-1);
	cout << endl<<"Imprimir Metodo Seleccion"<<endl;
	a.Seleccion(0);
	a.ImprimirVector(a.getN()-1);
	cout<<endl<<"Metodo 1 Busqueda Secuencial"<<endl;
	cout << "Ingrese el valor que desea buscar en el vector: ";
    cin >> valB;
    a.busquedaSecuencial(valB);
    cout<<endl<<"Metodo 2 Busqueda Binaria"<<endl;
	cout << "Ingrese el valor que desea buscar en el vector: ";
	cin >> valB2;
	a.busquedaBinaria(valB2, 0, a.getN() - 1);
    cout <<endl<< "Ingrese el nuevo elemento a agregar: ";
    cin >> nuevoElemento;
    a.insertarElemento(nuevoElemento, 0);
    a.ImprimirVector(a.getN()-1);
    cout << "Ingrese el número que desea eliminar del vector: ";
    int numeroEliminar;
    cin >> numeroEliminar;
    a.eliminarNumero(numeroEliminar);
    

    
	return 0;
}
