// ArbolBinario.h
// Clase que contiene metodos de gestion de un AB
// Autor: Julio Santillán C.

#ifndef _ARBOL_BINARIO_H
#define _ARBOL_BINARIO_H

#include "NodoBinario.h"				//acceder a metodos de nodos

class ArbolBinario{						//definicion de la clase
private:								//atributos
	NodoBinario* raiz;					//apuntador al nodo raiz

//==================================================================================================

	void imprimirEsp(int c){			//metodo privado para imprimir espacios
		for (int i = 1; i <= c; i++){	//ciclo impresion espacios
			cout << "   ";
	    }
	}

//==================================================================================================

	NodoBinario* leerNodo(int margen){	//metodo privado para ingresar AB por nodos
		Tipo aux;						//var de lectura
		Tipo fin = 99999;				//marca de fin de lectura
		NodoBinario* p;					//puntero a nuevo nodo
	
		cout << endl;
		imprimirEsp(margen);			//imprimir espacios
		cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: ";
		cin >> aux;						//lectura
		
		if (aux != fin){				//no ingresa marcador de fin lectura
		   p = construirAB(aux, NULL, NULL);  	//construye nuevo nodo solo con dato
		   imprimirEsp(margen);			//imprimir espacios
		   cout << "--- SUBARBOL IZQUIERDO ---";
		   p -> setIzq(leerNodo(margen+1)) ;	//puntero izq recibe direccion nuevo nodo ingresado
		   imprimirEsp(margen);			//imprimir espacios
		   cout << "--- SUBARBOL DERECHO ---";
		   p -> setDer(leerNodo(margen+1)) ;	//puntero der recive direccion nuevo nodo ingresado
		   return p;					//devuelve direccion nuevo nodo creado
		} else {						//ingreso marcador final de lectura
			return NULL;				//no se creo el nodo
		}
	}

//==================================================================================================

	void preorden(NodoBinario *r) {		//implementa Recorrido de un árbol binario en preorden
		if (r != NULL) {
			cout << " " << r->getDato();
			preorden (r->getIzq());
			preorden (r->getDer());
		}
	}

//==================================================================================================

	void inorden(NodoBinario *r) {		//implementa Recorrido de un árbol binario en inorden
		if (r != NULL) {
			inorden (r->getIzq());
			cout << " " << r->getDato();
			inorden (r->getDer());
		}
	}

//==================================================================================================

	void postorden(NodoBinario *r) {	//implementa Recorrido de un árbol binario en postorden
		if (r != NULL) 	{
			postorden (r->getIzq());
			postorden (r->getDer());
			cout << " " << r->getDato();
		}
	}

//==================================================================================================

	NodoBinario* insertar(NodoBinario* rSub, Tipo v) {		//implementa la inserción de un nodo en AB
		if (rSub == NULL) {									//no hay nodos en arbol
			rSub = new NodoBinario(v);						//crea nuevo nodo y lo apunta desde rsub
		} else {											//si hay nodos en el arbol
			if (v < rSub->getDato()) {						//valor a insertar es menor que valor del nodo actual
				NodoBinario* iz = insertar(rSub->getIzq(), v);	//tratar de insertar a la izq del nodo actual
				rSub->setIzq(iz);							//actualiza apuntador
			} else {										//valor a insertar no es menor que valor nodo actual
				if (v > rSub->getDato()) {					//valor a insertar es mayor que valor nodo actual
					NodoBinario* dr = insertar(rSub->getDer(), v);	//tratar de insertar a derecha del nodo actual
					rSub->setDer(dr);						//actualiza apuntador
				} else {									//valor a insertar ya existe en arbol
					return NULL; 							//Nodo duplicado tratamiento de repetición
				}			
			} 
		} 
		return rSub;										//devuelve apuntador de nodo insertado
	}

//==================================================================================================

	NodoBinario* eliminar (NodoBinario *rSub, Tipo v) {		//implementa la eliminacion de un nodo del AB
		if (rSub == NULL) {									//arbol no tiene nodos
			return NULL; 									//No se ha encontrado el nodo con el valor ingresado
		} else {											//arbol si tiene nodos
			if (v < rSub->getDato()){						//valor buscado es menor que valor de nodo actual
				NodoBinario* iz = eliminar(rSub->getIzq(), v);	//tratar de eliminar en subarbol izquierdo
				rSub->setIzq(iz);							//actualiza rama izq del nodo raiz
			} else {										//valor buscado no es menor que valor nodo actual
				if (v > rSub->getDato()){					//valor buscado es mayor que valor del nodo actual
					NodoBinario* dr = eliminar(rSub->getDer(), v);	//tratar de eliminar en subarbol derecho
					rSub->setDer(dr);						//actualiza rama derecha del nodo raiz
				} else { 									//Nodo encontrado con valor buscado
					NodoBinario* q = rSub; 					// nodo a quitar del árbol
					if (q->getIzq() == NULL) {				//ramal izquierdo de este nodo es NULL
						rSub = q->getDer(); 				//se toma ramal derecho
					} else {								//si hay nodo apuntado en ramal izquierdo
						if (q->getDer() == NULL) {			//No hay nodo apuntado por ramal derecho
							rSub = q->getIzq(); 			//se toma ramal izquierdo
						} else { 							// tiene rama izquierda y derecha
							q = reemplazar(q); 				//reemplaza nodo q
						}
					}
					q = NULL;								//hace que q apunte a null
				}
			}
		}
		return rSub;										//devuelve apuntador a nodo actual
	}

//==================================================================================================

	NodoBinario* reemplazar(NodoBinario* act) {				//sustituye un nodo por otro en AB (parte de eliminación)
		NodoBinario *a, *p;
		p = act;
		a = act->getIzq();									// rama de nodos menores
		while (a->getDer() != NULL) {						//mientras haya nodos en ramal derecho
			p = a;											//actualiza apuntador
			a = a->getDer();								//recorre el ramal derecho
		}
		
		act->setDato(a->getDato());							// copia en act el valor del nodo apuntado por a
		if (p == act) { 									// a es el hijo izquierdo de act
			p->setIzq(a->getIzq());							// enlaza subarbol izquierdo
		} else {											//a no es hijo izq de act
			p->setDer(a->getIzq()); 						//se enlaza subarbol derecho
		}
		return a;											//devuelve apuntador a nodo actual
	}	

//==================================================================================================

	NodoBinario* buscar(NodoBinario* rSub, Tipo v) {		//implementa búsqueda de un nodo en el AB
		if (rSub == NULL) {									//no existen nodos
			return NULL;									//no encontro: devuelve apuntador a NULL
		} else {											//si hay nodos
			if (v == rSub->getDato()){						//valor buscado esta en este nodo
				return rSub;								//devuelve apuntador a este nodo
			} else {										//valor buscado no esta en este nodo
				if (v < rSub->getDato()){					//valor buscado es menor que valor del nodo
					return buscar(rSub->getIzq(), v);		//repite busqueda en subarbol izquierdo
				} else {									//valor buscado no es menor que valor del nodo
					return buscar(rSub->getDer(), v);		//repite busqueda en subarbol derecho
				}
			}
		} 
	}

//==================================================================================================

public:									//metodos publicos
	ArbolBinario();						//constructor

	void setRaiz(NodoBinario* v);		//metodo que actualiza el atributo
	NodoBinario* getRaiz();				//metodo que devuelve el atributo

	bool esVacio();						//metodo que determina si el AB carece de nodos
	NodoBinario* construirAB(Tipo dato, NodoBinario* i, NodoBinario* d);	//metodo para construye un nodo binario del AB

	void leer();						//metodo que permite el ingreso de los nodos de un AB
	void imprimirABSimple(NodoBinario* p);	//metodo que imprime un AB simple (sin formato jerarquico)	
	void imprimirABJerarquia(NodoBinario *p, int n); //metodo que imprime un AB con formato jerarquico

	int contarNodos(NodoBinario *r);				//determina la cantidad de nodos que posee un arbol
	int calcularAltura(NodoBinario *r);				//determina la altura de un arbol
	void verHojas(NodoBinario *r);					//visualiza las hojas de un AB

	void recorrerEnPreorden(); 						//metodo de recorrido en preorden
	void recorrerEnInorden();						//metodo de recorrido en ineorden
	void recorrerEnPostorden();						//metodo de recorrido en postorden

	void insertarNodo(Tipo valor);					//permite insertar un nuevo nodo con valor v en un arbol binario
	void eliminarNodo(Tipo valor);					//permite eliminar un nodo con valor v de un arbol binario
	NodoBinario* buscarNodo(Tipo v);				//permite buscar y encontrar un nodo con valor v en un arbol binario

	void vaciar(NodoBinario *r);					//vacia un arbol
	NodoBinario* nodoHijoIzq();						//devuelve direccion del hijo del lado izquierdo
	NodoBinario* nodoHijoDer();						//devuelve direccion del hijo del lado derecho

	bool arbolLleno(NodoBinario *r);				//determina si el arbol es lleno o no
	void copiaArbol(ArbolBinario &a);				//copia una rama del arbol
	NodoBinario* copiarArbol(NodoBinario* r);		//copia un arbol recibiendo direccion del nodo raiz
};

//==================================================================================================

ArbolBinario::ArbolBinario(){				//constructor
	setRaiz(NULL);							//al inicio no hay nodos en el AB
}

//==================================================================================================

void ArbolBinario::setRaiz(NodoBinario* v){		//metodo que actualiza el atributo
	raiz = v;
}

//==================================================================================================

NodoBinario* ArbolBinario::getRaiz(){		//metodo que devuelve el atributo
	return raiz;
}

//==================================================================================================

bool ArbolBinario::esVacio(){				//metodo que determina si el AB carece de nodos
	return (getRaiz() == NULL);				//true si raiz == null 
}

//==================================================================================================

NodoBinario* ArbolBinario::construirAB(Tipo dato, NodoBinario* i, NodoBinario* d){
	return new NodoBinario(dato, i, d);		//construye un nuevo nodo con los parametros y devuelve su direccion
}

//==================================================================================================

void ArbolBinario::leer(){					//metodo que permite lectura de un AB
	setRaiz(leerNodo(0));					//actualiza raiz del AB con apuntador devuelto por nuevo nodo ingresado
}

//==================================================================================================

void ArbolBinario::imprimirABSimple(NodoBinario* p){		//metodo que imprime un AB	
	if (p != NULL){
		cout << endl << "> " << p -> getDato();
		imprimirABSimple(p -> getIzq());
		imprimirABSimple(p -> getDer());
	}
	return;
}

//==================================================================================================

void ArbolBinario::imprimirABJerarquia(NodoBinario *p, int n){		//visualiza el abb 90@ a la izquierda
    if(p == NULL){	//no apunta a ningun nodo
       return;
	}
    imprimirABJerarquia(p -> getDer(), n+1);	//llamado recursivo pasando subarbol derecho
    imprimirEsp(n);								//espaciar la impresion
    cout << p -> getDato() << endl;				//visualiza el valor almacenado en el nodo
    imprimirABJerarquia(p -> getIzq(), n+1); 	//llamado recursivo pasando subarbol izq
}

//==================================================================================================

int ArbolBinario::contarNodos(NodoBinario *r){				//determina la cantidad de nodos que posee un arbol
	if (r == NULL) {
		return 0;
	} else {
		return 1 + contarNodos(r->getIzq()) + contarNodos(r->getDer());
	}
}

//==================================================================================================

int ArbolBinario::calcularAltura(NodoBinario *r){				//determina la altura de un arbol
	if (r == NULL) {
		return 0 ;
	} else {
		int alturaIz = calcularAltura (r->getIzq());
		int alturaDr = calcularAltura (r->getDer());
		if (alturaIz > alturaDr) {								//determina si altura de subarbol izq es mayor que la de subarbol der
			return alturaIz + 1;
		} else {
			return alturaDr + 1;
		}
	}
}

//==================================================================================================

void ArbolBinario::recorrerEnPreorden() {		// recorrido en preorden
	preorden(getRaiz());						//llama a metodo interno de recorrido
}

//==================================================================================================

void ArbolBinario::recorrerEnInorden() {		// recorrido en ineorden
	inorden(getRaiz());							//llama a metodo interno de recorrido
}

//==================================================================================================

void ArbolBinario::recorrerEnPostorden() {		// recorrido en postorden
	postorden(getRaiz());						//llama a metodo interno de recorrido
}

//==================================================================================================

void ArbolBinario::verHojas(NodoBinario *r){						//metodo de recorrido de nodos hoja							//visualiza las hojas de un AB
	if (r != NULL){													//nodo recibido no es nulo
		if ((r -> getIzq() == NULL) && (r -> getDer() == NULL)) {	//no tiene nodos hijo => hoja
			cout << endl << "> " << r -> getDato();					//visualiza dato contenido
		} else {													//si tiene nodos hijo => nodo rama
			verHojas(r -> getIzq());								//recorrer subarbol izq
			verHojas(r -> getDer());								//recorres subarbol der
		}
	}
	return;
}

//==================================================================================================

NodoBinario* ArbolBinario::buscarNodo(Tipo v){					//permite buscar y encontrar un nodo con valor v en un arbol binario
	return buscar(getRaiz(), v);								//llama a metodo interno de búsqueda
}

//==================================================================================================

void ArbolBinario::insertarNodo(Tipo v){						//permite insertar un nuevo nodo con valor v en un arbol binario
	setRaiz(insertar(getRaiz(), v));							//llama a metodo interno de insercion de nodo
}

//==================================================================================================

void ArbolBinario::eliminarNodo(Tipo v){						//permite eliminar un nodo con valor v de un arbol binario
	setRaiz(eliminar(getRaiz(), v));							//llama a metodo interno de eliminacion de nodo
}

//==================================================================================================

void ArbolBinario::vaciar(NodoBinario *r) {
	if (r != NULL)	{
		vaciar(r->getIzq());
		vaciar(r->getDer());
		r = NULL;
	}
}

//==================================================================================================

NodoBinario* ArbolBinario::nodoHijoIzq() {		//devuelve direccion del hijo del lado izquierdo
	if(getRaiz()){
		return getRaiz()->getIzq();				//devuelve valor apuntado por ramal izq
	} else {
		return NULL; 							//arbol vacio
	}
}
	
//==================================================================================================

NodoBinario* ArbolBinario::nodoHijoDer() {		//devuelve direccion del hijo del lado derecho
	if(getRaiz())
		return getRaiz()->getDer();				//devuelve direccion apuntada por ramal derecjho
	else
		return NULL; 							//arbol vacio
}

//==================================================================================================

bool ArbolBinario::arbolLleno(NodoBinario *r){	//determina si el arbol es lleno o no
	if (r == NULL) {							//arbol vacio	
		return true;							//si es arbol lleno
	} else {									//si hay nodos
		if (ArbolBinario::calcularAltura(r->getIzq()) != ArbolBinario::calcularAltura(r->getDer())) {	//altura de ramal izq diferente de altura ramal derecho
			return false;						//no es arbol lleno
		}
	}
	return arbolLleno(r->getIzq()) && arbolLleno(r->getDer());
}

//==================================================================================================

void ArbolBinario::copiaArbol(ArbolBinario &a) {
	a.setRaiz(copiarArbol(this->raiz));
}

//==================================================================================================

NodoBinario* ArbolBinario::copiarArbol(NodoBinario* r) {
	NodoBinario *rCop;									//nodo copia
	
	if (r == NULL) {									//no hay nodos en arbol
		rCop = NULL;									//en la copia pone null porque arbol esta vacio
	} else {											//arbol no vacio
		NodoBinario* izqCop, *derCop;					//dos nuevos nodos
		izqCop = copiarArbol(r->getIzq());				//en nuevo izq, pone copia de ramal izq original
		derCop = copiarArbol(r->getDer());				//en nuevo der, pone copia de ramal der del original
		rCop = new NodoBinario(r->getDato(), izqCop, derCop);	//crea nuevo nodo
	}
	return rCop;										//devuelve apuntador a la copa
}

//==================================================================================================
#endif
