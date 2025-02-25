/******************************************************************************
*Autor:Juan Pabon Vargas
*Fecha: Febrero 24, 2025
*Título: Taller Compilación Modular. Se junto el programa de las matrices con 
*el programa de los vectores y se hizo un menú que deja el usuario escoger que 
*quiere hacer. Se hizo un módulo para las funciones de matrices y otro módulo 
*para las funciones del vector.
*******************************************************************************/

#ifndef __BIBLIOTECASVEC_H__
#define __BIBLIOTECASVEC_H__

/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

void vectorInicio(vectorDinamico *V);

int totalVector(vectorDinamico *V);

static void resizeVector(vectorDinamico *V, int capacidad);

void addVector(vectorDinamico *V, void *elemento);

void freeVector(vectorDinamico *V);

void *getVector(vectorDinamico *V, int indice);

void setVector(vectorDinamico *V, int indice, void *elemento);

void borrarVector(vectorDinamico *V, int indice);

#endif