#include <stdio.h>
#include <math.h>
void solution1();
void solution2();
void solution3();
void solution4();
void solution5();
void solution6();
void solution7();
void solution8();
void solution9();
void solution10();


void menu();
int main()
{
    int sel = 0;
    do
    {
        menu();
        scanf("%i", &sel);
        switch (sel)
        {

        case 1:
            solution1();
            break;
        case 2:
            solution2();
            break;
        case 3:
            solution3();
            break;
        case 4:
            solution4();
            break;
        case 5:
            solution5();
            break;
        case 6:
            solution6();
            break;
        case 7:
            solution7();
            break;
        case 8:
            solution8();
            break;
        case 9:
            solution9();
            break;
        case 10:
            solution10();
            break;
        case 0:
            printf("Bye-bye");
            break;
        default:
            printf("Wrong selected\n");
        }
    }
    while (sel != 0);
    return 0;
}

void solution1()
{
    printf("Solution 1\n");
//1. Ввести вес и рост человека.
// Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.

    int m;
    float h;
    float I;
    printf("\n Enter your Weight, kg: ");
      scanf("%d",&m);
    printf("\n Enter your Height,m: ");
      scanf("%f",&h);

    I=m/((h*h));
    printf("%f\n Yours IMT i: ", I);
        getchar();
}

void solution2()
{
    printf("Solution 2\n");
// 2. Написать программу обмена значениями двух целочисленных переменных:
//      a. с использованием третьей переменной;
//      b. *без использования третьей переменной.

    int a=4;
    int b=21;
//a.с использованием третьей переменной;
// int c=b;
//c=b;
//b=a;
//a=c;

//      b. *без использования третьей переменной.
            // Бинарный метод
        a = a ^ b;
        b = b ^ a;
        a = a ^ b;
            //математический метод
            //a = a + b;
            //b = b - a;
            //b = -b;
            //a = a - b;

}
void solution3()
{
    //3. Написать программу нахождения корней заданного квадратного уравнения.
    printf ("Solution 3\n");

    int a,b,c,D;
    float x1,x2;
    printf ("\n Enter a: ");
      scanf("%d",&a);
    printf ("\n Enter b:");
      scanf("%d",&b);
    printf ("\n Enter c:");
      scanf("%d",&c);
    D=(b*b)-(4*a*c);
   if(D>0 & a!=0)
    {
     x1=(-b+sqrt(D)/(2*a));
     x2=(-b-sqrt(D)/(2*a));
     printf("equation root x1: %f \n ", x1);
     printf(" equation root x2: %f \n",x2);
    }

    else if (D==0)
    {
     x1=-b/(2*a);
     printf("\n%d equation root x= ",x1);
    }
    else printf("\n no equation roots!\n");

}
void solution4()
{
    int m=0;
    printf("Enter a number of Month: ");
    scanf("%d", &m);

        if (m==12 & m<=2 & m!=0) printf("Winter");
        if (m>2 & m<=3 & m!=0) printf ("Spring");
        if (m==12 & m<=3 & m!=0) printf ("Summer");
        if ((m==12 & m<=3 & m!=0) printf ("Autumn");
}
void solution5()
{
   // 5. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
    printf("Solution 5\n");

    int age;
    printf("Enter yours Age: \n");
    scanf("%d",&age);

    if (age %10 ==1) printf("Vam %d god",age );
    if(age>=10 & age<=20 | age%10==0 | age%10>=5 & age%10<=9) printf("Vam %d Let", age);
    if(age%10>=2 & age%10<=4) printf("Vam %d Goda", age);

}
void solution6()
{

   //6. *С клавиатуры вводятся числовые координаты двух полей шахматной
    // доски (x1,y1,x2,y2). Требуется определить, относятся ли к поля к одному цвету или нет.
    printf("Solution 6\n");
    struct Point
{
    int x;
    int y;
};
	struct Point p1;
	struct Point p2;
	int value;
printf("Point 1 (enter number from 1 to 8) ");
        printf("Enter x: ");
        scanf("%d", &p1.x);
        printf("Enter y: : ");
        scanf("%d", &p1.y);
        printf("Point 2 (enter number from 1 to 8) ");
        printf("Enter  x: : ");
        scanf("%d", &p2.x);
        printf("Enter y: : ");
        scanf("%d", &p2.y);
        value=p1.x+p1.y+p2.x+p2.y;
	if (value%2==0)
    {
        printf ("\tyes same color\n\n");
    }
	else printf("\tnot same color\n\n");
}

void solution7()
{
    //    7. Даны целые положительные числа N и K.
    //      Используя только операции сложения и вычитания, найти частное от деления нацело N на K,
    //      а также остаток от этого деления.

    int N,K;
    int i=0;
    printf("Solution 7\n");
    printf("\nEnter N: ");
      scanf("%d",&N);
    printf("\n Enter K: ");
      scanf("%d",&K);
    do
    {
        N=N-K;
        i++;
    }
    while (N-K>=0);
    printf("the quotient of %d\n",i);
    printf("remainder of division %d\n",N);
}
void solution8()
{
    //8. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить,
    //имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
    printf("Solution 8\n");

    int N;
    int t=0;

    printf("Enter N: ");
    scanf("%d",&N);
    do
    {
        if ((N%10)%2==0)
        {
           t=1;
        }
        N=N/10;
    }
    while (N!=0);
    if (t==1) printf("true");
    else printf("false");
}
void solution9()
{
  //  9. * Написать функцию, генерирующую случайное число от 1 до 100. без использования стандартной функции rand()
    printf("Solution 9\n");
    int x, a, b, m;
    m = 100;
    b = 5;
    a = 5;
    int i;
    int modulus = 100;
    for (i = 0; i < modulus; i++)
    {
      x = (a * x + b) % m;
    }
    printf("%d ", x);
}
void solution10()
{
    // Автоморфные числа - Не готово.

    printf("Solution 10\n");
    int d=10;
    int x;
    do
  {
      for (x=0; x<100;x++)
     if ((x*x)%d==x ) printf ("%d \t", x );
  }
  while (x<100);
}
void menu()
{
    printf("\n\tPlease select Task\n");
    printf("\t1 - task1\n");
    printf("\t2 - task2\n");
    printf("\t3 - task3\n");
    printf("\t4 - task4\n");
    printf("\t5 - task5\n");
    printf("\t6 - task6\n");
    printf("\t7 - task7\n");
    printf("\t8 - task8\n");
    printf("\t9 - task9\n");
    printf("\t10 - task10\n");

    printf("\t0 - exit\n");
}


