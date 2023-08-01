#include<stdio.h>
#include"sharedfile.h"

void fileopen(char* f1,char *f2)
{
  int fd1=0 ,fd2=0;
    struct stat sobj1;
    struct stat sobj2;
    char Buffer1[1024];
    char Buffer2[1024];
    int Ret=0;

    fd1 = open(f1,O_RDONLY);
    fd2 = open(f2,O_RDONLY);

    if(fd1 ==-1 || fd2 == -1)
    {
        printf("unable to open file\n");
        return ;
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are different as size are not same\n");
        return ;
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

}

//To Create .o file
// gcc -c -fpic sharedfile.c

//To create .so file
// gcc -shared -o library.so sharedfile.o