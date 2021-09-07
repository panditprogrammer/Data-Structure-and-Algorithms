// Circular Linked List  operations Insert, Delete, Traverse
#include <stdio.h>
#include <stdlib.h>

//structure for node
struct Node
{
    int data;
    struct Node *next;
};


//Create Node
struct Node* Create_Node()
{
    struct Node *new_node;
    new_node = (struct Node*) malloc(sizeof(struct Node));

    if(new_node==NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    else
    {   // set default value
        new_node->data = 0;
        new_node->next = NULL;
        return new_node;
    }
}

//Insert At First
struct Node* Insert_at_first(struct Node *start, int data)
{
    struct Node *new_node = Create_Node();
    struct Node *temp;

    if(start==NULL)  //if list is empty
    {
        new_node->data = data;
        new_node->next = new_node;
        start = new_node;
        return start;
    }
    else
    {
        temp = start->next;
        while(temp->next != start)
            temp = temp->next;  //goto last node next pointer

        temp->next = new_node;
        new_node->data = data;
        new_node->next = start;
        start = new_node;      //start will be new node
        return start;
    }

}

//Insert At Last
struct Node* insert_at_last(struct Node *start, int data)
{
    struct Node *new_node = Create_Node();

    if(start == NULL) // if list is empty
    {
        start = Insert_at_first(start,data);
        return start;
    }
    else
    {
        struct Node *temp;
        temp = start;
        while(temp->next != start)  //go to last
            temp = temp->next;

        temp->next = new_node;
        new_node->data = data;
        new_node->next = start;
        return start;

    }

}

//Display the Circular Linked List
void Display_C_list(struct Node *start)
{
    struct Node *temp = start;
    if(start == NULL)
    {
        printf("Circular Linked List is Empty\n");
    }
    else
    {
        printf("Circular Linked List is \n");
        do
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }while(temp != start);
    }
    printf("\n");
}

//Count Elements in List
int Number_of_Elements(start)
{
    struct Node *temp = start;
    int i = 0;
    if(start == NULL)  //if list is empty
    {
        return i;
    }

    while(temp->next != start)
    {
        temp = temp->next;
        i++;
    }
    return i+1;
}

//Insert After index
struct Node* Insert_After(struct Node *start, int data, int index)
{
    struct Node *new_node = Create_Node();
    //checking valid index
    if(Number_of_Elements(start) < index || index <= 0)
    {
        printf("Index Not Found!\n");
        return start;
    }
//    if List is empty
    if(start == NULL)
    {
        start = Insert_at_first(start,data);
        return start;
    }
    else
    {
        struct Node *temp = start, *temp_next;
//        goto index
        for(int i=0;i< index-1;i++)
        {
            temp = temp->next;
        }
        temp_next = temp->next;
        temp->next = new_node;
        new_node->next = temp_next;
        new_node->data = data;
        return start;
    }

}

//delete first
struct Node* delete_first(struct Node *start)
{
    struct Node *temp = start;
    if(start == NULL)
    {
        printf("Can't Deleted! Linked List is Empty\n");
        return start;
    }
    //if node has only one
    if(start->next == start)
    {
        free(start);
        start = NULL;
        return start;
    }

    while(temp->next != start)
        temp = temp->next;   //last node next pointer
    temp->next = start->next;
    temp = start;
    start = start->next;
    return start;

}

//delete Last
struct Node* delete_last(struct Node *start)
{
    struct Node *temp, *first_temp;
    if(start == NULL)
    {
        printf("Can't Deleted! Linked List is Empty\n");
        return start;
    }
    //if node has only one
    if(start->next == start)
    {
        temp = start;
        free(temp);
        start = NULL;
        return start;
    }
    temp = start->next;
    first_temp = start;
    while(temp->next != start)
    {
        temp = temp->next;  //last node next pointer
        first_temp = first_temp->next;
    }
    first_temp->next = start;
    free(temp);
    printf("Last Node Deleted!\n");
    return start;

}

//delete after
struct Node* delete_after(struct Node *start, int index)
{
    struct Node *temp,*temp_next;

//    if index is greater than equal number of elements
    if(index >= Number_of_Elements(start) || index <= 0)
    {
        printf("Index is not availabe!\n");
        return start;
    }

    if(start == NULL)
    {
        printf("Can't Deleted! Linked List is Empty\n");
        return start;
    }
    temp = start;
    temp_next = start->next;
    for(int i=0;i<=index;i++)
    {
        temp = temp->next;   //goto index
        temp_next = temp_next->next;
    }
    temp->next = temp_next->next;
    free(temp_next);
    return start;


}

 main()
{
    struct Node *start = NULL;
    int data = 0,sel = 0, number = 0;

    while(1)
    {
        system("cls");
        printf("********Circular Linked List Operations ********\n\n");
        printf("\n 1. Insert At First");
        printf("\n 2. Insert At Last");
        printf("\n 3. Insert After");
        printf("\n 4. Delete First");
        printf("\n 5. Delete Last");
        printf("\n 6. Delete After");
        printf("\n 7. Total Elements");
        printf("\n 8. Print List");
        printf("\n 9. Exit\n");
        printf("\n Enter Your Selection ");
        scanf("%d",&sel);

        switch(sel)
        {
        case 1:
            printf("Enter data ");
            scanf("%d",&data);
            start = Insert_at_first(start,data);
            break;
        case 2:
            printf("Enter data ");
            scanf("%d",&data);
            start = insert_at_last(start,data);
            break;
        case 3:
            printf("Enter data ");
            scanf("%d",&data);
            printf("Enter index ");
            scanf("%d",&number);
            start = Insert_After(start,data,number);
            break;
        case 4:
            start = delete_first(start);
            break;
        case 5:
            start = delete_last(start);
            break;
        case 6:
            printf("Enter index ");
            scanf("%d",&number);
            start = delete_after(start,number);
            break;
        case 7:
            printf("Total Elements %d\n",Number_of_Elements(start));
            break;
        case 8:
            Display_C_list(start);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid selection\n");
            break;
        }

        system("pause");

    }

}
