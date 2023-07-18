#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    int fd1=0 ,fd2=0;
    struct stat sobj1;
    struct stat sobj2;
    char Buffer1[1024];
    char Buffer2[1024];
    int Ret=0;

    if(argc!=3)
    {
        printf("Insuffient Arguments\n");
        printf("Usage : ./Executable_Name   Name_Of_First_File   Name_Of_Second_File\n");
        return -1;
    }


    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    if(fd1 ==-1 || fd2 == -1)
    {
        printf("unable to open file\n");
        return -1;
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are different as size are not same\n");
        return -1;
    }

    while((Ret = read(fd1,Buffer1,sizeof(Buffer1)))!=0)
    {
        Ret = read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,Ret)!=0)
        {
            break;
        }
    }
    if(Ret==0)
    {
        printf("Both files are identicial\n");
    }
    else
    {
         printf("Both files are different\n");
    }

    close(fd1);
    close(fd2);
    
    return 0;
}