#include <stdio.h>
#include <stdlib.h>

//la lista enlazada define su extremo izquierdo con un puntero anterior nulo y su extremo derecho con un puntero next nulo
// el struct ocupa 16 bytes en la memoria
typedef struct Node {
	int data;
	struct Node *next;
  struct Node *previous;
} Node;

typedef struct Indice {
  struct Node *apuntado;
} Indice;

//funcion que crear un nodo y lo agrega una nueva direccion en la lista
int crear_nodo(Indice *indice, int datos)
{
	Node *nuevo = calloc(1, 16);
  nuevo->data = datos;
  nuevo->next = NULL;
  if (indice->apuntado != NULL)
  {
    nuevo->previous = indice->apuntado;
    indice->apuntado = nuevo;
  } else {
    indice->apuntado = nuevo;
  }
	return 0;
}

void borrar_nodo()
{

}

void obtener_nodo()
{

}

void reescribir_datos()
{

}

void vaciar_lista()
{

}

//funcion que muestra los nodos a partir del indice provisto, retrocediendo desde ese indice hasta el principio de la lista
void mostrar_lista(Indice *indice)
{
  Node *posicion_inicial = indice->apuntado;
  while (indice->apuntado->previous != NULL) 
  {
    printf("%d\n", indice->apuntado->data);
    indice->apuntado = indice->apuntado->previous;
  }
  indice->apuntado = posicion_inicial;
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
  //el puntero indice sirve como el indice de en que posicion actual de la lista se esta en el momento
	Indice *indice = calloc(1, sizeof(Indice));
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
        if (crear_nodo(indice, nuevo_numero) == 0)
        {
          printf("Su nuevo nodo ha sido creado y contiene el numero %d\n", indice->apuntado->data);
        }
        //indice_actual = indice_actual->next;//esto seria el indice que indica la posicion dentro de la listas
        break;
      case 2:
        printf("Ingrese el indice de nodo que quiere borrar\n");
        break;
      case 3:
        mostrar_lista(indice);
        break;
      case 4:
        printf("Ingresa el indice del nodo que queres acceder\n");
        break;
    }
    printf("Que operacion va a hacer?\n");
    scanf("%d", &ingreso);
	}
  //seccion en la que se libera toda la memoria ocupada por la lista enlazada
	return 0;
}
