#include <stdio.h>

void task1 (int aDec)
{
    if(aDec>=2)  task1(aDec/2);
    printf("%d",aDec%2);
}

int task2a (int a,int b)//2-a
{
    int num = 1;
    if (b==0) return 1;
    while (b)
    {
       num = num * a;
        b --;
    }
    printf("%d", num);
}

int task2b(int a,int  b) //2-b
{
    if (b==0) return 1;
    else if (b>0)
    {
      return task2b(a,b-1)*a;
    }
}
int task2c (int a,int b) //2-c
{
    if ( b>0 )
    {
        if ( b % 2 ) return task2c(a,b-1)*a;
        else return task2c(a,b/2);
    }
}
int  task3(int n,int to)
{
    if (n<to)
    return task3(n+1,to)+task3(n*2,to);
    else if (n==to) return 1;
    else return 0;
}

int main ()
{
    int aBin,aDec,uChoise,a,b,n;
    printf("Please choose task:\n Task 1 - 1\n Task 2 - 2\n Task 3 - 3\n Your`s choice: ");
     scanf("%d",&uChoise);
    if (uChoise==1)
    {
        printf("enter number to convert to Bin: ");
        scanf("%d",&aDec);
            task1(aDec);
    }
    else if (uChoise==2)
    {
       printf("enter number: ");
         scanf("%d",&a);
       printf("enter pow count: ");
         scanf("%d",&b);
       printf("NonRecursed: ");
        task2a(a,b);
       printf("\nRecursed : ");
       printf("%d\n",task2b(a,b));
       printf("FastPowRecursed: ");
       printf("%d\n",task2c(a,b));
    }
    else if (uChoise==3)
    {
        printf("Total counts: %d\n ",task3(3,20));

    }
    else printf("Wrong number!!!");
    return 0;
}
