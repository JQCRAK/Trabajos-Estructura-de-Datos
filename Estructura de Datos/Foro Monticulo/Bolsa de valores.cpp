/*Foro Simulacion de la Bolsa de Valores
Jhostin Quispe 7365
*/

using namespace std;
#include <iostream>
#include "monticulo.h"
#include "Utilidades.h"

// Definicion de la estructura Accion
struct Accion {
    string simbolo;
    Clave precio;  // Usamos Clave (int) para el precio
    
    Accion(string s = "", Clave p = 0) : simbolo(s), precio(p) {}
    
    friend ostream& operator<<(ostream& os, const Accion& a) {
        os << a.simbolo << ": $" << a.precio;
        return os;
    }
};

// Prototipos de funciones
void leerMonticulo(Monticulo* m, int n);
void imprimirMonticulo(Monticulo m, int n);
void mostrarAccionMasBarata(Monticulo& m);
void mostrarAccionMasCara(Monticulo& m);
void comprarAccionMasBarata(Monticulo& m);
void mostrarCantidadAcciones(Monticulo& m);
void mostrarEstadisticas(Monticulo& m);

int main() { 								// programa principal
    system("color fc");
    int n; 									// cantidad de nodos del monticulo
    cout << endl << "Ingrese la cantidad de acciones para la Bolsa de Valores: ";
    n = leerN(0, MAXDATOS); 				// INGRESO DE CANTIDAD DE ELEMENTOS A PROCESAR
    Monticulo m(n); 						// instanciar un monticulo

    cout << endl << "Lectura de acciones";
    leerMonticulo(&m, n - 1); 				// llamado lectura

    int opcion;
    do {
        cout << "\n--- Simulacion de Bolsa de Valores ---" << endl;
        cout << "1. Mostrar todas las acciones" << endl;
        cout << "2. Mostrar accion mas barata" << endl;
        cout << "3. Mostrar accion mas cara" << endl;
        cout << "4. Comprar accion mas barata" << endl;
        cout << "5. Mostrar cantidad de acciones" << endl;
        cout << "6. Mostrar estadisticas de acciones" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << endl << "Impresion de acciones";
                imprimirMonticulo(m, m.getNumDatosAct() - 1); // llamado de impresion
                break;
            case 2:
                mostrarAccionMasBarata(m);
                break;
            case 3:
                mostrarAccionMasCara(m);
                break;
            case 4:
                comprarAccionMasBarata(m);
                break;
            case 5:
                mostrarCantidadAcciones(m);
                break;
            case 6:
                mostrarEstadisticas(m);
                break;
            case 0:
                cout << "Gracias por usar la simulacion de Bolsa de Valores." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}

void leerMonticulo(Monticulo* m, int n) { 							// funcion de lectura del Heap
    if (n >= 0) {
        leerMonticulo(m, n - 1); 									// llamado recursivo
        Clave precio;
        cout << endl<<"Ingrese el precio de la accion: ";
        cin >> precio;
        m->Insertar(precio); 										// llamado a metodos de inserccion
    }
}

void imprimirMonticulo(Monticulo m, int n) { // funcion de impresion del heap 
    if (n >= 0) {
        imprimirMonticulo(m, n - 1); // llamado recursivo
        Clave precio = m.getValor(n);
        cout << endl << "	> Precio: $" << precio;
    }
}

void mostrarAccionMasBarata(Monticulo& m) {
    if (m.Esvacio()) {
        cout <<endl<< "La bolsa esta vacia." << endl;
        return;
    }
    
    Clave precioMinimo = m.BuscarMinimo();
    cout <<endl<< "El precio de la accion mas barata es: $" << precioMinimo << endl;
}

void mostrarAccionMasCara(Monticulo& m) {
    if (m.Esvacio()) {
        cout << "La bolsa esta vacia." << endl;
        return;
    }
    
    Clave precioMaximo = m.getValor(0);
    for (int i = 1; i < m.getNumDatosAct(); i++) {
        if (m.getValor(i) > precioMaximo) {
            precioMaximo = m.getValor(i);
        }
    }
    cout <<endl<< "El precio de la accion mas cara es: $" << precioMaximo << endl;
}

void comprarAccionMasBarata(Monticulo& m) {
    if (m.Esvacio()) {
        cout << "La bolsa esta vacia." << endl;
        return;
    }
    
    Clave precioComprado = m.EliminarMinimo();
    cout << "Se ha comprado la accion con precio: $" << precioComprado << endl;
}

void mostrarCantidadAcciones(Monticulo& m) {
    cout << "La cantidad total de acciones en el monticulo es: " << m.getNumDatosAct() << endl;
}

void mostrarEstadisticas(Monticulo& m) {
    if (m.Esvacio()) {
        cout << "La bolsa esta vacia." << endl;
        return;
    }
    
    Clave precioMinimo = m.BuscarMinimo();
    Clave precioMaximo = m.getValor(0);
    
    for (int i = 1; i < m.getNumDatosAct(); i++) {
        Clave precioActual = m.getValor(i);
        if (precioActual > precioMaximo) {
            precioMaximo = precioActual;
        }
    }
    
    Clave rangoPrecios = precioMaximo - precioMinimo;
    
    cout << "Estadisticas de las acciones en la bolsa:" << endl;
    cout << "  - Precio minimo: $" << precioMinimo << endl;
    cout << "  - Precio maximo: $" << precioMaximo << endl;
    cout << "  - Rango de precios: $" << rangoPrecios << endl;
}

