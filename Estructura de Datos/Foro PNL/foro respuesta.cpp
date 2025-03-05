// main.cpp#include <iostream>
using namespace std;
#include <iostream>
#include "GrafoMatriz1.h"

int main(){
	system("color F4");
    GrafoMatriz expresionesFaciales(5); // Crear un grafo con 5 expresiones faciales

    expresionesFaciales.nuevoVertice("Feliz");
    expresionesFaciales.nuevoVertice("Triste");
    expresionesFaciales.nuevoVertice("Enojado");
    expresionesFaciales.nuevoVertice("Sorprendido");
    expresionesFaciales.nuevoVertice("Neutro");

    expresionesFaciales.setArco("Feliz", "Triste");
    expresionesFaciales.setArco("Triste", "Enojado");
    expresionesFaciales.setArco("Enojado", "Sorprendido");
    expresionesFaciales.setArco("Sorprendido", "Neutro");
    // Ejemplo de detección de expresión facial
    string expresionDetectada = "Feliz";
    while (true){
        cout<<"Expresion Actual: "<<expresionDetectada<<endl;
        // Mostrar expresiones faciales adyacentes
        cout<<"Expresiones Adyacentes: ";
        for (int i = 0; i < expresionesFaciales.getNumVerts(); ++i){
            if (expresionesFaciales.adyacente(expresionDetectada, expresionesFaciales.getVertice(i).getDato())){
                cout<<expresionesFaciales.getVertice(i).getDato()<<" ";
            }
        }
        cout<<endl;
        // Preguntar al usuario por la próxima expresión facial
        cout<<endl<<"Ingrese la proxima expresion facial (o 'exit' para salir): ";
        cin >> expresionDetectada;

        if (expresionDetectada == "exit"){
            break;
        }
        // Verificar si la expresión ingresada es válida
        if (expresionesFaciales.getNumVertice(expresionDetectada) < 0){
            cout<<"Expresion facial no reconocida. Intente de nuevo."<<endl;
        }
    }

    return 0;
}
