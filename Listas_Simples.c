//Carlos Bertin Cano Dominguez
//Ingenieria en Computacion
//Universidad Autónoma del Estado de México
//Listas Simples

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct nodo{		
	int dato;
	struct nodo* sig;
}Nodo;

Nodo *insertarFinal(Nodo *lista){ //Ingresa un nodo nuevo al final de la lista o crea una nueva lista en caso de no haber una
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo)); //Declaramos un nodo nuevo
	int d;
	
	printf("\nIngrese dato: "); 
	scanf("%d",&d);
	nuevo->dato=d;
	nuevo->sig=NULL;
	
	if(lista==NULL){ //Si la lista esta vacia se crea un nodo con el dato ingresado y este nodo sera la nueva lista
		lista=nuevo;
		printf("\nLista creada!");
	}
	
	else{          //Si no esta vacia se llega hata su ultimo nodo y se agrega el nodo nuevo como siguiente
		Nodo *aux=lista;  //Creamos un nodo auxiliar 
		
		while(aux->sig!=NULL){ //Iteramos en la lista hasta llegar al ultimo nodo
			aux=aux->sig;
		}
		
	
		aux->sig=nuevo;		//Una ves alcanzado el ultimo nodo se agrega el nodo nuevo al final de la lista
	}
	return lista;
}

Nodo *insertarInicio(Nodo *lista){	//Ingresa un nodo al inicio de la lista , si la lista esta vacia crea una nueva
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo)); //Declaramos un nodo nuevo
	int d;
	
	printf("\nIngrese dato: ");
	scanf("%d",&d);
	nuevo->dato=d;
	
	if(lista==NULL){ //Si la lista esta vacia se crea un nodo con el dato ingresado y este nodo sera la nueva lista
		lista=nuevo;
		lista->sig=NULL;
		printf("\nLista creada!");
	}
	
	else{           //El nodo nuevo apunta hacia la lista , luego se iguala la lista a nuevo , queando nodo nuevo como el primer elemento
		nuevo->sig=lista;
		lista=nuevo;
	}
	
	return lista;
}

void imprimir(Nodo *lista){		//Imprime los valores de los nodos de la lista
	
	if(lista==NULL){		//Si esta vacia , mandamos mensaje de error
		printf("\nERROR , Lista vacia");
		return;
	}
	
	else{            		//Si no esta vacia iteramos sobre la lista imprimiendo el dato contenido en cada iteracion
			Nodo *aux=(Nodo*)malloc(sizeof(Nodo));
			aux=lista;
			int contador=1;		//Agregamos un contador para saber el numero de nodo
		
			while(aux!=NULL){  
				printf("\nNodo : %d , Contenido : %d",contador,aux->dato);
				aux=aux->sig;
				contador++;
			}
		
		printf("\n");
		
		return;
	}
}

Nodo *insertarAleatorioFinal(Nodo *lista){		//Ingresa un nodo con un numero aleatorio al final de la lista
	int n,i;
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));	//Creamos el nodo nuevo y con la funcion rand agregamos un valor aleatorio de 1 a 100 al campo dato del nodo nuevo
	nuevo->dato=rand()%100+1;
	nuevo->sig=NULL;

	
	if(lista==NULL){							//Si la lista esta vacia , la lista sera el nodo nuevo	
		lista=nuevo;
	}
	
	else{										//Si la lista no esta vacia iteramos hasta el ultimo nodo y agregamos el nodo nuevo al final
		Nodo *aux=lista;
			while(aux->sig!=NULL){
			aux=aux->sig;
			}
		
		aux->sig=nuevo;

	}
	
	return lista;

}

Nodo *insertarAleatorioInicio(Nodo *lista){	//inserta un nodo con un valor aleatorio al inicio de la lista
	int n,i;									
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));	//Creamos el nodo nuevo
	nuevo->dato=rand()%100+1;					//Asignamos unvalor aleatorio hasta 100 al nodo nuevo
	
	
	if(lista==NULL){						//Si la lista esta vacia mandamos mensaje de error
		nuevo->sig=NULL;
		lista=nuevo;
	}
	
	else{							//Si la lista no esta vacia , asiganamos la lista como el puntero siguiente del nodo nuevo
									//Y despues la lista se iguala al nodo nuevo, haciendo que el nodo neuvo quede como primer elemento
		nuevo->sig=lista;
		lista=nuevo;
	}
	
	return lista;
	
}

Nodo *invertir(Nodo *lista){			//Invierte la lista , el ultimo nodo es el primer y viceversa
	Nodo *actual=lista;					//Creamos tres punteros
	Nodo *anterior=NULL;
	Nodo *siguiente=(Nodo*)malloc(sizeof(Nodo));
	
	
	while(siguiente->sig!=NULL){			//En cada iteracion el puntero siguiente puntara al nodo anterior
											//En el primer caso el puntero siguiente del primer elemento apuntara a NULL
		siguiente=actual->sig;
		actual->sig=anterior;
		anterior=actual;
		actual=siguiente;
	}
	
	
	actual->sig=anterior;				//El ultimo nodo de la lista quedara como cabeza
	lista=actual;
	
	return lista;
	
	
}

Nodo *eliminarInicio(Nodo *lista){		//Hacemos que la lista sea su elemento siguiente , dejando el primer nodo olvidado
	
	if(lista==NULL){
		printf("\nError lista vacia");
	}
	
	else{
	lista=lista->sig;
	}
	
	return lista;
}

Nodo *eliminarFinal(Nodo *lista){		//Llegamos hasta el penultimo nodo y hacemos que su siguiente sea NULL dejando olvidado el ultimo nodo
	
	if(lista==NULL){
		printf("\nError lista vacia");
	}
	
	
	else{
	
		Nodo *aux=lista;
	
		while(aux->sig->sig!=NULL){
			aux=aux->sig;
		}
	
		aux->sig=NULL;
	
	}
	
	return lista;
}

int buscarBool(Nodo *lista,int n){  //devuelve 1 si encontro el nodo deseado , devuelve 0 si no lo encontro
	
	if(lista==NULL){
		printf("\nLista vacia , ningun nodo encontrado");
		return 0;
	}
	
	else{
		Nodo *aux=lista;
		int c=0;
		
		while(aux->sig!=NULL){	//Iteramos sobre la lista si encuentra el nodo retorna 1 
			c++;				//En cada iteracion aumenta el contador
			if(aux->dato==n){
			
				return 1;
			}
			
			aux=aux->sig;
		}//FIN while 
		
		
		return 0;
		
	
	}//fin else
	
}

void buscar(Nodo *lista,int n){  //Imprime en pantalla si encontro el dato deseado
	
	if(lista==NULL){
		printf("\nLista vacia , ningun nodo encontrado");
		return;
	}
	
	else{
		Nodo *aux=lista;
		int c=0;
		
		while(aux!=NULL){	//Iteramos sobre la lista si encuentra el nodo retorna 1 
			c++;				//En cada iteracion aumenta el contador
			if(aux->dato==n){
				printf("\nNodo encontrado en el nodo numero: %d",c);
				
			}
			
			aux=aux->sig;
		}//FIN while 
		
		printf("\nNodo no encontrado");
	
		
	
	}//fin else
	
}



int main(){
	Nodo *lista1=NULL;
	int opcion,n,i,dato1,b;

	do{
	

		printf("\n\n.-.-.-.-.-.-.-.- M E N U .-.-.-.-.-.-.-.-.-");
		printf("\n 1)Insertar Al Inicio\n 2)Insertar Al Final\n 3)Ingresar Numeros Aleatorios Al Final\n 4)Ingresar Numeros Aleatorios Al Inicio\n 5)Invertir Lista");
		printf("\n 6)Eliminar Nodo Del inicio\n 7)Eliminar Ultimo Nodo\n 8)Imprimir\n 9)Buscar (VOID)\n10)Buscar (BOOL)\n");
		
			printf("\nIngrese Opcion: ");
			scanf("%d",&opcion);
		
			while(opcion>20||opcion<1){		//pedimos ingresar opcion hasta que se ingrese una opcion valida (numero entre 1 y 20)
											//No se aceptan letras ni simbolos raros e.e
			opcion = (int)opcion;
			fflush(stdin);
			printf("\nIngrese Opcion: ");
			scanf("%d",&opcion);
			}
		
		
		
		switch(opcion){
			case 1: 
				lista1=insertarInicio(lista1);
				printf("\nExito ingresando nodo al inicio");
				break;
				
			case 2:
				lista1=insertarFinal(lista1);
				printf("\nExito ingresando nodo al final");
				break;
				
			case 3:
				lista1=insertarAleatorioFinal(lista1);
				printf("\nCuantos numeros desea agregar?: ");
				scanf("%d",&n);
				
					for(i=0;i<n-1;i++){
						lista1=insertarAleatorioFinal(lista1);
					}
				printf("\nExito ingresando nodos aleatorios al final");
				break;
			
			case 4: 
				lista1=insertarAleatorioInicio(lista1);
				printf("\nCuantos numeros desea agregar?: ");
				scanf("%d",&n);
				
					for(i=0;i<n-1;i++){
						lista1=insertarAleatorioInicio(lista1);
					}
				printf("\nExito ingresando nodos aleatorios al inicio");
				break;
				
				
			case 5:
				lista1=invertir(lista1);
				printf("\nExito invirtiendo lista!");
				break;
				
			case 6:
				lista1=eliminarInicio(lista1);
				printf("\nExito eliminando primer nodo!");
				break;
				
			case 7:
				lista1=eliminarFinal(lista1);
				printf("\nExito eliminando ultimo nodo!");
				break;
				
			case 8:
				imprimir(lista1);
				break;
				
			case 9:
				printf("\nIngrese dato a buscar: ");
				fflush(stdin);
				scanf("%d",&dato1);
				buscar(lista1,dato1);
				break;
				
			case 10:
				printf("\nIngrese dato a buscar: ");
				fflush(stdin);
				scanf("%d",&dato1);
				if(buscarBool(lista1,dato1)){
					printf("\nNodo encontrado");
				}
				
				else{
					printf("Nodo no encontrado");
				}
				break;
				
			default:
				printf("Opcion no encontrada, por favor ingrese otra vez numero de opcion deseada");
		}
		
		
	
		
	}while(opcion!=11);
return 0;
}
