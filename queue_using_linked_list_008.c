// create queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// front and rare
struct Node *f = NULL;
struct Node *r = NULL;

// insert in queue
void insert_q(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    if (node == NULL)
    {
        printf("queue is full\n"); // memory error
    }
    else
    {
        node->data = data;
        node->next = NULL;
        if (f == NULL) // when queue is empty
        {
            f = r = node ;
        }
        else
        {
            r->next = node; // new node will be rare
            r = node;
        }
    }
}

// show all queue elements
void show_q(struct Node *temp)
{

    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int delete_item()
{
    int data = -1;
    struct Node *temp = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;    // front increment
        data = temp->data;
        free(temp);
    }
    return data;
}

int main()
{
    system("cls");

    insert_q(34);
    insert_q(45);
    insert_q(44);
    insert_q(56);
    insert_q(22);
    show_q(f);
    printf("after deleting \n");
    delete_item();
    delete_item();


    show_q(f);

    system("pause");
}
