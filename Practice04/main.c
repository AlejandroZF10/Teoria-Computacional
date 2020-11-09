//Zepeda Flores Alejandro de Jesús - 2CM4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codigo.h"

int main(int argc, char *argv[]) {
	int cantidad = 0, repeat = 0;
	struct informacion dato;

	do{
		printf("Practica 4 - Morelos Ordonez Pedro Luis\n");
		printf("	     Zepeda Flores Alejandro de Jesús\n\n");
		printf("Longitud de la cadena? ");
		scanf("%d", &cantidad);
		if(cantidad % 2 == 0)
			verificar(readfile("archivo.txt"),cantidad);
		else printf("Longitud incorrecta");
		printf("\n\nDesea repetir el programa? Si (1)   NO (2) ");
		scanf("%d",&repeat);
		system("cls");
	}while(repeat == 1);
	return 0;
}
