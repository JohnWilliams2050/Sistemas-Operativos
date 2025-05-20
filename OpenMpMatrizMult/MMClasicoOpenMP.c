/************************************************************************************
 * Fecha: 20 Mayo, 2025
 * Autor: Juan Pabon Vargas
 * Tema: OpenMP
 * Clase: Sitemas Operativos
 * Descripcion: En este programa se va realizar el algoritmo de multiplicacion de
 * matrices usando OpenMP para realizar regiones del programa en paralelo dado la
 * cantidad de hilos con que va usar para realizar las operaciones en paralelo.
 *
 * Conclusiones: En este programa se realizo el algoritmo de multiplicacion de
 * matrices usando OpenMP. OpenMP es una interface que permite el programador
 * realizar regiones de su codigo en paralelo. Esto lo hace por medio de pragmas
 * (directivas al compilador) que le dice que se va hacer en paralelo.
 * Uno puede decirle cuantos hilos vamos a usar, o se pueden usar la maxima cantidad
 * de hilos disponibles que son la cantidad de cores en el procesador.
 * En el caso de este taller, la persona que esta ejecutando este programa le dice
 * la cantidad de hilos que se van a usar, y tambien el tamano de las matrices.
 *
 * Ya en la funcion que se encarga de multiplicar matrices, se le da una directiva
 * al compilador que le dice que la siguiente seccion de codigo se va realizar en
 * paralelo y se va hacer con la cantidad de hilos dado.
 *
 * Inicialmente, la funcion "multiMatrix" inicializa valores afuera del for. Y
 * Se usa el pragma para decirle que se va realizar en paralelo. Y los datos que
 * estan afuera son privados para cada hilo. Se puede eliminar esto y hacer que
 * los datos sean locales para cada hilo en el for, pero es mejor hacerlos privados
 * para que se puedan usar en otras partes del programa.
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>
#include "MMOpenMP.h"


int main(int argc, char *argv[]){
	//Revision de cantidad de elementos
	if(argc < 3){
		printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
		exit(0);
	}

	//Primero el tamaño de la matriz
	int N = atoi(argv[1]);

	/****************************
	* Numero de hilos que nosotros determinamos. Es uno de los parametros de entrada 
	*****************************/
	int TH = atoi(argv[2]);

	//Se inicializan las matrices A, B y C que se usaran para los datos
	size_t *matrixA  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixB  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixC  = (size_t *)calloc(N*N, sizeof(size_t));
	
	if (!matrixA || !matrixB || !matrixC) {
		fprintf(stderr, "Error: No se pudo asignar memoria. Reduce el tamaño de la matriz (N=%d).\n", N);
		free(matrixA); free(matrixB); free(matrixC);
		return EXIT_FAILURE;
	}
	//Rand para el llenado de datos
	srand(time(NULL));

	/****************************
	* Se define el numero de hilos que se van a usar en la regiones paralelas
	*****************************/
	omp_set_num_threads(TH);

	//Inicializa las matrices con su respectivo tamaño
	iniMatrix(matrixA, matrixB, N);
	//Muestra matrices creadas
	impMatrix(matrixA, N);
	impMatrix(matrixB, N);
	//Se hace la instancia del experimento para la multiplicación de matrices
	InicioMuestra();
	multiMatrix(matrixA, matrixB, matrixC, N);
	FinMuestra();
	//Imprime matriz resultado
	impMatrix(matrixC, N);

	/*Liberación de Memoria*/
	free(matrixA);
	free(matrixB);
	free(matrixC);
	
	return 0;
}
