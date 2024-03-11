pid_t pid;
pthread_t tid;

pid = fork();
if (pid == 0) {
    fork();
    pthread_create(&tid, NULL, thread_function, NULL);
    sleep(1);
} else if (pid > 0) {
    fork();
} else {
    fprintf(stderr, "Error");
    return 1;
}