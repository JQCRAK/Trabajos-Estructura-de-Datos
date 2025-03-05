/* 	Utilidades
	Contiene rutinas comunes a varios casos
	
	Autor: Angel Guaño (7337)
*/

int leerN(int li, int ls){
	int vl;		//var de lectura
	
	cout << endl << "Ingrese un valor positivo comprendido en el rango [" << li << ".." << ls << "]: ";
	cin >> vl;
	
	if ((vl <li) || (vl > ls)){				//vl esta fuera del rango
		return leerN(li, ls); 				//llamdo recursivo a nueva lectura
	}
	return vl;
}