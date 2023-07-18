#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd=0;

    if(argc!=2)
    {
        printf("Insufficient Arguments\n");
        printf("Usage: ./Executale_Name    Name_Of_File \n");
        return -1;
    }

    fd=open(argv[1],O_RDONLY);
    if(fd==-1)
    {
        printf("uanble to open file\n");
    }
    else
    {
        printf("File Opened Succesfully with fd : %d\n",fd);
    }


    return 0;
}