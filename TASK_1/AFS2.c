#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd =0;
    int Mode =0;

    if(argc!=3)
    {
        printf("Insufficient Arguments\n");
        printf("Usage: ./Executable_Name    Name_of_File    Mode_of_File\n");
        return -1;
    }

    if(strcmp(argv[2],"Read")==0)
    {
        Mode = O_RDONLY;
    }
    else if((strcmp(argv[2],"Write")==0))
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDWR;
    }

    fd=open(argv[1],Mode);
    if(fd==-1)
    {
        printf("Unable to Open the File\n");
        return -1;
    }
    printf("File Opend Successfully with fd %d & Mode %d\n",fd,Mode);

    return 0; 
}