#include <stdio.h>
//get the minimum value from an array

int getMin(int arr[],int size)
{
    int min = arr[0];
    for(int i=1; i<size; i++)
        if(min > arr[i])
            min = arr[i];
    return min;
}

//get the maximum value from an array
int getMax(int arr[],int size)
{
    int max = arr[0];
    for(int i=1; i<size; i++)
        if(max < arr[i])
            max = arr[i];
    return max;
}

main()
{
    int arr[] = {10,8,128,45,82,7,12,25};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d \n",getMin(arr,size));
    printf("%d \n",getMax(arr,size));
}
