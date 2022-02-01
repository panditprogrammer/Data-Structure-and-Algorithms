#include <stdio.h>
// insertion sort algorithms

void printArray(int arr[],int len)
{
    for(int i=0; i<len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}


void insertion_sort(int *arr,int len)
{
    int j,temp;
    for(int i=1; i < len;i++) // start with index 1
    {
        temp = arr[i];
        j = i-1;
        while(j >= 0 && temp < arr[j])  // compare with 0 to < i
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;  // if j < 0
    }
}

int main()
{
    int arr[] = {12,54,65,7,89,1};
    int len = 6;
    system("cls");

    printArray(arr,len);
    insertion_sort(arr,len);
    printArray(arr,len);

    system("pause");
    return 0;
}
