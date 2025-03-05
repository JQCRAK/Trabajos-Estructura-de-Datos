// Vertice.h
// Definicion de la clase que origina los vertices de grafos
using namespace std;
typedef std::string TipoG;			//definicion de la calidad de datos que se pueden almacenar en el vertice

#ifndef _VERTICE_H
#define _VERTICE_H

class Vertice{				//definicion de la clase vertice
private:					//atributos
	TipoG dato;				//valor contenido en el vertice
	int num;				//valor que contiene el ordinal del vertice
	
public:						//metodos
	Vertice();				//constructor
	Vertice(TipoG v1);		//constructor conociendo el dato a contener
	Vertice(TipoG v1, int v2);	//constructor conociendo el dato y el numero de orden del vertice
	void setDato(TipoG val);//metodo que actualiza estado del atr
	void setNum(int val);	//metodo que actualiza estado del atr
	TipoG getDato();		//metodo que devuelve estado del atr
	int getNum();			//metodo que devuelve estado del atr
	bool esIgualDato(TipoG val);	//metodo que determina si val corresponde al valor contenido en atr dato
	bool esIgualNum(int val);//metodo que determina si val corresponde al valor contenido en atr num
};

Vertice::Vertice(){			//constructor
	setNum(0);				//inicializar del ordinal del vertice	
}

Vertice::Vertice(TipoG v1){	//constructor conociendo el dato a contener
	setDato(v1);			//actualiza el estado del atr
	setNum(0);				//inicializar del ordinal del vertice	
}

Vertice::Vertice(TipoG v1, int v2){	//constructor conociendo el dato y el numero de orden del vertice
	setDato(v1);				//actualiza el estado del atr
	setNum(v2);				//inicializar del ordinal del vertice	
}

void Vertice::setDato(TipoG val){//metodo que actualiza estado del atr
	dato = val;
}

void Vertice::setNum(int val){	//metodo que actualiza estado del atr
	num = val;
}

TipoG Vertice::getDato(){		//metodo que devuelve estado del atr
	return dato;
}

int Vertice::getNum(){			//metodo que devuelve estado del atr
	return num;
}

bool Vertice::esIgualDato(TipoG val){	//metodo que determina si val corresponde al valor contenido en atr dato
	return (getDato() == val);		//compara atr dato con val y devuelve el resultado
}

bool Vertice::esIgualNum(int val){//metodo que determina si val corresponde al valor contenido en atr num
	return (getNum() == val);		//compara atr num con val y devuelve el resultado
}

#endif
