//Caso: Gestion de Descargas de Archivos

#include <iostream>
#include "Cola.h"

#define FIN 999999

void leerCola(Cola *c);
void imprimirCola(Cola c);
void procesarDescarga(Cola *c);
void procesarTodasLasDescargas(Cola *c);
using namespace std;



int main() {
    system("color f0");
    Cola descargas;
    cout << "Gestion de Descargas de Archivos" << endl;
    leerCola(&descargas);

    cout << "Estado inicial de la cola de descargas:" << endl;
    imprimirCola(descargas);

    procesarDescarga(&descargas);

    cout << "\nEstado de la cola de descargas despues de procesar una descarga:" << endl;
    imprimirCola(descargas);

    procesarTodasLasDescargas(&descargas);

    cout << "\nEstado final de la cola de descargas despues de procesar todas las descargas:" << endl;
    imprimirCola(descargas);

    return 0;
}

void leerCola(Cola *c) {
    Tipo vl;

    cout << endl << "Ingrese ID de la descargas. Finalice con [" << FIN << "]: ";
    cin >> vl;

    while (vl != FIN) {
        c->insertar(vl);
        cout << "Ingrese ID de la descargas. Finalice con [" << FIN << "]: ";
        cin >> vl;
    }
}

void imprimirCola(Cola c) {
    if (!c.colaVacia()) {
        Tipo primerElemento = c.frenteCola();
        c.quitar();
        imprimirCola(c);
        cout << primerElemento << endl; 
        c.insertar(primerElemento); 
    }
}

void procesarDescarga(Cola *c) {
    if (!c->colaVacia()) {
        Tipo idDescarga = c->quitar();
        cout << endl << "Procesando descarga con ID " << idDescarga << "...\n";
        cout << "Descarga con ID " << idDescarga << " completada.\n";
    } else {
        cout << "No hay descargas en la cola para procesar.\n";
    }
}

void procesarTodasLasDescargas(Cola *c) {
    if (!c->colaVacia()) {
        procesarDescarga(c);
        procesarTodasLasDescargas(c);
    }
}

