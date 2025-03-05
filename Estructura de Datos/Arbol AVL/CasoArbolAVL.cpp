#include "ArbolAVL.h"
#include <iostream>
#include <cstdlib> // Para generación de números aleatorios
#include <ctime>   // Para inicialización de semilla aleatoria

using namespace std;

void imprimirMenu() {
	cout << "Simulador Interactivo de Árbol AVL"<<endl;
    cout << "1. Insertar nodo" << endl;
    cout << "2. Eliminar nodo" << endl;
    cout << "3. Buscar nodo" << endl;
    cout << "4. Mostrar arbol (Inorden, Preorden, Postorden)" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opción: ";
}

int main() {
    srand(time(NULL)); // Inicializar semilla aleatoria

    ArbolAVL arbol;

    int opcion;
    do {
        imprimirMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int clave = rand() % 100 + 1; // Generar clave aleatoria entre 1 y 100
                int valor = rand() % 1000 + 1; // Generar valor aleatorio entre 1 y 1000
                cout << "Insertando nodo con clave " << clave << " y valor " << valor << endl;
                arbol.insertar(clave, valor);
                cout << "Se creo aleatoriamente los valores existosamente"<<endl;
                break;
            }
            case 2: {
                int clave;
                cout << "Ingrese la clave del nodo a eliminar: ";
                cin >> clave;
                arbol.eliminar(clave);
                break;
            }
            case 3: {
                int clave;
                cout << "Ingrese la clave del nodo a buscar: ";
                cin >> clave;
                NodoAVL* nodo = arbol.buscar(clave);
                if (nodo != NULL) {
                    cout << "Nodo encontrado: (" << nodo->clave << ", " << nodo->valor << ")" << endl;
                } else {
                    cout << "Nodo con clave " << clave << " no encontrado." << endl;
                }
                break;
            }
            case 4: {
                cout << "Inorden: ";
                arbol.imprimirInOrder();
                cout << "Preorden: ";
                arbol.imprimirPreOrder();
                cout << "Postorden: ";
                arbol.imprimirPostOrder();
                cout << endl;
                break;
            }
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
        cout << endl;
    } while (opcion != 5);

    return 0;
}

