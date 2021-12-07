// delete array element at given index
#include <stdio.h>

int main()
{
    int ar[] = {1,3,5,2,8};
    int index = 2; // index for deletion
    int len = 5; // length of array

    display_array(ar,5);
    delete_fromArray(ar,index,len);
    display_array(ar,5);


}

void display_array(int ar[],int len)
{
    for(int i =0; i<len; i++)
        if(ar[i] != 0)
        printf("%d ",ar[i]);
        printf("\n");
}


void delete_fromArray(int ar[], int del_index, int len)
{
    for(int i=del_index; i <len; i++)
        ar[i] = ar[i+1];
}
