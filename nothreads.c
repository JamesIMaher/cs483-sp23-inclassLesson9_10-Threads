#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(int argc, char *argv[]){

    long upper = atol(argv[1]);
    long sum = 0;

    for (long i=0; i <= upper; i++){
        sum += i;
    }

    setlocale(LC_NUMERIC, "");
    printf("sum= %'ld\n", sum);

    return 0;
}
