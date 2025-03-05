/*Heap 002
Generar todos los caminoas de un heap
Incomplento
*/

using namespace std;
#include <iostream>
#include "monticulo.h"
#include "Utilidades.h"
#include "Pila.h"  // Incluir la definición de la clase Pila


void leerMonticulo(Monticulo* m, int n);  // Prototipo de la función de lectura Heap
void imprimirMonticulo(Monticulo m, int n);  // Prototipo de la función de impresión del heap
void recorrerMonticulo(Monticulo m, int n, int i);
void GenerarCaminosMonticulo(Monticulo m, int n);  // Prototipo de la función para generar caminos

int main() {
    system("color fc");

    int n;  // Cantidad de nodos del montículo

    cout << endl << "Ingrese los nodos del montículo: ";
    n = leerN(0, MAXDATOS);  // Ingreso de cantidad de elementos a procesar

    Monticulo m(n);  // Instanciar un montículo
    cout << endl << "Lectura del montículo";
    leerMonticulo(&m, n - 1);  // Llamado a la función de lectura
    cout << endl << "Impresión del montículo";
    imprimirMonticulo(m, n - 1);  // Llamado de impresión
    cout << endl << "Montículo sus Hojas";
    GenerarCaminosMonticulo(m, n);  // Generación de caminos utilizando una pila

    return 0;
}

// Implementación de las funciones omitidas


void leerMonticulo(Monticulo* m, int n) {
    if (n >= 0) {
        leerMonticulo(m, n - 1);  // Llamado recursivo
        Clave vl;  // Variable de lectura
        cout << endl << "Valor a incluir en el Montículo: ";
        cin >> vl;
        m->Insertar(vl);  // Llamado a métodos de inserción
    }
}

void imprimirMonticulo(Monticulo m, int n) {
    if (n >= 0) {
        imprimirMonticulo(m, n - 1);  // Llamado recursivo
        Clave vl;  // Variable de lectura
        vl = m.getValor(n);
        cout << endl << " > " << vl;
    }
}

void GenerarCaminosMonticulo(Monticulo m, int n) {
    Pila pila;  // Creamos una pila para almacenar los caminos

    // Llamamos a la función recursiva para generar caminos desde la raíz
    GenerarCaminosRecursivo(m, n, pila, 0);
}

void GenerarCaminosRecursivo(Monticulo m, int n, Pila& pila, int i) {
    if (i < n) {
        pila.push(m.getValor(i));  // Empujar el valor actual a la pila

        // Llamar recursivamente para el hijo izquierdo
        GenerarCaminosRecursivo(m, n, pila, 2 * i + 1);

        // Llamar recursivamente para el hijo derecho
        GenerarCaminosRecursivo(m, n, pila, 2 * i + 2);

        // Si es una hoja, imprimir el camino desde la raíz hasta esta hoja
        if (2 * i + 1 >= n && 2 * i + 2 >= n) {
            cout << endl << "Camino hasta hoja:";
            while (!pila.pilaVacia()) {
                cout << " " << pila.pop();
            }
        }
    }
}

