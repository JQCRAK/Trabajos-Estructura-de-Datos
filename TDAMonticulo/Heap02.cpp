/*Heap 002
Generar todos los caminoas de un heap
Incomplento
*/

using namespace std;
#include <iostream>
#include "monticulo.h"
#include "Utilidades.h"
#include "Pila.h"  // Incluir la definici�n de la clase Pila


void leerMonticulo(Monticulo* m, int n);  // Prototipo de la funci�n de lectura Heap
void imprimirMonticulo(Monticulo m, int n);  // Prototipo de la funci�n de impresi�n del heap
void recorrerMonticulo(Monticulo m, int n, int i);
void GenerarCaminosMonticulo(Monticulo m, int n);  // Prototipo de la funci�n para generar caminos

int main() {
    system("color fc");

    int n;  // Cantidad de nodos del mont�culo

    cout << endl << "Ingrese los nodos del mont�culo: ";
    n = leerN(0, MAXDATOS);  // Ingreso de cantidad de elementos a procesar

    Monticulo m(n);  // Instanciar un mont�culo
    cout << endl << "Lectura del mont�culo";
    leerMonticulo(&m, n - 1);  // Llamado a la funci�n de lectura
    cout << endl << "Impresi�n del mont�culo";
    imprimirMonticulo(m, n - 1);  // Llamado de impresi�n
    cout << endl << "Mont�culo sus Hojas";
    GenerarCaminosMonticulo(m, n);  // Generaci�n de caminos utilizando una pila

    return 0;
}

// Implementaci�n de las funciones omitidas


void leerMonticulo(Monticulo* m, int n) {
    if (n >= 0) {
        leerMonticulo(m, n - 1);  // Llamado recursivo
        Clave vl;  // Variable de lectura
        cout << endl << "Valor a incluir en el Mont�culo: ";
        cin >> vl;
        m->Insertar(vl);  // Llamado a m�todos de inserci�n
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

    // Llamamos a la funci�n recursiva para generar caminos desde la ra�z
    GenerarCaminosRecursivo(m, n, pila, 0);
}

void GenerarCaminosRecursivo(Monticulo m, int n, Pila& pila, int i) {
    if (i < n) {
        pila.push(m.getValor(i));  // Empujar el valor actual a la pila

        // Llamar recursivamente para el hijo izquierdo
        GenerarCaminosRecursivo(m, n, pila, 2 * i + 1);

        // Llamar recursivamente para el hijo derecho
        GenerarCaminosRecursivo(m, n, pila, 2 * i + 2);

        // Si es una hoja, imprimir el camino desde la ra�z hasta esta hoja
        if (2 * i + 1 >= n && 2 * i + 2 >= n) {
            cout << endl << "Camino hasta hoja:";
            while (!pila.pilaVacia()) {
                cout << " " << pila.pop();
            }
        }
    }
}

