#ifndef NODO_H
#define NODO_H

#include <vector>

// Declaración adelantada de BTree para hacerla amiga de BTreeNode
class BTree;

// Definición de un nodo del árbol B
struct BTreeNode {
    std::vector<int> keys;           // Vector de claves en el nodo
    std::vector<BTreeNode*> children; // Vector de punteros a los hijos
    bool leaf;                       // Indica si es nodo hoja
    int num_keys;                    // Número actual de claves en el nodo
    
    // Constructores
    BTreeNode(bool leaf);
    BTreeNode(const std::vector<int>& keys, const std::vector<BTreeNode*>& children, bool leaf, int num_keys);
    
    // Función amiga para permitir acceso a miembros privados desde BTree
    friend class BTree;
};

#endif // NODO_H

