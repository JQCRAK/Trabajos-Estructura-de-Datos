#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_CANTIDAD_NUMEROS = 10;
vector<int> obtenerDigitos(int num);
bool contieneDigito(vector<int>& digitos, int digito);
int encontrarNumeroComun(int numeros[], int cantidad);

int main() {
  int numeros[MAX_CANTIDAD_NUMEROS];
  int cantidad;

  cout << "Ingrese la cantidad de numeros: ";
  cin >> cantidad;
  
  for (int i = 0; i < cantidad; ++i) {
    cout << "Ingrese en la posicion [" << i + 1 << "]: ";
    cin >> numeros[i];
  }

  int comun = encontrarNumeroComun(numeros, cantidad);

  if (comun != -1) {
    cout << "El numero comun en los numeros es: " << comun << endl;
  } else {
    cout << "No hay un numero comun en el vector." << endl;
  }

  return 0;
}

vector<int> obtenerDigitos(int num) {
  vector<int> digitos;
  bool esNegativo = num < 0;
  num = abs(num);
  while (num > 0) {
    digitos.push_back(num % 10);
    num /= 10;
  }
  if (esNegativo) {
    digitos.push_back('-');
  }
  reverse(digitos.begin(), digitos.end());
  return digitos;
}

bool contieneDigito(vector<int>& digitos, int digito) {
  bool encontrado = false;
  for (int i = 0; i < digitos.size(); ++i) {
    if (digitos[i] == abs(digito)) {
      encontrado = true;
      break;
    }
  }
  return encontrado;
}

int encontrarNumeroComun(int numeros[], int cantidad) {
  if (cantidad == 0) {
    return -1;
  }

  vector<int> digitosComunes;

  // Obtener los dígitos del primer número
  vector<int> digitosPrimerNumero = obtenerDigitos(numeros[0]);

  // Iterar sobre los dígitos del primer número
  for (int i = 0; i < digitosPrimerNumero.size(); ++i) {
    int digito = digitosPrimerNumero[i];
    bool presenteEnTodos = true;

    // Verificar si el dígito está presente en todos los números
    for (int j = 1; j < cantidad; ++j) {
      vector<int> digitosNumero = obtenerDigitos(numeros[j]);
      if (!contieneDigito(digitosNumero, digito)) {
        presenteEnTodos = false;
        break;
      }
    }

    // Si el dígito está presente en todos los números, agregarlo a la lista de dígitos comunes
    if (presenteEnTodos) {
      digitosComunes.push_back(digito);
    }
  }

  // Si hay dígitos comunes, formar el número común concatenando estos dígitos
  if (!digitosComunes.empty()) {
    int numeroComun = 0;
    bool esNegativo = digitosComunes[0] == '-';
    if (esNegativo) {
      digitosComunes.erase(digitosComunes.begin());
    }
    for (int i = 0; i < digitosComunes.size(); ++i) {
      int digito = digitosComunes[i];
      numeroComun = numeroComun * 10 + digito;
    }
    if (esNegativo) {
      numeroComun *= -1;
    }
    return numeroComun;
  } else {
    return -1; // No hay número común
  }
}


