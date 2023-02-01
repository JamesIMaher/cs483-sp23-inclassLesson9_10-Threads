#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <pthread.h>

long sum;

void *runner(void *param) {
    long i;
    long upper = atol((char *) param);
    sum = 0;
    for (i=0; i<=upper; i++){ //Sum all numbers from 0 to the user inputed number.
        sum += i;
    }
    pthread_exit(0);
}

int main (int argc, char *argv[]){
    pthread_t tid; //Initialize the pthread ID variable
    pthread_attr_t attr; //Initialize a pthread attribute structure

    //Initialize the pthread attribute structure
    pthread_attr_init(&attr);
    //Create the thread
    pthread_create(&tid, &attr, runner, argv[1]);
    //Wait for the thread to complete
    pthread_join(tid, NULL);
    setlocale(LC_NUMERIC, "");
    printf("sum = %'ld\n", sum);
    return 0;

}