#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pid1 = 0, pid2 = 0, pid3 = 0;

    pid1 = fork();

    if(pid1 == 0)  // Child
    {
        execl("./Process2","NULL",NULL);
    }

    pid2 = fork();

    if(pid2 == 0)
    {
        execl("./Process3","NULL",NULL);
    }

    pid3 = fork();

    if(pid3 == 0)
    {
        execl("./Process4","NULL",NULL);
    }

    else
    {
        printf("Parent is running with PID : %d\n",getpid());
        wait(NULL);
    }

    return 0;
}
