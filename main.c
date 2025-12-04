#include <stdio.h>
#include <stdlib.h>

//la lista enlazada define su extremo izquierdo con un puntero anterior nulo y su extremo derecho con un puntero next nulo
// el struct ocupa 16 bytes en la memoria
typedef struct Node 
{
	int data;
	struct Node *next;
} Node;

//funcion que crear un nodo y lo agrega una nueva direccion en la lista
int crear_nodo(Node *anterior, int datos)
{
	if (anterior == NULL)
	{
		return -1;
	}
	Node *nuevo = malloc(16);
  nuevo->data = datos;
  nuevo->next = NULL;
	if (anterior->next == NULL)
	{
    anterior->next = nuevo;
	}
	return 0;
}

void borrar_nodo()
{

}

void obtener_nodo()
{

}

void copiar_datos()
{

}

//funcion que muestra los nodos a partir del indice provisto, generalmente recomendado que este puntero sea al primero nodo de la lista
void mostrar_lista(Node *primer_nodo)
{
	if (primer_nodo == NULL)
	{
		printf("Error: el puntero pasado a la funcion es nulo\n");
	}
	else
	{
		while (primer_nodo->next != NULL)
		{
			printf("%d\n", primer_nodo->data);
			primer_nodo = primer_nodo->next;
		}
		printf("%d\n", primer_nodo->data);
	}
}

/*
  * esta lista de nodos tiene que existir fuera de las funciones en las que son accedidas, hay que usar el heap para
  * darles memoria
  * necesito un sistema claro de organización de la lista, para poder buscar y leer datos de nodos despues default:
  * su creacion
*/
int main()
{
  //printf("%d\n", sizeof(Node));
	Node *primero = malloc(16);
	printf("Bienvenido a el controlador the listas enlazadas, ¿que quiere hacer?\n");
	printf("Ingrese 1 para crear un nodo, 2 para borrar un nodo, 3 para ver la lista de nodos actual, 4 para acceder a un nodo especifico, 5 para salir del programa\n");
	int ingreso = 0;
	scanf("%d", &ingreso);
	while (ingreso != 5) 
  {
    switch(ingreso)
    {
      case 1:
        printf("Ingrese el numero entero que quiere guardar en este nuevo nodo\n");
        int nuevo_numero = 0;
        scanf("%d", &nuevo_numero);
        if (crear_nodo(primero, nuevo_numero) == 0)
        {
          printf("Su nuevo nodo ha sido creado y contiene el numero %d\n", primero->next->data);
        }
        //indice_actual = indice_actual->next;//esto seria el indice que indica la posicion dentro de la listas
        break;
    }
    printf("Que operacion va a hacer?\n");
    scanf("%d", &ingreso);
	}
  //seccion en la que se libera toda la memoria ocupada por la lista enlazada
	return 0;
}
