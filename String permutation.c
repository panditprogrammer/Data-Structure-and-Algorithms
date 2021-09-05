#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//recursion and backtracking example


void swap_char(char *char1, char *char2)
{
    char ch;

    ch = *char1;
    *char1 = *char2;
    *char2 = ch;
}


void permutation(char *str,int start_index,int string_length)
{
    static int count;

    if(start_index == string_length)
    {
        count++;
        printf("%d. %s,\t",count,str);
    }
    else
    {
        for(int j=start_index;j<= string_length;j++)
        {
            swap_char((str+start_index),(str+j)); //swap the character
            permutation(str,start_index+1,string_length);
            swap_char((str+start_index),(str+j)); // this is called backtracking
        }
    }

}



int main()
{
    char str[20];
    system("cls");

    printf("Finding permutations of given string \n");
    printf("Enter String ");
    gets(str);
    permutation(str,0,strlen(str)-1);

    system("pause");
    return 0;
}
