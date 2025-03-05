/*Jhostin Quispe 7365
Generar una pila ordenada descendentemente con los valores comunes a varias colas ingresadas
*/

#include <iostream>
#include "Cola.h"
#define FIN 999999
using namespace std;

// Prototipos de funciones
void leerColas(Cola colas[], int index, int numColas);
void leerCola(Cola *c);
void imprimirCola(Cola c);
void encontrarComunes(Cola colas[], int numColas, Cola &comunes);
void extraerComunes(Cola colas[], Cola &comunes, int index, int numColas);
bool estaEnTodasLasColas(Cola colas[], Tipo val, int numColas);
void ordenarColaDescendentemente(Cola &c, Cola &sorted);
void transferirCola(Cola &source, Cola &dest);

int main() {
    system("color f0");
    Cola comunes;
    int n;
    cout << endl << "Ejercicio 6"<<endl;
    cout << "Ingrese cuantas colas va ingresar: ";
    cin >> n;

    Cola* colas = new Cola[n];
    
    leerColas(colas, 0, n);
    encontrarComunes(colas, n, comunes);
    
    Cola sortedResult;
    ordenarColaDescendentemente(comunes, sortedResult);
    
    cout << endl << "Contenidos de la Cola Ordenada Descendentemente";
    imprimirCola(sortedResult);

    return 0;
}

void leerColas(Cola colas[], int index, int numColas) {
    if (index < numColas) {
        cout << endl << "Ingrese valores para la cola " << index + 1 << ":";
        leerCola(&colas[index]);
        leerColas(colas, index + 1, numColas);
    }
}

void leerCola(Cola *c) {
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

void encontrarComunes(Cola colas[], int numColas, Cola &comunes) {
    extraerComunes(colas, comunes, 0, numColas);
}

void extraerComunes(Cola colas[], Cola &comunes, int index, int numColas) {
    if (!colas[0].colaVacia()) {
        Tipo val = colas[0].quitar();
        if (estaEnTodasLasColas(colas + 1, val, numColas - 1)) {
            comunes.insertar(val);
        }
        extraerComunes(colas, comunes, index, numColas);
    }
}

bool estaEnTodasLasColas(Cola colas[], Tipo val, int numColas) {
    if (numColas == 0) {
        return true;
    }
    Cola temp;
    bool found = false;
    while (!colas->colaVacia()) {
        Tipo tempVal = colas->quitar();
        if (tempVal == val) {
            found = true;
        }
        temp.insertar(tempVal);
    }
    transferirCola(temp, *colas);
    return found && estaEnTodasLasColas(colas + 1, val, numColas - 1);
}

void ordenarColaDescendentemente(Cola &c, Cola &sorted) {
    if (!c.colaVacia()) {
        Tipo maxVal = c.quitar();
        Cola temp;
        while (!c.colaVacia()) {
            Tipo val = c.quitar();
            if (val > maxVal) {
                temp.insertar(maxVal);
                maxVal = val;
            } else {
                temp.insertar(val);
            }
        }
        sorted.insertar(maxVal);
        transferirCola(temp, c);
        ordenarColaDescendentemente(c, sorted);
    }
}

void transferirCola(Cola &source, Cola &dest) {
    if (!source.colaVacia()) {
        dest.insertar(source.quitar());
        transferirCola(source, dest);
    }
}

