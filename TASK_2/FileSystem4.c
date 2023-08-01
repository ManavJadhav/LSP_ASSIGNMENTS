#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp =NULL;
    struct dirent *entry =NULL;
    char name[30];
    char type[20];

    struct stat sobj;

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
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat (name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
           printf("%s File size : Regular file\n",name);
        }
        if(S_ISDIR(sobj.st_mode))
        {
           printf("%s File size : Directory file\n",name);
        }
        if(S_ISLNK(sobj.st_mode))
        {
           printf("%s File size : Symbloic file\n",name);
        }
    }

    closedir(dp);


    return 0;
}
