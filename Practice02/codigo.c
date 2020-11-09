#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificar(char * cadena){
	int numero = 0, i = 0;
	if(strlen(cadena) == 5){ //Verificamos la longitud de la cadena
		while(cadena[i] != '\0'){ //Recorremos la cadena hasta su fin
			if(cadena[i]>='0' && cadena[i]<='9') i++; //Comprobamos que solo contenga caracteres
			else return 0;
		}
	return 1;	
	}
	else return 0; 
}

int validar(char * cadena){
	int check = 0, i = 0;
	if(cadena[0] == '0' || cadena[0] == '1') //El primer caracter solo puede contener 0 o 1
		if(cadena[1]>'0' && cadena[1]<='9') //El segundo tiene un rango de 1-9
			if(cadena[0] == '1' && cadena[1]>'6') //Excepcion... si el primer digito es 1, el segundo no puede sobrepasar el 6
				return check;
			else check = 1;
		else return check;
	else return check;
}
