#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define HOLESIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    char FileName[20];
    char Buffer [HOLESIZE] = {'\0'};

    if(argc!=2)
    {
     printf("Insufficient Arguments\n");
     printf("Usage: ./Executable_Name   Name_of_File\n");
     return -1;
    }

    fd = open(argv[1], O_RDONLY | O_WRONLY );
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    lseek(fd,0,SEEK_END);
    write(fd,Buffer,sizeof(Buffer));
    return 0;
}
