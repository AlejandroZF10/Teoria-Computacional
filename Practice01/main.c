//Zepeda Flores Alejandro de Jesús - 2CM4	22/Febrero/2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practica1.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]){
	int x = 0, opt = 0, repeat = 0, exponente = 0;
	char cadena1[100];	char cadena2[100];
	
	do{ //Ciclo do while para ofrecer al usuario la opción de realizar otras operaciones sin la necesidad de cerrar el programa
		printf("Practica 1 - Alejandro Zepeda Flores\n\n"); //Interfaz para hacer más accesible el uso del programa
		printf("1-. Palindromo\n2-. Longitud\n3-. Concatenacion\n4-. Potencias\n5-. Inverso\n6-. Prefijos\n7-. Sufijos\n8-. Subcadenas\n9-. Salir\n\n");
		printf("Opcion: "); scanf("%d", &opt);
		switch(opt){
			case 1: //Caso 1: Cadena palindromo
				system("cls"); fflush(stdin);
				printf("Cadena: "); gets(cadena1);
				printf("\nCadena original: %s\n",cadena1);
				printf("Cadena invertida: %s",invertir(cadena1));
				if(palindromo(cadena1)) printf("\n\nLa cadena es un palindromo\n\n");
				else printf("\n\nLa cadena no es un palindromo\n\n");
				repeat = 1; system("pause");
				system("cls");
			break;
			case 2: //Caso 2: Longitud de la cadena
				system("cls"); fflush(stdin);
				printf("Cadena: "); gets(cadena1);
				printf("\nLongitud de la cadena %s: %d\n\n",cadena1,longitud(cadena1));
				repeat = 1;	system("pause"); 
				system("cls");
			break;
			case 3: //Caso 3: Concatenación de dos cadenas
				system("cls");
				fflush(stdin); printf("Cadena 1: "); gets(cadena1);
				fflush(stdin); printf("Cadena 2: "); gets(cadena2);
				printf("\nCadena concatenada: %s\n\n",concatenar(cadena1,cadena2));
				repeat = 1;	system("pause"); 
				system("cls");
			break;
			case 4: //Caso 4: Potencia de una cadena
				system("cls"); fflush(stdin);
				printf("Cadena: "); gets(cadena1);
				printf("Potencia: "); scanf("%d", &exponente);
				if(potencia(cadena1,exponente) == NULL) 
					printf("\nNueva cadena %c\n\n",156);
				else
					printf("\nNueva cadena: %s\n\n",potencia(cadena1,exponente));
				repeat = 1;	system("pause"); 
				system("cls");
			break;
			case 5: //Caso 5: Invertir cadena
				system("cls"); fflush(stdin);
				printf("Cadena: "); gets(cadena1);
				printf("\nCadena invertida: %s\n\n",invertir(cadena1));
				repeat = 1; system("pause");
				system("cls");
			break;
			case 6: //Caso 6: prefijos de una cadena
				system("cls"); fflush(stdin);
				printf("Cadena: "); gets(cadena1);
				prefijos(cadena1);
				repeat = 1; system("pause");
				system("cls");
			break;
			case 7: //Caso 7: posfijos de una cadena
				system("cls"); fflush(stdin);
				printf("Cadena: "); gets(cadena1);
				sufijos(cadena1);
				repeat = 1; system("pause");
				system("cls");
			break;
			case 8: //Caso 8 subacadenas de una cadena
				system("cls"); 
				fflush(stdin); printf("Cadena: "); gets(cadena1);
				buscar_subcadena(cadena1); printf("\n\n");
				repeat = 1; system("pause");
				system("cls");	
			break;				
			case 9: //Caso 9: salir del programa
				repeat = 0;
			break;
			default:
				repeat = 1;
				system("cls");
		}
	}while(repeat == 1);
	return 0;
}
