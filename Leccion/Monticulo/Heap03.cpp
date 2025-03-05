/*Heap03
Determinar si los valores de cada nivel estan ordenados asce, desce, o ninguno
*/

using namespace std;

#include <iostream>
#include "monticulo.h"
#include "Utilidades.h"

// Prototipos de funciones
void leerMonticulo(Monticulo* m, int n);
void imprimirMonticulo(Monticulo m, int n);
void verificarOrdenNivel(Monticulo m, int n);

int main() { // programa principal
    system("color fc");

    int n; // cantidad de nodos del monticulo

    cout << endl << "Ingrese los nodos del monticulo: ";
    n = leerN(0, MAXDATOS); // INGRESO DE CANTIDAD DE ELEMENTOS A PROCESAR

    Monticulo m(n); // instaciar un monticulo
    cout << endl << "Lectura del monticulo";
    leerMonticulo(&m, n - 1); // llamado lectura
    cout << endl << "Impresion del monticulo";
    imprimirMonticulo(m, n - 1); // llamado de impresion 
    cout << endl << "Verificacion del orden de los niveles del monticulo";
    verificarOrdenNivel(m, n);

    return 0;
}

void leerMonticulo(Monticulo* m, int n) { // funcion de lectura del Heap
    if (n >= 0) {
        leerMonticulo(m, n - 1); // llamado recursivo
        Clave vl; // var de lectura 
        cout << endl << "Valor a incluir en el Monticulo: ";
        cin >> vl;
        m->Insertar(vl); // llamado a metodos de inserccion
    }
}

void imprimirMonticulo(Monticulo m, int n) { // funcion de impresion del heap 
    if (n >= 0) {
        imprimirMonticulo(m, n - 1); // llamado recursivo
        Clave vl; // var de lectura 
        vl = m.getValor(n);
        cout << endl << " > " << vl;
    }
}

void recorrerMonticulo(Monticulo m, int n, int i) {
    // implementación de la función de recorrido (no se proporciona en el código original)
}

void verificarOrdenNivel(Monticulo m, int n) {
    int nivel = 0;
    int inicio = 0;

    while (inicio < n) {
        int fin = inicio + (1 << nivel); // 1 << nivel es lo mismo que 2^nivel
        if (fin > n) {
            fin = n;
        }

        bool ascendente = true;
		bool descendente = true;
        for (int i = inicio; i < fin - 1; ++i) {
            if (m.getValor(i) > m.getValor(i + 1)) {
                ascendente = false;
            }
            if (m.getValor(i) < m.getValor(i + 1)) {
                descendente = false;
            }
        }

        cout << endl << "Nivel " << nivel << ": ";
        if (ascendente) {
            cout << "Ordenado Ascendentemente";
        } else if (descendente) {
            cout << "Ordenado Descendentemente";
        } else {
            cout << "No tiene un orden especifico";
        }

        inicio = fin;
        ++nivel;
    }
}



