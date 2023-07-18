#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd =0;
    int Ret=0;
    char str[]="Welcome to Marvellous";

    if(argc!=2)
    {
        printf("Insufficient Argumenst\n");
        printf("Usage: ./Executable_Name   Name_of_File \n");
        return -1;
    }

    fd=creat(argv[1],0777);
    if(fd==-1)
    {
        printf("Unable to Create file\n");
    }

    Ret=write(fd,str,strlen(str));
    if(Ret==-1)
    {
        printf("Unable to write the data into file\n");
    }
    printf("String Successfully written in file %s is %s\n",argv[1],str);
    

    return 0;
}
