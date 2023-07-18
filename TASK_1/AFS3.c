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
        Mode = R_OK;
    }
    else if((strcmp(argv[2],"Write")==0))
    {
        Mode = W_OK;
    }
    else if((strcmp(argv[2],"Executable")==0))
    {
        Mode = X_OK;
    }

    fd=access(argv[1],Mode);
    if(fd==-1)
    {
        printf("Unable to Access the File\n");
        return -1;
    }
    printf("File Accessed Successfully with Mode :%s\n",argv[2]);

    return 0; 
}