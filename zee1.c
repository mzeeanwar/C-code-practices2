#include <stdio.h>
  int lock = 0;
  int TestAndSet(int *target) {
     int oldValue = *target;
     *target = 1;
     return oldValue; 
}
void Process(int id) {
     while (TestAndSet(&lock)){}
     printf("Process %d entered Critical Section\n", id);
     printf("Process %d is executing...\n", id);
     printf("Process %d leaving Critical Section\n\n", id);
      lock = 0;
 }
  int main() {
     Process(1);
     Process(2);
     return 0;
 }
