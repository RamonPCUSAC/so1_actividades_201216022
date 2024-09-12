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

    pid = fork(); 
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
