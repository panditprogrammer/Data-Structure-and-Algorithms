// queue data structure using array
#include <stdio.h>
#include <stdlib.h>

//structure for queue
struct Queue
{
    int front;
    int rear;
    int *array;
    int size;
};

int isEmptyQ(struct Queue *Q)
{
     if(Q->front == Q->rear)
        return 1;
     return 0;
}

int isFullQ(struct Queue *Q)
{
    if(Q->rear == Q->size -1)
        return 1;
    return 0;
}

// insert in queue
void insert_in_queue(struct Queue *Q, int data)
{
    if(isFullQ(Q))
    {
        printf("Queue is Full!\n");
    }
    else
    {
        Q->rear++;
        Q->array[Q->rear] = data;
    }
}

//delete in queue
int delete_from_queue(struct Queue *Q)
{
    int front = -1;
    if(isEmptyQ(Q))
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        Q->front++;
        front = Q->array[Q->front];
    }
    return front;
}

main()
{
    system("cls");
    // create
    struct Queue Q;
    Q.size = 200;
    Q.front = -1;
    Q.rear = -1;
    Q.array = (int*) malloc(sizeof(int)*Q.size);

    insert_in_queue(&Q,10);
    insert_in_queue(&Q,9);
    printf("deleted element is %d \n",delete_from_queue(&Q));
    printf("deleted element is %d \n",delete_from_queue(&Q));
    if(isFullQ(&Q))
        printf("Q is Full\n");
    if(isEmptyQ(&Q))
        printf("Q is Empty\n");



    system("pause");
}
