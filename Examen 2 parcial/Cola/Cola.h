// Cola.h
// Implementa el TDA Cola

typedef int Tipo;		//definicion del tipo de datos que contendra la estructura
#define EXT 50			//dimension maxima del TDA

class Cola{				//definicion del TDA
private:				//atributos
	Tipo vec[EXT];		//definicion del arreglo contenedor de datos
	int frente;			//apuntador a posicion de extraccion de elementos del TDA
	int final;			//apuntador a posicion de insercion de elementos en el TDA
	
public:					//metodos
	Cola();				//constructor
	void setVec(Tipo val, int pos);	//actualizar el estado de la posicion pos del arreglo vec
	void setFrente(int val);		//actualizar el estado del atributo con valor val
	void setFinal(int val);			//actualizar el estado del atributo con valor val
	Tipo getVec(int pos);			//devuelve el estado del atr que se encuentra en la posicion pos
	int getFrente();				//devuelve el estado del atr
	int getFinal();					//devuelve el estado del atr
	void borrarCola();				//reinicializar el TDA
	bool colaVacia();				//determina si el TDA esta vacio
	bool colaLlena();				//determina si el TDA esta lleno
	int tamanioCola();				//determina la cantidad de elementos actuales en el TDA
	Tipo quitar();					//eliminar un elemento del TDA
	void insertar(Tipo val);		//insertar el elemento val en el TDA
	Tipo frenteCola();				//devolver el valor del TDa ubicado en pos frente
};

Cola::Cola(){				//constructor
	setFinal(-1);	//apuntador de insercion a posicion anterior a 0
	setFrente(0);	//apuntador de eliminacion a primera ubicacion del arreglo
}

void Cola::setVec(Tipo val, int pos){	//actualizar el estado de la posicion pos del arreglo vec
	vec[pos] = val;				//actualizar estado
}

void Cola::setFrente(int val){		//actualizar el estado del atributo con valor val
	frente = val;				//actualizar
}

void Cola::setFinal(int val){			//actualizar el estado del atributo con valor val
	final = val;				//actualizar
}

Tipo Cola::getVec(int pos){			//devuelve el estado del atr que se encuentra en la posicion pos
	return vec[pos];			//retorna el estado del atr
}

int Cola::getFrente(){				//devuelve el estado del atr
	return frente;				//retornar estado del atr
}

int Cola::getFinal(){					//devuelve el estado del atr
	return final;				//retornar estado del atr
}

void Cola::borrarCola(){				//reinicializar el TDA
	setFinal(-1);	//apuntador de insercion a posicion anterior a 0
	setFrente(0);	//apuntador de eliminacion a primera ubicacion del arreglo
}

bool Cola::colaVacia(){			//determina si el TDA esta vacio
	return (getFrente() > getFinal());	//cuando frente apunta a pos mayor que final
}

bool Cola::colaLlena(){			//determina si el TDA esta lleno
	return (getFinal() >= (EXT - 1));	//cuando frente apunta a pos mayor que final
}

int Cola::tamanioCola(){				//determina la cantidad de elementos actuales en el TDA
	return ((getFinal() - getFrente()) + 1);		//calcula cantidad de elementos actuales del TDA
}

Tipo Cola::quitar(){					//eliminar un elemento del TDA
	Tipo aux;
	
	if (!colaVacia()){					//el TDA si contiene elementos
		aux = getVec(getFrente());		//almacena temporalmente el valor de posicion frente del TDA
		setFrente(getFrente()+1);		//incrementar apuntador frente
	}
	return aux;							//retornar el valor extraido del TDA
}

void Cola::insertar(Tipo val){			//insertar el elemento val en el TDA
	if (!colaLlena()){
		setFinal(getFinal()+1);			//incrementar apuntador de insercion
		setVec(val, getFinal());		//almacena val en pos final
	}
}

Tipo Cola::frenteCola(){				//devolver el valor del TDa ubicado en pos frente
	Tipo aux;
	
	if (!colaVacia()){					//el TDA si contiene elementos
		aux = getVec(getFrente());		//almacena temporalmente el valor de posicion frente del TDA
	}
	return aux;							//retornar el valor extraido del TDA
}
