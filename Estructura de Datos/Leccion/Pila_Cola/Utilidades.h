/*Utilidades 
Contiene rutinas comunes a varios casos*/

int leeN(int li,int ls){
	int vl;        //var de lectura
	
	cout << "Ingrese un valor positivos contenido en ["<<li<<","<<ls<<"]: ";
	cin >> vl;
	if (vl<li || vl>ls){  				//vl esta fuera del rango
		return leeN(li,ls);				//llamado recursivoa nueva lectura
	}
	return vl;               			//delver el valor infgresado
}
