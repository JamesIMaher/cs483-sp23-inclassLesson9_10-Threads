#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <pthread.h>

#define NUM_THREADS 4

long sum0, sum1, sum2, sum3;

void *runner0(void *param) {
    long i;
    sum0 = 0;
    for (i=0; i<1000000000; i++){ //Sum all numbers from 0 to the user inputed number.
        sum0 += i;
    }
    pthread_exit(0);
}

void *runner1(void *param) {
    long i;
    sum1 = 0;
    for (i=1000000000; i< 2000000000; i++){ //Sum all numbers from 0 to the user inputed number.
        sum1 += i;
    }
    pthread_exit(0);
}

void *runner2(void *param) {
    long i;
    sum2 = 0;
    for (i=2000000000; i<3000000000; i++){ //Sum all numbers from 0 to the user inputed number.
        sum2 += i;
    }
    pthread_exit(0);
}

void *runner3(void *param) {
    long i;
    sum3 = 0;
    for (i=3000000000; i<=4000000000; i++){ //Sum all numbers from 0 to the user inputed number.
        sum3 += i;
    }
    pthread_exit(0);
}

int main (int argc, char *argv[]){
    pthread_t tid[NUM_THREADS]; //Initialize the pthread ID variable
    pthread_attr_t attr[NUM_THREADS]; //Initialize a pthread attribute structure

    //Initialize the pthread attribute structure
    for (int k = 0; k<NUM_THREADS; k++){
         pthread_attr_init(&attr[k]);
    }
   
    //Create the thread
    pthread_create(&tid[0], &attr[0], runner0, NULL);
    pthread_create(&tid[1], &attr[1], runner1, NULL);
    pthread_create(&tid[2], &attr[2], runner2, NULL);
    pthread_create(&tid[3], &attr[3], runner3, NULL);
    
    //Wait for the thread to complete
    for(int k = 0; k < NUM_THREADS; k++){
        pthread_join(tid[k], NULL);
    }
    
    setlocale(LC_NUMERIC, "");
    printf("sum = %'ld\n", sum0 + sum1 + sum2 + sum3);
    return 0;

}