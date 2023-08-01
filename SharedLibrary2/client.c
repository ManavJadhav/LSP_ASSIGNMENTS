#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>  // dl - dynamic linking

int main(int argc, char*argv[])
{
    void *ptr = NULL;
    void (*fptr)(char *, char*);

    ptr = dlopen("/home/maddy/Desktop/LSP_ASSIGNMENTS/ASS_7/2/library.so",RTLD_LAZY);   // RunTime LoaD  
    if(ptr==NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr= dlsym(ptr,"fileopen");
    if(fptr==NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }


    fptr(argv[1],argv[2]);
    
}


// gcc -rdynamic -o Myexe client.c
// ./Myexe