#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>  // dl - dynamic linking
#include<string.h>

void sharedHelper(int iNo)
{
    void *ptr = NULL;
    void (*fptr)(int);

    ptr = dlopen("/home/vedant/LSPAssignments/Assignment7/4/factlib.so",RTLD_LAZY);   // RunTime LoaD
    if(ptr==NULL)
    {
        printf("Unable to load library\n");
        return;
    }
    fptr= dlsym(ptr,"factorial");
    if(fptr==NULL)
    {
      printf("Unable to load the address of function inside so\n");
      return;
    }

    fptr(iNo);
    
}

//To Create .o file
// gcc -c -fpic shared1.c

//To create .so file
// gcc -shared -o sharedlib.so shared1.o
