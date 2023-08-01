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
    char newfile[20];
    struct FileInfo fobj;
    char name[30];
    int Ret = 0, size = 0;
    int fdread = 0;

    fdread = open("AllCombine.txt",O_RDONLY);

    while((Ret = read(fdread,&fobj,sizeof(fobj))) != 0)
   {
        size = fobj.FileSize;
        sprintf(newfile,fobj.FileName);
        lseek(fdread,size,SEEK_CUR);
        if(size > 10)
        {
            printf("%s\t",newfile);
            printf("%d\n",size);
        }
   }
    close(fdread);

    return 0;
}
