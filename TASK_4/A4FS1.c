#include<stdio.h>

int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        printf("Insuffient Arguments\n");
        printf("Usage : ./Executable_Name  < Output.txt > Input.txt\n");
        return -1;
    }
    int iNo1=0,iNo2=0,iAns=0;

    scanf("%d",&iNo1);
    scanf("%d",&iNo2);

    iAns=iNo1+iNo2;
    printf("Addition is :%d\n",iAns);

    return 0;
}