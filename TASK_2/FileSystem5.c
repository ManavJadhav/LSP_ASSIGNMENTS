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
    struct stat sobj;
    int iMax=0;
    char name[30];
    char namecopy[30];

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

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(iMax < sobj.st_size)
            {
                iMax = sobj.st_size;
                strcpy(namecopy,name);
            }
        }
    }
    printf("Name of largest file : %s with size %d bytes \n",namecopy,iMax);
    closedir(dp);


    return 0;
}
