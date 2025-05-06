# Taller de evaluación de rendimiento


## Objetivos

El objetivo de este taller es comparar las ejecuciones del algoritmo de multiplicación de matrices en serie y en paralelo. Esto se realizó en diferentes sistemas de cómputo para obtener más datos sobre el rendimiento de cada ejecución. Esto nos permite conseguir un valor que está más cerca a la realidad. Los promedios de los datos nos dejan comparar los valores para llegar a una conclusión y poder dar recomendaciones sobre las diferentes formas de ejecutar un algoritmo.

## Para ejecutarlo 

    1. Descargar la carpeta TallerRendimiento

    2. Entrar al director “TallerRendimiento”

    3. Ejecutar el siguiente codigo: "gcc programas_a_compilar_incluyendo_librerias.c -o nombre_ejecutable"

Para ejecutar el OpenMP se necesita la línea “-fopenmp” al final del comando. También toca asegurarse que los ejecutables se nombren de la forma que se encuentra en el archivo “lanza.pl” siendo estos los siguientes:

- Fork: MMFork
- Posix: MMPosix
- OpenMP: MMOpenMP

Ya con los ejecutables, se ejecuta el programa “lanza.pl”. Este programa se encarga de generar las ejecuciones y guardar los datos resultantes en sus propias carpetas.


# Integrantes 
- Juan Pabon Vargas 
- Juan Felipe Rodriguez Amador 
- Arley Bernal 
- Tomas Alejandro Silva Correal
- Sergio Pardo Hurtado

