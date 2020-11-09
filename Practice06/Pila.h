struct informacion{
	char llave;
	int linea;
};

struct nodo{
	struct informacion dato;
	struct nodo * siguiente;
};

typedef struct nodo * pila; //Pila es un apuntador a struct nodo
typedef struct informacion INFO; //INFO es un struct informaci�n
typedef struct nodo NODO; //NODO es un struct nodo
typedef enum b{FALSE,TRUE}booleano; //Mensajes para la funci�n empty
typedef enum M{NO_MEMORY,OK}mensaje; //Mensajes para la funci�n push

void iniciar(pila * p); //Inicializa la pila
void reiniciar_pila(pila * p); //Libera la pila
INFO pop(pila * p); //Regresa el �ltimo elemento guardado
mensaje push(pila * p, INFO dato); //Guarda el �ltimo elemento le�do y regresa un mensaje de confirmaci�n
booleano empty(pila p); //Vac�a la pila
INFO top(pila p); //Obtiene una copia de la cima de la pila
int autopila(char * namefile,int cantidad);
char * automata(char * namefile,int cantidad);
