#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int Ret = 0 , Ret1;
    int iValue1 =0;
   
    Ret = nice(0);

    printf("Current Priority of process is %d\n", Ret);

    iValue1 = Ret - 5;

    Ret1 =  nice(iValue1);

    printf("Current Priority of process is %d\n", Ret1);

    return 0;
}


