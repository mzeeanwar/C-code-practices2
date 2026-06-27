#include <stdio.h>  
int semaphore = 1;
void wait_sem() {
     semaphore--; }
 void signal_sem() {
     semaphore++; 
}  
void Process1() {
     wait_sem();
      printf("Process 1 entered Critical Section\n");
     printf("Process 1 is executing...\n");
     printf("Process 1 leaving Critical Section\n\n");
      signal_sem(); 
}  
void Process2() {
     wait_sem();
      printf("Process 2 entered Critical Section\n");
     printf("Process 2 is executing...\n");
     printf("Process 2 leaving Critical Section\n\n");
      signal_sem();
 }
  int main() {
     Process1();
     Process2();
     return 0;
}
