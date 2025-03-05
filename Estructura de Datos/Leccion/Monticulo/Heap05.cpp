/*
Determinar el camino mas largo y mas corto y determinar su valores comunes entres estos dos
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
        int fin = inicio + (1 << nivel);
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
	if(i < n){
		if (((2*i)+1)>n){	
		cout <<endl<< " > "<<m.getValor(i);
	}
	recorrerMonticulo(m, n, ((2*i)+1));
	recorrerMonticulo(m, n, ((2*i)+2));
	}	
}	

void recorrerMonticulo(Monticulo& m, int n, int i, int prof, Pila& caminoAc, Pila& caminoMasL, Pila& caminoMasC, int& longM, int& longMn) {
    if (i >= n) return;

    caminoAc.push(m.getValor(i));

    if (2 * i + 1 >= n) {
        if (prof > longM) {
            longM = prof;
            caminoMasL = caminoAc;
        }
        if (prof < longMn) {
            longMn = prof;
            caminoMasC = caminoAc;
        }
    } else {
        // Recorrer hijos
        recorrerMonticulo(m, n, 2 * i + 1, prof + 1, caminoAc, caminoMasL, caminoMasC, longM, longMn);
        recorrerMonticulo(m, n, 2 * i + 2, prof + 1, caminoAc, caminoMasL, caminoMasC, longM, longMn);
    }

    caminoAc.pop();
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

Pila encontrarValoresComunes(Pila p1, Pila p2) {
    Pila comunes;
    Pila temp1 = p1;
    Pila temp2 = p2;
    
    while (!temp1.pilaVacia()) {
        int valor = temp1.pop();
        Pila temp2Copia = temp2;
        bool encontrado = false;
        while (!temp2Copia.pilaVacia()) {
            if (valor == temp2Copia.pop() && !encontrado) {
                comunes.push(valor);
                encontrado = true;
                break;
            }
        }
    }
    
    return comunes;
}

void determinarDiferenciaRamas(Monticulo m, int n) {
    if (n == 0) {
        cout << "El monticulo esta vacio." << endl;
        return;
    }

    Pila caminoAc;
    Pila caminoMasL;
    Pila caminoMasC;
    int longM = 0;
    int longMn = INT_MAX;

    recorrerMonticulo(m, n, 0, 0, caminoAc, caminoMasL, caminoMasC, longM, longMn);

    cout << "Camino mas largo: ";
    imprimirCamino(caminoMasL);
    cout << endl;

    cout << "Camino mas corto: ";
    imprimirCamino(caminoMasC);
    cout << endl;

    cout << "Diferencia de longitud: " << longM - longMn << endl;

    Pila valoresC = encontrarValoresComunes(caminoMasL, caminoMasC);
    cout << "Comunes: ";
    imprimirCamino(valoresC);
    cout << endl;
}
