#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
	int dato;
	int num_nodo;
	struct Nodo *siguiente_nodo;
};

int numero_nodos;
/*
Si *siguiente_siguiente es NULL entonces no apunta a nadie
Si se le pasa un apuntador a un nodo existente, esto equivale
a ponerla una flecha a ese nodo
*/
struct Nodo *crea_nodo(int dato, struct Nodo *siguiente_nodo)
{
	struct Nodo *nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	if(nuevo_nodo == NULL)
	{
		printf("\nProblema al crear el cliente");
		exit(0);
	}
	nuevo_nodo->dato=dato;
	nuevo_nodo->siguiente_nodo = siguiente_nodo;
	return nuevo_nodo;	
}

void numera_nodos(struct Nodo *primer_nodo)
{
	if(esta_vacia(primer_nodo))
	{
		printf("\nNo hay clientes para numerar");
		return;
	}
	int num_nodo = 1;
	struct Nodo *aux = primer_nodo;
	while(aux->siguiente_nodo != NULL)
	{
		aux->num_nodo = num_nodo;
		aux = aux->siguiente_nodo;
		num_nodo++;
	}
	aux->num_nodo=num_nodo;
	numero_nodos=num_nodo;
}

struct Nodo *inserta_inicio(struct Nodo *primer_nodo, int dato)
{
	struct Nodo *nuevo_nodo = crea_nodo(dato,primer_nodo);
	primer_nodo = nuevo_nodo;
	numera_nodos(primer_nodo);
	return primer_nodo;
}

int esta_vacia(struct Nodo *primer_nodo)
{
	return (primer_nodo == NULL);
}

struct Nodo *borra_inicio(struct Nodo *primer_nodo)
{
	if(esta_vacia(primer_nodo))
	{
		printf("\nNo hay elementos para borrar");
		return NULL;
	}
	struct Nodo *aux = primer_nodo;
	primer_nodo = primer_nodo->siguiente_nodo;
	aux->siguiente_nodo=NULL; // borrar la flecha del nodo donde está parado aux
	free(aux);
	numera_nodos(primer_nodo);
	return primer_nodo;
}

struct Nodo *inserta_final(struct Nodo *primer_nodo, int dato)
{
	if(esta_vacia(primer_nodo))
		return inserta_inicio(primer_nodo, dato);
	// Creamos el nodo nuevo
	struct Nodo *nuevo_nodo = crea_nodo(dato, NULL);
	// Creamos un auxiliar para que recorra la lista hasta el final
	struct Nodo *aux = primer_nodo;
	while(aux->siguiente_nodo != NULL)
		aux = aux->siguiente_nodo;
	aux->siguiente_nodo = nuevo_nodo; // pone una flecha desde aux hasta nuevo_nodo
	numera_nodos(primer_nodo);
	return primer_nodo;
}

struct Nodo *borra_final(struct Nodo *primer_nodo)
{
	if(esta_vacia(primer_nodo))
	{
		printf("\nLa lista está vacía y no se puede borrar nada ");
		return NULL;
	}
	// Si solo hay un nodo
	if(primer_nodo->siguiente_nodo == NULL)
		return borra_inicio(primer_nodo);
	struct Nodo *aux1 = primer_nodo;
	struct Nodo *aux2 = primer_nodo->siguiente_nodo;
	while(aux2->siguiente_nodo != NULL)
	{
		aux1=aux1->siguiente_nodo;
		aux2=aux2->siguiente_nodo;
	}
	aux1->siguiente_nodo=NULL;
	free(aux2);
	numera_nodos(primer_nodo);
	return primer_nodo;
}

struct Nodo *inserta_lugar_n(struct Nodo *primer_nodo, int posicion, int dato)
{
	if(posicion < 1 || posicion > numero_nodos + 1)
	{
		printf("\nPosicion fuera de rango");
		return primer_nodo;
	}
	if(posicion == 1)
	{
		printf("\nInsertando al inicio");
		return inserta_inicio(primer_nodo, dato);
	}
	if(posicion == numero_nodos + 1)
		return inserta_final(primer_nodo, dato);
	if(posicion > 1 && posicion <= numero_nodos)
	{
		// Ponemos un aux1 en posicion-1, y aux2 en posicion
		int n = 1;
		struct Nodo *aux1 = primer_nodo;
		struct Nodo *aux2 = aux1->siguiente_nodo;
		while(n < posicion - 1)
		{
			n++;
			aux1 = aux1->siguiente_nodo;
			aux2 = aux2->siguiente_nodo;
		}
		struct Nodo *nuevo_nodo =  crea_nodo(dato, aux2);
		aux1->siguiente_nodo=nuevo_nodo;
		numera_nodos(primer_nodo);
		return primer_nodo;
	}
}

struct Nodo *borra_lugar_n(struct Nodo *primer_nodo, int posicion)
{
	if(posicion < 1 || posicion > numero_nodos)
	{
		printf("\nPosicion fuera de rango ");
		return primer_nodo;
	}
	if(posicion == 1)
		return borra_inicio(primer_nodo);
	if(posicion == numero_nodos)
		return borra_final(primer_nodo);
	if(posicion > 1 && posicion < numero_nodos)
	{
		// Posicionamos aux1 en posicion-1, y aux2 en posicion
		int n = 1;
		struct Nodo *aux1 = primer_nodo;
		struct Nodo *aux2 = primer_nodo->siguiente_nodo;
		while(n < posicion-1)
		{
			n++;
			aux1 = aux1->siguiente_nodo;
			aux2 = aux2->siguiente_nodo;
		}
		aux1->siguiente_nodo=aux2->siguiente_nodo;
		free(aux2);
		numera_nodos(primer_nodo);
		return primer_nodo;
	}
}

void imprime_lista(struct Nodo *primer_nodo)
{
	// Si está vacia no se imprime nada
	if(esta_vacia(primer_nodo))
	{
		printf("\nNo hay elementos para imprimir");
		return;
	}
	/*
	primer_nodo inicialmente está posicionado sobre el primer nodo
	de la lista. Dentro del while lo que hacen las dos instrucciones 
	es: 1. imprime dato del nodo actual
	    2. avanza al siguiente nodo
	*/
	printf("\nElementos de la lista ligada\n");
	while(primer_nodo != NULL){
		printf("%d) %d ",primer_nodo->num_nodo,primer_nodo->dato);  // imprime dato
		primer_nodo = primer_nodo->siguiente_nodo;  // avanza al siguiente
	}
}

void buscar_numero(struct Nodo *primer_nodo, int numeroBuscado)
{
	if(esta_vacia(primer_nodo))
	{
		printf("\nNo hay elementos para imprimir");
		return;
	}
	struct Nodo *aux = primer_nodo;
	int bandera=0;
	while(aux != NULL && !bandera)
	{
	    if (aux->dato == numeroBuscado) 
		{
	        bandera = 1;
	    } else 
		{
	        aux=aux->siguiente_nodo;
	    }
	}
	if(bandera)
	{
	    printf("\nNumero %d esta en la posicion %d", numeroBuscado, aux->num_nodo);
	}
	else
	{
	    printf("\nEl numero %d no encuentra en la lista", numeroBuscado);
	}
}

struct Nodo *inserta_numero_despues(struct Nodo *primer_nodo, int numeroBuscado, int dato)
{
	if(esta_vacia(primer_nodo))
	{
		printf("\nNo hay elementos para insertar");
		return;
	}
	struct Nodo *aux = primer_nodo;
	struct Nodo *aux2 = primer_nodo->siguiente_nodo;
	int bandera=0;
	while(aux != NULL && !bandera)
	{
	    if (aux->dato == numeroBuscado) 
		{
			printf("\nNumero actual es: %d esta en la posicion %d", aux->dato, aux->num_nodo);
			printf("\nSiguiente numero es %d esta en la posicion %d", aux2->dato, aux2->num_nodo);
			bandera=1;
	        struct Nodo *nuevo_nodo =  crea_nodo(dato, aux2);
			aux->siguiente_nodo=nuevo_nodo;
			numera_nodos(primer_nodo);
			return primer_nodo;
	    }
		else 
		{
	        aux = aux->siguiente_nodo;
	        aux2 = aux->siguiente_nodo;
	    }		 
	}
}

void posicionar_nodo(struct Nodo *primer_nodo, int posicion)
{
	if(esta_vacia(primer_nodo))
	{
		printf("\nNo hay elementos para imprimir");
		return;
	}
	struct Nodo *aux = primer_nodo;
	int i;
	while(aux != NULL)
	{
		for(i = 1; i < numero_nodos; i++)
		{
			if(i == posicion)
			{
				printf("\nNumero actual es: %d esta en la posicion %d", aux->dato, aux->num_nodo);
				return;
			}
			else
			{
				aux = aux->siguiente_nodo;
			}
		}
	}
}

void reescribe_nodo(struct Nodo *primer_nodo, int datoViejo, int dato_nuevo)
{
	if(esta_vacia(primer_nodo))
	{
		printf("\nNo hay elementos para imprimir");
		return;
	}
	struct Nodo *aux = primer_nodo;
	int bandera=0;
	while(aux != NULL)
	{
		if(aux->dato == datoViejo)
		{
			bandera=1;
			aux->dato=dato_nuevo;
			printf("\nNumero actualizado es: %d en la posicion %d", aux->dato, aux->num_nodo);
		}
		aux = aux->siguiente_nodo;
	}
	if(bandera == 0)
	{
		printf("\nDato no econtrado");
	}
}

void ordenar_nodos(struct Nodo *primer_nodo)
{
	if(esta_vacia(primer_nodo))
	{
		printf("\nNo hay elementos para ordenar");
		return;
	}
	struct Nodo *aux = primer_nodo, *aux2;
	int intercambia;
	while(aux != NULL)
	{
		aux2 = aux->siguiente_nodo;
		while(aux2 != NULL)
		{
			if(aux->dato > aux2->dato)
			{
				intercambia = aux2->dato;
				aux2->dato = aux->dato;
				aux->dato = intercambia;
			}
			aux2 = aux2->siguiente_nodo;
		}
		aux= aux->siguiente_nodo;
	}
}

struct Nodo *en_orden(struct Nodo *primer_nodo, int dato)
{
	if(esta_vacia(primer_nodo))
		return inserta_inicio(primer_nodo, dato);
	ordenar_nodos(primer_nodo);
	struct Nodo *aux1 = primer_nodo;
	int i = 1;
    while(aux1 != NULL && dato >= aux1->dato) 
	{
		if (aux1->dato == dato) 
		{
			printf("\nElemento %d duplicado en la lista", dato);
			return primer_nodo;
	    }
	    i++;
	    aux1 = aux1->siguiente_nodo;
    }
    return inserta_lugar_n(primer_nodo, i, dato);
}

struct Nodo *borrar_en_orden(struct Nodo *primer_nodo, int dato_a_borrar)
{    
    if(esta_vacia(primer_nodo))
	{
		printf("\nNo hay elementos para ordenar");
		return primer_nodo;
	} 
	ordenar_nodos(primer_nodo);
  	struct Nodo *aux1 = primer_nodo;
	struct Nodo *aux2;
	int bandera=0;
    while(aux1 != NULL) 
	{
		if (primer_nodo->dato == dato_a_borrar) 
		{
			aux2 = primer_nodo;
			primer_nodo=primer_nodo->siguiente_nodo;
			aux1 = aux1->siguiente_nodo;
			aux2 = NULL;
			bandera = 1;
	    }
		else 
		{
			if(aux1->siguiente_nodo != NULL && aux1->siguiente_nodo->dato == dato_a_borrar)
			{
				aux2 = aux1->siguiente_nodo;
				aux1->siguiente_nodo = aux1->siguiente_nodo->siguiente_nodo;
				aux2 = NULL;
				bandera = 1;
			}else
			{
				aux1 = aux1->siguiente_nodo;
			}
	    }
    }
    if(bandera != 0)
    {
    	printf("\nEl numero: %d fue borrado exitosamente", dato_a_borrar);
	}
	else
	{
		printf("\nEl numero: %d no fue encontrado en la lista", dato_a_borrar);
	}
    return primer_nodo;
}

struct Nodo *volteaLista(struct Nodo *primer_nodo)
{
	struct Nodo *lista2 = primer_nodo;
	struct Nodo *primer_nodo2 = NULL;
	struct Nodo *nodo_siguiente = NULL;
	
	while (lista2 != NULL) 
	{
		nodo_siguiente = lista2->siguiente_nodo;
		lista2->siguiente_nodo = primer_nodo2;
		primer_nodo2 = lista2;
		lista2 = nodo_siguiente;
	}
	return primer_nodo2;
}

void eliminaRepetidos(struct Nodo *primer_nodo)
{
	if(esta_vacia(primer_nodo))
	{
		printf("\nNo hay elementos para ordenar");
		return;
	}
    struct Nodo *aux;
	while(primer_nodo != NULL && primer_nodo->siguiente_nodo != NULL)
	{
		if(primer_nodo->dato == primer_nodo->siguiente_nodo->dato)
		{ 
            aux = primer_nodo->siguiente_nodo; 
            primer_nodo->siguiente_nodo = primer_nodo->siguiente_nodo->siguiente_nodo; 
            aux = NULL; 
        }
        else 
            primer_nodo = primer_nodo->siguiente_nodo; 
	}
}

void getMitad(struct Nodo *primer_nodo) 
{
    if(esta_vacia(primer_nodo))
        printf("\nLa lista no tiene nodos que imprimir");
    else{
        int mitad;
        mitad = numero_nodos/2;
        struct Nodo *aux = primer_nodo;
        while(aux != NULL) 
        {
            if(aux->dato == mitad) 
            {
                if(mitad%2 == 0)
                    printf("\nNodo: ", aux->siguiente_nodo->dato);
                else
                    printf(" ", aux->dato);
            } 
            aux = aux->siguiente_nodo;
        }
    }
}

int cuenta_voales(char *cadena)
{
	int vocales = 0, i;
	for (i= 0; cadena[i] != '\0'; i++)
	{
		char letraActual = tolower(cadena[i]);
		if(letraActual == 'a' || letraActual == 'e' || letraActual == 'i' || letraActual == 'o' || letraActual == 'u')
		{
			vocales++;
		}
	}
	return vocales;
}

/*void *get_sbs(char *cadena, int m, int n)
{
	char *sbs;
	int i, total, contador=0;
	total = n-m;
	sbs = (char *)malloc(sizeof(char ));
	while(*cadena != '\0')
	{
		contador++;
		if(contador == m)
		{
			for(i = 1; i <= n; i++)
			{
				*sbs = sbs[i] + cadena[i];
			}
			//strcpy(sbs, cadena);
		}
	}
	for(i = 1; i <= n; i++ )
	{
		printf("%s", sbs[m]);
	}
	//return sbs;
}*/

int gv(int y)
{
	int x = 200;
	x += y;
	return x;
}

int main()
{
	/*char cadena[] = "hola a todo mundo";
	char cadenanueva;
	printf("\nCadena actual %s", cadena);
	get_sbs(cadena, 4, 8);*/
	
	int p, y = 10;
	printf("\n%d", y);
	p = gv(y);
	printf("\n%d", &p);
	exit(0);
	
	//printf("\nCadena nueva %s", cadenanueva);
	//struct Nodo *primer_nodo = NULL;
	/*
	primer_nodo = inserta_inicio(primer_nodo, 1);
	primer_nodo = inserta_final(primer_nodo, 1);
	primer_nodo = inserta_final(primer_nodo, 2);
	primer_nodo = inserta_final(primer_nodo, 2);
	primer_nodo = inserta_final(primer_nodo, 2);
	primer_nodo = inserta_final(primer_nodo, 2);
	primer_nodo = inserta_final(primer_nodo, 2);
	primer_nodo = inserta_final(primer_nodo, 56);
	primer_nodo = inserta_final(primer_nodo, 76);
	primer_nodo = inserta_final(primer_nodo, 76);
	primer_nodo = inserta_final(primer_nodo, 110);
	primer_nodo = inserta_final(primer_nodo, 120);
	primer_nodo = inserta_final(primer_nodo, 120);
	primer_nodo = inserta_final(primer_nodo, 900);
	primer_nodo = inserta_final(primer_nodo, 1010);
	
	numera_nodos(primer_nodo);
	ordenar_nodos(primer_nodo);
	imprime_lista(primer_nodo);
	
	eliminaRepetidos(primer_nodo);
	numera_nodos(primer_nodo);
	imprime_lista(primer_nodo);
	*/
	//primer_nodo = volteaLista(primer_nodo);
	//numera_nodos(primer_nodo);
	//imprime_lista(primer_nodo);
	/*
	primer_nodo = borrar_en_orden(primer_nodo, 65);
	imprime_lista(primer_nodo);
	*/
	
	//ordenar_nodos(primer_nodo);
	/*
	primer_nodo = en_orden(primer_nodo, 25);
	primer_nodo = en_orden(primer_nodo, 98);
	primer_nodo = en_orden(primer_nodo, 1);
	primer_nodo = en_orden(primer_nodo, 8);
	primer_nodo = en_orden(primer_nodo, 2);
	primer_nodo = en_orden(primer_nodo, 150);
	primer_nodo = en_orden(primer_nodo, 36);
	primer_nodo = en_orden(primer_nodo, 74);
	primer_nodo = en_orden(primer_nodo, 50);
	
	numera_nodos(primer_nodo);
	imprime_lista(primer_nodo);
	
	primer_nodo = en_orden(primer_nodo, 75);
	numera_nodos(primer_nodo);
	imprime_lista(primer_nodo);
	*/
	/*
	printf("\nBusca Nodo");
	buscar_numero(primer_nodo, 56);
	printf("\nInserta Nodo");
	inserta_numero_despues(primer_nodo, 56, 37);
	imprime_lista(primer_nodo);
	
	printf("\nPosicionar Nodo");
	posicionar_nodo(primer_nodo, 4);
	printf("\nReescribe Nodo");
	reescribe_nodo(primer_nodo, 76, 20);
	imprime_lista(primer_nodo);
	*/
	/*
	primer_nodo = borra_inicio(primer_nodo);
	printf("\nHay %d nodos ",numero_nodos);
	
	imprime_lista(primer_nodo);
	primer_nodo = inserta_lugar_n(primer_nodo, 3, 450);
	imprime_lista(primer_nodo);
	
	primer_nodo = borra_lugar_n(primer_nodo, 3);
	imprime_lista(primer_nodo);
	*/
}
