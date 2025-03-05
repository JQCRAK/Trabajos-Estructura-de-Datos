// Ingresados un AB y una lista simple, determinar si la lista coincide con alguna rama completa del AB
#include <iostream>
#include "Lista.h"
#include "ArbolBinario.h"
#define FIN 999
int main() {
    Lista l;
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
    cout << "Ingreso de la LISTA";
    void ingresarLista(Lista* l);
    ingresarLista(&l);
    aux = a.getRaiz();
    int camino[100]; 
    cout << "Imprimir ARBOL:" << endl;
    void ImprimirCamino(NodoBinario* p, NodoBinario* raiz, int camino[], int nivel, Lista& l);
    ImprimirCamino(a.getRaiz(), aux, camino, 0, l);
	void imprimirLista(Nodo* act);
    cout << "Imprimir LISTA:" << endl;
    imprimirLista(l.getPrimero());
    return 0;
}
void ingresarLista(Lista* l) {
    Tipo aux;
    cout << endl << "Ingrese un valor para insertar en la lista: (FINALICE CON [999])";
    cin >> aux;
    if (aux != FIN) {
        l->insertarAlInicio(aux);
        ingresarLista(l);
    }
}
void imprimirLista(Nodo* act) {
    if (act != nullptr) {
        cout << "  >  " << act->getDato();
        imprimirLista(act->getPunt());
    }
}
void ImprimirCamino(NodoBinario* p, NodoBinario* raiz, int camino[], int nivel, Lista& l) {
    if (p != nullptr) {
        camino[nivel] = p->getDato();
        if (p->getIzq() == nullptr && p->getDer() == nullptr) {
            cout << "Camino: ";
            for (int i = 0; i <= nivel; ++i) {
                cout << camino[i] << " ";
            }
            Nodo* listaInicio = l.getPrimero();
            Nodo* listaActual = listaInicio;
            int i = 0;
            while (listaActual != nullptr && i <= nivel) {
                if (listaActual->getDato() != camino[i]) {
                    break;
                }
                listaActual = listaActual->getPunt();
                ++i;
            }
            if (listaActual == nullptr && i == nivel + 1) {
                cout << " <- Coincide con la lista." << endl;
            } else {
                cout << " <- No coincide con la lista." << endl;
            }
        } else {
            ImprimirCamino(p->getIzq(), raiz, camino, nivel + 1, l);
            ImprimirCamino(p->getDer(), raiz, camino, nivel + 1, l);
        }
    }
}