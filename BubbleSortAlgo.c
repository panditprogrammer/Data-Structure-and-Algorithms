#include <stdio.h>
// sorting algo
void bubbleSortAlgo(int ar[], int lenght)
{
    for(int i = 0; i< lenght-1; i++)  // number of passes
    {
        for(int j= 0; j< lenght-1-i; j++)  // number of comparision
        {
            if(ar[j] > ar[j+1])
            {
                // swap the number
                int temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }
}

// print array lenght
void printAr(int ar[],int lenght)
{
    for(int i =0; i<lenght; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
}
// get the array lenght
int getArrayLength(int ar[])
{
    int i = 0;
    while(ar[i] != 0)
    {
        i ++;
    }
    return i-1;
}

main()
{
    int ar[] = {12,83,82,98,22,93,48,5,36};

    int lenght = getArrayLength(ar);
    printAr(ar,lenght);
    bubbleSortAlgo(ar,lenght);
    printAr(ar,lenght);

}
