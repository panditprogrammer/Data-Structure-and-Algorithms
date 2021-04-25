//Stack Data Structure through c language array
#include <stdio.h>
#include <stdlib.h>

//create a structure for stack

struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

//function for create stack
struct ArrayStack* createStack(int capacity)
{
//    array stack pointer
    struct ArrayStack *stack;

//    assigning address to the stack pointer
    stack = malloc(sizeof(struct ArrayStack));

//    assigning capacity of ArrayStack
    stack->capacity = capacity;

//    assigning value at the top of ArrayStack
//    this is initial value
    stack->top = -1;

//    create an array for the ArrayStack
//    it will create an array with capacity of blocks
    stack->array = malloc(sizeof(struct ArrayStack)*stack->capacity);

//    returning final created ArrayStack address
    return stack;
}

//checking Stack is full
int is_stack_full( struct ArrayStack *stack)
{
//        checking value of top of stack and capacity of stack is eqal
    if(stack->top == stack->capacity-1)
        return 1; //true
    else
        return 0; //false

}

//checking stack is emtpy
int is_stack_empty(struct ArrayStack *stack)
{
    //checking default top value is available
    if(stack->top == -1)
        return 1;
    else
        return 0;
}


//push the element in arraystack
void push(struct ArrayStack *stack ,int item)
{
    if(!is_stack_full(stack))
    {
        stack->top++;
        stack->array[stack->top] = item;
    }
    else
    {
        printf("Array Stack is full\n");
    }

}

//getting value from stack
int pop(struct ArrayStack *stack)
{
    int item;
    if(!is_stack_empty(stack))
    {
        item = stack->array[stack->top];
        stack->top--;
        return item;
    }
    else
    {
        return -1;
    }
}




void main()
{
    struct ArrayStack *stack;
    int sel;
    int item;

    //create a stack
    stack = createStack(4);

    //menu driven program
    while(1)
    {
        system("cls");
        printf("\nData Structure Stack\n\n1. Push\n2. Pop\n3. Exit\n");
        printf("Enter your Choice ");
        scanf("%d",&sel);

        switch(sel)
        {
        case 1:
            printf("Enter a number ");
            scanf("%d",&item);
            push(stack,item);
            break;
        case 2:
            item = pop(stack);
            if(item != -1)
            printf("Pop value is %d\n",item);
            else
                printf("Array Stack is Empty\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;

        }
        system("pause");
    }

}
