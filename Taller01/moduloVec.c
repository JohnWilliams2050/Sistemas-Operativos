/******************************************************************************
*Autor:Juan Pabon Vargas
*Fecha: Febrero 24, 2025
*Título: Taller Compilación Modular. Se junto el programa de las matrices con 
*el programa de los vectores y se hizo un menú que deja el usuario escoger que 
*quiere hacer. Se hizo un módulo para las funciones de matrices y otro módulo 
*para las funciones del vector.
*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "moduloVec.h"
#define CAPACIDAD_INICIAL 4

/*Inicializa el vector asignando memoria
*@param: Un elemento de tipo vectorDinamico
*@return: nada
*/
void vectorInicio(vectorDinamico *V){
        V->capacidad = CAPACIDAD_INICIAL;
        V->totalElementos = 0;
        V->elementos = malloc(sizeof(void *) * V->capacidad);
}
/*Da el número total de Elementos del vector
*@params: Un elemento de tipo vectorDinamico
*return: totalElementos (int)
*/
int totalVector(vectorDinamico *V){
        return V->totalElementos;
}
/*Redefine el tamaño del vector y mira si elementos ya no es nulo para actualizar el el elemento tipo vectorDinamico
*@param: Un elemento de tipo vectorDinamico, capacidad (int)
*@return: nada
*/
static void resizeVector(vectorDinamico *V, int capacidad){
        printf("Redimensión: %d a %d \n", V->capacidad, capacidad);

        void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
        if(elementos){
                V->elementos = elementos;
                V->capacidad = capacidad;
        }
}
/*Mira si el vector a llegado a su capacida
*y si ya está en capacidad, cambia el tamaño del
*vector para que sea el doble de la capacidad actual
*y le meta el elemento en el vector
*@param: Un elemento de tipo vectorDinamico, void *elemento
*@return: nada
*/
void addVector(vectorDinamico *V, void  *elemento){
        if(V->capacidad == V->totalElementos)
                resizeVector(V, V->capacidad*2);
        V->elementos[V->totalElementos++] = elemento;
}
/*Libera la memoria del vector 'elementos'
*@param: Un elemento de tipo vectorDinamico
*@return: nada
*/
void freeVector(vectorDinamico *V){
        free(V->elementos);
}
/*Se asegura que el índice está dentro de los límites del vector
*y retorna el elemento en el vector si lo está. Si no está, retorna NULL
*@param: Un elemento de tipo vectorDinamico, int indice
*@return: un elemento, o NULL
*/
void *getVector(vectorDinamico *V, int indice){
        if(indice >= 0 && indice < V->totalElementos)
                return V->elementos[indice];
        return NULL;
}
/*Se asegura que el índice está dentro de los límites del vector.
*Si lo está, asigna un elemento al vector en el indice.
*@param: Un elemento de tipo vectorDinamico, indice (int), void *elemento
*@return: nada
*/
void setVector(vectorDinamico *V, int indice, void *elemento){
        if(indice >= 0 && indice < V->totalElementos)
                V->elementos[indice]=elemento;
}
/*Borra un elemento del vector dinámico y mueve los elementos hacia la izquierda para que no
*haya espacios entre elementos. Si la cantidad de los elementos es igual a ¼ de la 
*entonces reduce el tamaño del vector
*@param: Un elemento de tipo vectorDinamico, indice (int)
*@return: nada
*/
void borrarVector(vectorDinamico *V, int indice){
        if(indice < 0 || indice >= V->totalElementos)
                return;

        V->elementos[indice] = NULL;

        for(int i=indice; i<V->totalElementos-1; i++){
                V->elementos[i] = V->elementos[i+1];
                V->elementos[i+1] = NULL;
        }
        V->totalElementos--;
        if(V->totalElementos>0 && V->totalElementos == V->capacidad/4)
                resizeVector(V, V->capacidad/2);
}

