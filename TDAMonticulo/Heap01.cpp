/*Ejercicio 001
Ingresar Heap y determinar nodos hojas
*/
using namespace std;

#include <iostream>
#include "monticulo.h"
#include "Utilidades.h"

int main(){                    //programa princiapl
    system("color fc");

    int n;            //cantidad de nodos del monticulo

    void leerMonticulo(Monticulo* m, int n);                 //prototipo de la funcion de lectura Heap
    void imprimirMonticulo(Monticulo m, int n);                //prototipo de funcion de impresion del heap 
    void recorrerMonticulo(Monticulo m,int n, int i);
    

    cout <<endl<< "Ingrese los nodos del monticulo: ";
    n=leerN(0,MAXDATOS);            //INGRESO DE CANTIDAD DE ELEMENTOS A PROCESAR

    Monticulo m(n);                //instaciar un montiulo
    cout <<endl<<"Lectura del monticulo";
    leerMonticulo(&m,n-1);                 //llamado lectura
    cout << endl<<"Impresion del menticulo";
    imprimirMonticulo(m,n-1);                //llamado de impreion 
    cout << endl<<"Monticulo sus Hojas";
    recorrerMonticulo(m,n, 0);


}

void leerMonticulo(Monticulo* m, int n){                 //funcion de la funcion de lectura Heap
    if (n>=0){
        leerMonticulo(m,n-1);                            //llamado recrusivo
        Clave vl;                                        //var de lectura 
        cout << endl<< "Valor a incluir en el Monticulo: ";
        cin >> vl;
        m->Insertar(vl);                                //llamado a metodos de inserccion
    }
}

void imprimirMonticulo(Monticulo m, int n){                //funcion de funcion de impresion del heap 
    if (n>=0){
        imprimirMonticulo(m,n-1);                            //llamado recrusivo
        Clave vl;                                        //var de lectura 
        vl=m.getValor(n);
        cout << endl<< " > "<<vl;
    }
}


void recorrerMonticulo(Monticulo m,int n, int i){
	if(i < n){//caso base: posisciion actual esta dentro del monticulo
		if (((2*i)+1)>n){
		cout <<endl<< " > "<<m.getValor(i);
	}
	recorrerMonticulo(m, n, ((2*i)+1));//
	recorrerMonticulo(m, n, ((2*i)+2));
	}	
}
