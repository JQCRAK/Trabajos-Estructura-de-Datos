
// NodoBinario.h
// contiene la definicion de cada nodo de un AB

#ifndef _NODO_BINARIO_H
#define _NODO_BINARIO_H

typedef int Tipo;		//definicion del tipo de valores que contendra cada nodo

class NodoBinario{		//definicion de la clase nodobinario
private:				//atributos
	Tipo dato;			//atributo que contiene el valor del nodo
	NodoBinario* izq;	//apuntador al subarbol izquierdo
	NodoBinario* der;	//apuntador al subarbol derecho
	
public:					//metodos
	NodoBinario();		//constructor por defecto
	NodoBinario(Tipo val);		//constructor conociendo el dato a almacenar en el nodo
	NodoBinario(Tipo val, NodoBinario* i, NodoBinario* d);		//constructor conociendo el dato a almacenar en el nodo y los apuntadores
	void setDato(Tipo val);	//metodo que actualiza el estado del atributo
	void setIzq(NodoBinario* val);	//metodo que actualiza el estado del atributo
	void setDer(NodoBinario* val);	//metodo que actualiza el estado del atributo
	Tipo getDato();					//metodo que devuelve el estado del atributo
	NodoBinario* getIzq();			//metodo que devuelve el estado del atributo
	NodoBinario* getDer();			//metodo que devuelve el estado del atributo
};

NodoBinario::NodoBinario(){		//constructor por defecto
	setIzq(NULL);				//empieza apuntando a null subarbol izquierdo
	setDer(NULL);				//empieza apuntando a null subarbol derecho
}

NodoBinario::NodoBinario(Tipo val){		//constructor conociendo el dato a almacenar en el nodo
	setDato(val);				//actualiza el estado del atributo dato
	setIzq(NULL);				//empieza apuntando a null subarbol izquierdo
	setDer(NULL);				//empieza apuntando a null subarbol derecho
}

NodoBinario::NodoBinario(Tipo val, NodoBinario* i, NodoBinario* d){		//constructor conociendo el dato a almacenar en el nodo y los apuntadores
	setDato(val);				//actualiza el estado del atributo dato
	setIzq(i);				//empieza apuntando a null subarbol izquierdo
	setDer(d);				//empieza apuntando a null subarbol derecho
}

void NodoBinario::setDato(Tipo val){	//metodo que actualiza el estado del atributo
	dato = val;					//almacena el parametro en el atributo
}

void NodoBinario::setIzq(NodoBinario* val){	//metodo que actualiza el estado del atributo
	izq = val;					//almacena el parametro en el atributo
}

void NodoBinario::setDer(NodoBinario* val){	//metodo que actualiza el estado del atributo
	der = val;					//almacena el parametro en el atributo
}

Tipo NodoBinario::getDato(){					//metodo que devuelve el estado del atributo
	return dato;				//devuelve el valor contenido en el atributo
}

NodoBinario* NodoBinario::getIzq(){			//metodo que devuelve el estado del atributo
	return izq;				//devuelve el valor contenido en el atributo
}

NodoBinario* NodoBinario::getDer(){			//metodo que devuelve el estado del atributo
	return der;				//devuelve el valor contenido en el atributo
}


#endif
