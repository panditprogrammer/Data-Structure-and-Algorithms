//program to find all permutation of Binary string
#include <stdio.h>
#include <stdlib.h>

//binary string function
void binary(int n,char arr[])
{
    if(n<1)
        printf(" %s\n",arr);
    else
    {
        arr[n-1] = '0';
        binary(n-1,arr);
        arr[n-1] = '1';
        binary(n-1,arr);
    }
}

void main()
{
    char a[5];
    system("cls");
    a[4] = '\0';  //assining null character
    binary(4,a);
    system("pause");


}


