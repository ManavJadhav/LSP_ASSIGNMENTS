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

    if(argc!=3)
    {
        printf("Insuffient Arguments\n");
        printf("Usage : ./Executable_Name   Name_Of_Directory    Name_Of_File\n");
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
        if((strcmp(argv[2],entry->d_name))==0)
        {
            printf("File is present in Directory\n");
            break;
        }
    }

    if(entry==NULL)
    {
        printf("There is no such file\n");
        return -1;
    }
    closedir(dp);

    return 0;
}