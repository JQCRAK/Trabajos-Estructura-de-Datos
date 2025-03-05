/*heap00.cpp
Programa que implemente el ingreso y visualizacion de un heap minimal
*/
using namespace std;

#include <iostream>
#include "monticulo.h"
#include "Utilidades.h"

void leerMonticulo(Monticulo* m, int n);               // Prototipo de la funci�n de lectura Heap
void imprimirMonticulo(Monticulo m, int n);            // Prototipo de la funci�n de impresi�n del heap 
void eliminarMonticulo(Monticulo* m, int *n);			//prototipo de la funcion  que elimina el valor minimo del heap 
/*
void inordenMonticulo(Monticulo m, int n);             // Prototipo de la funci�n de recorrido inorden
void preordenMonticulo(Monticulo m, int n);            // Prototipo de la funci�n de recorrido preorden
void postordenMonticulo(Monticulo m, int n);           // Prototipo de la funci�n de recorrido postorden
*/
int main() {                    // Programa principal
    system("color fc");
    
    int n;          // Cantidad de nodos del mont�culo
    
    cout << endl << "Ingrese los nodos del mont�culo: ";
    n = leerN(0, MAXDATOS);         // INGRESO DE CANTIDAD DE ELEMENTOS A PROCESAR
    
    Monticulo m(n);             // Instanciar un mont�culo
    cout << endl << "Lectura del mont�culo";
    leerMonticulo(&m, n-1);                 // Llamado lectura
    cout << endl << "Impresi�n del mont�culo";
    imprimirMonticulo(m, n-1);              // Llamado de impresi�n 

	//cout << endl<< "El valor menor ingresado es: "<<m.BuscarMinimo();
	cout << endl<< "El valor menor ingresado es: "<< m.EliminarMinimo();
	
	cout << endl << "Impresi�n del mont�culo eliminando el minimo";
	imprimirMonticulo(m, n-2);


	/*
    cout << endl << "Recorrido Inorden del mont�culo:";
    inordenMonticulo(m, 0);

    cout << endl << "Recorrido Preorden del mont�culo:";
    preordenMonticulo(m, 0);

    cout << endl << "Recorrido Postorden del mont�culo:";
    postordenMonticulo(m, 0);
*/
    return 0;
}

void leerMonticulo(Monticulo* m, int n) {               // Funci�n de lectura Heap
    if (n >= 0) {
        leerMonticulo(m, n-1);                          // Llamado recursivo
        Clave vl;                                       // Var de lectura 
        cout << endl << "Valor a incluir en el Monticulo: ";
        cin >> vl;
        m->Insertar(vl);                                // Llamado a m�todos de inserci�n
    }
}

void imprimirMonticulo(Monticulo m, int n) {            // Funci�n de impresi�n del heap 
    if (n >= 0) {
        imprimirMonticulo(m, n-1);                      // Llamado recursivo
        Clave vl;                                       // Var de lectura 
        vl = m.getValor(n);
        cout << endl << " > " << vl;    
    }
}
/*
void inordenMonticulo(Monticulo m, int n) {             // Recorrido inorden
    if (n >= 0) {
        int hijoIzq = 2 * n + 1;
        int hijoDer = 2 * n + 2;
        if (hijoIzq < m.getValor(n)) {
            inordenMonticulo(m, hijoIzq);
        }
        cout << m.getValor(n) << " ";
        if (hijoDer < m.getValor(n)) {
            inordenMonticulo(m, hijoDer);
        }
    }
}

void preordenMonticulo(Monticulo m, int n) {            // Recorrido preorden
    if (n >= 0) {
        cout << m.getValor(n) << " ";
        int hijoIzq = 2 * n + 1;
        int hijoDer = 2 * n + 2;
        if (hijoIzq < m.numDatosAct) {
            preordenMonticulo(m, hijoIzq);
        }
        if (hijoDer < m.numDatosAct) {
            preordenMonticulo(m, hijoDer);
        }
    }
}

void postordenMonticulo(Monticulo m, int n) {           // Recorrido postorden
    if (n >= 0) {
        int hijoIzq = 2 * n + 1;
        int hijoDer = 2 * n + 2;
        if (hijoIzq < m.numDatosAct) {
            postordenMonticulo(m, hijoIzq);
        }
        if (hijoDer < m.numDatosAct) {
            postordenMonticulo(m, hijoDer);
        }
        cout << m.getValor(n) << " ";
    }
}
*/

