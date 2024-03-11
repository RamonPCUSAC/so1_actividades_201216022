# Respuestas y Razonamiento

## a) ¿Cuántos procesos únicos son creados?

En el código proporcionado, se utilizan llamadas al sistema `fork()` para crear procesos. Además, se crea un hilo en uno de los procesos hijos. Aquí está el análisis paso a paso:

1. Se inicia con un proceso padre.
2. El proceso padre llama a `fork()`, creando un proceso hijo (Child 1).
3. Dentro de Child 1, se llama a `fork()` nuevamente, creando otro proceso hijo (Child 2).
4. Dentro de Child 1, se crea un hilo utilizando `pthread_create()`.
5. Regresando al proceso padre, se llama a `fork()` nuevamente, creando dos procesos hijos más (Child 3 y Child 4).

Entonces, en total, hay 6 procesos únicos creados:
- El proceso padre original.
- Los dos hijos del proceso padre (Child 1 y Child 3).
- Los tres hijos del primer proceso hijo (Child 2, el proceso hijo que tiene un hilo y otro proceso hijo que se crea dentro de él).

## b) ¿Cuántos hilos únicos son creados?

Solo se crea un hilo único en el proceso hijo inicial (Child 1). Este hilo se crea utilizando `pthread_create()` dentro de Child 1. Por lo tanto, hay un único hilo creado en total.

