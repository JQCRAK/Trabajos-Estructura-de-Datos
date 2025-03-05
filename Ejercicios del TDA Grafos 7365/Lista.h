// Lista.h
// Implementa el TDA Lista simple enlazada
#ifndef _LISTA_H
#define _LISTA_H

#include "Nodo.h"

class Lista{			//definicion del TDA
private:				//atributos
	Nodo* primero;		//apuntador al primer nodo de la lista
	Nodo* buscar(Nodo* act, Tipo val);	//metodo privado que imprementa busqueda recursiva de nodo

public:									//metodos
	Lista();							//constructor
	void setPrimero(Nodo* val);			//metodo que actualiza el estado del atr
	Nodo* getPrimero();					//metodo que devuelve el estado del atr
	bool esVacia();						//metodo que determina si la lista carece de nodos
	void insertarAlInicio(Tipo val);	//metodo que inserta un valor val como primer nodo de la lista
	void insertarAlFinal(Tipo val);		//metodo que inserta un valor val como ultimo elemento de la lista
	void insertarEnOrden(Tipo val);		//metodo que permite insertar nuevos nodos ordenadamente en la lista
	Nodo* buscarElemento(Tipo val);		//metodo que permite buscar un valor en la lista
	bool eliminar(Tipo val);			//metodo que permite eliminar el nodo que contiene el valor v
	Nodo* ultimo();						//metodo que devuelve puntero al ultimo nodo de la lista
	Nodo* anterior(Tipo val);			//metodo que devuelve apuntador al nodo anterior al que contiene el valor val
	int tamanioLista(Nodo* act);		//metodo que determina el tamanio de la lista
};

Lista::Lista(){							//constructor
	setPrimero(NULL);					//inicializa la lista sin nodos
}

void Lista::setPrimero(Nodo* val){		//metodo que actualiza el estado del atr
	primero = val;						//actualizar del estado del atr
}

Nodo* Lista::getPrimero(){				//metodo que devuelve el estado del atr
	return primero;						//devolver el estado del atr
}

bool Lista::esVacia(){					//metodo que determina si la lista carece de nodos
	return (getPrimero() == NULL);		//devuelve indicador de inexistencia de nodos
}

void Lista::insertarAlInicio(Tipo val){	//metodo que inserta un valor val como primer nodo de la lista
	setPrimero(new Nodo(val, getPrimero()));
}

void Lista::insertarAlFinal(Tipo val){	//metodo que inserta un valor val como ultimo elemento de la lista
	if (esVacia()){						//lista aun vacia
		setPrimero(new Nodo(val));		//el primer nodo es el nuevo con valor recibido
	} else {							//lista no vacia
		ultimo()->setPunt(new Nodo(val));	//el ultimo nodo apunta al nuevo nodo creado con valor val
	}
}

void Lista::insertarEnOrden(Tipo val){	//metodo que permite insertar nuevos nodos ordenadamente en la lista
	Nodo* act;							//apuntador para recorrer la lista
	Nodo* ant;							//apuntador al nodo anterior al nuevo
	Nodo* nuevo;
	
	nuevo = new Nodo(val);				//creacion del nuevo nodo

	if (esVacia()){						//si la lista no contiene nodos aun
		setPrimero(nuevo);				//se añade el nuevo nodo a la lista
	} else {							//la lista contiene nodos anteriores
		ant = act = getPrimero();		//iniciamos con la direccion apuntada por inicio de lista
		while ((act != NULL) && (act->getDato() < val)) {	//recorrido mientras el nodo apuntado no apunta a null
			ant = act;					//actualiza apuntador ant
			act = act->getPunt();		//actualizar apuntador de recorrido
		}
		
		if (ant == act){				//anterior y actual son el mismo nodo
			nuevo->setPunt(getPrimero());	//nuevo nodo apunta al anterior primer nodo
			setPrimero(nuevo);			//el nuevo nodo es el primero de la lista
		} else {						//el nuevo nodo se debe insertar entre dos nodos ya existentes
			ant->setPunt(nuevo);		//nodo anterior apunta a nodo recien creado
			nuevo->setPunt(act);		//nodo recien creado apunta al nodo actual
		}
	}
}

Nodo* Lista::buscarElemento(Tipo val){		//metodo que permite buscar un valor en la lista
	return buscar(getPrimero(), val);		//devuelve valor retornado por metodo privado de busqueda
}

Nodo* Lista::buscar(Nodo* act, Tipo val){	//imprementa busqueda recursiva
	if (act != NULL){						//se apunta a un nodo
		if (act->getDato() == val){			//nodo contiene valor buscado
			return act;						//retorna dir nodo actual
		}
		return buscar(act->getPunt(), val);	//llamado recursiva a busqueda con el siguiente nodo
	}
	return NULL;							//retorna valor por defecto
}

bool Lista::eliminar(Tipo val){				//metodo que permite eliminar el nodo que contiene el valor v
	Nodo* act;								//apuntador al nodo actual
	Nodo* enc = buscarElemento(val);		//var que ubica el elemento dentro de la lista

	if (enc == NULL){						//el valor no existe en la lista
	  return false;							//devuelve indicador de fracaso del eliminacion
	}
	
	if (enc == getPrimero()){				//el valor se encuentra en el primer nodo de la lista
		setPrimero(enc->getPunt());			//primero apunta al segundo nodo
	} else {								//el valor no se encuentra en el primer nodo
		act = getPrimero();					//iniciamos con la direccion apuntada por inicio de lista
		while (act->getPunt() != enc){		//recorrido mientras el nodo apuntado no apunta a null
			act = act->getPunt();			//actualizar apuntador de recorrido
		}
		act->setPunt(enc->getPunt());		//actualiza apuntador del nodo anterior con la direcion de nodo siguiente
	}
	return true;							//devolver indicador de cumplimiento de eliminacion
}


Nodo* Lista::ultimo(){						//metodo que devuelve direccion ultimo nodo de lista
	Nodo* act;								//apuntador auxiliar para recorrer lista
	
	act = getPrimero();						//inicializacion de recorrido
	if (!esVacia()){
		while (act->getPunt() != NULL){		//el siguiente nodo apunta a null => es el ultimo
			act = act->getPunt();			//avanza al siguiente nodo
		}
	}
	return act;								//devuelve valor del apuntador
}

Nodo* Lista::anterior(Tipo val){			//metodo que devuelve apuntador al nodo anterior al que contiene el valor val
	Nodo* act;								//apuntador auxiliar para recorrer lista
	Nodo* ant = NULL;
	act = getPrimero();						//inicializacion de recorrido
	if (!esVacia()){
		while ((act->getDato() != val) && (act != NULL)){		//el siguiente nodo apunta a null => es el ultimo
			ant = act;						//actualiza dir nodo ant al actual
			act = act->getPunt();			//act avanza al siguiente nodo
		}
	}
	return ant;								//devuelve valor del apuntador
}

int Lista::tamanioLista(Nodo* act){		//funcion que determina el tamanio de la lista
	if (act != NULL){			//se apunta a un nodo
		return 1+tamanioLista(act->getPunt());		//llamado recursivo a impresion de los siguientes nodos
	}
	return 0;
}
#endif