#include<stdio.h>
#include"sharedfile.h"

void CheckPerfect(int iNo)
{
   int iSum = 0, iCnt = 0;
    if(iNo < 0)
    {iNo = -iNo;}
    
    for(iCnt = 1; iCnt <= (iNo / 2); iCnt++)
       {
           if((iNo % iCnt) == 0)       // 4
           {
               iSum = iSum + iCnt;
           }
       }
    if(iSum == iNo)
    {
        printf("%d is a PERFECT number.\n", iNo);
    }
    else
    {
        printf("%d is a  not perfect number.\n", iNo);
    }

}

//To Create .o file
// gcc -c -fpic sharedfile.c

//To create .so file
// gcc -shared -o library.so sharedfile.o