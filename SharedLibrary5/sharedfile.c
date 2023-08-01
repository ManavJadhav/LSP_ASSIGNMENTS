#include"sharedfile.h"

void fileinfo(char * filename)
{
    struct stat sobj;


    stat (filename,&sobj);  //filename & empty object address

    printf("File name: %s\n",filename);
    printf("File size is : %d\n",sobj.st_size);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("Inode number : %d\n",sobj.st_ino);
    printf("File System number : %d\n",sobj.st_dev);
    printf("Number of blocks : %d\n",sobj.st_blocks);
}