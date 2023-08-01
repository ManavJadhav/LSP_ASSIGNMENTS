#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
   printf("Process4 created with PID : %d with Parent PID : %d\n",getpid(),getppid());

    return 0;
}
