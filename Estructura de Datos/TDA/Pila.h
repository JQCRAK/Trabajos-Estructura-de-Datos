// TDA Pila
// Autor: Julio Santillán C.
#include <string>

#define EXT 50		//extension por defecto de la pila
typedef std::string Tipo;	//definicion del tipo de datos a almacenar en la pila

class Pila{			//definicion de la clase
private:
	Tipo vec[EXT];	//arreglo para almacenar los datos de la pila
	int top;		//posicion que ocupa el elemento de la cima de la pila	
public:				//metodos
	Pila();			//constructor
	void setVec(Tipo v, int pos);	//definicion del metodo que actualiza el estado del atributo vec en la posicion pos
	void setTop(int v);				//definicion del metodo que actualiza el estado del atributo top
	Tipo getVec(int pos);			//definicion del metodo que devuelve el estado del atributo vec en la posicion pos
	int getTop();					//definicion del metodo que devuelve el estado del atributo top
	bool pilaVacia();				//definicion del metodo que determina si la pila esta vacia
	bool pilaLlena();				//definicion del metodo que determina si la pila esta llena
	void push(Tipo v);				//definicion del metodo que inserta un elemento en la pila
	Tipo pop();						//definicion del metodo que extrae un elemento de la pila
	void vaciarPila();				//definicion del metodo que vacia una pila
	int tamanioPila();				//definicion del metodo que calcula la cantidad de elementos que contiene la pila
	Tipo cimaPila();				//definicion del metodo que devuelve el valor que ocupa la posicion cima de la pila (no lo elimina)
};

Pila::Pila(){						//constructor
	setTop(-1);						//inicializa la pila guardando como posicion del elemento cima, el valor -1
}

void Pila::setVec(Tipo v, int pos){	//definicion del metodo que actualiza el estado del atributo vec en la posicion pos
	vec[pos] = v;					//actualiza el valor en el atributo
}

void Pila::setTop(int v){			//definicion del metodo que actualiza el estado del atributo top
	top = v;						//actualiza el valor en el atributo
}

Tipo Pila::getVec(int pos){			//definicion del metodo que devuelve el estado del atributo vec en la posicion pos
	return vec[pos];				//devuelve el valor
}

int Pila::getTop(){					//definicion del metodo que devuelve el estado del atributo top
	return top;						//devuelve el valor
}

bool Pila::pilaVacia(){				//definicion del metodo que determina si la pila esta vacia
	return (getTop() == -1);		//devuelve verdadero si top conserva el valor original
}

bool Pila::pilaLlena(){				//definicion del metodo que determina si la pila esta llena
	return (getTop() == (EXT-1));		//devuelve verdadero si top conserva el valor original
}

void Pila::push(Tipo v){			//definicion del metodo que inserta un elemento en la pila
	if (!pilaLlena()){				//aun hay espacio en la pila
		setTop(getTop()+1);			//incrementa posicion de top
		setVec(v, getTop());		//guarda el valor v en posicion top
	}
}

Tipo Pila::pop(){					//definicion del metodo que extrae un elemento de la pila
	Tipo aux;						//var para almacenar el valor de la posicion top

	if (!pilaVacia()){				//pila tiene elementos
		aux = getVec(getTop());		//almacena temporalmente el valor a devolver
		setTop(getTop()-1);			//decrementa posicion de top
	}
	return aux;						//devolver el valor
}

void Pila::vaciarPila(){			//definicion del metodo que vacia una pila
	setTop(-1);						//alterar el valor del apuntador a la cima de la pila
}

int Pila::tamanioPila(){			//definicion del metodo que calcula la cantidad de elementos que contiene la pila
	return getTop()+1;
}

Tipo Pila::cimaPila(){				//definicion del metodo que devuelve el valor que ocupa la posicion cima de la pila (no lo elimina)
	Tipo aux;						//var para almacenar el valor de la posicion top

	if (!pilaVacia()){				//pila tiene elementos
		aux = getVec(getTop());		//almacena temporalmente el valor a devolver
	}
	return aux;					//devolver el valor
}
