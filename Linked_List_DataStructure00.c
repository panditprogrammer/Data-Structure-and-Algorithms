// (Singly Linked List) Linked List Data Structure
#include <stdio.h>
#include <stdlib.h>
//create a node
struct Node* create_node();
//insert at first in Linked List
struct Node* insert_at_first(struct Node *, int );
//insert after
struct Node* insert_after(struct Node *, int , int );
//insert at last
struct Node* insert_at_last(struct Node *, int );
//travarsal of Linked List
void display_list(struct Node *);
//total number of elements
int number_of_elements(struct Node *);
//Delete first node
struct Node* delete_first(struct Node *);
// Delete last Node
struct Node* delete_last(struct Node *);
// Delete after
struct Node* delete_after(struct Node * , int );




//structure of Linked List
struct Node
{
    int data;
    struct Node *next;
};

//create a node
struct Node* create_node()
{
    struct Node *new_node= NULL;
    new_node = (struct Node*) malloc(sizeof(struct Node));
    if(new_node==NULL)
        printf("Memory Error!\n");
    new_node->data = 0;
    new_node->next = NULL;
    return new_node;
}

//insert at first in Linked List
struct Node* insert_at_first(struct Node *start, int data)
{
    struct Node *new_Node;

    new_Node = create_node();
    new_Node->next = start;
    new_Node->data = data;
    return new_Node;
}

//insert after
struct Node* insert_after(struct Node *start, int data, int index)
{
    struct Node *temp, *new_Node;
    new_Node = create_node();
    temp = start;

    if(index > number_of_elements(start))
    {
        printf("Index not fount!\n");
        return start;
    }

    for(int i=1;i <= index-1;i++)
    {
        temp = temp->next;
    }
    new_Node->data = data;
    new_Node->next = temp->next;
    temp->next = new_Node;
    return start;

}
//insert at last
struct Node* insert_at_last(struct Node *start, int data)
{
    struct Node *temp, *new_node = create_node();
    temp = start;
    if(start==NULL)
    {
        start = insert_at_first(start,data);
        return start;
    }
    while(temp->next !=NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->data = data;
    new_node->next = NULL;
    return start;
}

//travarsal of Linked List
void display_list(struct Node *start)
{
    if(start==NULL)
        printf("Linked List is Empty\n");
    else
    {
        while(start != NULL)
        {
            printf(" %d",start->data);
            start = start->next;
        }
    }
}
//total number of elements
int number_of_elements(struct Node *start)
{
    struct Node *temp;
    int i = 0;
    temp = start;
    if(start == NULL)
        return 0;
    while(temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i+1;
}

//Delete first node
struct Node* delete_first(struct Node *start)
{
    struct Node *temp;

    if(start == NULL)
    {
        printf("Can't Deleted! Linked List Empty\n");
        return NULL;
    }

    temp = start;
    start = start->next;
    free(temp);
    return start;

}

// Delete last Node
struct Node* delete_last(struct Node *start)
{
    struct Node *temp, *delete_temp;
    temp = start;
    if(start == NULL)
    {
        printf("Can't Deleted! Linked List Empty\n");
        return NULL;
    }
    if(start->next== NULL)  //if only one node exist
    {
        start= delete_first(start);
        return start;
    }

    while(temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
    delete_temp = temp->next;
    free(delete_temp);
    return start;
}

// Delete after
struct Node* delete_after(struct Node *start, int index)
{
    struct Node *temp, *temp_next;

    if(start == NULL)
    {
        printf("\nCan't Deleted! Linked List is empty\n");
        return NULL;
    }
    else
    {
        if(index > number_of_elements(start)-1)
        {
            printf("Index not fount!\n");
            return start;
        }
        temp = start;
        temp_next = start->next;
        for(int i=0;i<index-1;i++)
        {
            temp = temp->next;
            temp_next = temp_next->next;
        }
        temp->next = temp_next->next;
        free(temp_next);
        return start;
    }

}



main()
{
    int sel = 0,value = 0, index = 1;
    struct Node *start;   // initial Node pointer
    start =NULL;

   while(1)
   {
       system("cls");

       printf("\n***************** Singly Linked List Data Structure ***********************\n");
       printf("\n1. Insert At First");
       printf("\n2. Insert At Last");
       printf("\n3. Insert After");
       printf("\n4. Display ");
       printf("\n5. Total Elements");
       printf("\n6. Delete First");
       printf("\n7. Delete Last");
       printf("\n8. Delete After");
       printf("\n9. Exit");
       printf("\n\nEnter your selection here ");
       scanf("%d",&sel);

       switch(sel)
       {
           case 1:
               printf("Enter data ");
               scanf("%d",&value);
               start = insert_at_first(start,value);
               break;
           case 2:
               printf("Enter data ");
               scanf("%d",&value);
               start = insert_at_last(start,value);
               break;
           case 3:
               printf("Enter data ");
               scanf("%d",&value);
               printf("Insert After ");
               scanf("%d",&index);
               start = insert_after(start,value,index);
               break;
           case 4:
               display_list(start);
               printf("\n");
               break;
           case 5:
               printf("Total number of Elements %d\n",number_of_elements(start));
               break;
           case 6:
               start = delete_first(start);
               break;
           case 7:
               start = delete_last(start);
               break;
           case 8:
               printf("Delete After ");
               scanf("%d",&index);
               start = delete_after(start,index);
               break;
           case 9:
               exit(0);
           default:
                printf("\nInvalid Input Fount! Try again\n");
                break;

       }
    system("pause");
   }
}
