# Actividad 6 - Procesos e Hilos
1. **¿Incluyendo el proceso inicial, cuantos procesos son creados por el siguiente programa?**
    El programa crea un total de 8 procesos, incluyendo el proceso inicial.
    
    1. Proceso inicial (antes de la primera llamada a fork):
       - 1 proceso
    2. Después de la primera llamada a fork:
       - 2 procesos (1 padre + 1 hijo)
    3. Después de la segunda llamada a fork:
       - 4 procesos (2 procesos existentes, cada uno crea 1 nuevo proceso)
    4. Después de la tercera llamada a fork:
       - 8 procesos (4 procesos existentes, cada uno crea 1 nuevo proceso)

Por lo tanto, incluyendo el proceso inicial, el programa crea un total de 8 procesos.

2. **Utilizando un sistema Linux, escriba un programa en C que cree un proceso hijo (fork) 
que finalmente se convierta en un proceso zombie. Este proceso zombie debe 
permanecer en el sistema durante al menos 60 segundos.**

### solución
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Crea un proceso hijo

    if (pid > 0) {
        printf("Proceso padre (PID: %d), hijo (PID: %d) creado.\n", getpid(), pid);
        sleep(60);
        printf("Proceso padre está terminando. Eliminando el proceso zombie...\n");
        wait(NULL);  // Limpia el proceso zombie
    } else if (pid == 0) {
        printf("Proceso hijo (PID: %d) se está terminando.\n", getpid());
        exit(0);
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}
````
3. **Usando el siguiente código como referencia, completar el programa para que sea 
ejecutable y responder las siguientes preguntas:**
    ¿Cuántos procesos únicos son creados?
    6 procesos
    ¿Cuántos hilos únicos son creados?
    1 hilo único

### Código Completo

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Hilo en ejecutándose: TID = %ld\n", pthread_self());
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t thread;

    pid = fork();  // Primera llamada a fork()
    if (pid == -1) {
        perror("Error al crear el proceso");
        exit(1);
    }

    if (pid == 0) { 
        fork();

        if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
            perror("Error");
            exit(1);
        }
        pthread_join(thread, NULL);
    }

    fork();
    sleep(5); 

    return 0;
}
