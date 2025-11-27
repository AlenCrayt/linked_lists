#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	int data;
	struct Node *next;
} Node;

int crear_nodo(Node *raiz, int datos)
{
	int codigo;
	Node nuevo = {datos, NULL};
	if (raiz == NULL)
	{
		return -1;
	}
	else
	{
		while (raiz->next != NULL)
		{
			raiz = raiz->next;
		}
		raiz->next = &nuevo;
	}
	return 0;
}

int borrar_nodo()
{

}

int obtener_nodo()
{

}

int copiar_datos()
{

}

void mostrar_listas(Node *lista_actual)
{
	if (lista_actual == NULL)
	{
		printf("Error: el puntero pasado a la funcion es nulo\n");
	}
	else
	{
		while (lista_actual->next != NULL)
		{
			printf("%d\n", lista_actual->data);
			lista_actual = lista_actual->next;
		}
		printf("%d\n", lista_actual->data);
	}
}

int main()
{
	Node primero = {0, NULL};
	Node *indice_actual = &primero;
	printf("Bienvenido a el controlador the listas enlazadas, ¿que quiere hacer?\n");
	printf("Ingrese 1 para crear un nodo, 2 para borrar un nodo, 3 para ver la lista de nodos actual\n");
	int ingreso = 0;
	scanf("%d", &ingreso);
	switch(ingreso)
	{
		case 1:
			printf("Ingrese el numero entero que quiere guardar en este nuevo nodo\n");
			int nuevo_numero = 0;
			scanf("%d", &nuevo_numero);
			int ret = crear_nodo(indice_actual, nuevo_numero);
			printf("Su nuevo nodo ha sido creado y contiene el numero %d\n", primero.next->data);
			indice_actual = indice_actual->next;
			break;

	}
	return 0;
}
