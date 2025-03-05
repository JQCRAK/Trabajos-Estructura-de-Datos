//Generar todos los caminos a todas las hojas de un derivadas de cualquier nodo de un AB
#include <iostream>
#include "ArbolBinario.h"
using namespace std;
int main() {
      ArbolBinario a;
    NodoBinario n8(2);
    NodoBinario n9(5);
    NodoBinario n10(7);
    NodoBinario n11(9);
    NodoBinario n12(11);
    NodoBinario n13(13);
    NodoBinario n14(20);
    NodoBinario n15(30);
    NodoBinario n7(29,&n14,&n15);
    NodoBinario n6(12,&n12,&n13);
    NodoBinario n5(8,&n10,&n11);
    NodoBinario n4(4,&n8,&n9);
    NodoBinario n2(6,&n4,&n5);
    NodoBinario n3(19,&n6,&n7);
    NodoBinario n1(9,&n2,&n3);
    a.setRaiz(&n1);
    NodoBinario* aux;
    aux = a.getRaiz();
    cout << endl << " Caminos: "<< endl;
    int camino[100];  
    void ImprimirCamino(NodoBinario* p, NodoBinario* raiz, int camino[], int nivel);
    ImprimirCamino(a.getRaiz(), aux, camino, 0);
    return 0;
}

void ImprimirCamino(NodoBinario* p, NodoBinario* raiz, int camino[], int nivel) {
    if (p != nullptr) {
        camino[nivel] = p->getDato();

        if (p->getIzq() == nullptr && p->getDer() == nullptr) {
            for (int i = 0; i <= nivel; ++i) {
                cout << camino[i] << " ";
            }
            cout << endl;
        } else {
            ImprimirCamino(p->getIzq(), raiz, camino, nivel + 1);
            ImprimirCamino(p->getDer(), raiz, camino, nivel + 1);
        }
    }
}