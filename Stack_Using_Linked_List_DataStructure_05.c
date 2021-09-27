// Stack Implementation using Linked List
#include <stdio.h>
#include <stdlib.h>

//create a structure
struct Node
{
    int data;
    struct Node *next;
};

//Create a Node
struct Node* Create_Node()
{
    struct Node *new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node == NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    new_node->next = NULL;  //default value
    new_node->data = 0;  //default value
    return new_node;  // return node address
}

//checking whether stack is empty
int is_empty(struct Node *top_of_stack)
{
    if(top_of_stack == NULL)
        return 1;
    return 0;
}

//push data in stack
struct Node* push_in_stack(struct Node *top_of_stack, int value)
{
    struct Node *temp,*new_node;
    new_node = Create_Node();  // create a new node
    if(new_node == NULL)
    {
        printf("Stack Overflow!\n");
        return NULL;
    }
    if(top_of_stack == NULL)
    {
        top_of_stack = new_node;
        new_node->data = value;
        new_node->next = NULL;
        return top_of_stack;
    }
    else
    {
        temp = top_of_stack;
        top_of_stack = new_node;
        new_node->data = value;
        new_node->next = temp;
        return top_of_stack;
    }
}

//getting value from stack (Pop operation)
struct Node* pop_from_stack(struct Node *top_of_stack)
{
    int value;
    struct Node *temp;
    if(top_of_stack == NULL)
    {
        printf("Can't popped, Stack is Empty!\n");
        return top_of_stack;
    }
    temp = top_of_stack;
    top_of_stack = temp->next;
    value = temp->data;
    free(temp);
    return top_of_stack;

}
// Show Stack
void show_stack(struct Node *top_of_stack)
{
    if(top_of_stack == NULL)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        struct Node *temp ;
        temp = top_of_stack;
        do{
            printf("%d\n",temp->data);
            temp = temp->next;
        }while(temp !=NULL);
    }
}

//count elements in stack
int count_elements(struct Node *top_of_stack)
{
    int count_ele = 0;
    if(top_of_stack == NULL)
    {
        return count_ele;
    }
    struct Node *temp;
    temp = top_of_stack;
    while(temp != NULL)
    {
         temp = temp->next;
         count_ele++;
    }
    return count_ele;
}


//peak data from stack
int peak_data(struct Node *top_of_stack, int position)
{
    struct Node *temp;
    int total_elements = count_elements(top_of_stack);

    if(top_of_stack == NULL)
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    if(position > count_elements(top_of_stack) || position < 1)
    {
        printf("Index is Not Available!\n");
         return -1;
    }

    temp = top_of_stack;
    for(int i = 1; i < position; i++)
            temp = temp->next;   //start of linked list is top_of_stack
    return temp->data;

}



// driver code
main()
{
    int data,sel =0;
    struct Node *stack_top = NULL;
    while(1)
    {
        system("cls");
        printf("-------------- Stack Using Linked List -------------------\n");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peak at Position");
        printf("\n4. Count");
        printf("\n5. Is Empty?");
        printf("\n6. Show Stack");
        printf("\n7. Exit");
        printf("\n\n  Enter your selection ");
        scanf("%d",&sel);

        switch(sel)
        {
        case 1:
            printf("Enter integer data ");
            scanf("%d",&data);
            stack_top = push_in_stack(stack_top,data);
            break;
        case 2:
            stack_top = pop_from_stack(stack_top);
            break;
        case 3:
            printf("Enter position to peak data ");
            scanf("%d",&data);
            printf("Picked Value is %d\n",peak_data(stack_top,data));
            break;
        case 4:
            printf("Total Elements %d\n",count_elements(stack_top));
            break;
        case 5:
            if(is_empty(stack_top))
                printf("Yes! Stack is Empty\n");
            else
                printf("No! Stack is Not Empty\n");
            break;
        case 6:
            show_stack(stack_top);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Selection\n");
            break;

        }
    system("pause");
    }
}
