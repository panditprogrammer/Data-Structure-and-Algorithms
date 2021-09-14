// Doubly Linked List DataStructure
#include <stdio.h>
#include <stdlib.h>

//Node structure
struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
};

//create new node
struct Node* Create_node()
{
    struct Node *new_node;
    new_node = (struct Node*) malloc(sizeof(struct Node));

    if(new_node==NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    new_node->data = 0;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

//insert at first
struct Node* Insert_at_first(struct Node *start, int data)
{
    struct Node *new_node;
    new_node = Create_node();
    if(start == NULL)
    {
        start = new_node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->previous = NULL;
        return start;
    }

    new_node->data = data;
    start->previous = new_node;
    new_node->next = start;
    start = new_node;
    return start;
}

//insert data at last
struct Node* Insert_at_last(struct Node *start, int data)
{
    struct Node *temp;
    struct Node *new_node;

    if(start == NULL)
    {
        start = Insert_at_first(start,data);
        return start;
    }

    new_node = Create_node();
    temp = start;
    while(temp->next != NULL)
        temp = temp->next;

    new_node->data = data;
    temp->next = new_node;
    new_node->previous = temp;
    new_node->next = NULL;
    return start;
}

// insert after index
struct Node* Insert_After(struct Node *start, int data, int index)
{
    struct Node *new_node;
    struct Node *temp, *temp_n;

    if(start==NULL)
    {
        start = Insert_at_first(start,data);
        return start;
    }
//    checking valid index
    if(index > Count_item(start) || index <= 0)
    {
        printf("Invalid Index!\n");
        return start;
    }
    new_node = Create_node();
    temp = start;
    temp_n = start->next;
    for(int i=1;i<=index-1;i++)
    {
        temp = temp->next;
        temp_n = temp_n->next;
    }
    if(temp->next==NULL)
    {
        start = Insert_at_last(start,data);
        return start;
    }

    new_node->data = data;
    new_node->next = temp->next;
    new_node->previous = temp;
    temp->next = new_node;
    new_node->next->previous = new_node;
    return start;
}

// display D-Linked List left to right
void display_LTR(struct Node *start)
{
    struct Node *temp;
    if(start == NULL)
    {
        printf("D-Linked List is Empty!\n");
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
            printf("\n");
    }
}

//display D-linked list right to left
void display_RTL(struct Node *start)
{
    struct Node *temp;
    if(start == NULL)
    {
        printf("D-Linked List is Empty!\n");
    }
    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        do{
            printf("%d ",temp->data);
            temp = temp->previous;
        }while(temp != NULL);
        printf("\n");
    }
}

//count elements in list
int Count_item(struct Node *start)
{
    struct Node *temp;
    int i=0;
    if(start == NULL)
    {
        return i;
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            i++;
            temp = temp->next;
        }
        return i;
    }
}

int find_data(struct Node *start, int data)
{
    if(start == NULL)
    {
        printf("D-Linked List is Empty\n");
        return 0;
    }
    struct Node *temp;
    temp = start;
    while(temp != NULL)
    {
        if(temp->data == data) //checking data
            return 1;
        temp = temp->next;
    }
    return 0;
}
//delete from first
struct Node* Delete_from_first(struct Node *start)
{
    struct Node *temp;
    if(start == NULL)
    {
        printf("Can't deleted! D-Linked List is Empty!\n");
        return NULL;
    }
    temp = start;
//    for first node
    if(temp->next == NULL)
    {
        start = NULL;
        free(temp);
        return start;
    }

    start = start->next;
    start->previous = NULL;
    free(temp);
    return start;
}

//delete from last
struct Node* Delete_from_last(struct Node *start)
{
    struct Node *temp;
    if(start == NULL)
    {
        printf("Can't deleted! D-Linked List is Empty!\n");
        return start;
    }
    temp = start;
    if(temp->next ==NULL)
    {
        start = NULL;
        free(temp);
        return start;
    }
//    go to last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->previous->next = NULL;
    free(temp);
    return start;
}

//delete node by index
struct Node* Delete_after(struct Node *start, int index)
{
    struct Node *temp, *temp_del;
    if(start==NULL)
    {
        printf("Can't Deleted! D-Linked List is Empty\n");
        return start;
    }

    if(index >= Count_item(start) || index <=0)
    {
        printf("Invalid Index!\n");
        return start;
    }
    temp = start;
    temp_del = start->next;
    for(int i=1;i <= index-1;i++)
    {
        temp = temp->next;
        temp_del = temp_del->next;
    }
    // deleting last node
    if(temp->next->next ==NULL)
    {
        start = Delete_from_last(start);
        return start;
    }

    temp->next = temp_del->next;
    temp_del->next->previous = temp;
    free(temp_del);
    return start;

}

main()
{
    int data =0,sel = 0,index =0;
    struct Node *start = NULL;
    start = Create_node();

    while(1)
    {
    system("cls");
        printf("=============== Doubly-Linked_List DataStructure ==============\n");
        printf("\n 1.   Insert At First");
        printf("\n 2.   Insert After");
        printf("\n 3.   Insert At Last");
        printf("\n 4.   Display Left To Right");
        printf("\n 5.   Display Right To Left");
        printf("\n 6.   Total Items");
        printf("\n 7.   Search Data");
        printf("\n 8.   Delete From First");
        printf("\n 9.   Delete After");
        printf("\n 10.  Delete From Last");
        printf("\n 11.  Exit");
        printf("\n\nEnter selection ");
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
            printf("Enter index ");
            scanf("%d",&index);
            start = Insert_After(start,data,index);
            break;
        case 3:
            printf("Enter data ");
            scanf("%d",&data);
            start = Insert_at_last(start,data);
            break;
        case 4:
            printf("\n");
            display_LTR(start);
            break;
        case 5:
            printf("\n");
            display_RTL(start);
            break;
        case 6:
            printf("Total number of items %d\n",Count_item(start));
            break;
        case 7:
            printf("Enter data to search ");
            scanf("%d",&data);
            if(find_data(start,data) ==1)
                printf("Data is Available\n");
            else
                printf("Data is Not Available\n");
            break;
        case 8:
            start = Delete_from_first(start);
            break;
        case 9:
            printf("Enter index to delete ");
            scanf("%d",&index);
            start = Delete_after(start,index);
            break;
        case 10:
            start = Delete_from_last(start);
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid selection!\n");
        }
    system("pause");
    }

}
