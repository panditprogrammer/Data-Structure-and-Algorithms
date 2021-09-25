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

//stack top element
int top_of_stack(struct Stack *stack)
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

    return stack->array[stack->top];

}

//stack bottom element
int bottom_of_stack(struct Stack *stack)
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

    return stack->array[0];

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

//peak  operation
int get_value_at_position(struct Stack *stack, int position)
{
    struct Stack *temp;
    if(stack == NULL)
    {
        printf("Stack Not Initialized yet!\n");
        return -1;
    }

    if(is_stack_empty(stack))
    {
        printf("Stack is Emtpy\n");
        return -1;
    }
    temp = stack;
    if(position <= 0 || stack->capacity-position < 0)
    {
        printf("Invalid Position\n");
        return -1;
    }

    return temp->array[stack->capacity-position];
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
        printf("\n5. Value at Top");
        printf("\n6. Value at Bottom");
        printf("\n7. Peak value at Position");
        printf("\n8. Is Stack Emtpy");
        printf("\n9. Is Stack Full");
        printf("\n10. Exit");
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
            printf("Value of Top of Stack is %d\n",top_of_stack(stack));
            break;
        case 6:
            printf("Value of Bottom of Stack is %d\n",bottom_of_stack(stack));
            break;
        case 7:
            printf("Enter Position to Get Value ");
            scanf("%d",&value);
            printf("Value at Position %d is %d\n",value,get_value_at_position(stack,value));
            break;
        case 8:
            if(is_stack_empty(stack))
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
                break;
        case 9:
            if(is_stack_full(stack))
                printf("Stack is full\n");
            else
                printf("Stack is not full\n");
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid Selection!\n");
            break;
        }
        system("pause");
    }

}
