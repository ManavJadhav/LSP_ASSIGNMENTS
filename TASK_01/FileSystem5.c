#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd=0;
    int Ret= 0;
    char *Buffer = NULL;
    int Size=0;

    if(argc!=3)
    {
        printf("Insuffient Arguments\n");
        printf("Usage: ./Executable_Name   Name_of_File   Bytes_of_data\n");
        return -1;
    }
    
    fd=open(argv[1],O_RDONLY);
    if(fd== -1)
    {
        printf("unable to open File\n");
        return -1;
    }

    Size = atoi(argv[2]);

    Buffer = (char *)malloc(Size);

    Ret=read(fd,Buffer,Size);
    if(Ret== 0)
    {
        printf("Unable to read\n");
        return -1;
    }
    
    printf("Data from file is : %s\n",Buffer);


    return 0;
}
