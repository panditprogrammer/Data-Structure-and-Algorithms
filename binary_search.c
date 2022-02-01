#include <stdio.h>

int binary_search(int arr[],int size,int element)
{
    int lower_index,higher_index,mid_index;
    lower_index =0;
    higher_index = size-1;

    while(lower_index <= higher_index)
    {
        mid_index = (lower_index+higher_index)/2;
        if(arr[mid_index] == element)
            return mid_index;
        if(arr[mid_index] < element)
            lower_index = mid_index+1;    // increase the low_index (half of arr)
        else
            higher_index = mid_index-1;   // decrease the high_index  (half of arr)
    }
    return -1;
}

int main()
{
    int arr[] = {5,18,23,34,41,57,62,77,85,99};
    int size = sizeof(arr)/sizeof(int);
    printf("element found at index %d\n",binary_search(arr,size,34));

    system("pause");
}
