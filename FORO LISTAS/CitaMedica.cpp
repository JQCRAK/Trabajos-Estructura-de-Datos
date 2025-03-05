#include <iostream>
#include <string>
#include "LISTA.h"
using namespace std;

void agregarCita(Lista *l);
void siguienteCita(Lista *l);
void eliminarCita(Lista *l);
void mostrarCita(Nodo *cita);
void mostrarCitas(Lista *l);
void menu(Lista *l);

int main() {
    Lista listaCitas;
    menu(&listaCitas);
    return 0;
}

void agregarCita(Lista *l) {
    string nombre, fecha, hora, especialidad;
    cout << "Ingrese los detalles de la cita (nombre, fecha, hora, especialidad)." << endl;
    cout << "Nombre del paciente: ";
    cin >> nombre;
    cout << "Fecha (dd/mm/aaaa): ";
    cin >> fecha;
    cout << "Hora (hh:mm): ";
    cin >> hora;
    cout << "Especialidad medica: ";
    cin >> especialidad;
    Cita nuevaCita = {nombre, fecha, hora, especialidad};
    l->insertarCita(nuevaCita);
}

void siguienteCita(Lista *l) {
    Nodo *siguiente = l->getPrimero();
    if (siguiente != NULL) {
        cout << "Siguiente cita a atender:" << endl;
        mostrarCita(siguiente);
    } else {
        cout << "No hay citas pendientes." << endl;
    }
}

void eliminarCita(Lista *l) {
    string nombre;
    cout << "Ingrese el nombre del paciente cuya cita desea eliminar: ";
    cin >> nombre;

    if (l->eliminarCita(nombre)) {
        cout << "La cita del paciente \"" << nombre << "\" ha sido eliminada." << endl;
    } else {
        cout << "No se encontro ninguna cita para el paciente \"" << nombre << "\"." << endl;
    }
}

void mostrarCita(Nodo *cita) {
    Cita c = cita->getDato();
    cout << "Nombre del paciente: " << c.nombrePaciente << endl;
    cout << "Fecha: " << c.fecha << endl;
    cout << "Hora: " << c.hora << endl;
    cout << "Especialidad: " << c.especialidad << endl;
}

void mostrarCitas(Lista *l) {
    cout << "Lista de Citas Medicas:" << endl;
    Nodo *actual = l->getPrimero();
    while (actual != NULL) {
        mostrarCita(actual);
        actual = actual->getPunt();
    }
}

void menu(Lista *l) {
    int opcion;
    cout << endl <<"=========================================================="<<endl;
    cout << "Menu:" << endl;
    cout << "1. Agregar cita medica" << endl;
    cout << "2. Ver siguiente cita a atender." << endl;
    cout << "3. Eliminar cita medica" << endl;
    cout << "4. Mostrar citas medicas" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
        	cout << endl <<"=========================================================="<<endl;
            agregarCita(l);
            break;
        case 2:
        	cout << endl <<"=========================================================="<<endl;
            siguienteCita(l);
            break;
        case 3:
        	cout << endl <<"=========================================================="<<endl;
            eliminarCita(l);
            break;
        case 4:
        	cout << endl <<"=========================================================="<<endl;
            mostrarCitas(l);
            break;
        case 5:
            cout << "Saliendo del programa." << endl;
            return; 
        default:
            cout << "Opcion no valida. Por favor, seleccione una opción valida." << endl;
    }
    
    menu(l);
}

