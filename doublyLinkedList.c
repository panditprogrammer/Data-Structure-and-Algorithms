#include <stdio.h>

/*
all functions used in these doubly linked list
*/
struct Node* CreateNode(int);
struct Node* insertAtFirst(struct Node*,int);
struct Node* insertAtLast(struct Node*,int);
struct Node* insertAtIndex(struct Node *,int,int);
struct Node* deleteFromFirst(struct Node *);
struct Node* deleteFromLast(struct Node *);
struct Node* deleteFrom(struct Node *,int);
void showDLL(struct Node*);
int getLen(struct Node*);



//main function
main()
{
    system("cls");

    struct Node *start = NULL;

    start = insertAtLast(start,50);
    start = insertAtLast(start,60);
    start = insertAtLast(start,70);
    start = insertAtLast(start,12);
    start = insertAtLast(start,80);

    start = insertAtFirst(start,66);
    start = insertAtFirst(start,36);
    start = insertAtFirst(start,87);
    start = insertAtFirst(start,875);

    start = insertAtIndex(start,100,3);

    showDLL(start);

    start = deleteFrom(start,5);

    showDLL(start);

    system("pause");
}


//structure for DLL
struct Node
{
    int data;
    struct Node *next,*prev;
};

//create a node
struct Node* CreateNode(int data)
{
    struct Node *node;
    node = (struct Node*) malloc(sizeof(struct Node ));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

//insertion at first in doubly linked list
struct Node* insertAtFirst(struct Node *start,int data)
{
    if(start == NULL)
    {
        start = CreateNode(data);
        return start;
    }
    else
    {
        struct Node *temp = start;
        struct Node *newNode = CreateNode(data);
        temp = start;
        start = newNode;
        newNode->prev = NULL;
        temp->prev = newNode;
        newNode->next  = temp;

        return start;
    }
}


//insertion at last in doubly linked list
struct Node* insertAtLast(struct Node *start,int data)
{
    if(start == NULL)
    {
        start = CreateNode(data);
        return start;
    }
    else
    {
        struct Node *temp = start;
        struct Node *newNode = CreateNode(data);

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    return start;

}

//insertion at index in doubly linked list
struct Node* insertAtIndex(struct Node *start,int data,int index)
{

    if(start == NULL || index == 0)
    {
        start = insertAtFirst(start,data);
        return start;
    }

    if(index > getLen(start)-1 || index < 0)
    {
        printf("Invalid index\n");
        return start;
    }

    struct Node *tempS = start;
    struct Node *newNode = CreateNode(data);

    while(index)
    {
        tempS = tempS->next;
        index--;
    }

    tempS->prev->next = newNode;
    tempS->prev = newNode;
    newNode->prev = tempS->prev;
    newNode->next = tempS;

    return start;
}

//delete from first
struct Node* deleteFromFirst(struct Node *start)
{
    struct Node *temp = start;
    start = start->next;
    start->next->prev = NULL;
    free(temp);
    return start;
};

//delete from last
struct Node* deleteFromLast(struct Node *start)
{
    struct Node *temp = start;
    while(temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return start;
};


//deletion in doubly linked list
struct Node* deleteFrom(struct Node *start,int index)
{
    if(start == NULL)
        return NULL;

    if(index < 0 || index >=getLen(start))
    {
        printf("Invalid index\n");
        return start;
    }

    if(index == 0)
    {
        start = deleteFromFirst(start);
        return start;
    }

    if(index == getLen(start)-1)
    {
        start = deleteFromLast(start);
        return start;
    }

    struct Node *tempS = start;
    while(index)
    {
        tempS = tempS->next;
        index--;
    }

    tempS->prev->next = tempS->next;
    tempS->next->prev = tempS->prev;
    free(tempS);
    return start;
}

//show the DLL
void showDLL(struct Node* start)
{
    if(start == NULL)
    {
        printf("Nothing to show!\n");
    }
    else
    {
        struct Node *temp = start;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

//get the length of DLL
int getLen(struct Node* start)
{
    int count = 0;
    if(start == NULL)
        return count;

    struct Node *temp = start;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;

}

