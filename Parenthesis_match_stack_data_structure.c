#include <stdio.h>
#include <stdlib.h>
//include the stack file
#include "Stack_Using_Array_DataStructureModule.c";

struct Stack *stack = NULL;

//checking parenthesis matching
int parenthesis_match(char *exp)
{
    for(int i=0; exp[i]!= '\0'; i++)
    {
        if(exp[i] == '(')
        {
            push_in_stack(stack,'(');

        }
        else if(exp[i] == ')')
        {
            if(is_stack_empty(stack))
            {
                return 0;
            }
            pop_from_stack(stack);
        }
    }
    if(is_stack_empty(stack))
            return 1;
        return 0;
}

main()
{
    char expression[50];  //array for taking input
    stack = Create_Stack(30);
    system("cls");
    printf("Enter expression ");
    gets(expression);
    printf("%s",expression);

    if(parenthesis_match(expression))
        printf("\nParenthesis is Matching\n");
    else
        printf("\nParenthesis is Not Matching\n");

    system("pause");
}
