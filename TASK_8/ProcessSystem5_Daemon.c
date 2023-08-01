#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int chdir = 0;
    int noclose = 0;

    int ret = 0;

    ret = daemon(chdir,noclose);
    if(ret != 0)
    {
        printf("unable to craete daemon process\n");
        return -1;
    }

    while(1)
    {
        sleep(5);
    }
    

    return 0;
}

// gcc A8PS5.c -o Deamon
// ./Deamon

// pgrep Deamon

// pgrep -u root,daemon

//ps -p PID -o "user pid ppid pgid sid tty command"

// lsof -p PID

// kill PID
