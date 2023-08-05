#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1 (void * ptr)
{
    printf("Inside ThreadProc1\n");
    int iCnt = 0;
    for(iCnt = 1; iCnt <=500; iCnt++)
    {
        printf("%d\t",iCnt);
    }
    printf("\n");
    pthread_exit(NULL);
}

void * ThreadProc2 (void * ptr)
{
    printf("Inside ThreadProc2\n");
    int iCnt = 0;
    for(iCnt = 500; iCnt >=1; iCnt--)
    {
        printf("%d\t",iCnt);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main()
{
    int Ret1 = 0 , Ret2 = 0;

    pthread_t TID1, TID2 ;

    Ret1 = pthread_create(&TID1,        //Address of pthraed_attr_t strcuture object
                        NULL,        // thread attributes
                        ThreadProc1,  //Address of callback function
                        NULL);       // Parameters to callback function

    if(Ret1 != 0)
    {
        printf("Unable to create thraed\n");
        return -1;
    }

    Ret2 = pthread_create(&TID2,        //Address of pthraed_attr_t strcuture object
                        NULL,        // thread attributes
                        ThreadProc2,  //Address of callback function
                        NULL);       // Parameters to callback function

    if(Ret2 != 0)
    {
        printf("Unable to create thraed\n");
        return -1;
    }

    printf("Thread1 created Successfully with id : %u\n",TID1);
    printf("Thread2 created Successfully with id : %u\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID1,NULL);

    printf("End of main thread\n");
    return 0 ;
}