#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[50];
    int fd = 0;

    if(argc!=3)
    {
        printf("Insuffient Arguments\n");
        printf("Usage : ./Executable_Name   Name_Of_Directory  Name_Of_File\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],argv[2]);
        if(strcmp(argv[2],entry->d_name)==0)
        {
            printf("File Already Present in directory\n");  
        }
        else
        {
            fd=creat(name,0777);
            if(fd==-1)
            {
                printf("Unable to craete File\n")
            }
            printf("File Successfully Created in teh Directory\n");
        }
    }

    closedir(dp);
    
    return 0;
}