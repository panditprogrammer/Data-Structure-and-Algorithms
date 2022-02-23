// creating a queue data structure using dynamic array
#include <stdio.h>
#include <stdlib.h>


//main structure
struct Queue
{
    int First,Last;
    int capacity;
    int *array;
};

//create queue
struct Queue* create_Queue(int capacity)
{
    struct Queue *queue;
    queue = malloc(sizeof(struct Queue));
//    if memory is not initialize
    if(queue == NULL)
        return NULL;
    queue->capacity = capacity;
    queue->First = -1;   //first element index
    queue->Last = -1;    //last element index
    queue->array = malloc(sizeof(int)*capacity);   //dynamic array
//    if memory is not initialize for array
    if(queue->array == NULL)
        return NULL;
    return queue;

}

//check if the queue is full
int is_queue_full(struct Queue *queue)
{
    if((queue->Last+1)% queue->capacity == queue->First)
        return 1;
    return 0;
}

//check if the queue is empty
int is_queue_empty(struct Queue *queue)
{
    if(queue->First == -1)
        return 1;
    return 0;
}

// number of item in queue
int queue_size(struct Queue *q)
{
    int i=0;
   if(q->First == - 1)
        return i;
    else
    {
        for(i = q->First; i <= q->Last; i++);
        return i;
    }
    //return((queue->capacity - queue->First+queue->Last+1) % queue->capacity);
}


// insert data in queue
void insert_in_queue(struct Queue *queue, int value)
{
    if(is_queue_full(queue))
      {
        printf("cannot insert, Queue is full!\n");
      }
    else
    {
        queue->Last = (queue->Last+1) % queue->capacity;
        queue->array[queue->Last] = value;
        if(queue->First== -1)
            queue->First = queue->Last;

    }
}

//display queue
void display_Queue(struct Queue *q)
{
    if(q->First == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : ");
        for(int i = q->First; i <= q->Last; i++)
            printf("%d .", q->array[i]);
        printf("\n");
    }
    system("pause");
}

// delete data from queue
int delete_from_queue(struct Queue *queue)
{
    int value = -1;
    if(is_queue_empty(queue))
    {
        //printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        value = queue->array[queue->First];
        if(queue->First == queue->Last)
            queue->First = queue->Last = -1;
        else
            queue->First = (queue->First+1) % queue->capacity;
    }
    return value;
}

// delete the queue
void delete_queue(struct Queue *queue)
{
    if(queue)
    {
        if(queue->array)
        {
            free(queue->array);
        }
        free(queue);
    }
}

int main()
{
    int sel=0,data=0,capacity=0;
    struct Queue *Q = NULL;

    void is_Queue_create_(){
        do{
            printf("\n\nTo Initiate Queue \n");
            printf("\nEnter Capacity of Queue ");
            scanf("%d",&capacity);
            Q = create_Queue(capacity);
        }while(Q==NULL);

    }

    while(1)
    {
        if(Q== NULL)
            is_Queue_create_();

        system("cls");
        printf("\n************* Queue DataStructure *************\n");

        printf("\n Queue Capacity is %d\n\n",capacity);
        printf("\n1. Insert");
        printf("\n2. Display Queue");
        printf("\n3. Delete element");
        printf("\n4. Number of elements");
        printf("\n5. Delete Queue");
        printf("\n6. Exit");
        printf("\n\nEnter selection ");
        scanf("%d",&sel);

        switch(sel)
        {
        case 1:
            printf("Enter data ");
            scanf("%d",&data);
            insert_in_queue(Q,data);
            break;
        case 2:
            display_Queue(Q);
            break;
        case 3:
            data = delete_from_queue(Q);
            if(data == -1)
                printf("Can't delete Queue is Empty\n");
            else
                printf("Deleted data is %d\n",data);
            break;
        case 4:
            data = queue_size(Q);
            printf("Total number of elements %d\n",data);
            break;
        case 5:
            delete_queue(Q);
            printf("Queue Deleted\n");
            Q = NULL;
            break;
        case 6:
            exit(0);
        }
        system("pause");
    }



} //end main
