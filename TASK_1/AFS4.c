#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc!=2)
    {
        printf("Insuffient Arguments\n");
        printf("Usage: ./Executable_Name   Name_of_File\n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("File Name: %s\n",argv[1]);
    printf("File Size: %d\n",sobj.st_size);
    printf("Inode Number: %d\n",sobj.st_ino);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("File System number : %d\n",sobj.st_dev);
    printf("Number of blocks : %d\n",sobj.st_blocks);


    return 0;
}