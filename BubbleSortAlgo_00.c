#include <stdio.h>
// bubble sort algorithms

main()
{
    int ar[] = {34,11,4,56,78,9,15,29,8};
    int length = 9;

    bubbleSort(ar,length);
    // print
    for(int i =0; i<length; i++)
        printf("%d\n",ar[i]);
}

void bubbleSort(int ar[], int len)
{
    int round,i,temp;

    for(round=1; round <= len-1; round++) // round
        for(int i=0; i <= len-1-round; i++)
            //swap
            if(ar[i]> ar[i+1])
            {
                temp = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = temp;
            }

}
