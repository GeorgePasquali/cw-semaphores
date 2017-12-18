#include<stdio.h>
#include"shared.h"
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    sem_t full, empty;
    
    empty = sem_init(63662);
    full = sem_init(62662);

    int *common,i,a;
    int bytes_written;

    common = (int *)getmem(61662); // Allocate shared memory

    int fd = open("myfile.txt", O_RDWR | O_CREAT, 0640);

    if(fd == -1){
        perror("open");
        return 1;
    }

    for(i=1;i<50;i++){
        PS(full);
        printf("here");
        bytes_written = write(fd, common, sizeof(int));
        if (bytes_written == -1){
            perror("write");
            return 1;
        }
        VS(empty    );
    }
    printf("write process ended");
}