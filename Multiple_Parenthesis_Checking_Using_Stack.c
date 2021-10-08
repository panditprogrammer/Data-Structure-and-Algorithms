#include <stdio.h>
#include <stdlib.h>
//include the stack file
#include "Stack_Using_Array_DataStructureModule.c";

struct Stack *stack = NULL;

int is_brackets_pair(char b1, char b2)
{
    if(b1 == '(' && b2 == ')')
        return 1;
    if(b1 == '{' && b2 == '}')
        return 1;
    if(b1 == '[' && b2 == ']')
        return 1;
    return 0;
}


//checking Multiple parenthesis matching
int parenthesis_match(char *exp)
{
    char popped_character;
    for(int i=0; exp[i]!= '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push_in_stack(stack,exp[i]);

        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(is_stack_empty(stack))
            {
                return 0;
            }
            popped_character = pop_from_stack(stack);
            if(!is_brackets_pair(popped_character,exp[i]))
            return 0;
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
