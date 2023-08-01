#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<pthread.h>

//  void * ______ (void * ________)
// {}

void * ThreadProc(void *ptr)
{


  DIR *dp = NULL;
  struct dirent *entry = NULL;
  char name[1024]= {'\0'};
  struct stat sobj;
  int fd = 0;

  char *DirName = (char*)ptr;

  dp = opendir(DirName);
  if(dp == NULL)
  {
    printf("Unable to open directory\n");
    return -1;
  }

  fd = creat("DemoCombine.txt",0777);

  while((entry = readdir(dp)) != NULL)
  {
    sprintf(name,"%s/%s",DirName,entry->d_name);
    write(fd,name,strlen(name));
    printf("%s\n",entry->d_name);
  }

  pthread_exit(NULL);
}

int main()
{
  pthread_t TID;
  int ret = 0;
  char DeskPath[1024];

    char *homeDir = getenv("HOME");
    if (homeDir == NULL) {
        printf("Unable to retrieve home directory.\n");
        return 1;
    }

   
    sprintf(DeskPath,"%s/Desktop", homeDir);


  ret =  pthread_create(&TID,        //Address of pthraed_attr_t strcuture object
                        NULL,        // thread attributes
                        ThreadProc,  //Address of callback function
                        DeskPath);       // Parameters to callback function

  if(ret != 0)
  {
    printf("Unable to craete thread\n");
    return -1;
  }

  printf("Thread is successfully created with iD : %u\n",TID);

  pthread_join(TID,NULL);

  printf("End of main thread\n");

  pthread_exit(NULL);
  
  return 0;
}



