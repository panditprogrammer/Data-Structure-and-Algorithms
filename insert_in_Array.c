// insert the value in given position in an array
#include<stdio.h>
int main()
{
    int arr[40]= {23,33,44,55,66};
    int size = 5; // total elements
    int pos = 2;  // insert at
    int value = 999;  // value for insertion
    int i;

//    from last to positon
    for(i=size-1; i>=pos-1; i--)
    {
        arr[i+1]=arr[i];
    }
    // insert the value at blank position
    arr[pos-1]= value;

    printf("after inserting the value\n");

    for(i=0; i<=size; i++)
        printf("%d\n",arr[i]);
    return 0;
}
