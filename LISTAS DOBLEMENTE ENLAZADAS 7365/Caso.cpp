// Caso: Sistema de gestión de inventario de una tienda utilizando listas doblemente enlazadas

#include <iostream>
#include "ListaDoble.h"

using namespace std;

void mostrarMenu() {
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Agregar producto al final del inventario" << endl;
    cout << "2. Agregar producto al inicio del inventario" << endl;
    cout << "3. Agregar producto en una posicion específica" << endl;
    cout << "4. Eliminar primer producto del inventario" << endl;
    cout << "5. Eliminar ultimo producto del inventario" << endl;
    cout << "6. Eliminar producto en una posicion específica" << endl;
    cout << "7. Mostrar inventario de productos" << endl;
    cout << "8. Mostrar inventario de productos en orden inverso" << endl;
    cout << "9. Salir" << endl;
    cout << "Ingrese su opcion: ";
}

int main() {
    ListaDoble inventario;

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int codigo;
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                inventario.insertarAlFinal(codigo);
                break;
            }
            case 2: {
                int codigo;
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                inventario.insertarAlInicio(codigo);
                break;
            }
            case 3: {
                int codigo, posicion;
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                cout << "Ingrese la posicion en la que desea insertar el producto: ";
                cin >> posicion;
                inventario.insertarEnPosicion(codigo, posicion);
                break;
            }
            case 4: {
                inventario.eliminarAlInicio();
                break;
            }
            case 5: {
                inventario.eliminarAlFinal();
                break;
            }
            case 6: {
                int posicion;
                cout << "Ingrese la posicion del producto que desea eliminar: ";
                cin >> posicion;
                inventario.eliminarEnPosicion(posicion);
                break;
            }
            case 7: {
                cout << "Inventario de productos:" << endl;
                inventario.imprimirAdelante();
                break;
            }
            case 8: {
                cout << "Inventario de productos (en orden inverso):" << endl;
                inventario.imprimirAtras();
                break;
            }
            case 9: {
                cout << "Saliendo del sistema de gestion de inventario..." << endl;
                break;
            }
            default:
                cout << "Opcion invalida. Intentelo de nuevo." << endl;
        }

    } while (opcion != 9);

    return 0;
}

