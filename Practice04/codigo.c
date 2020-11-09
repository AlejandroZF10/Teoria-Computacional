#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codigo.h"

char * readfile(char * namefile){
	int posicion = 0, tam = 0, i = 0;
	char caracter; char * lenguaje;
	
	FILE * file = fopen(namefile,"r");
    	fflush(stdin); caracter = fgetc(file);
    	while(caracter != EOF){
    		tam = tam + 1;
		caracter = fgetc(file);	
	}
    	fclose(file); fopen(namefile,"r");
    	lenguaje = (char *)malloc(sizeof(char)*(tam+1));
    	fflush(stdin); caracter = fgetc(file);
    	for(i=0; i<tam; i++){
    		lenguaje[posicion++] = caracter;
		caracter = fgetc(file);    			
	}
	lenguaje[posicion] = '\0';
	fclose(file);
	return lenguaje;
}

int verificar(char * cadena, int repeat){
	char s; char a; char b; char x = 0;
	int i = 0, j = 0, l = 0, tam = 0;
	i = tam = strlen(cadena)-1;
	while(cadena[i]!=32){
		if(cadena[i]>=65 && cadena[i]<=90){
			s = cadena[i]; break;
		}
		else 
			l = l+1;
		i = i-1;
	} j = tam-l-5;
	b = cadena[tam]; a = cadena[tam-l-1];
	printf("%c\n",156);
	for(x=1; x<=repeat ;x++){
		for(i=0; i<j*x ;i++)
			printf("%c",a);
		if(x!=repeat)
			printf("%c",s);
		for(i=0; i<l*x ;i++)
			printf("%c",b);
		printf("\n");
	}
	return 0;
}
