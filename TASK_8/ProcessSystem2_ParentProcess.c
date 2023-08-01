#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int GrandChild = 0;

    Ret = fork();

    if(Ret == 0)  // Child
    {
        execl("./ChildProcess1","NULL",NULL);
    }
    else
    {
        printf("GrandParent is running with PID : %d\n",getpid());
        GrandChild = wait(NULL);
    }

    return 0;
}
