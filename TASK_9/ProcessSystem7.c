#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<string.h>

extern char **environ;

int main()
{
    char **env = environ;

    for(;*env != NULL; env++)
    {
        if((strncmp(*env,"HOME=",5))==0)
        {
            printf("Home Directory environment for process is : %s\n",*env);
        }
        else if((strncmp(*env,"USERNAME=",9))==0)
        {
            printf("Login Username for process is : %s\n",*env);
        }

    }

    return 0;
}
