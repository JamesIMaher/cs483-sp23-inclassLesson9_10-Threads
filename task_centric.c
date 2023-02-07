#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_INTS 1000
#define NUM_THREADS 3

typedef struct _params{
	int *values;
	int numValues;
}params;

float o_avg;
int o_max;
int o_min;

void *meanThread (void *numbers){
	params *struct_ptr = (params *) numbers;
	int sum = 0;

	for (int i=0; i<struct_ptr->numValues; i++){
		sum += struct_ptr->values[i];
	}
	o_avg = sum / struct_ptr->numValues;
	pthread_exit(0);
}

void *minThread (void *numbers){
	params *struct_ptr = (params *) numbers;
	int min = 999999;

	for (int i = 0; i < struct_ptr->numValues; i++){
		if (struct_ptr->values[i] < min){
			min = struct_ptr->values[i];
		}
	}
	o_min = min;
	pthread_exit(0);
}

void *maxThread (void *numbers){
	params *struct_ptr = (params *) numbers;
	int max = -1;

	for (int i = 0; i<struct_ptr->numValues; i++){
		if (struct_ptr->values[i] > max){
			max = struct_ptr->values[i];
		}
	}
	o_max = max;
	pthread_exit(0);
}

int main (){
	char buf[256];
	int numbers[1000];
	int int_counter = 0;

	

	pthread_t tids[NUM_THREADS];
	pthread_attr_t attrs[NUM_THREADS];

	for (int i = 0; i<NUM_THREADS; i++){
		pthread_attr_init(&attrs[i]);
	}	

	while(fgets(buf, 256, stdin) != NULL){
		numbers[int_counter] = atoi(buf);
		int_counter++;
	}

	params p = {numbers, NUM_INTS};

	pthread_create(&tids[0], &attrs[0], meanThread, &p);
	pthread_create(&tids[1], &attrs[1], minThread, &p);
	pthread_create(&tids[2], &attrs[2], maxThread, &p);
	
	for (int i = 0; i<NUM_THREADS; i++){
		pthread_join(tids[i],NULL);
	}
	
	printf("The average is: %f\n",o_avg);
	printf("The min value is: %d\n",o_min);
	printf("The max value is: %d\n", o_max);

	return 0;
}
