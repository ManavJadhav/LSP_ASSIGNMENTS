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
    struct stat sobj;

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

    
    while((entry = readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size==0)
            {   
                remove(name);
                printf("Empty Files Deleted Succesfully\n");
            }
        }
    }
    closedir(dp);

    return 0;
}
