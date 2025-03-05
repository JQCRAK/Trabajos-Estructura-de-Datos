#ifndef NODO_H
#define NODO_H

#include <vector>

// Declaraci�n adelantada de BTree para hacerla amiga de BTreeNode
class BTree;

// Definici�n de un nodo del �rbol B
struct BTreeNode {
    std::vector<int> keys;           // Vector de claves en el nodo
    std::vector<BTreeNode*> children; // Vector de punteros a los hijos
    bool leaf;                       // Indica si es nodo hoja
    int num_keys;                    // N�mero actual de claves en el nodo
    
    // Constructores
    BTreeNode(bool leaf);
    BTreeNode(const std::vector<int>& keys, const std::vector<BTreeNode*>& children, bool leaf, int num_keys);
    
    // Funci�n amiga para permitir acceso a miembros privados desde BTree
    friend class BTree;
};

#endif // NODO_H

