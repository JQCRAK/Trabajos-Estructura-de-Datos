/*Jhostin Quispe 7365
Eliminar los valores repetidos en una cola previamente ingresada
*/

#include <iostream>
#include "Cola.h"
#define FIN 999999
using namespace std;

void leerCola(Cola *c);                   // Prototipo de funcion de ingreso del TDA
void imprimirCola(Cola c);                // Prototipo de la funcion de impresion
void eliminarDuplicados(Cola *c);         // Prototipo de la funcion para eliminar duplicados
void eliminarDuplicadosRec(Cola *c, Cola *temp); // funcion recursiva auxiliar
bool buscarRecursivo(Cola *c, Tipo valor, int pos); // funcion recursiva para buscar un valor en la cola sin modificarla

int main() {
    system("color f0");
    Cola a;

    cout << endl << "Ejercicio 1";
    leerCola(&a);
    cout << endl << "Contenidos del TDA Cola antes de eliminar duplicados:";
    imprimirCola(a);

    eliminarDuplicados(&a);
    cout << endl << "Contenidos del TDA Cola despues de eliminar duplicados:";
    imprimirCola(a);

    return 0;
}

void leerCola(Cola *c) {        // Funcion de ingreso del TDA
    Tipo vl;
    cout << endl << "Ingrese un valor a agregar en el TDA Cola." << endl;
    cout << "Finalice con [" << FIN << "]: ";
    cin >> vl;
    if (vl != FIN) {            
        c->insertar(vl);        
        leerCola(c);           
    }
}

void imprimirCola(Cola c) {
    if (!c.colaVacia()) {       
        cout << endl << "> " << c.quitar();
        imprimirCola(c);        
    }       
}

bool buscarRecursivo(Cola *c, Tipo valor, int pos) {
    if (pos == -1) {
        return false;
    } else {
        Tipo actual = c->getVec(pos);
        bool encontrado = (actual == valor) || buscarRecursivo(c, valor, pos - 1);
        return encontrado;
    }
}

void eliminarDuplicados(Cola *c) {
    Cola temp;  
	eliminarDuplicadosRec(c, &temp);
    cout << endl << "Contenidos de la cola temporal antes de transferir:";
    imprimirCola(temp);
    eliminarDuplicadosRec(&temp, c);
}

void eliminarDuplicadosRec(Cola *c, Cola *temp) {
    if (!c->colaVacia()) {
        Tipo actual = c->quitar();
        if (!buscarRecursivo(temp, actual, temp->getFinal())) {
            temp->insertar(actual);
        }
        eliminarDuplicadosRec(c, temp); 
    }
}

