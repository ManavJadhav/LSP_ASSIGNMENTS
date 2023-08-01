#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int cpid = 0;
    int Exit_status = 0;

    Ret = fork();

    if(Ret == 0)  // Child
    {
        execl("./ChildProcess","NULL",NULL);
    }
    else    // Parent
    {
        cpid = wait(&Exit_status);
        printf("Child process terminated having PID %d with exit status %d\n",cpid,Exit_status);
        printf("Parent process terminated having PID : %d\n",getpid());
    }

    return 0;
}
