/*Jhostin Quispe 7365
Intercambiar las posiciones pares con las impares dentro de un TDA Cola ingresado previamente
*/

#include <iostream>
#include "Cola.h"
#define FIN 999999
using namespace std;

void leerCola(Cola *c);                    // Prototipo de funcion de ingreso del TDA
void imprimirCola(Cola c);                 // Prototipo de la funcion de impresión
void intercambiarPosiciones(Cola *c);      // Prototipo de la funcion para intercambiar posiciones
void intercambiarRecursivo(Cola *c, int n, bool esPar); // funcion recursiva para intercambiar posiciones

int main() {
    system("color f0");
    Cola a;

    cout << endl << "Ejercicio 2";
    leerCola(&a);
    cout << endl << "Contenidos del TDA Cola antes de intercambiar posiciones:";
    imprimirCola(a);

    intercambiarPosiciones(&a);
    cout << endl << "Contenidos del TDA Cola despues de intercambiar posiciones:";
    imprimirCola(a);

    return 0;
}

void leerCola(Cola *c) {        // funcion de ingreso del TDA
    Tipo vl;
    cout << endl << "Ingrese un valor a incluir en el TDA Cola." << endl;
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

void intercambiarPosiciones(Cola *c) {
    int tam = c->tamanioCola();
    bool esPar = (tam % 2 == 0);
    intercambiarRecursivo(c, tam, esPar);
}

void intercambiarRecursivo(Cola *c, int n, bool esPar) {
    if (n > 1) {
        Tipo primero = c->quitar();
        Tipo segundo = c->quitar();
        c->insertar(segundo);
        c->insertar(primero);
        intercambiarRecursivo(c, n - 2, esPar);
    } else if (n == 1 && !esPar) {
        Tipo ultimo = c->quitar();
        c->insertar(ultimo);
    }
}


