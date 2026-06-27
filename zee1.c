#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
int lock = 0;  // Shared lock variable
int TestAndSet(int *target) {
    int old = *target;
    *target = 1;
    return old;
}
void* process(void* arg) {
int id = *((int*)arg);
while (TestAndSet(&lock) == 1);
printf("Process %d is in the critical section\n", id);
for (int i = 0; i < 1000000; i++);
lock = 0;
printf("Process %d exited critical section\n", id);
return NULL;
}
int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, process, &id1);
    pthread_create(&t2, NULL, process, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
