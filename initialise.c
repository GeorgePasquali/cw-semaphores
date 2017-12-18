#include<stdio.h>
#include"shared.h"

int main(){
    sem_t full, empty;
    
    empty = sem_init(63662);
    full = sem_init(62662);
    sem_set(full, 0);
    sem_set(empty, 1);


    
    printf("Init process ended");
    return 0 ;
}