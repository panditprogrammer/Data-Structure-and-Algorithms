//Recursive function to find fibonacci series
#include <stdio.h>
#include <stdlib.h>

long fibonacci(int);

void main()
{
    int N;
    long fib;
    system("cls");
    printf("Enter a number to find fibonacci series upto N ");
    scanf("%d",&N);
    fib = fibonacci(N);
    printf("%dth terms is %d\n",N,fib);

        //printing series of fibonacci upto N
    printf("\nFabonacci Series \n");
    for(int i =1;i<=N;i++)
        printf("%d ",fibonacci(i));
    printf("\n");
    system("pause");
}

//function for fabonacci series
long fibonacci(int n)
{
    if(n==1 || n==2)
        return 1;
    else
        return(fibonacci(n-1)+fibonacci(n-2));
}
