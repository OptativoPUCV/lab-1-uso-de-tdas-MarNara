#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for(int k = 1; k <= 10; k++){
      int* valorDeK = (int*)malloc(sizeof(int));
      if(valorDeK == NULL) EXIT_FAILURE;
      *valorDeK = k; //este valor esta apuntando a k
      pushBack(L, valorDeK);
      
   }
   /**/
   
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;
   int tamanoLista = get_size(L);
   int* elemento = first(L);
   for(int k = 0; k < tamanoLista; k++){
      suma += *elemento;// era nesesario desreferenciar :)
      elemento = next(L);

   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int tamanoLista = get_size(L);
   int *elemento = first(L);
   for(int k = 0; k < tamanoLista; k++){
      if(*elemento == elem){
         popCurrent(L);
      }
      elemento = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack*P1, Stack* P2) {
   Stack *auxPila = create_stack();
   while(top(P1) != NULL){
      void *elem = top(P1);// devuelve un puntero
      push(auxPila, elem);// me falta un dato
      pop(P1);
   }
   

   while(top(auxPila) != NULL){
      void *elem = top(auxPila);// devuelve un puntero
      push(P2, elem);// me falta un dato
      push(P1, elem);
      pop(auxPila);
   }


}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   /*pasos: primero debo crear una pila1 que
   guarde la mitad de los elementos (se que llega a 
   la mitad con un contador de elementos) y una pila2 
   crear una pila auxiliar y ahi dar vuelta una de las pilas*/
   
   //int largoCadena = strlen(cadena);
   int cont = 0; 
   while(cadena[cont] != '\0'){
      cont++;
   }

   if(cont % 2 == 1){
      return 0;
   }
   Stack *auxPila = create_stack();
   Stack *P1 = create_stack();
   Stack *P2 = create_stack();

   int mitad = cont/2;
   //agregar datos a pila 1.
   for(int k = 0; k < mitad; k++){
      char *carac = &cadena[k];//sacar el caracter
      push(P1, carac);// agregar el caracter
   }
   
   int contadorPila2 = 0;
   //agregar datos a una pila vacia auxiliar.
   for(int k = 0; k < cont; k++){
      char *carac = &cadena[k];//sacar el caracter
      push(auxPila, carac);// agregar todos los caracteres
      contadorPila2++;
   }

   int mitadPila2 = contadorPila2 / 2;
   //agregar datos a pila 2.
   for(int k = 0; k < mitadPila2; k++){
      void *elem = top(auxPila);// devuelve un puntero
      push(P2, elem);
      pop(auxPila);
   }

   for(int k = 0; k < mitad; k++){
      char *elem1 = top(P1);
      char *elem2 = top(P2);

      if((*elem1 == '(' && *elem2 == ')') || (*elem1 == '{' && *elem2 == '}') || (*elem1 == '[' && *elem2 == ']')){
         return 1;
      }
      pop(P1);
      pop(P2);
      
   }




   return 0;
}

