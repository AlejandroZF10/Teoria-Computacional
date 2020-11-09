#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practica1.h"

int palindromo(char * cadena){
	int i = 0, j = 0, palindromo = 1;
	j = longitud(cadena)-1; //Calcular la longitud de la cadena 
	for(i=0; i<longitud(cadena)/2 ; i++,j--){ //Ciclo for para recorrer los extremos de la cadena
		if(*(cadena+i) != *(cadena+j)){ //SI un caracter no coincide, terminar el ciclo
			palindromo = 0; break; //Terminamos el ciclo y actualizamos palindromo
		}
	}
	if(palindromo) return 1; //Si palindromo = 1, significa que la cadena es palindromo
	else return 0;
}

int longitud(char * cadena){
	return strlen(cadena); //Retorna la longitud de una cadena
}

char * concatenar(char * cadena1, char * cadena2){
	char * auxiliar = NULL;
	int x = 0, y = 0, tam1 = 0, tam2 = 0;
	
	tam1 = longitud(cadena1); //Calcular tamaño de cadena1
	tam2 = longitud(cadena2); //Calcular tamano de cadena 2
	auxiliar = (char *)malloc(sizeof(char)*(tam1+tam2)); //Solicitar el espacio de memoria para la suma de los tamaños
	while(x<tam1){ auxiliar[x] = cadena1[x]; x++; } //Asignar a la nueva cadena la cadena 1
	while(y<=tam2){ auxiliar[x] = cadena2[y]; x++; y++;	} //Asignar a la nueva cadena la cadena 2
	auxiliar[x] = '\0'; //Asignar el fin de cadena
	return auxiliar;	
}

char * potencia(char * cadena, int exponente){
	int i = 0, j = 0, tam = 0, tam2 = 0; 
	char * auxiliar = NULL; char * auxiliar2 = NULL;
	
	if(exponente == 0)	return NULL; //Si exponente = 0 retorna epsilon
	else if(exponente == 1) return cadena; //Si exponente = 1 retorna la misma cadena
		else if(exponente == -1) return invertir(cadena); //Si exponente = -1 retorna la cadena inversa
	if(exponente>1){ //Mientras exponente > 1
		tam = longitud(cadena); //Obtener longitud de cadena
		auxiliar = (char *)malloc((sizeof(char))*((tam*exponente)+1)); //Solicitar los caracteres de la nueva cadena
		for(i=0; i<(tam*exponente) ;i++){ //Ciclo for para recorrer la longitud de la nueva cadena
			auxiliar[i] = cadena[j]; j++; //Asignar a la nueva cadena la original
			if(j==tam) j = 0; //Si j == tam, significa que recorrimos toda la cadena original
		}
		auxiliar[i] = '\0';//Asignar el fin de cadena
		return auxiliar;
	}
	if(exponente<-1){
		auxiliar2 = invertir(cadena); //Invertir la cadena
		tam = longitud(auxiliar2); //Obtener longitud de cadena
		auxiliar = (char *)malloc((sizeof(char))*(((tam*(exponente*(-1)))+1))); //Solicitar los caracteres de la nueva cadena
		for(i=0; i<(tam*(exponente*(-1))) ;i++){ //Ciclo for para recorrer la longitud de la nueva cadena
			auxiliar[i] = auxiliar2[j]; j++; //Asignar a la nueva cadena la original
			if(j==tam) j = 0; //Si j == tam, significa que recorrimos toda la cadena original
		}
		auxiliar[i] = '\0'; //Asignar el fin de cadena
		return auxiliar;
	}
}

char * invertir(char * cadena){
	int i = 0, j = 0, tam = 0;
	char * auxiliar = NULL;
	
	tam = longitud(cadena); //Obtener la longitud de la cadena
	auxiliar = (char *)malloc(sizeof(char)*tam); //Solicitar la memoria para la nueva cadena
	for(i=tam-1; i>=0 ; i--){ //Ciclo for inverso para recorrer la cadena
		auxiliar[j] = cadena[i]; j++; //Asignar la nueva cadena la original invertida
	}
	auxiliar[j] = '\0'; //Asignar el fin de cadena
	return auxiliar;
}

void prefijos(char * cadena){
	int i = 0, j = 0, l = 0, tam = 0;
	char auxiliar[100][100];
	
	tam = longitud(cadena); //Obtener la longitud de la cadena
	for(i=0; i<=tam ;i++) //Asignar a todas las posiciones de la primer columana el caracter vacío
		auxiliar[i][0] = 156;
	for(i=0; i<=tam ;i++){ //Ciclo for que recorre columnas
		for(j=1; j<=tam ;j++,l++) //Ciclo for que recorre filas
			auxiliar[i][j] = cadena[l]; l=0; //Asignar la cadena original al nuevo original
	}
	for(i=0; i<tam+1 ;i++){ //Primer ciclo for para imprimir
		if(i<9) printf("Prefijo 0%d: ",i+1); //Imprimir prefijos
		else printf("Prefijo %d: ",i+1); //Imprimir prefijos
		for(j=0; j<tam+1 ;j++){ //Segundo ciclo for para imprimir
			if(j<=i)
				printf(" %c", auxiliar[i][j]); //Imprimir los caracteres correspondientes
			if(j==i)
				printf("\n");
		}
	}	
}

void sufijos(char * cadena){
	int i = 0, j = 0, l = 0, tam = 0;
	char auxiliar[100][100]; char nueva[100];
	
	strcpy(nueva,invertir(cadena)); //Invertir la cadena original
	tam = longitud(nueva); //Obtener la longitud de la cadena
	for(i=0; i<=tam ;i++) //Asignar a la primera posición de la primer columna
		auxiliar[i][0] = 156;
	for(i=0; i<=tam ;i++){ //Primer ciclo for para asignar
		for(j=1; j<=tam ;j++,l++) //Segundo ciclo for para asignar
			auxiliar[i][j] = nueva[l]; l=0; //Asignarl la cadena al nuevo arreglo
	}
	for(i=0; i<tam+1 ;i++){ //Primer ciclo for para imprimir
		if(i<9) printf("Posfijo 0%d: ",i+1); //Imprimir posfijos
		else printf("Posfijo %d: ",i+1); //Imprimir posfijos
		for(j=tam+1; j>=0 ;j--){ //Segundo ciclo for para imprimir
			printf(" %c ",auxiliar[i][j-1-i]); //Imprimir los caracteres correspondientes
		}
		printf("\n");
	}	
}

void buscar_subcadena(char * cadena1){
	int l = 0, tam = 0, i = 0, p = 0, k = 0, j = 0, m = 0;
	
	p = tam = longitud(cadena1); //Obtener la longitud de la cadena
	for (l=0; l<tam; l++){ //Primer ciclo for para recorrerla
		for (i=0; i<p; i++){ //Segundo ciclo for para recorrerla 
			k = k + 1; printf("\n");
			for (j = m; j < k ;j++) //Ciclo for para imprimir
				printf("%c",cadena1[j]); //Imprimir los caracteres correspondientes
		}
		m = m + 1; p = p - 1; //Aumento de contadores
		k = m; printf("\n");
	}
}
