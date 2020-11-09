struct informacion{
	char llave;
	int linea;
};

struct nodo{
	struct informacion dato;
	struct nodo * siguiente;
};

typedef struct nodo * pila; //Pila es un apuntador a struct nodo
typedef struct informacion INFO; //INFO es un struct información
typedef struct nodo NODO; //NODO es un struct nodo
typedef enum b{FALSE,TRUE}booleano; //Mensajes para la función empty
typedef enum M{NO_MEMORY,OK}mensaje; //Mensajes para la función push

void iniciar(pila * p); //Inicializa la pila
void reiniciar_pila(pila * p); //Libera la pila
INFO pop(pila * p); //Regresa el último elemento guardado
mensaje push(pila * p, INFO dato); //Guarda el último elemento leído y regresa un mensaje de confirmación
booleano empty(pila p); //Vacía la pila
INFO top(pila p); //Obtiene una copia de la cima de la pila
int autopila(char * namefile,int cantidad);
char * automata(char * namefile,int cantidad);
