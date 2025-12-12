#include <stdio.h>
#include <stdlib.h>

//la lista enlazada define su extremo izquierdo con un puntero anterior nulo y su extremo derecho con un puntero next nulo
// el struct ocupa 24 bytes en la memoria
typedef struct Node {
  unsigned int ID;
	int data;
	struct Node *next;
  struct Node *previous;
} Node;

typedef struct Indice {
  struct Node *apuntado;
  unsigned int longitud;
} Indice;

//funcion que crear un nodo y lo agrega una nueva direccion en la lista
int crear_nodo(Indice *indice, int datos)
{
	Node *nuevo = calloc(1, 24);
  nuevo->data = datos;
  nuevo->next = NULL;
  if (indice->apuntado != NULL)
  {
    nuevo->previous = indice->apuntado;
    nuevo->ID = indice->apuntado->ID + 1;
    indice->apuntado = nuevo;
  } else {
    nuevo->ID = 0;
    indice->apuntado = nuevo;
  }
	return 0;
}

void borrar_nodo(Indice *indice, unsigned int ingreso_id)
{
  /*
   * usar iteracion para encontrar el nodo con el ID indicado?
   * O una busqueda binaria? Al menos inicialmente los ID estan ordenados de menor a mayor. Aunque no se puede garantizar que se mantendra ordenada durante la vida del programa.
   * Mover el indice al nodo siendo comparado actualmente o solo usarlo como punto de partida
   * asegurarse de que no quede ninguna referencia al nodo borrado en los nodos adyacentes
   * varios casos de fallas durante tiempo de ejecucion:
   * 1. al borrar ciertos nodos(el primero) dejan de ser mostrados por mostrar_lista() lista otros nodos como el ultimo nodo
   */
  Node *temp = NULL;
  while (indice->apuntado->ID != ingreso_id && indice->apuntado->previous != NULL) 
  {
    //este condicional al estar posicionado adentro del bucle va a constantemente actualisarse en vez de setear el valor una sola vez
    if (indice->apuntado->ID != ingreso_id && temp == NULL) 
    {
      temp = indice->apuntado;
    }
    indice->apuntado = indice->apuntado->previous; 
  }
  if (indice->apuntado->ID == ingreso_id) 
  {
    if (indice->apuntado->previous != NULL)//problema si el nodo que queremos borrar esta en un extremo de la lista 
    {
      indice->apuntado->previous->next = indice->apuntado->next;
    }
    if (indice->apuntado->next != NULL) 
    {
      indice->apuntado->next->previous = indice->apuntado->previous;
    }
    if (indice->apuntado->previous == NULL) 
    {
      indice->apuntado->next->previous = NULL;
    }//segfault causada por alguno de estos condicionales me parece
    if (indice->apuntado->next == NULL)
    {
      indice->apuntado->previous->next = NULL;
    }
    if (temp->previous == indice->apuntado) 
    {
      temp->previous = indice->apuntado->previous;
    }
    Node *a_eliminar = indice->apuntado;
    indice->apuntado = temp;
    free(a_eliminar);
  } else if (indice->apuntado->previous == NULL && indice->apuntado->ID != ingreso_id) {
    printf("No se ha encontrado ningun nodo con el ID indicado\n");
  }
}

void obtener_nodo()
{

}

void cambiar_numero()
{

}

void vaciar_lista()
{

}

//funcion que muestra los nodos a partir del indice provisto, retrocediendo desde ese indice hasta el principio de la lista
void mostrar_lista(Indice *indice)
{
  Node *posicion_inicial = indice->apuntado;
  //al tener una direccion de memoria vaciada por free pero no NULL este sigue avanzado
  while (indice->apuntado->previous != NULL) 
  {
    printf("ID: %d numero: %d\n", indice->apuntado->ID, indice->apuntado->data);
    indice->apuntado = indice->apuntado->previous;
  }
  printf("ID: %d numero: %d\n", indice->apuntado->ID, indice->apuntado->data);
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
  //printf("%ld\n", sizeof(Node));// ocupa 24 bytes
  //printf("%ld\n", sizeof(Indice));// ocupa 8 bytes
  //el puntero indice sirve como el indice de en que posicion actual de la lista se esta en el momento
	Indice *indice = calloc(1, sizeof(Indice));
  indice->longitud = 0;
  printf("Bienvenido a el controlador the listas enlazadas, ¿que quiere hacer?\n");
	printf("Ingrese 1 para crear un nodo, 2 para borrar un nodo, 3 para ver la lista de nodos actual, 4 para acceder a un nodo especifico, 5 para salir del programa\n");
	unsigned int ingreso = 0;
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
          indice->longitud += 1;
          printf("Su nuevo nodo ha sido creado y contiene el numero %d\n", indice->apuntado->data);
        }
        //indice_actual = indice_actual->next;//esto seria el indice que indica la posicion dentro de la listas
        break;
      case 2:
        printf("Ingrese el indice de nodo que quiere borrar\n");
        scanf("%d", &ingreso);
        borrar_nodo(indice, ingreso);;
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
