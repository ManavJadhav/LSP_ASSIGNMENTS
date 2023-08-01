#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char * Buffer = NULL;
    char newfile[20];
    struct FileInfo fobj;
    char name[30];
    int Ret = 0, icnt = 1, size = 0;
    int fdwrite = 0, fdread = 0, iRet = 0;

    fdread = open("AllCombine.txt",O_RDONLY);

    while((Ret = read(fdread,&fobj,sizeof(fobj))) != 0)
   {
        size = fobj.FileSize;

        sprintf(newfile,fobj.FileName);
        Buffer = (char*)malloc(size);
        Ret = read(fdread,Buffer,size);
        fdwrite = creat(newfile,0777);
        write(fdwrite,Buffer,Ret);
        icnt++;
   }
   printf("%d\n",icnt);

    close(fdread);

    return 0;
}
