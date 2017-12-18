#include<stdio.h>
#include<fcntl.h>

main(){
    int bytes_read, i = 0;
    int nums[50];
    int fd = open("myfile.txt", O_RDONLY);
    
    if(fd == -1){
        perror("read");
        return 1;
    }

    while(bytes_read = read(fd, &nums[i], sizeof(int))){
        if (bytes_read == -1){
            perror("read");
            return 1;
        }
        printf("number: %i", i);
        i++;
    }
}