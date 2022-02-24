//create a stack in c language using array
#include <stdio.h>
#include <stdlib.h>

//stack structure
struct Array_stack
{
    int capacity;
    int top_of_stack;
    int *array_pointer;
};

//function for create a stack
struct Array_stack* create_stack(int cap)
{
    struct Array_stack *stack_pointer;
    stack_pointer = malloc(sizeof(struct Array_stack));
    stack_pointer->capacity = cap;
    stack_pointer->top_of_stack = -1;
    stack_pointer->array_pointer = malloc(sizeof(int)*cap);
    return stack_pointer;

}

//checking if the stack is full
int is_stack_full(struct Array_stack *stack_pointer)
{
    if(stack_pointer->top_of_stack == stack_pointer->capacity -1)
        return 1;
    return 0;
}

//checking if the stack is empty
int is_stack_empty(struct Array_stack *stack_pointer)
{
    if(stack_pointer->top_of_stack == -1)
        return 1;
    return 0;
}

//push in stack
void push_in_stack(struct Array_stack *stack_pointer, int value)
{
    if(is_stack_full(stack_pointer))
    {
        printf("Stack is full");
    }
    else
    {
        stack_pointer->top_of_stack++;
        stack_pointer->array_pointer[stack_pointer->top_of_stack] = value;
    }
}

//pop from stack
int pop_from_stack(struct Array_stack *stack_pointer)
{
    int data;
    if(is_stack_empty(stack_pointer))
    {
            return -1;
    }
    else
    {
        data = stack_pointer->array_pointer[stack_pointer->top_of_stack];
        stack_pointer->top_of_stack--;
        return data;
    }

}


main()
{
    int data;
    struct Array_stack *stack_pointer;

    stack_pointer = create_stack(5);

   while(1)
   {
       system("cls");
       printf("\n1. push");
       printf("\n2. pop");
       printf("\n3. Exit");
        printf("Enter  ");
        scanf("%d",&data);
        switch(data)
        {
        case 1:
            printf("Enter a value for stack ");
            scanf("%d",&data);
            push_in_stack(stack_pointer,data);
            break;
        case 2:
            data = pop_from_stack(stack_pointer);
            if(data == -1)
            {
                printf("stack is empty\n");
            }
            else
            {
                printf("pop value is %d\n",data);
            }
            break;

        case 3:
            exit(0);
        }
        system("pause");
   }

}



