/*Autores:
Jhostin Quispe 7365
Angel Guaño    7337
En equipos de hasta dos personas, elaborar un programa recursivo en C++ 
que permita el ingreso de una Cola de valores y proceda a invertir el orden 
de los mismos sin el empleo de arreglos ni TDA's auxiliares. Ejemplo:
Entrada: [1, 2, 3, 4, 5]
Salida: [5, 4, 3, 2, 1]
Realice un único envío por equipo de trabajo, con todo el código fuente generado.
*/
using namespace std;
#include <iostream>
#include "Cola.h"
#define FIN 999999

int main() {
	system("color f0");
    // Crea un objeto de la clase Cola
    Cola a;
    void leerCola(Cola *c);
    void imprimirCola(Cola c);
    void invertirCola(Cola &cola);

    cout << endl <<"\tPRACTICA 001"<<endl;
	leerCola(&a);			//llamados
	cout <<endl<< "Cola Original:";
	imprimirCola(a);

    // Muestra la cola invertida
    cout <<endl<< "Cola invertida:";
    invertirCola(a);
    imprimirCola(a);

    return 0;
}

void leerCola(Cola *c){		//funcion ingreso del TDA
	Tipo vl;				//var de lectura
	cout << "Ingrese un valor a incluir en el TDA Cola."<<endl;
	cout <<" Finalice con [" << FIN <<"]: ";
	cin >> vl;
	
	if(vl != FIN){			//usr aun desea ingresar valores al TDA
		c->insertar(vl);	//llamdo al metodo de insercion del nuevo elemento en TDA
		leerCola(c);		//llamado recursivo
	}
}

void imprimirCola(Cola c){			//funcion de impresion
	if(!c.colaVacia()){			//aun hay elementos en el TDA
		cout << endl << " > " << c.quitar();
		imprimirCola(c);			//llamado recursivo
	}
}

void invertirCola(Cola &cola) {
    if (!cola.colaVacia()) {
        Tipo valor = cola.quitar(); // Quita el primer elemento de la cola
        invertirCola(cola); // Llama recursivamente para invertir el resto de la cola
        cola.insertar(valor); // Inserta el valor al final de la cola (invertido)
    }
}

