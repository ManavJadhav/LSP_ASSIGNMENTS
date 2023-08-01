#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int cpid = 0;
    int exit_st = 0;

    Ret = fork();

    if(Ret == 0)  // Child
    {
        execl("./ChildProcess2","NULL",NULL);
    }
    else
    {
        printf("1st child running with PID : %d with Parent PID : %d\n",getpid(),getppid());
        cpid = wait(NULL);
    }

    return 0;
}
