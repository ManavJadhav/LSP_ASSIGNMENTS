#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    int fd=0;

    if(argc!=2)
    {
        printf("Insuffient Arguments\n");
        printf("Usage : ./Executable_Name   Name_Of_Directory_You_Want_To_Create\n");
        return -1;
    }

    fd=mkdir(argv[1],0777);
    if(fd==-1)
    {
        printf("Unable to create the directory\n");
        return -1;
    }

    printf("Directory %s Created Successfully\n",argv[1]);



    return 0;
}
