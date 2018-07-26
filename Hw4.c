#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 4
#define X 8
#define Y 8
#define HSTEPS (X*Y)-1

int board[Y][X];
int sY[8]={2,-1,1,-1,2,-2,2,-2};
int sX[8]={1,2,-2,-2,1,1,-1,-1};

void Print (int m,int n, int a [N][M])
{
   int i;
   int j;
   for (i =0; i<n;i++)
   {
       for(j=0; j<m; j++)
        printf("%4d",a[i][j]);
    printf("\n");
   }
}
//Task 1
int closeCell (int n, int m , int a [N][M])
{
    int j;
    int i;
 for (j=0;j<m;j++)
       a[0][j]=1;
    for (i=2;i<n;i++)
    {
        a[i][0]=1;
        a[i-1][j]=0;
        a[i][j-2]=0;
    }
}
//Task 2

void annull(int arr[Y][X])
{
	int i;
	int j;
	for (i = 0; i < Y; i++)
		for (j = 0; j < X; j++)
			arr[i][j] = 0;
}
void printBoard(int arr[Y][X])
{
	int i;
	int j;
	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++)
			printf("%3d", arr[i][j]);
		printf("\n");
	}
}
int checkHorse(int x, int y)
{
    int i;
    int j;
    if (board[Y][X]==0)
    {
        for (i=0;i<Y;i++)
            for(j=0;j<X;j++)
                if(y!=sY[i] &x!=sX[i] &&j<X &&i<Y) return 1;
    }

return 0;
}
int checkBoard()
{
	int i;
	int j;
	for (i = 0; i < Y; i++)
		for (j = 0; j < X; j++)
			if (board[i][j] != 0)
				if (checkHorse(i, j) == 0)
					return 0;
	return 1;
}

int hStep(int posX,int posY,int step)
{
    int x;
    int y;
    int i;
    int j;
   // board[posY][posX]=step;
	if (checkBoard() == 0) return 0;
	if (step == HSTEPS + 1) return 1;
	for (i = 0; i < Y; i++)
	//	for (j = 0; j < X; j++)
            {
			if (board[posY][posX] == 0)
            {
                    y=posY+sY[i];
                    x=posX+sX[i];
				board[posY][posX] = step;

			}
			if (checkHorse(y,x)==1 && hStep(y,x,step + 1)==1) return 1;
		}
	return 0;
}
int main(int argc, char *argv[])
{ //Task 1
    int A [N][M];
    int i;
    int j;
    int uChoise=0;
    printf("Press 1 to Task 1 \nPress 2 to Task 2\n___: ");
        scanf("%d",&uChoise);
if (uChoise==1)
{
    for (i=0;i<N;i++)
        for (j=0;j<M;j++)
        {
            if (closeCell(N,M,A)!=0)
            A[i][j]=A[i-1][j-1] + A[i-1][j];
            if (closeCell(N,M,A)==0) A[i][j]=0;
        }
Print(N,M,A);
}

//task 2
 else if (uChoise ==2)
 {
    annull(board);
	hStep(0,0,0);
	printBoard(board);
 }
else printf("Wrong Number!");
   return 0;

}

