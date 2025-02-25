/******************************************************************************
*Autor:Juan Pabon Vargas
*Fecha: Febrero 24, 2025
*Título: Taller Compilación Modular. Se junto el programa de las matrices con 
*el programa de los vectores y se hizo un menú que deja el usuario escoger que 
*quiere hacer. Se hizo un módulo para las funciones de matrices y otro módulo 
*para las funciones del vector.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "moduloMat.h"
#include "moduloVec.h"


#define CAPACIDAD_INICIAL 4

int main(int argc, char *argv[]){
    
        if(argc < 2){
            printf("Error argumentos entradas:\n");
            printf("    $./ejecutable N\n");
            exit(0);
        }
        int num;
        printf("Con que quieres jugar?\n*******************\n1. Vectores\n2. Matrizes\n3. Salir\n*******************\n");
        scanf("%d", &num);
        while(num>3)
        {
            printf("Lo siento, ese numero no es valido. Intente de nuevo.\n");
            printf("Con que quieres jugar?\n*******************\n1. Vectores\n2. Matrizes\n3. Salir\n*******************\n");
            scanf("%d", &num);
        }
        while(num!=3)
        {
            if(num==1)
            {
                vectorDinamico editor;
                //Se inicializa ‘editor’ de tipo vectorDinamico
                vectorInicio(&editor);
                //Se le agregan los elementos al vector de elementos en el vectorDinamico
                addVector(&editor, "Hola");
                addVector(&editor, "Profesional");
                //Se imprimen los elementos en el vector
                for (int i = 0; i < totalVector(&editor); i++)
                printf("%s", (char *) getVector(&editor, i));
                //Se borra el elemento en el índice 1
                borrarVector(&editor, 1);
                
                //Se intenta agregar un nuevo elemento al vector pero no va poder porque el índice no cumple
                //con los requisitos para agregar el elemento al vector
                setVector(&editor, 1, "Buenos");
                
                //Imprime los elementos en el vector. Como el total del vector es 1, solo imprime el elemento 0 del vector
                for (int i = 0; i < totalVector(&editor); i++)
                printf("%s \n", (char *) getVector(&editor, i));
            }
            else if(num==2)
            {
        
                /*Se toma el valor de entrado tamano de matriz*/
                int N = (int) atoi(argv[1]);
                printf("Valor ingresado %d \n", N);
                /*reserva de memoria para matrices*/
                int *mA = (int *) malloc(N*N*sizeof(int));
                int *mB = (int *) malloc(N*N*sizeof(int));
                int *mC = (int *) malloc(N*N*sizeof(int));
        
        
                /*Se inicializan las matrizes*/
                iniMatriz(mA,mB,N);
                /*Se imprimen las matrizes*/
                multMatriz(mA,mB,mC,N);
                impriMatriz(mA,N);
                impriMatriz(mB,N);
                impriMatriz(mC,N);
                /*Se libera la memoria*/
                free(mA);
                free(mB);
                free(mC);
            }
            else
            {
                break;
            }
            printf("Con que quieres jugar?\n*******************\n1. Vectores\n2. Matrizes\n3. Salir\n*******************\n");
            scanf("%d", &num);
            while(num>3)
            {
                printf("Lo siento, ese numero no es valido. Intente de nuevo.\n");
                printf("Con que quieres jugar?\n*******************\n1. Vectores\n2. Matrizes\n3. Salir\n*******************\n");
                scanf("%d", &num);
            }
        }
}

