// SERVER for shared memory

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/shm.h>


int main()
{
  int shmid = 0;
  int key = 1234;
  int shmsize = 100;
  char *ptr = NULL;

  printf("Server application runnig...\n");

  shmid = shmget(key,shmsize,0666);

  printf("Shared memomry allocated successfully...\n");

  ptr = shmat(shmid,NULL,0);

  if(ptr != NULL)
  {
   printf("Shared memory attached succesfully...\n");
  }
   
  printf("Data from file is: \n");
  while(*ptr != '\0')
  {
    printf("%c",*ptr);
    ptr++;
  }
  printf("\n");

  shmdt(ptr);

  return 0;
}



