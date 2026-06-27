#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex;
void* process(void* arg) {
    int id = *((int*)arg);
    sem_wait(&mutex);
    printf("Process %d is in the critical section\n", id);
    for (int i = 0; i < 1000000; i++);
    sem_post(&mutex); 
    printf("Process %d exited critical section\n", id);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;
    sem_init(&mutex, 0, 1);
    pthread_create(&t1, NULL, process, &id1);
    pthread_create(&t2, NULL, process, &id2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&mutex);
    return 0;
}
