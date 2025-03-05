
//program de busqueda
#include<iostream>
#define MAX 100
#include <cmath>
//espacio de nombres con el que se trabaja

using namespace std;

//Funcion principal
int main(){
	system ("color F4");
	cout<<endl<<"		GESTION DE VECTORES 001"<<endl;
	int v[MAX];						// Dimensionar arreglo
	int n; 
	int x;                        //valor a buscar
	
	int leerN(int li, int ls);					// prototipo de funcion que permite saber cuantos valores se procesaran
	void leerVector(int a[], int n1);
	void imprimirVector(int b[], int n2);
	void imprimirInverso(int c[], int n3);
	void contarDigitosVector(int d[], int n4);
	void ordenarVector(int e[], int n5);
    int  busquedalineal(int f[], int n7, int x);                     //prototipo de la funcion buscar
	int buscarBinaria(int g[], int n, int x);                   //prototipo de busqueda binaria 
	n=leerN(1, MAX);
	
	cout<<endl<<"LECTURA DEL VECTOR"<<endl<<endl;
	leerVector(v, n);
	
	cout<<endl<<"IMPRESION DEL VECTOR"<<endl;
	ordenarVector(v, n);
	imprimirVector(v, n);

	cout << endl<< "Ingrese el numero buscar en el vector por busqeudad binaria :";
	cin>> x;
	
	int resp =busquedalineal(v, n, x);          //almacena respuesta de la funcion para comparar
	
	if(resp>=0){           //valor devuelto corresponde a su subindice
		cout << endl<< "El valor fue encontrado en la posicion ["<< resp+1<<"]: ";
		cout << v[resp];
	}else{                             // valor no fue encontado en el arreglo
		cout << endl<< "No existe...... :(";
	}
	
	cout<<endl;
	system("pause");
}
int leerN(int li, int ls){
	int x;
	cout<<endl<<"Cantidad de valores a procesar ["<<li<<"..."<<ls<<"]: ";
	cin>>x;
	if((x<li) || (x>ls)){
		leerN(li, ls);
	}
	return x;
}
void leerVector(int a[], int n1){			// leerVector(int *a)
	for(int i=0; i<n1; i++){
		cout<<"-> Ingrese un valor para la posicion ["<<i+1<<"]: ";
		cin>>a[i];
	}	
}
void imprimirVector(int b[], int n2){
	for(int i=0; i<n2; i++){
		cout<<endl<<"-> Valor en la posicion ["<<i+1<<"]: "<<b[i];
	}
}
void imprimirInverso(int c[], int n3){
	for(int i=n3-1; i>=0; i--){
		cout<<endl<<"-> Valor en la posicion ["<<i+1<<"]: "<<c[i];
	}
}
int contarDigitos(int num, 	int *cp, int *ci){
	int cont=0;
	int dig;
	int p=0, i=0;

	do{	//ciclo de conteo
		dig=num % 10; //calcular el ultimo digito del numero
		
		if(dig % 2 == 0){ //si el digito es divisible para 2 es parte de los pares
			(*cp)++; //contador par
		}else{
			(*ci)++;  //contador impar
		}
		
		num/=10; 	//eliminar digito(num=num/10)
		cont ++; //conteo 
	}while(num!=0);//repeir mientras el numero posee 
	
	//*cp=p;
	//*ci=i;
	
	//devolver respuesta
	return cont;
}
void ordenarVectorPares(int e[], int par[], int n6){
	for(int i=0; i<n6-1; i++){
		for(int j=(i+1); j<n6; j++){
			if(par[i]<par[j]){
				int aux = e[i];
				e[i] = e[j];
				e[j] = aux;
				
				int auxp = par[i];
				par[i] = par[j];
				par[j] = auxp;
			}
		}
	}
}
void contarDigitosVector(int d[], int n4){
	int par[n4];
	for(int i=0; i<n4; i++){
		int cp=0, ci=0;
		cout<<endl<<"-> Valor en la posicion ["<<i+1<<"] tiene "<<contarDigitos(d[i], &cp, &ci)<<" digitos";
		par[i]=cp;
		cout<<endl<<"-> Existen "<<cp<<" digitos pares y "<<ci<<" digitos impares"<<endl;
	}
	cout<<endl<<"ORDENAMIENTO SEGUN PARES"<<endl;
	ordenarVectorPares(d, par, n4);
	imprimirVector(d, n4);
	
}
void ordenarVector(int e[], int n5){
	for(int i=0; i<n5-1; i++){
		for(int j=(i+1); j<n5; j++){
			if(e[i]<e[j]){
				int aux = e[i];
				e[i] = e[j];
				e[j] = aux;
			}
		}
	}
}


int  busquedalineal(int f[], int n7, int x){              // funcion de buscar linealmente
    for(int i=0;i<n7;i++){                      //ciclo del recorrido del arreglo
        if (f[i]==x){                               //el valor de esta posicion corresponde al valor 
        	return i;
	}
	}
	return -1;	
}


int buscarBinaria(int g[], int n, int x){                 // funcion para buscar en binario
	int ini, fin, med;                                 //var para segmentar
	ini=0;                                                  //tomar primera posicion
	fin = n-1;												// tomar la ultima posicion
	while(ini<=fin){                                       // mientras que haya elementos por fina;lizar 
		med=(ini+fin)/2;                                 //calculo la posicion central del arreglo
		if (g[med]== x ){                                  //posicion buscar esta en el centro delvolvemos su posicion
		    return med;                                 // devuelve la posici central encontrado
		}else{                                         // nose encontro el valor igual 
			if(x<g[med]){                               //valor buscado en la posicion central 
			fin= med-1;                                  // posicion final de busqueda en el anterior 
		}else  {                                        //valor buscado es mayor a la posicion central
			ini = med +1;                              // la nueva posicion de incioa para leer
		}
	}	
 }
 return -1;                                           //devolver indicador que no se encontro 
}

