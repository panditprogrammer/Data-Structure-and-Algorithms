//program to find permutation of given string
#include <stdio.h>
#include <stdlib.h>
void permutation(char*,int ,int);

void main()
{
    char str[50];
    system("cls");

    printf("Enter String ");
    gets(str);
    permutation(str,0,strlen(str)-1);

    system("pause");
}
//permutation function
void permutation(char *s,int i,int n)
{
    static int count;
    int j;
    if(i==n)
    {
        count++;
        printf("%d %s\n",count,s);
    }
    else
    {
        for(j=i;j<=n;j++)
        {
            swap((s+i),(s+j));
            permutation(s,i+1,n);
            swap((s+i),(s+j)); //this is called backtracking
        }
    }

}

//swapping of two character
void swap(char *c1,char *c2)
{
    char temp;

    temp = *c1;
    *c1 = *c2;
    *c2 = temp;

}
