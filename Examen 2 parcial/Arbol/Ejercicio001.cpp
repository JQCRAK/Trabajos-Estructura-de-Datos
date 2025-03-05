using namespace std;
#include <iostream>
#include "ArbolBinario.h"

void iterativeInOrder(ArbolBinario& arbol) {
    NodoBinario* current = arbol.getRaiz();
    NodoBinario* stack[100];
    int top = -1;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->getIzq();
        }
        current = stack[top--];
        cout << current->getDato() << " ";
        current = current->getDer();
    }
}

void iterativePreOrder(ArbolBinario& arbol) {
    NodoBinario* stack[100];
    int top = -1;
    NodoBinario* current = arbol.getRaiz();

    if (current != NULL) {
        stack[++top] = current;
    }

    while (top != -1) {
        current = stack[top--];
        cout << current->getDato() << " ";
        
        if (current->getDer() != NULL) {
            stack[++top] = current->getDer();
        }
        if (current->getIzq() != NULL) {
            stack[++top] = current->getIzq();
        }
    }
}

void iterativePostOrder(ArbolBinario& arbol) {
    NodoBinario* stack1[100];
    NodoBinario* stack2[100];
    int top1 = -1;
    int top2 = -1;
    NodoBinario* current = arbol.getRaiz();

    if (current != NULL) {
        stack1[++top1] = current;
    }

    while (top1 != -1) {
        current = stack1[top1--];
        stack2[++top2] = current;

        if (current->getIzq() != NULL) {
            stack1[++top1] = current->getIzq();
        }
        if (current->getDer() != NULL) {
            stack1[++top1] = current->getDer();
        }
    }

    while (top2 != -1) {
        cout << stack2[top2--]->getDato() << " ";
    }
}

int main() {
    system("color f0");
    ArbolBinario arbol;
    
    cout << "Ejercicio 1" << endl;
    cout << "Ingreso de valores para el arbol binario";
    arbol.leer();
    cout << endl << "Visualizacion del arbol binario" << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    cout << endl << "Recorrido In-Orden:" << endl;
    iterativeInOrder(arbol);
    cout << endl << "Recorrido Pre-Orden:" << endl;
    iterativePreOrder(arbol);
    cout << endl << "Recorrido Post-Orden:" << endl;
    iterativePostOrder(arbol);

    return 0;
}


