#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char *argv[])
{
    int fd = 0;
    char Arr[20];
    int Ret=0;

    if(argc!=3)
    {
        printf("Insuffient Arguments\n");
        printf("Usage : ./Executable_Name   Name_Of_File  Offset\n");
        return -1;
    }

    fd=open(argv[1],O_RDONLY);
    if(fd==-1)
    {
        printf("unable to open file\n");
        return -1;
    }

    lseek(fd,atoi(argv[2]),0);

    Ret=read(fd,Arr,20);

    printf("Data from file is \n");
    write(1,Arr,Ret);

    close(fd);
    
    return 0;
}