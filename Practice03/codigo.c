#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codigo.h"

int verificar(char * cadena){
	int numero = 0, i = 0;
	if(strlen(cadena) == 5){ //Verificamos la longitud de la cadena
		while(cadena[i] != '\0'){ //Recorremos la cadena hasta su fin
			if(cadena[i]>='0' && cadena[i]<='9') i++; //Comprobamos que solo contenga caracteres
			else return 1; //Si no contiene solo n�meros, termina la funci�n
		}
		return 1; //Si el ciclo while llega a su fin, expresi�n valida	
	}
	else return 0; //Si la cadena cuenta con una longitud diferente a 5, termina la funci�n
}

int validar(char * cadena){
	int check = 0, i = 0;
	if(cadena[0]=='0' || cadena[0]=='1'){ //Verificamos el primer estado
		printf("\nQ%d -> Q%d estado correcto\n",i,i+1); i = i + 1; //Imprimimos la validaci�n e incrementamos el contador
		if((cadena[0]=='0' && cadena[1]!='0') || (cadena[0]=='1' && cadena[1]<='6')){ //Verficamos la combinaci�n de los 2 primeros d�gitos
			printf("Q%d -> Q%d estado correcto\n",i,i+1); i = i + 1; //Imprimimos la validaci�n e incrementamos el contador
			for(i; i<5 ;i++){ 
				if(cadena[i]>='0' && cadena[i]<='9') //Comprobamos que solo contenga n�meros
					printf("Q%d -> Q%d estado correcto\n",i,i+1); //Imprimimos la validaci�n e incrementamos el contador
				else{ printf("Q%d -> Q%d estado incorrecto\n",i,i+1); return 0; } //Imprimimos el error y termina la funci�n
			}
			return 1;
		}
		else{ printf("Q%d -> Q%d estado incorrecto\n",i,i+1); return 0; }  //Imprimimos el error y termina la funci�n
	}
	else{ printf("\nQ%d -> Q%d estado incorrecto\n",i,i+1); return 0; } //Imprimimos el error y termina la funci�n	
}
