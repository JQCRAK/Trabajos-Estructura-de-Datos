/*Programa recursivo que permite calcular un exponente por medio de productos*/
#include <iostream>

using namespace std;

int main(){
	system("Color f1");
	int n1,n2;
	int c=0;
	int leerDatos(int li, int ls);     //prototipo
	int calcularExponente(int b, int e);      //prototipo
	int calcularProducto(int a, int b);
	int calcularSumaExponente(int a, int b, int c);
	
	cout << "Ingrese la base: ";
	n1=leerDatos(0,100);
	cout <<endl<< "Ingrese el exponente: ";
	n2=leerDatos(0,5);
	cout << endl<<"La base "<<n1<< " elevado al esponente "<<n2 <<": " <<calcularExponente(n1,n2);
	cout << "Seguiente problemas"<<endl;
	cout << endl<<"Ingrese el multiplicando: ";
	n1=leerDatos(0,100);
	cout << "Ingrese el multiplicador: ";
	n2=leerDatos(0,5);
	calcularProducto(n1,n2);
	cout << "La multiplicacion entre "<<n1<<" * "<<n2<<" = "<< calcularProducto(n1,n2);
	cout <<endl<<"Siquiente Problema"<<endl;
	cout << "Ingrese el primer valor:";
	n1=leerDatos(0,100);
	cout<<"Ingrese el segundo valor: ";
	n2=leerDatos(0,5);
	cout << "La multiplicacion entre "<<n1<<" * "<<n2<<" = "<< n1*n2<< "tambien es "<< n1<<"Con esponente "<<calcularSumaExponente(n1,n2,c);
	
}


int leerDatos(int li, int ls) {
    int n;
    cout << "Ingree un valor positivo ["<<li<<","<<ls<<"]: ";
    cin >> n;

    if (n < li || n > ls) {
        cout << "El dato no esta dentro del rango" << endl;
        return leerDatos(li, ls);
    }
    return n;
}

int calcularExponente(int b, int e){
	if (e>=1){                                   //Valor del exponente es poitivo
		return b* calcularExponente(b,e-1);               //Llamado recursivo 
	}
	return 1;
}
int calcularProducto(int a, int b){
	if(b>=1){
		return b+calcularProducto(a, b-1);
	}	
	return 0;
}

int calcularSumaExponente(int a, int b, int c){
	if (a*b!=a*b){
		return calcularSumaExponente(a,b,c+1);
	}
}
