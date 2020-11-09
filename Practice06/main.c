#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pila.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char * namefile = "archivo.txt";
	char * cadena = automata(namefile,cantidad(namefile));
	int x = 0, opt = 0, repeat = 0;
	
	do{
		printf("Practica 6 - Alejandro Zepeda Flores\n");
		printf("1-. Lectura del archivo\n2-. Salir del programa\n");
		printf("Opcion: "); scanf("%d",&opt);
		switch(opt){
			case 1:
				system("cls");
				autopila(namefile,cantidad(namefile));
				system("pause");
				system("cls"); repeat = 1;
			break;
			case 2:
				exit(0);
			break;
			default:
				repeat = 1;
				system("cls");
			break;
		}
	}while(repeat == 1);
}
