#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sched.h>

void * ThreadProc(void*ptr)
{
    int iCnt = 0;
    printf("Value received from main thread is : %s\n",(char*)ptr);
    for(iCnt = 1; iCnt <= 100; iCnt++)
    {
        printf("%s\t%d\n",(char*)ptr,iCnt);
        sched_yield();
    }
}

int main()
{
    pthread_t TID1, TID2;
    int ret1 = 0,ret2 = 0, no = 11;

    ret1 = pthread_create(&TID1,      //Address of pttread_attr_t structure object
                         NULL,      //Thread attributes
                         ThreadProc,//Address of callback function
                         "Thread1");     //Parameters to callback function

    if(ret1 != 0)
    {
        printf("Unable to create thread1\n");
        return -1;
    }

    printf("Thread1 is created with ID : %ld\n",TID1);

    ret2 = pthread_create(&TID2,      //Address of pttread_attr_t structure object
                         NULL,      //Thread attributes
                         ThreadProc,//Address of callback function
                         "Thread2");     //Parameters to callback function

    if(ret2 != 0)
    {
        printf("Unable to create thread1\n");
        return -1;
    }

    printf("Thread2 is created with ID : %ld\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    printf("End of main thread\n");
    pthread_exit(NULL);
    return 0;
}
