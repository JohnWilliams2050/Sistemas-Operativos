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
#include "moduloMat.h"
/*Imprime las matrizes
*@param:matriz de enteros, S (int) El tamaño de las matrices 
*@return: nada
*/
void impriMatriz(int *matriz, int S){
        printf("****************************\n");
        for(int i=0;i<S;i++){
                for(int j=0;j<S;j++){
                        printf("%d ", matriz[i*S+j]);
                }
        printf("\n");
        }
        printf("\n****************************\n");
}
/*Inicializa las matrices
*@param: matriz1 de enteros, matriz2 de enteros, S (int) el tamaño de las matrices
*return: nada
*/
void iniMatriz(int *m1,int *m2, int S){
        for(int i=0; i<S*S;i++){
                m1[i] = i;
                m2[i] = 3*i;
        }
}
/*Multiplica las dos matrices y las guarda en una tercera matriz
*@param: matrizA de enteros, matrizB de enteros, matrizC de enteros, S (int) el tamaño de las matrices
*@return: nada
*/
void multMatriz(int *a,int *b, int *c, int S){
        for(int i=0;i<S;i++){
                for(int j=0; j<S;j++){
                        int Suma = 0;
                        int *pA, *pB;
                        pA= a + i;
                        pB = b + j;
                        for(int k=0; k<S;k++,pA++,pB+=S){
                                Suma +=(*pA * *pB);
                        }
                        c[i*S+j] = Suma;
                }
        }
}

