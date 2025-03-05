//utilidades.h
//Jhostin Quispe 
	
#include <iostream>
using namespace std;

int leerN(int li, int ls){
	int x;
	
	cout<<endl<<"Ingrese el numero: ";
	cin>>x;
	
	if((x<li) || (x > ls)){
		return leerN(li,ls);
	}
	return x;
}
