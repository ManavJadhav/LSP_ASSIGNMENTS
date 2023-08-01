#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>  // dl - dynamic linking

int main(int argc, char*argv[])
{
    int iVaule1 =0;

    printf("Enter a Number: \n");
    scanf("%d",&iVaule1);

    void *ptr = NULL;
    void *ptr1 = NULL;
    void (*fptr)(int);
    void (*fptr1)(int);

    ptr = dlopen("/home/maddy/Desktop/LSP_ASSIGNMENTS/ASS_7/3/library1.so",RTLD_LAZY);   // RunTime LoaD  
    if(ptr==NULL)
    {
        printf("Unable to load library1\n");
        return -1;
    }

    ptr1 = dlopen("/home/maddy/Desktop/LSP_ASSIGNMENTS/ASS_7/3/library2.so",RTLD_LAZY);   // RunTime LoaD  
    if(ptr==NULL)
    {
        printf("Unable to load library2\n");
        return -1;
    }

    fptr= dlsym(ptr1,"CheckPerfect");
    if(fptr==NULL)
    {
        printf("Unable to load the address of function -->CheckPerfect\n");
        return -1;
    }

    fptr1= dlsym(ptr,"CheckPrime");
    if(fptr1==NULL)
    {
        printf("Unable to load the address of function-->CheckPrime\n");
        return -1;
    }



    fptr(iVaule1); //6
    fptr1(iVaule1); //11

    
}


// gcc -rdynamic -o Myexe client.c
// ./Myexe