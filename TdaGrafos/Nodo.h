// Nodo.h
// Definicion de la clase nodo de una lista

#ifndef _NODO_H
#define _NODO_H

typedef int Tipo;			//definicion del tipo de dato que contiene cada nodo

class Nodo{					//definicion de la clase
private:					//atributos
	Tipo dato;				//atr que contiene el valor del nodo
	Nodo* punt;				//atr que permite apuntar al siguiente nodo
	
public:						//metodos
	Nodo();					//constructor
	Nodo(Tipo val);			//constructor conociendo el valor a contener
	Nodo(Tipo val, Nodo* p);//constructor conociendo el valor a contener y la direccion del nodo a apuntar
	void setDato(Tipo val);	//metodo que actualiza el atr dato
	void setPunt(Nodo* val);//metodo que actualiza el atr punt
	Tipo getDato();			//metodo que devuelve estado del atr dato
	Nodo* getPunt();		//metodo que devuelve estado del atr punt
};

Nodo::Nodo(){					//constructor
	setPunt(NULL);				//inicializa del nodo se consigue con apuntador a NULL
}

Nodo::Nodo(Tipo val){			//constructor conociendo valor a contener
	setDato(val);				//inicializa el nodo con el valor recibido
	setPunt(NULL);				//inicializa del nodo se consigue con apuntador a NULL
}

Nodo::Nodo(Tipo val, Nodo* p){		//constructor conociendo el valor a contener y la direccion del nodo a apuntar
	setDato(val);				//inicializa el nodo con el valor recibido
	setPunt(p);					//inicializa del nodo se consigue con apuntador a p
}

void Nodo::setDato(Tipo val){	//metodo que actualiza el atr dato
	dato = val;					//actualiza el atr
}

void Nodo::setPunt(Nodo* val){	//metodo que actualiza el atr punt
	punt = val;					//actualiza el atr
}

Tipo Nodo::getDato(){			//metodo que devuelve estado del atr dato
	return dato;				//devuelve el estado del atr
}

Nodo* Nodo::getPunt(){			//metodo que devuelve estado del atr punt
	return punt;				//devuelve el estado del atr
}

#endif