#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1 (void * ptr)
{
    printf("Inside ThreadProc1\n");

    pthread_exit(NULL);
}

void * ThreadProc2 (void * ptr)
{
    printf("Inside ThreadProc2\n");

    pthread_exit(NULL);
}

void * ThreadProc3 (void * ptr)
{
    printf("Inside ThreadProc3\n");

    pthread_exit(NULL);
}

void * ThreadProc4 (void * ptr)
{
    printf("Inside ThreadProc4\n");

    pthread_exit(NULL);
}

void *(*Arr[]) (void *) = {ThreadProc1,ThreadProc2,ThreadProc3,ThreadProc4};


int main()
{
    pthread_t TID[4];
  int ret = 0;
  int iCnt =0;

for(iCnt = 0 ; iCnt < 4; iCnt++)
{
  ret =  pthread_create(&TID[iCnt],        //Address of pthraed_attr_t strcuture object
                        NULL,        // thread attributes
                        Arr[iCnt],  //Address of callback function
                        NULL);       // Parameters to callback function
}

  if(ret != 0)
  {
    printf("Unable to craete thread\n");
    return -1;
  }


  for(iCnt = 0 ; iCnt < 3; iCnt++)
  {
    pthread_join(TID[iCnt],NULL);
  }
  printf("End of main thread\n");

  pthread_exit(NULL);
  return 0;
}