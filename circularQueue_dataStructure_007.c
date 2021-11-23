// Circular queue using array
#include <stdio.h>
#include <stdlib.h>

/* NOTE :- one array block should be always
    empty for checking circular queue
    full condition
*/


//structure for queue
struct Circular_Q
{
    int front, rare, size;
    int *array;
};

int isEmpty(struct Circular_Q *q)
{
    if(q->front == q->rare)
        return 1;
    return 0;
}


int isFull(struct Circular_Q *q)
{
    if(q->front == (q->rare + 1) % (q->size))    // rare + 1 is front
        return 1;
    return 0;
}


// enqueue operation
void insert_in_q(struct Circular_Q *q, int data)
{
    if(isFull(q))
    {
        printf("Q is full!\n");
    }
    else
    {
        q->rare = (q->rare +1) % q->size;   // increment rare by 1
        q->array[q->rare] = data;
        printf("inserted in Q %d\n",q->array[q->rare]);
    }
}

// dequeue operation
int delete_from_q(struct Circular_Q *q)
{
    int data = -1;
    if(isEmpty(q))
    {
        printf("Q is Empty!\n");
    }
    else{
            q->front = (q->front +1) % q->size;  // increment front by 1
            data = q->array[q->front];
    }
    printf("deleted data is %d\n",data);
    return data;

}


main()
{
//    queue size for initilizing
    int size = 4;
    system("cls");

    struct Circular_Q c_queue;
    c_queue.front = c_queue.rare = 0;
    c_queue.size = size+1;
    c_queue.array = (int*)malloc(sizeof(int) * c_queue.size);

//
    insert_in_q(&c_queue,40);
    insert_in_q(&c_queue,40);
    insert_in_q(&c_queue,60);
    insert_in_q(&c_queue,60);
    insert_in_q(&c_queue,60);

    delete_from_q(&c_queue);
    delete_from_q(&c_queue);


//
//    if(isFull(&c_queue))
//        printf("Q full\n");
//    if(isEmpty(&c_queue))
//        printf("Q empty\n");


    system("pause");
}
