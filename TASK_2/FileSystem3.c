#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp =NULL;
    struct dirent *entry =NULL;

    if(argc!=2)
    {
        printf("Insufficient Argumenst\n");
        printf("Usage: ./Executable_Name   Name_of_Directory \n");
        return -1;
    }

    dp=opendir(argv[1]);
    if(dp==NULL)
    {
        printf("Unable to Open Directory\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        printf("File Name: %s\n",entry->d_name);
    }

    closedir(dp);


    return 0;
}
