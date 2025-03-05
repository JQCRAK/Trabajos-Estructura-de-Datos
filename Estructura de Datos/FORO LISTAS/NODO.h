#ifndef _NODO_H
#define _NODO_H

#include <string>

struct Cita {
    std::string nombrePaciente;
    std::string fecha;
    std::string hora;
    std::string especialidad;
    // Otros detalles de la cita, como el médico, pueden añadirse según sea necesario
};

class Nodo {
private:
    Cita dato;
    Nodo* punt;

public:
    Nodo();
    Nodo(Cita cita);
    Nodo(Cita cita, Nodo* p);
    void setDato(Cita cita);
    void setPunt(Nodo* val);
    Cita getDato();
    Nodo* getPunt();
};

Nodo::Nodo() {
    setPunt(NULL);
}

Nodo::Nodo(Cita cita) {
    setDato(cita);
    setPunt(NULL);
}

Nodo::Nodo(Cita cita, Nodo* p) {
    setDato(cita);
    setPunt(p);
}

void Nodo::setDato(Cita cita) {
    dato = cita;
}

void Nodo::setPunt(Nodo* val) {
    punt = val;
}

Cita Nodo::getDato() {
    return dato;
}

Nodo* Nodo::getPunt() {
    return punt;
}

#endif

