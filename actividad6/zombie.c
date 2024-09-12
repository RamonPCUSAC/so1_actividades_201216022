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