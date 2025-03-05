/*Jhostin Quispe 
Gestion de turnos en una consulta medica
En una consulta medica los pacientes pueden ser atendidos en el orden en que llegaron 
similar a una cola FIFO. Una cola circular podria representar la lista de pacientes en espera 
donde se agregan nuevos pacientes al final de la cola y se atienden del frente.*/
#include <iostream>
#include "Cola Circulares.h" // Incluimos la implementación de la cola circular

#define FIN 9999

using namespace std;

// Prototipos de funciones
void ingresarPacientesRecursivo(ColaCircular *cola);
void atenderPacientesRecursivo(ColaCircular cola);

int main() {
    system("color f0");

    ColaCircular colaConsultorio; // Instanciamos el objeto de la cola circular
    cout << endl << "Gestion de turnos en una consulta medica";
	cout << endl << "Ingrese el numero de turno del paciente. Finalice con [" << FIN << "]: ";
    // Ingresar pacientes recursivamente
    ingresarPacientesRecursivo(&colaConsultorio);
	cout << endl << "Atendiendo Pacientes"<<endl;
    // Atender pacientes en el orden en que llegaron
    atenderPacientesRecursivo(colaConsultorio);

    return 0;
}

// Funcion recursiva para ingresar pacientes a la cola
void ingresarPacientesRecursivo(ColaCircular *cola) {
    Tipo numeroTurno;
    cin >> numeroTurno;
    if (numeroTurno != FIN) {
        cola->enqueue(numeroTurno); // Agregar paciente a la cola
        cout << "Ingrese el numero de turno del siguiente paciente o [" << FIN << "] para finalizar: ";
        ingresarPacientesRecursivo(cola); // Llamada recursiva
    }
}

// Funcion recursiva para atender pacientes en orden de llegada
void atenderPacientesRecursivo(ColaCircular cola) {
    if (!cola.colaVacia()) {
        cout << "Paciente con turno #" << cola.dequeue() << " atendido." << endl;
        atenderPacientesRecursivo(cola); // Llamada recursiva
    } else {
        cout << "Todos los pacientes han sido atendidos." << endl;
    }
}

