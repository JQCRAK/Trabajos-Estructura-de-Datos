#ifndef _LISTA_H
#define _LISTA_H

#include "Nodo.h"


class Lista {
private:
    Nodo* primero;

public:
    Lista();
    void setPrimero(Nodo* val);
    Nodo* getPrimero();
    bool esVacia();
    void insertarCita(Cita cita);
    bool eliminarCita(std::string nombrePaciente);
    Nodo* buscarCita(std::string nombrePaciente);
};

Lista::Lista() {
    setPrimero(NULL);
}

void Lista::setPrimero(Nodo* val) {
    primero = val;
}

Nodo* Lista::getPrimero() {
    return primero;
}

bool Lista::esVacia() {
    return (getPrimero() == NULL);
}

void Lista::insertarCita(Cita cita) {
    setPrimero(new Nodo(cita, getPrimero()));
}

bool Lista::eliminarCita(std::string nombrePaciente) {
    Nodo* actual = getPrimero();
    Nodo* anterior = NULL;

    while (actual != NULL) {
        if (actual->getDato().nombrePaciente == nombrePaciente) {
            if (anterior == NULL) {
                setPrimero(actual->getPunt());
            } else {
                anterior->setPunt(actual->getPunt());
            }
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->getPunt();
    }
    return false;
}

Nodo* Lista::buscarCita(std::string nombrePaciente) {
    Nodo* actual = getPrimero();

    while (actual != NULL) {
        if (actual->getDato().nombrePaciente == nombrePaciente) {
            return actual;
        }
        actual = actual->getPunt();
    }
    return NULL;
}

#endif

