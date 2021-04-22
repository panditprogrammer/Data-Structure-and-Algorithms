//Recursive function for calculate factorial of a number
#include <stdio.h>
#include <stdlib.h>
long fact(int);

void main()
{
    int n;
    long factorial;
    system("cls");

    printf("Enter a number to calculate factorial ");
    scanf("%d",&n);
    factorial = fact(n);
    printf("Factorial of %d is %ld \n",n,factorial);


    system("pause");
}

//factorial function
long fact(int N)
{
    if(N>0)
        return(N*(fact(N-1)));
    else
        return (1);
}
