#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int repeat = 0, opt = 0, i = 0; 
	int * numero = (int *)malloc(sizeof(int)*5);
	char * codigo = (char *)malloc(sizeof(char)*5);
	
	do{
		printf("Practica 2 - Alejandro Zepeda Flores\n\n");
		printf("1-. Verificar codigo\n2-. Salir del programa\n\n");
		printf("Opcion: "); scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Codigo postal: "); //Solicitar el c�digo postal
				fflush(stdin); gets(codigo); //Lectura del c�digo
				if(verificar(codigo)) //Primera verificaci�n
					if(validar(codigo)) //Segunda verificaci�n
						printf("Codigo postal %s CORRECTO\n",codigo); //Mensaje de aprobaci�n
					else printf("Codigo postal %s INCORRECTO\n",codigo); //Mensaje de negaci�n
				else printf("Codigo postal %s INCORRECTO\n",codigo);
				system("pause"); system("cls"); repeat = 1;
			break;
			case 2:
				repeat = 0;
			break;
			default:
				repeat = 1;
				system("cls");
		}
	}while(repeat == 1);
	return 0;
}
