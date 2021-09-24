//Implementing  Stack using array
#include <stdio.h>
#include <stdlib.h>


//create a stack structure
struct Stack
{
    int capacity;
    int top;
    int *array;
};


//Create Stack
struct Stack* Create_Stack(int capacity)
{
    struct Stack *stack;
    stack = malloc(sizeof(struct Stack)); // create a stack type block
    if(stack == NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(sizeof(int)*capacity);
    return stack;
}


//is full stack
int is_stack_full(struct Stack *stack)
{
    if(stack == NULL)
    {
        printf("Stack is Not Initialized Yet!\n");
        return 0;
    }

    if(stack->top == stack->capacity-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//is stack empty
int is_stack_empty(struct Stack *stack)
{
    if(stack == NULL)
    {
        printf("Stack is Not Initialized Yet!\n");
        return 1;
    }

    if(stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//push element in stack
void push_in_stack(struct Stack *stack, int data)
{
    if(stack == NULL)
    {
        printf("Stack is Not Initialized Yet!\n");
        return;  //only returning control
    }

    if(is_stack_full(stack))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        stack->top++;
        stack->array[stack->top] = data;
    }
}

//stack element pop
int pop_from_stack(struct Stack *stack)
{
    if(stack == NULL)
    {
        printf("Stack is Not Initialized Yet!\n");
        return -1;
    }

    int value;
    if(is_stack_empty(stack))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        value = stack->array[stack->top];
        stack->top--;
        return value;
    }
}

//show stack
struct Stack* show_stack(struct Stack *stack)
{
    if(stack == NULL)
    {
        printf("Stack Not Initialized yet!\n");
        return NULL;
    }
    if(is_stack_empty(stack))
    {
        printf("Stack is Emtpy\n");
        return stack;
    }
    for(int i=0;i<= stack->top;i++)
    {
        printf("%d ",stack->array[i]);
    }
    printf("\n");
    return stack;
}

main()
{
    int sel,value;
    struct Stack *stack = NULL;

    while(1)
    {
        system("cls");
        printf("******** Stack Using Array **********\n");
        printf("\n1. Create Stack");
        printf("\n2. Push In Stack");
        printf("\n3. Pop from Stack");
        printf("\n4. Show Stack");
        printf("\n5. Is Stack Emtpy");
        printf("\n6. Is Stack Full");
        printf("\n7. Exit");
        printf("\n\n  Enter Your Selection ");
        scanf("%d",&sel);

        switch(sel)
        {
        case 1:
            printf("Enter Capacity of Stack ");
            scanf("%d",&value);
            stack = Create_Stack(value);
            break;
        case 2:
            printf("Enter Element ");
            scanf("%d",&value);
            push_in_stack(stack,value);
            break;
        case 3:
            printf("Poped Value is %d\n",pop_from_stack(stack));
            break;
        case 4:
            stack = show_stack(stack);
            break;
        case 5:
            if(is_stack_empty(stack))
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
                break;
        case 6:
            if(is_stack_full(stack))
                printf("Stack is full\n");
            else
                printf("Stack is not full\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Selection!\n");
            break;
        }
        system("pause");
    }

}
