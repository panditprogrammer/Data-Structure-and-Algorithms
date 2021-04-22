//Recursive function to calculate Greatest common divisor
//using Euclide theorem
#include <stdio.h>
#include <stdlib.h>
int GCD(int ,int);

void main()
{
    int A,B,gcd;
    system("cls");
    printf("Enter two number to find GCD(a,b)");
    scanf("%d,%d",&A,&B);
    gcd = GCD(A,B);
    printf("GCD is %d ",gcd);

    system("pause");
}

int GCD(int a,int b)
{
    if(a==b)
        return a;
    else if(a%b==0)
        return b;
    else if (b%a==0)
        return a;
    else if(a>b)
        return(GCD(a%b,b));
    else
        return(GCD(a,b%a));

}
