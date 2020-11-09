#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pila.h"

void iniciar(pila * p){
	*p = NULL; // Inicializa la pila a NULL
}

void reiniciar_pila(pila * p){
	while(!empty(*p))
		pop(p);	//Mientras la pila no este vacía, eliminar los elementos de la pila
}

mensaje push(pila * p, INFO dato){
	pila temp = NULL;
	temp = (pila)malloc(sizeof(NODO)); //Reservamos espacio de memoria para cada nodo que vamos creando
	if(temp == NULL)
		return NO_MEMORY; //Verificamos que el requerimiento haya sido aceptado
	temp->dato = dato; //El campo dato de temp es igual al dato que solicitamos como parametro
	temp->siguiente = *p; //El apuntador siguiente de temp apuntara a la cima de la pila
	*p = temp; //El nodo de la cima de la pila es igual al nodo temp
	return OK;  
}

INFO pop(pila * p){
	pila temp = NULL; 
	INFO copia;
	copia = (*p)->dato; //Asignamos a copia los datos que se encuentren en la cima de la pila
	temp = *p; //Asignamos a temp la dirección de memoria la cima de la pila
	*p = (*p)->siguiente; // La direccion de la cima de la lista es igual a la dirección del siguiente elemento
	free(temp); //Liberamos temp
	return copia;
}

booleano empty(pila p){
	if(p == NULL)
		return TRUE; //Si la pila esta nula, regresa TRUE
	return FALSE; //Si la pila no esta nula, regresa FALSE
}

INFO top(pila p){
	INFO copia;
	copia = p->dato; //Crea una copia de la informacion de la cima de la pila
	return copia;
}

int cantidad(char * namefile){ 
	FILE * file; char caracter; int numero = 0;
	
	file = fopen(namefile,"r");
    caracter = fgetc(file);
    while(caracter != EOF){
    	numero = numero + 1;
    	caracter = fgetc(file);
	}
	fclose(file);
	return numero;
}

int autopila(char * namefile,int cantidad){
	FILE * file; char caracter;
	struct nodo * stack;
	struct informacion dato;
	char * cadena = automata(namefile,cantidad);
	int apertura = 0, clausura = 0;
	iniciar(&stack); fflush(stdin);
	file = fopen(namefile,"r");
	caracter = fgetc(file);
	while(caracter != EOF){
		switch(caracter){
			case '{': dato.llave = 'A';push(&stack,dato);apertura = apertura + 1;break;
			case '[': dato.llave = 'B';push(&stack,dato);apertura = apertura + 1;break;
			case '(': dato.llave = 'C';push(&stack,dato);apertura = apertura + 1;break;	
			break;
			case '}': case ']': case ')':
				clausura = clausura + 1;
				if(!empty(stack)){
					dato = top(stack);
		            if((dato.llave=='A' && caracter=='}')||(dato.llave=='B' && caracter==']')||(dato.llave=='C' && caracter==')')){
						pop(&stack);
					}
				}
			break;
		}
		caracter = fgetc(file);
	}
	if(apertura == clausura){
		if(empty(stack))
   			printf("Cadena %s aceptada - PILA VACIA\n\n",cadena);
   		else{
   			printf("Cadena %s rechazada - PILA NO VACIA\n\n",cadena);
			while(!empty(stack)){
				printf("*****\n");
				if(top(stack).llave == 'A') printf("* %c * Lenguaje para llave\n", top(stack).llave);
				if(top(stack).llave == 'B') printf("* %c * Lenguaje para corchete\n", top(stack).llave);
				if(top(stack).llave == 'C') printf("* %c * Lenguaje para parentesis\n", top(stack).llave);
				pop(&stack);
			}
			printf("*****\n\n");
		}
	}
	else{
		if(apertura<clausura)
			printf("Cadena %s rechazada - PILA VACIA\n\n",cadena);
		else{
			printf("Cadena %s rechazada - PILA NO VACIA\n\n",cadena);
			while(!empty(stack)){
				printf("*****\n");
				if(top(stack).llave == 'A') printf("* %c * Lenguaje para llave\n", top(stack).llave);
				if(top(stack).llave == 'B') printf("* %c * Lenguaje para corchete\n", top(stack).llave);
				if(top(stack).llave == 'C') printf("* %c * Lenguaje para parentesis\n", top(stack).llave);
				pop(&stack);
			}
			printf("*****\n\n");	
		}
	}
	fclose(file);
}

char * automata(char * namefile,int cantidad){
	FILE * file; 
	char caracter; int posicion = 0;
	char * cadena = (char *)malloc(sizeof(char)*cantidad);
	file = fopen(namefile,"r");
	caracter = fgetc(file);
	while(caracter != EOF){
		cadena[posicion] = caracter;
		posicion = posicion + 1;
		caracter = fgetc(file);
	}
	cadena[posicion] = '\0';
	fclose(file);
	return cadena;
}
