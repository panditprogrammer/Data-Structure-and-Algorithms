//Implementing  Stack using array



//create a stack structure
struct Stack
{
    int capacity;
    int top;
    char *array;
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
    stack->array = (char*)malloc(sizeof(char)*capacity);
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
void push_in_stack(struct Stack *stack, char data)
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
char pop_from_stack(struct Stack *stack)
{
    if(stack == NULL)
    {
        printf("Stack is Not Initialized Yet!\n");
        return -1;
    }

    char value;
    if(is_stack_empty(stack))
    {
        printf("Stack Underflow!\n");
        return NULL;
    }
    else
    {
        value = stack->array[stack->top];
        stack->top--;
        return value;
    }
}

//stack top element
char top_of_stack(struct Stack *stack)
{
    if(stack == NULL)
    {
        printf("Stack is Not Initialized Yet!\n");
        return -1;
    }

    char value;
    if(is_stack_empty(stack))
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    return stack->array[stack->top];

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
        printf("%c ",stack->array[i]);
    }
    printf("\n");
    return stack;
}


//stack bottom element
char bottom_of_stack(struct Stack *stack)
{
    if(stack == NULL)
    {
        printf("Stack is Not Initialized Yet!\n");
        return -1;
    }

    char value;
    if(is_stack_empty(stack))
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    return stack->array[0];

}







