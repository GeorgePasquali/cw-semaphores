#include<stdio.h>
#include"shared.h"

int main(){
    sem_t full, empty;
    
    empty = sem_init(63662);
    full = sem_init(62662);

    int *common,i,a;

    common = (int *)getmem(61662); // Allocate shared memory

    for(i=1;i<50;i++){

        PS(empty);
        a = *common;
        a = a + 1;
        *common = a;
        VS(full);
    }
    printf("fill process ended");
    return 0;
}