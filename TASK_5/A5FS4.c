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
    char DirName[20];
    char Buffer[BLOCKSIZE] = {'\0'};
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    struct FileInfo fobj;
    char name[30];
    int ret = 0;
    int fd = 0, fdread = 0;
    
    if(argc!=2)
    {
     printf("Insuffient Arguments\n");
     printf("Usage: ./Executable_name  Name_Of_Directory\n");
     return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("AllCombine.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {
        if((entry->d_type) == DT_REG)
        {
            sprintf(name,"%s/%s",argv[1],entry->d_name);
            stat(name,&sobj);
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            write(fd,&fobj,sizeof(fobj));
            fdread = open(name, O_RDONLY);
            while((ret = read(fdread,Buffer,BLOCKSIZE)) != 0)
            {
                write(fd,Buffer,ret);
            }   
        }
    }

    close(fd);
    closedir(dp);
    close(fdread);
    
    return 0;
}
