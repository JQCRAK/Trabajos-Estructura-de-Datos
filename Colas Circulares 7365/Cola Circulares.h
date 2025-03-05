// Jhostin Quispe 7365
//ColaCircular.h
// Implementacion del TDA Cola Circular

typedef int Tipo;        // Definicion del tipo de datos que contendra la estructura
#define EXT 50          // Dimensión maxima del TDA

class ColaCircular {       // Definicion del TDA
private:                // Atributos
    Tipo vec[EXT];      // Definicion del arreglo contenedor de datos
    int frente;         // Apuntador a posicion de extracción de elementos del TDA
    int final;          // Apuntador a posicion de inserción de elementos en el TDA

public:                 // Metodos
    ColaCircular();         // Constructor
    void enqueue(Tipo val);     // Insercion de un elemento
    Tipo dequeue();         // Eliminacion de un elemento
    Tipo peek();            // Consulta del elemento en el frente
    bool colaVacia();       // Verificacion de estado (vacia)
    bool colaLlena();       // Verificacion de estado (llena)
};

ColaCircular::ColaCircular() {       // Constructor
    frente = 0;     // Inicializar frente
    final = 0;      // Inicializar final
}

void ColaCircular::enqueue(Tipo val) {   // Insercion de un elemento
    if (!colaLlena()) {
        vec[final] = val;       // Insertar elemento en posicion final
        final = (final + 1) % EXT;  // Actualizar posicion final de manera circular
    }
}

Tipo ColaCircular::dequeue() {      // Eliminacion de un elemento
    Tipo aux = -1;  // Valor por defecto si la cola esta vacia
    
    if (!colaVacia()) {
        aux = vec[frente];  // Almacenar el valor del elemento a eliminar
        frente = (frente + 1) % EXT;    // Actualizar posicion de frente de manera circular
    }
    return aux; // Retornar el valor extraido
}

Tipo ColaCircular::peek() {        // Consulta del elemento en el frente
    if (!colaVacia()) {
        return vec[frente];     // Retornar el valor del elemento en frente si la cola no esta vacia
    }
    return -1;  // Retornar -1 si la cola esta vacia
}

bool ColaCircular::colaVacia() {       // Verificacion de estado (vacia)
    return frente == final;     // La cola esta vacia si frente y final apuntan al mismo lugar
}

bool ColaCircular::colaLlena() {       // Verificacion de estado (llena)
    return (final + 1) % EXT == frente;    // La cola esta llena si la posicion siguiente a final es igual a frente
}

