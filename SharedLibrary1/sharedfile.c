#include<stdio.h>
#include"sharedfile.h"

void Addition(int iNo1 , int iNo2)
{
  int iAns = 0;                 
  if(iNo2 > iNo1)
  {
    return ;
  }

  iAns = iNo1 + iNo2;

  printf("Addition is : %d\n",iAns);                

}

void Subtraction(int iNo1 , int iNo2)
{
  int iAns = 0;                 
  if(iNo2 > iNo1)
  {
    return ;
  }

  iAns = iNo1 - iNo2;

  printf("Subtraction is : %d\n",iAns);                 

}

void Division(int iNo1 , int iNo2)
{
  int iAns = 0;                 
  if(iNo2 > iNo1)
  {
    return ;
  }

  iAns = iNo1 / iNo2;

  printf("Division is : %d\n",iAns) ;                

}

void Multiplication(int iNo1 , int iNo2)
{
  int iAns = 0;                 
  if(iNo2 > iNo1)
  {
    return ;
  }

  iAns = iNo1 * iNo2;

  printf("Multiplication is : %d\n",iAns);                  

}

//To Create .o file
// gcc -c -fPic sharedfile.c

//To create .so file
// gcc -shared -o library.so sharedfile.o