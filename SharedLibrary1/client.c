#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>  // dl - dynamic linking

int main()
{
    int iNo1 = 0;
    int iNo2 = 0;

    printf("Enter the 2 numbers : \n");
    scanf("%d %d",&iNo1,&iNo2);

    void *ptr = NULL;
    void (*fptr)(int,int);
    void (*fptr1)(int,int);
    void (*fptr2)(int,int);
    void (*fptr3)(int,int);

    ptr = dlopen("/home/maddy/Desktop/LSP_ASSIGNMENTS/ASS_7/1/library.so",RTLD_LAZY);   // RunTime LoaD  
    if(ptr==NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr= dlsym(ptr,"Addition");
    if(fptr==NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr1= dlsym(ptr,"Subtraction");
    if(fptr==NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr2= dlsym(ptr,"Division");
    if(fptr==NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr3= dlsym(ptr,"Multiplication");
    if(fptr==NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr(iNo1,iNo2);
    fptr1(iNo1,iNo2);
    fptr2(iNo1,iNo2);
    fptr3(iNo1,iNo2);
    
}


// gcc -rdyanmic -o Myexe client.c
// ./Myexe