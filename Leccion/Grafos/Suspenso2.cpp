/*Ingreso de una pila ordenar valores de una pila
Recuperacion02
Nota: cada funcion hace una sola cosa para tener la mejor opcion de usar funciones
usar parametros por referencia cuando si y cuando no 
*/
using namespace std;
#include <iostream>
#include "Pila.h"
#define FIN 999

int main() {
    system("color f5");
    Pila p;  // declaración del TDA
	void leerPila(Pila* p);               // ingresar valores
	void ordenarPila(Pila* p);
	void imprimirPila(Pila p);            // impresión
	void ordenarSegmentado(Pila* p, int segmento, int n);
	void insertarOrdenado(Pila* p, Tipo elemento);
	void insertarOrdenadoAsc(Pila* p, Tipo elemento, int n);
	void insertarOrdenadoDesc(Pila* p, Tipo elemento, int n) ;
	void ordenarAsc(Pila* p, int n);
	void ordenarDesc(Pila* p, int n);
	
    leerPila(&p);  // llamado a la función
    //ordenarPila(&p);
    
    ordenarSegmentado(&p, 0, 3);  // Iniciamos la ordenación segmentada
    
    cout << endl << "VALORES ORDENADOS EN SEGMENTOS:" << endl;
    imprimirPila(p);


    return 0;
}

void leerPila(Pila* p) {
    Tipo vl;
    cout << endl << "Ingrese un valor: ";
    cin >> vl;
    if (vl != FIN) {
        p->push(vl);
        leerPila(p);
    }
}

void imprimirPila(Pila p) {
    if (!p.pilaVacia()) {
        cout << ">" << p.pop() << endl;
        imprimirPila(p);
    }
}
/*
void insertarOrdenado(Pila* p, Tipo elemento) {
    if (p->pilaVacia() || p->cimaPila() <= elemento) {
        p->push(elemento);
    } else {
        Tipo temp = p->pop();
        insertarOrdenado(p, elemento);
        p->push(temp);
    }
}

void ordenarPila(Pila* p) {
    if (!p->pilaVacia()) {
        Tipo valor = p->pop();
        ordenarPila(p);
        insertarOrdenado(p, valor);
    }
}
*/
void insertarOrdenadoAsc(Pila* p, Tipo elemento, int n) {
    if (n == 0 || p->pilaVacia() || p->cimaPila() <= elemento) {
        p->push(elemento);
    } else {
        Tipo temp = p->pop();
        insertarOrdenadoAsc(p, elemento, n - 1);
        p->push(temp);
    }
}

void insertarOrdenadoDesc(Pila* p, Tipo elemento, int n) {
    if (n == 0 || p->pilaVacia() || p->cimaPila() >= elemento) {
        p->push(elemento);
    } else {
        Tipo temp = p->pop();
        insertarOrdenadoDesc(p, elemento, n - 1);
        p->push(temp);
    }
}

void ordenarAsc(Pila* p, int n) {
    if (n > 0 && !p->pilaVacia()) {
        Tipo valor = p->pop();
        ordenarAsc(p, n - 1);
        insertarOrdenadoAsc(p,valor,n);
    }
}

void ordenarDesc(Pila* p, int n) {
    if (n > 0 && !p->pilaVacia()) {
        Tipo valor = p->pop();
        ordenarDesc(p, n - 1);
        insertarOrdenadoDesc(p, valor, n);
    }
}

void ordenarSegmentado(Pila* p, int segmento, int n) {
    if (!p->pilaVacia()){
		 if (segmento % 2 == 0) {
	        ordenarAsc(p, n);
	    } else {
	        ordenarDesc(p, n);
	    }
	
	    if (!p->pilaVacia()) {
	        ordenarSegmentado(p, segmento + 1, n);
	    }
	}
}





