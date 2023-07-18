#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char * argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[20];
    char Buffer[10];
    struct stat sobj;
    int fd=0,fd1=0;
    int Ret = 0;

    if(argc!=2)
    {
        printf("Insuffient Arguments\n");
        printf("Usage : ./Executable_Name   Name_Of_Directory\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp==NULL)
    {
        printf("Unable to oepn directory\n");
        return -1;
    }

    fd=creat("DemoALL.txt",0777);
    if(fd==-1)
    {
        printf("Unable to craete the file\n");
        return -1;
    }
    
    while((entry = readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
           fd1=open(name,O_RDWR);
           if(fd1==-1)
           {
            printf("unable to open file\n");
            return -1;
           }
           
           
           Ret = read(fd1,Buffer,sizeof(Buffer))
           {
             write(fd,Buffer,Ret);
           }
           

            
        }
    }
    closedir(dp);

    return 0;
}
