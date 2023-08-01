#include<stdio.h>
#include"factorialShared.h"

void factorial(int iValue)
{
    int iFact = 1;
    int iCnt = 0;
    
    if(iValue < 0)  // Updator
    {
        iValue = -iValue;
    }
    for(iCnt = 1; iCnt <= iValue; iCnt++)
    {
        iFact = iFact * iCnt; //  4
    }
    printf("Factortial is : %d\n",iFact);
}

//To Create .o file
// gcc -c -fpic factorialShared.c

//To create .so file
// gcc -shared -o factlib.so factorialShared.o
