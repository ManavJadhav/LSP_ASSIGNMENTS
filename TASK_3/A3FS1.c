#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
    int fdSource=0;
    int fdDest=0;
    char Buffer[BLOCKSIZE];
    int Ret=0;

    if(argc!=3)
    {
        printf("Insufficient Arguments\n");
        printf("Usage: ./Executable_Name   Source_File_Name  Destination_File_Name \n");
        return -1;
    }

    fdSource=open(argv[1],O_RDONLY);
    if(fdSource==-1)
    {
        printf("unable to Open the file\n");
        return -1;
    }

    fdDest=creat(argv[2],0777);
    if(fdDest==-1)
    {
        printf("unable to Create the file\n");
        return -1;
    }

    while((Ret=read(fdSource,Buffer,sizeof(Buffer)))!=0)
    {
        write(fdDest,Buffer,Ret);
        memset(Buffer,0,sizeof(Buffer));
    }

    close(fdSource);
    close(fdDest);

    return 0;
}