#include <iostream>

int potencia(int base, int exponente) {
    // Caso base: cuando el exponente es 0, el resultado es 1
    if (exponente == 0) {
        return 1;
    }
    // Caso recursivo: la potencia es la suma de la base con la potencia(base, exponente-1)
    else {
        return base + potencia(base, exponente - 1);
    }
}

int main() {
    // Ejemplo de uso
    int base = 2;
    int exponente = 3;
    int resultado = potencia(base, exponente);
    std::cout << "El resultado es: " << resultado << std::endl;  // Salida: 8
    return 0;
}
