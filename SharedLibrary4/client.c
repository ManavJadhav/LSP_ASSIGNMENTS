#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>  // dl - dynamic linking
#include <getopt.h>
#include <unistd.h>

int main(int argc, char*argv[])
{
    void *ptrfinal = NULL;
    void (*fptr)(int);

    int iValue = 0;

    printf("Enter the number of which you want factorial of :\n");
    scanf("%d",&iValue);

    ptrfinal = dlopen("/home/vedant/LSPAssignments/Assignment7/4/sharedlib.so",RTLD_LAZY);   // RunTime LoaD
    if(ptrfinal==NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr= dlsym(ptrfinal,"sharedHelper");
    if(fptr==NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr(iValue);
}


// gcc -rdynamic -o Myexe client.c
// ./Myexe
