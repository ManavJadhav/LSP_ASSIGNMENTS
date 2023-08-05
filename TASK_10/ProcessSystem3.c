#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>

void * Factorial (void * ptr)
{
    int iValue = (int )ptr;
    int iCnt = 0 , iFact = 1;

    for(iCnt = 1; iCnt <= iValue ;iCnt++)
    {
        iFact = iFact * iCnt;
    }
    printf("Factorial is : %d\n",iFact);
    
    pthread_exit(NULL);
}

int main()
{
    int Ret1 = 0 , Ret2 = 0;
    int iNo =0;

    pthread_t TID1, TID2 ;

    printf("Enter a number : \n");
    scanf("%d",&iNo);

    Ret1 = pthread_create(&TID1,        //Address of pthraed_attr_t strcuture object
                        NULL,        // thread attributes
                        Factorial,  //Address of callback function
                    (int*) iNo);       // Parameters to callback function

    if(Ret1 != 0)
    {
        printf("Unable to create thraed\n");
        return -1;
    }

    printf("Thread created Successfully with id : %u\n",TID1);

    pthread_join(TID1,NULL);

    printf("End of main thread\n");

    return 0 ;
}