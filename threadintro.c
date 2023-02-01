#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *printMessage(void *messageString){
    printf("%s\n", (char *) messageString);
    pthread_exit(0);
}

int main (){
    pthread_t thread1;
    pthread_t thread2;

    char *message1 = "Hello from Thread 1!\n";
    char *message2 = "Hello from Thread 2!\n";

    pthread_create(&thread1, NULL, printMessage, message1);
    pthread_create(&thread2, NULL, printMessage, message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Back to a single thread of execution.\n");
    return 0;
}