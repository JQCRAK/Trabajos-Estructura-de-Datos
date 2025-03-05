/*
Determinar la diferencia existente entre la rama las larga y la mas corta del heap
*/

using namespace std;
#include <iostream>
#include "monticulo.h"
#include "Utilidades.h"
#include "Pila.h"

// Prototipos de funciones
void leerMonticulo(Monticulo* m, int n);
void imprimirMonticulo(Monticulo m, int n);
void verificarOrdenNivel(Monticulo m, int n);
void recorrerMonticulo(Monticulo m,int n, int i);
void determinarDiferenciaRamas(Monticulo m, int n);
void imprimirCamino(Pila p);

int main() { // programa principal
    system("color fc");

    int n; // cantidad de nodos del monticulo

    cout << endl << "Ingrese los nodos del monticulo: ";
    n = leerN(0, MAXDATOS); // INGRESO DE CANTIDAD DE ELEMENTOS A PROCESAR

    Monticulo m(n); // instanciar un monticulo
    cout << endl << "Lectura del monticulo";
    leerMonticulo(&m, n - 1); // llamado lectura
    cout << endl << "Impresion del monticulo";
    imprimirMonticulo(m, n - 1); // llamado de impresion 
    cout << endl << "Verificacion del orden de los niveles del monticulo";
    verificarOrdenNivel(m, n);
    cout << endl << "recorrer del monticulo";
    recorrerMonticulo(m,n,0);
    cout << endl << "Analisis de caminos en el monticulo:" << endl;
    determinarDiferenciaRamas(m, n);
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

void verificarOrdenNivel(Monticulo m, int n) {
    int nivel = 0;
    int inicio = 0;

    while (inicio < n) {
        int fin = inicio + (1 << nivel); // 1 << nivel es lo mismo que 2^nivel
        if (fin > n) {
            fin = n;
        }

        Pila ascendentePila;
        Pila descendentePila;
        
        bool ascendente = true;
        bool descendente = true;
        
        for (int i = inicio; i < fin; ++i) {
        	
            int valorActual = m.getValor(i);
            if (!ascendentePila.pilaVacia()) {
                if (valorActual < ascendentePila.cimaPila()) {
                    ascendente = false;
                }
            }
            ascendentePila.push(valorActual);
            if (!descendentePila.pilaVacia()) {
                if (valorActual > descendentePila.cimaPila()) {
                    descendente = false;
                }
            }
            descendentePila.push(valorActual);
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

void recorrerMonticulo(Monticulo m,int n, int i){
	if(i < n){//caso base: posisciion actual esta dentro del monticulo
		if (((2*i)+1)>n){
		cout <<endl<< " > "<<m.getValor(i);
	}
	recorrerMonticulo(m, n, ((2*i)+1));//
	recorrerMonticulo(m, n, ((2*i)+2));
	}	
}	

void recorrerMonticulo(Monticulo& m, int n, int indice, int profundidad, Pila& caminoActual, Pila& caminoMasLargo, Pila& caminoMasCorto, int& longitudMaxima, int& longitudMinima) {
    if (indice >= n) return;

    caminoActual.push(m.getValor(indice));

    // Si es una hoja
    if (2 * indice + 1 >= n) {
        if (profundidad > longitudMaxima) {
            longitudMaxima = profundidad;
            caminoMasLargo = caminoActual;
        }
        if (profundidad < longitudMinima) {
            longitudMinima = profundidad;
            caminoMasCorto = caminoActual;
        }
    } else {
        // Recorrer hijos
        recorrerMonticulo(m, n, 2 * indice + 1, profundidad + 1, caminoActual, caminoMasLargo, caminoMasCorto, longitudMaxima, longitudMinima);
        recorrerMonticulo(m, n, 2 * indice + 2, profundidad + 1, caminoActual, caminoMasLargo, caminoMasCorto, longitudMaxima, longitudMinima);
    }

    caminoActual.pop();
}

void imprimirCamino(Pila p) {
    Pila temp;
    while (!p.pilaVacia()) {
        temp.push(p.pop());
    }
    while (!temp.pilaVacia()) {
        int valor = temp.pop();
        cout << valor << " ";
        p.push(valor);
    }
}

void determinarDiferenciaRamas(Monticulo m, int n) {
    if (n == 0) {
        cout << "El monticulo esta vacio." << endl;
        return;
    }

    Pila caminoActual;
    Pila caminoMasLargo;
    Pila caminoMasCorto;
    int longitudMaxima = 0;
    int longitudMinima = INT_MAX;

    recorrerMonticulo(m, n, 0, 0, caminoActual, caminoMasLargo, caminoMasCorto, longitudMaxima, longitudMinima);

    cout << "Camino mas largo: ";
    imprimirCamino(caminoMasLargo);
    cout << endl;

    cout << "Camino mas corto: ";
    imprimirCamino(caminoMasCorto);
    cout << endl;

    cout << "Diferencia de longitud: " << longitudMaxima - longitudMinima << endl;
}
