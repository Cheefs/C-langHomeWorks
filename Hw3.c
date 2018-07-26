#include <stdio.h>
#include <stdlib.h>
#define MaxN 10

void fillArr (int N, int *a)
{

    int i;
    for(i = 0; i < N; i++)
      a[i]=rand()%1000;
}
void asymptotic (int N,int count)
{
    if (count<=(N+N)+N) printf("\nThe asymptotic complexity = O(2n)\n");
    else if (count>=(N*N)-N) printf("\nThe asymptotic complexity = O(n*n)\n");
}
void print(int N, int *a)
{
    int i;
    for(i = 0; i < N; i++)
        printf(" %6i ", a[i]);
        printf("\n");
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int bubleSort (int N, int *a)
{
    fillArr(N,a);
    int i;
    int j;
    int count =0;
    int left =0;
    int right =N;

    puts("Array before sort");
    print(N,a);
    while (right!=left)
    {
       i++;
       for(j = 0; j<N-1 ;j++)
        if (a[j] > a[j +1])
        {
          count++;
          swap(&a[j], &a[j + 1]);
        }
        count ++;
        right --;
    }
    puts ("Array after sort");
    print(N,a);
    printf("\nBooble Sort Optimized, count: %d", count);
    asymptotic(N,count);
}

int defaultBoble (int N, int *a)
{
    fillArr(N,a);
    int count =0;
    puts("Array before sort");
    print(N,a);

     for (int i=0; i<N-1;i++)
       for(int j = 0; j <N-1;j++)
       {
         count++;
         if (a[j] > a[j +1])
         {
           count++;
           swap(&a[j], &a[j + 1]);
         }
       }
    puts("Array after sort");
    print(N,a);
    printf("\nDefault Booble Sort, count: %d", count);
    asymptotic(N,count);
}


int ShekerSort(int N, int *a)
{
   fillArr(N,a);
   int i;
   int count =0;
   int left =0;
   int right =N-1;
    puts("Array before sort");
    print(N,a);
    while (left<=right)
    {
      for (i=left;i<right;i++)
        if (a[i]>a[i+1])
        {
         count++;
         swap(&a[i],&a[i+1]);
        }
        count++;
        right--;
      for (i=right;i>left;i--)
        if (a[i]<a[i-1])
        {
          count++;
          swap(&a[i],&a[i-1]);
        }
        count++;
        left++;
     }
    puts("Array After sort");
    print(N,a);
    printf("\nSheker Sort, count: %d", count);
    asymptotic(N,count);
}

int main()
{
    int a[MaxN];
    int N=MaxN;

    bubleSort(N,a);
    defaultBoble(N,a);
    ShekerSort(N,a);

    return 0;
}
