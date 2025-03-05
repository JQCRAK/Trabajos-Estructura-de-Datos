// Monticulo.h
// Implementa TDA Monticulo

#ifndef _MONTICULO_H
#define _MONTICULO_H

#define MAXDATOS 20
typedef int Clave;

class Monticulo {							//definicion de la clase
private:									//elementos privados: atributos
	Clave *val;								//vector de valores a almacenar en monticulo
	int numDatosMax;						//numero maximo de elementos y cantidad actual
	int numDatosAct;						//numero actual de elementos
											//metodos privados
	int getPosPadre(int i); 				//metodo que devuelve la posicion de padre de i
	int getPosHiIzq(int i); 				//metodo que devuelve la posicion de hijo izquierdo de i
	int getPosHiDer(int i); 				//metodo que devuelve la posicion de hijo derecho de i
	void flotar(int i);						//metodo que realiza el movimiento hacia arriba, en busca de la posición de inserción
	bool Lleno(); 							//metodo que determina si monticulo está lleno
	void criba (int r);						//metodo que modifica posicion de nodo raiz para ubicarlo en la posición requerida para cumplir condicion de monticulo. Llamado desde eliminar minimo
	void criba1(Clave v[], int r, int ult);	//llamado desde ordenar

public:										//metodos publicos
	Monticulo(); 							//constructor por defecto
	Monticulo(int n); 						//constructor conociendo cantidad de elementos a contener en monticulo
	void setNumDatosMax(int v);				//actualiza el estado del atributo numero datos maximo
	void setNumDatosAct(int v);				//actualiza el estado del atributo numero datos actual

	int getNumDatosMax();					//metodo que devuelve estado numero datos maximo
	int getNumDatosAct();					//metodo que devuelve estado numero datos actual
	Clave getValor(int pos);				//devuelve el valor almacenado en la posicion especifica

	void Insertar(Clave e); 				//añade al montículo
	void ordenar(Clave val[], int n); 		// el vector tiene n datos en las posiciones 0,1,…n-1
	Clave BuscarMinimo(); 					//retorna el elemento menor del montículo
	Clave EliminarMinimo(); 				//elimina el primer elemento
	bool Esvacio(); 						// está vacío
};

Monticulo::Monticulo() {						//constructor sin parametros
	setNumDatosMax(MAXDATOS);					//inicializa cantidad maxima de valores a manipular
	setNumDatosAct(0);							//hasta el momento no existen valores en monticulo: inicializa contador
	val = new Clave[getNumDatosMax()];			//inicializa el vector de valores con capacidad para cantidad maxima de elmemtos
}

Monticulo::Monticulo(int n){					//constructor conociendo cantidad de elementos a procesar
	setNumDatosMax(n);							//inicializa cantidad maxima de valores a manipular
	setNumDatosAct(0);							//hasta el momento no existen valores en monticulo: inicializa contador
	val = new Clave[getNumDatosMax()];			//inicializa el vector de valores con capacidad para cantidad maxima de elmemtos
}

void Monticulo::setNumDatosMax(int v){			//actualiza el estado del atributo numero datos maximo
	numDatosMax = v;							//almacena valor
}

void Monticulo::setNumDatosAct(int v){			//actualiza el estado del atributo numero datos actual
	numDatosAct = v;							//almacena valor
}

int Monticulo::getNumDatosMax(){				//metodo que devuelve estado numero datos maximo
	return numDatosMax;							//devuelve valor
}

int Monticulo::getNumDatosAct(){				//metodo que devuelve estado numero datos actual
	return numDatosAct;							//devuelve valor
}

Clave Monticulo::getValor(int pos){				//devuelve el valor almacenado en la posicion especifica
	return val[pos];
}

int Monticulo::getPosPadre(int i){				//devuelve posicion del nodo padre
	return (i - 1) / 2;
}

int Monticulo::getPosHiIzq(int i) {				//devuelve posicion del nodo hijo izquierdo
	return (2 * i + 1);
}

int Monticulo::getPosHiDer(int i){				//devuelve posicion de nodo hijo derecho
	return (2 * i + 1) + 1;
}		

void Monticulo::flotar(int i){					//realiza el movimiento hacia arriba, en busca de la posición de inserción
	Clave aux = val[i]; 						//se almacena el valor a flotar
	while ((i > 0) && (val[getPosPadre(i)] > aux)){	//mientras haya nodos padre
		val[i] = val[getPosPadre(i)];			//valor del nodo padre baja al espacio encontrado
		i = getPosPadre(i); 					//sube un nivel en el árbol
	}
	val[i] = aux; 								//sitúa el valor en la posición adecuada
}

bool Monticulo::Lleno() {						//determina si se alcanzo cantida maxima de nodos 
	return (getNumDatosMax() == getNumDatosAct());	//true si se alcanzo numero maximo de elementos
}

void Monticulo::Insertar(Clave v){				//inserta nuevo dato en monticulo

	if (!Lleno()) {								//monticulo no lleno => insertar
		val[getNumDatosAct()] = v;				//añade valor nuevo en vector de valores
		flotar(getNumDatosAct());				//desplaza elementos para conservar relacion entre elmentos
		setNumDatosAct(getNumDatosAct()+1);		//incrementa contador de numero de datos actual
	}
	else {
		cout << endl << "ERROR....Montículo lleno...";	//genera condicion de error
	}
}

void Monticulo::ordenar(Clave val[], int n){ 			// el vector tiene n datos en las posiciones 0,1,…n-1
	int j;

	for (j = (n - 1) / 2; j >= 0; j--){					//intercambiar los extremos, decrementar en 1 la posición del extremo superior y reconstruir el montículo del nuevo vector
		criba1(val, j, n-1 );
	}

	for (j = (n - 1); j >= 1; j--){						//intercambiar valores
		Clave c;
		c = val[0];										//intercambio
		val[0] = val[j];
		val[j] = c;
		criba1(val, 0, j-1 );								//reordenar monticulo
	}
}

Clave Monticulo:: BuscarMinimo(){				//determina el valor minimo del monticulo
	if (!Esvacio()) {							//no es monticulo vacio
		return val[0];							//devuelve valor minimo del monticulo
	}
	cout << endl << "ERROR....Montículo vacio...";	//genera condicion de error
	Clave x;									//devuelve elemento vacio
	return x;
}

bool Monticulo::Esvacio(){						//determina si el monticulo aun no contiene valores
	return (getNumDatosAct() == 0);				//true si hay 0 elementos actuales
}

void Monticulo::criba(int r){						//modifica posicion de nodo raiz para ubicarlo en la posición requerida para cumplir condicion de monticulo
	bool esMont = false;							//var bandera para indicar si cumple condicion monticulo
	int hi = getPosHiIzq(r), hd = getPosHiDer(r);	//inicializa variables
	int hm = hi;		 							//el candidato a hijo menor es hijoi

	while ((hm <= getNumDatosAct()-1) && !esMont){ 	// determina el índice del hijo menor
		if (hm < (getNumDatosAct() - 1)){ 			//único descendiente
			if (val[hm] > val[hd]){ 				//hijo menor es mayor que hijo derecho
				hm = hd;							//hijo menor recibe valor hijo derecho
			}
		}

		if (val[hm] < val[r]){						//compara raiz con el menor de los hijos
			Clave c = val[r];						//pone en c nodo raiz
			val[r] = val[hm];						//en raiz pone hijo menor
			val[hm] = c;							//en hijo menor pone c
			r = hm;									//en raiz pone hijo menor continua rama de claves mínimas
		} else {									//hijo menor no es inferior a raiz
			esMont = true;							//si cumple condicion de monticulo
		}
		
		hi = getPosHiIzq(r);						//actualiza variables de recorrido del monticulo
		hd = getPosHiDer(r);
		hm = hi;
	}
}

Clave Monticulo::EliminarMinimo(){				//elimina el primer nodo del monticulo y en su lugar pone el ultimo elemento. Con Criba implementa condicion de monticulo
	if (!Esvacio()) {
		Clave menor;
		menor = val[0];							//guarda temporalmente el valor a devolver como respuesta
		val[0] = val[getNumDatosAct() - 1];		//posiciona en raiz el ultimo nodo del monticulo
		setNumDatosAct(getNumDatosAct()-1);		//disminuye el tamaño del monticulo
	    criba(0);								//reordena elementos restantes del monticulo
		return menor;							//devuelve valor eliminado
	} else {
		cout << endl << "ERROR....Montículo vacio...";	//genera condicion de error
		Clave x;									//devuelve elemento vacio
		return x;
	}
}

void Monticulo::criba1(Clave val[], int r, int ult){
	bool esMont = false;							//var bandera para indicar si cumple condicion monticulo
	int hj = 2 * r + 1;								//posicion de nodo hijo

	while (hj <= ult && !esMont){ 					//determina el índice del hijo mayor
		if (hj < ult ){ 							//único descendiente
			if (val[hj] < val[hj + 1]){				//valor nodo hijo menor que valor siguiente
				hj++;								//continua recorriendo
			}
		}
		
		if (val[hj] > val[r]){						//compara raiz con el mayor de los hijos
			Clave c = val[r];						//auxiliar para intercambio
			val[r] = val[hj];						//entre nodo raiz e hijo
			val[hj] = c;
			r = hj; 								// continúa por la rama de claves mínimas
		} else {
			esMont = true;							//cumple condicion monticulo
		}
		hj = 2 * r + 1;								//calcula posicion siguiente nodo hijo
	}
}
#endif
