/*Jhostin 7365
TDA Vector  
Implemente datos y operaciones basicas de gestion de vectores*/
using namespace std;
#define EXT 20           //extencion maxina del vector

class Vector{				 //Definicion del TDA
private: 						//atributos
	int n;						//cantidad de elementos del vector
	int v[EXT];					//vector 
public:                        //metodos
	Vector();                 //CONSTRUCTOR
	void setN(int val);			//metodo que actualiza el estado del atributo n
	void setV(int val,int pos);			//metodo que actualiza el estado del atributo V en la posicion pos
	int getN();                 		//metodo que devuelve el estado del atributo
	int getV(int pos);    //metodo que devuelve el estado del atributo pos
	void leerVector(int p);			//metodo que permite el ingreso al vector 
	void ImprimirVector(int p);             //metodo para imprimir valores edl vector
	void metodoI(int i);      //metodo para ordenar por el metodi de insercion
	void iEpC(int pos);               //metodo de insetar en la poscion correcta del metodo de insercion
	void InsertarMm(int p, int g);  //metodo para insertar de mayor a menor recursivo
	void iMM(int p, int g); //metodo para insertar de mayor a menor
	void shellSortU(int g);    //metodo de shellsort dividir en dos partes
	void shellSort(int g); //metodo de shellsort ordenado
	void Burbuja(int f);      //metodo de burbuja ordenado en elvector
	void metodoB(int i, int f);     //metodo de ordenar 
	void Seleccion(int i);       //metodo de selecion 
	void enconMax(int i, int f, int& max);  //metodo de seleccion comparar numeros
	void busquedaSecuencial(int v);            //Metodo de buscar con el metodo secuencial
	void buscarV(int& pos, int val, int i);              //Metodo en buscar para el metodo secuencial
	int busquedaBinaria(int val, int izquierda, int derecha);   //Metodo de busqueda Binaria 
	void insertarElemento(int valor, int pos);          //Metodo Insertar elemento 
	void eliminarNumero(int numero);             //Metodo Elimnar un elemnto
	void eliminarRecursivo(int numero, int i);         //Metodo Eleminar en recursivo
	
};


Vector::Vector(){                 //CONSTRUCTOR
	setN(0);						//iniciaaliza la xantidad de elemetos del arreglo
}	
void Vector::setN(int val){			//metodo que actualiza el estado del atributo n
	n=val;                             //acyualiza v[pos]
	
}
void Vector::setV(int val,int pos){		//metodo que actualiza el estado del atributo V en la posicion pos
	v[pos]=val;
}
int Vector::getN(){                 		//metodo que devuelve el estado del atributo
	return n;
}
int Vector::getV(int pos){    //metodo que devuelve el estado del atributo pos
	return v[pos];
}

void Vector::leerVector(int p){ 				//metodo que permite el ingreso de volver
	int aux;
	if(p>=0){
		leerVector(p-1);                           // llamado recursivo
		cout <<"Ingrese un valor en la posicion ["<<p+1<<"]:";
		cin >> aux;
		setV(aux,p);              //guarda el valor leido en el vector
	}
	
}

void Vector::ImprimirVector(int p) {
    if (p >= 0) {
        ImprimirVector(p - 1);  // Llamada recursiva para imprimir elementos anteriores
        cout << v[p] << " ";    // Imprimir el elemento en la posición p
    }
}

//metodo de Insercion
void Vector::metodoI(int i) {
    if (i > 0) {
        // Llamada recursiva para insertar los elementos anteriores
        metodoI(i - 1);
        // Insertar el elemento en la posición adecuada para mantener el orden creciente
        iEpC(i);
    }
}

void Vector::iEpC(int pos) {
    if (pos <= 0) {
        return;  // Caso base: ya estamos en la primera posicion
    }

    int aux = v[pos];
    int j = pos - 1;

    // Si el elemento anterior es mayor que el elemento actual, desplazarlo hacia adelante
    if (j >= 0 && aux < v[j]) {
        v[j + 1] = v[j];
        v[j] = aux;
        iEpC(j);  // Llamada recursiva para seguir comparando hacia atras
    }
}


//metodo shellshort
void Vector::InsertarMm(int p, int g) {  //metodo para insertar de mayor a menor recursivo
    if (p < n && p - g >= 0) {
        if (v[p] > v[p - g]) {
            int temp = v[p];
            v[p] = v[p - g];
            v[p - g] = temp;
            InsertarMm(p - g, g);
        }	
    }
}

void Vector::iMM(int p, int g) {   //metodo para insertar de mayor a menor
    if (p < n) {
        InsertarMm(p, g);
        iMM(p + g, g);
    }
}

void Vector::shellSortU(int g) {     //metodo de shellsort dividir en dos partes
    if (g > 0) {
        shellSort(g / 2);
        iMM(g, g);
    }
}

void Vector::shellSort(int g) { //metodo de shellsort ordenado
    shellSortU(g);
}
//metodo de burbuja
void Vector::Burbuja(int f){
    if (f == 0)
        return;
    metodoB(0, f);
    Burbuja(f - 1);
}

void Vector::metodoB(int i, int f) {
    if (i == f)
        return;
    if (v[i] > v[i + 1]) {
        // Intercambia los elementos si estan en el orden incorrecto
        int aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
    }
    metodoB(i + 1, f);
}
//metodo de seleccion
void Vector::Seleccion(int i) {            //metodo de selecion 
    if (i >= n - 1)
        return;

    int mI = i;
    enconMax(i + 1, n - 1, mI);

    if (mI != i) {
        int aux = v[i];
        v[i] = v[mI];
        v[mI] = aux;
    }

    Seleccion(i + 1);
}

void Vector::enconMax(int i, int f, int& max) {   //metodo de seleccion comparar numeros
    if (i > f)
        return;

    if (v[i] > v[max])
        max = i;

    enconMax(i + 1, f, max);
}
//metodo de busqueda Secuencial
void Vector::busquedaSecuencial(int v) {            //Metodo de buscar con el metodo secuencial
    int pos = -1;
    if (n <= 0) {
        cout << "El vector esta vacio" << endl;
        return;
    }
    buscarV(pos, v, 0);
    if (pos != -1) {
        cout << "El valor " << v << " se encuentra en la posicion [" << pos+1 << "]" << endl;
    } else {
        cout << "El valor " << v << " no se encuentra en el vector" << endl;
    }
}

void Vector::buscarV(int& pos, int val, int i) {              //Metodo en buscar para el metodo secuencial
    if (pos != -1 || i >= n) {
        return;
    }
    if (v[i] == val) {
        pos = i;
    }
    buscarV(pos, val, i + 1);
}
//metodo de busqueda binaria
int Vector::busquedaBinaria(int val, int iz, int de) {
    int resultado = -1;
    while (iz <= de) {
        int medio = iz + (de - iz) / 2;

        if (v[medio] == val) {
            resultado = medio; // Se ha encontrado el valor en la posicion medio
            break;
        } else if (v[medio] < val) {
            iz = medio + 1; // Buscar en la mitad derecha del subarreglo
        } else {
            de = medio - 1; // Buscar en la mitad izquierda del subarreglo
        }
    }
    return resultado;
}




//Metodo de agregar un elemento
void Vector::insertarElemento(int valor, int pos) {          //Metodo Insertar elemento 
    if (pos == n) {
        // Llegamos al final del vector simplemente agregamos el elemento
        setV(valor, pos);
        setN(n + 1); // Incrementa el tamanio del vector
    } else {
        // Guardamos el valor actual en la posicion siguiente
        int valorActual = getV(pos);
        // Llamada recursiva para llegar a la posicion de insercion
        insertarElemento(valor, pos + 1);
        // Una vez que llegamos a la posición de insercion, restauramos el valor original en la posicion actual
        setV(valorActual, pos);
    }
}
//Metodo de eliminar dato
 
void Vector::eliminarNumero(int numero) {               //Metodo Elimnar un elemento
    int posicion = -1;
    buscarV(posicion, numero, 0); // Utiliza la funcion de búsqueda para encontrar la posicion del numero

    if (posicion != -1) {
        // Se ha encontrado el numero en el vector, eliminarlo
        eliminarRecursivo(numero, posicion);

        // Imprimir el nuevo vector despues de eliminar el numero
        cout << "El Vector despues de eliminar el numero es: ";
        ImprimirVector(n - 1);
        cout << endl;
    } else {
        // No se encontro el numero en el vector
        cout << "No se puede eliminar el numero " << numero << " porque no se encuentra en el vector." << endl;
    }
}

void Vector::eliminarRecursivo(int numero, int i) {         //Metodo Eleminar en recursivo
    if (i < n - 1) {
        v[i] = v[i + 1]; // Desplaza el elemento siguiente hacia la posicion actual
        eliminarRecursivo(numero, i + 1); // Llama recursivamente con el siguiente indice
    } else {
        // Si es el ultimo elemento simplemente reducimos la cantidad de elementos
        n--;
        cout << "El numero " << numero << " ha sido eliminado del vector." << endl;
    }
}


