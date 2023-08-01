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
    char olddir[50];
    char newdir[50];

    if(argc!=3)
    {
        printf("Insuffient Arguments\n");
        printf("Usage : ./Executable_Name   Name_Of_First_Directory    Name_Of_Second_Directory\n");
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
        sprintf(olddir,"%s/%s",argv[1],entry->d_name);
        sprintf(newdir,"%s/%s",argv[2],entry->d_name);

        rename(olddir,newdir);
    }
    closedir(dp);

    return 0;
}
