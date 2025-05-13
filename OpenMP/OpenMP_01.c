/*
* Autor: Juan Pabon Vargas
* Fecha 13 Mayo 2025
* Tema: Programacion Paralela- Introduccion OpenMP
*------------------------------------------------
* Resumen: Programa crea hilos de ejecucion para cada core
* Imprime cadena de caracteres por cada llamada.
*/

#include <omp.h> //-----------Header necesario para invocar API OpenMP
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	printf("OpenMP ejecutando con %d hilos\n", omp_get_max_threads());
	#pragma omp parallel
	{//el codigo ba se ejecutado por todos los hilos
		printf("Hello World desde el thread %d\n", omp_get_thread_num());
	}
	return 0;
}
