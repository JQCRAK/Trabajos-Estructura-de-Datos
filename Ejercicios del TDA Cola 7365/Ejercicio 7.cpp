/*Jhostin Quispe 7365
Ingresar una cola de valores, y si hubieran valores consecutivos adyacentes en esta, 
separarlos con un valor correspondiente al promedio calculado entre los dos elementos 
contiguos al espacio en que se insertará el nuevo valor
*/

#include <iostream>
#include "Cola.h"
#define FIN 999999
using namespace std;

// Prototipos de funciones
void leerCola(Cola *c);
void procesarCola(Cola *c);
void imprimirCola(Cola &c);

int main() {
    system("color f0");
    Cola a;

    cout << endl << "Ejercicio 7";
    leerCola(&a);
    procesarCola(&a);
    cout << endl << "Contenidos del TDA Cola:";
    imprimirCola(a);
    cout << endl;

    return 0;
}

void leerCola(Cola *c) {
    Tipo vl;
    cout << endl << "Ingrese un valor para agregar en el TDA Cola." << endl;
    cout << "Finalice con [" << FIN << "]: ";
    cin >> vl;
    if (vl != FIN) {
        c->insertar(vl);
        leerCola(c);
    }
}

void procesarCola(Cola *c) {
    Cola colaTemp;
    while (!c->colaVacia()) {
        Tipo actual = c->frenteCola();
        c->quitar();
        colaTemp.insertar(actual); 

        if (!c->colaVacia()) {
            Tipo siguiente = c->frenteCola();
            if (siguiente == actual) {
                c->quitar(); 
                if (!c->colaVacia()) {
                    Tipo siguienteSiguiente = c->frenteCola(); 
                    Tipo promedio = (actual + siguienteSiguiente) / 2; 
                    colaTemp.insertar(promedio); 
                }
            }
        }
    }
    while (!colaTemp.colaVacia()) {
        Tipo elemento = colaTemp.frenteCola();
        colaTemp.quitar();
        c->insertar(elemento);
    }
}

void imprimirCola(Cola &c) {
    if (!c.colaVacia()) {
        cout << endl << "> " << c.frenteCola();
        c.quitar();
        imprimirCola(c);
    }
}

