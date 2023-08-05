#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc (void *ptr)
{
    printf("Inside ThreadProc\n");
    printf("Thread created Successfully with id : %u\n",pthread_self());
    pthread_exit(NULL);
}

int main()
{
    int Ret = 0;
    pthread_t TID;

    Ret = pthread_create(&TID,        //Address of pthraed_attr_t strcuture object
                        NULL,        // thread attributes
                        ThreadProc,  //Address of callback function
                        NULL);       // Parameters to callback function

    if(Ret!=0)
    {
        printf("Unable to craete the thread \n");
        return -1;
    }
    printf("Thread created Successfully with id : %u\n",TID);

    pthread_join(TID,NULL);

    printf("end of main thraed \n");

    return 0;
}