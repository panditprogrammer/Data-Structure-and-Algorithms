//Array - Abstract Data Type
#include <stdio.h>
#include <stdlib.h>

//structure for ADT
struct Array_ADT
{
    int capacity;  // array capacity
    int element_last_index;   //last index of array's element
    int *array_ptr;
};

//Create An Array
struct Array_ADT* Create_array(int capacity)
{
    if(capacity <= 0)
    {
        printf("Invalid Capacity!\n");
        return NULL;
    }
    struct Array_ADT *array_adt;
    array_adt = (struct Array_ADT*) malloc(sizeof(struct Array_ADT));  // create structure variable
    if(array_adt==NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    array_adt->array_ptr = (int*)malloc(sizeof(int)*capacity); // create array
    array_adt->capacity = capacity;
    array_adt->element_last_index = -1;    // -1 indicates empty
    return array_adt;
}

//Insert Element
struct Array_ADT* Insert_element(struct Array_ADT *a_adt, int element)
{
    if(a_adt==NULL)
    {
        printf("Array Not Initilized Yet!\n");
        return NULL;
    }
    if(a_adt->element_last_index >= a_adt->capacity-1)
    {
        printf("Can't Inserted! Array is full\n");
        return a_adt;
    }
    a_adt->element_last_index++;
    a_adt->array_ptr[a_adt->element_last_index] = element;
    return a_adt;
}

//Replace element at index
struct Array_ADT* replace_at(struct Array_ADT *adt, int element, int index)
{
    if(adt==NULL)
    {
        printf("Array Not Initialized Yet!\n");
        return NULL;
    }
    int i;
    if(adt->element_last_index == -1)
    {
        Insert_element(adt,element);
        return adt;
    }
    else
    {
        if(index > adt->element_last_index || index < 0)
        {
            printf("Invalid index!\n");
            return adt;
        }
        for(i=0;i<index;i++);
        adt->array_ptr[i] = element;
        return adt;
    }

}

//get element from array
int get_element(struct Array_ADT *adt, int index)
{
    if(adt==NULL)
    {
        printf("Array Not Initialized Yet!\n");
        return NULL;
    }
    int i;
    if(adt->element_last_index == -1)
    {
        printf("Array is Empty!\n");
        return NULL;
    }
    if(index > adt->element_last_index || index < 0)
    {
        printf("Invalid Index!\n");
        return NULL;
    }
    for(i=0;i<index;i++); //0, 1, 2, 3
    return adt->array_ptr[i];
}

//number of array elements
int get_count(struct Array_ADT *adt)
{
    if(adt==NULL)
    {
        printf("Array Not Initialized Yet!\n");
        return NULL;
    }
    int i;
    if(adt->element_last_index == -1)
        return 0;
    for(i=0;i<=adt->element_last_index;i++);
    return i;
}
//Delete element from array
struct Array_ADT* Delete_element(struct Array_ADT *adt)
{
    if(adt==NULL)
    {
        printf("Array Not Initialized Yet!\n");
        return NULL;
    }
    if(adt->element_last_index == -1)
    {
        printf("Can't Deleted! Array is Empty\n");
        return adt;
    }
    adt->element_last_index = adt->element_last_index-1;
    return adt;

}

struct Array_ADT* Delete_at(struct Array_ADT *adt, int index)
{
    if(adt==NULL)
    {
        printf("Array Not Initialized Yet!\n");
        return NULL;
    }
    int i;
    if(adt->element_last_index == -1)
    {
        printf("Can't Deleted! Array is Empty\n");
        return adt;
    }
    if(index > adt->element_last_index || index < 0)
    {
        printf("Index is Invalid\n");
        return adt;
    }
    for(i = 0; i< index;i++);   //got to index

    for(int j = 0;j<= adt->element_last_index;j++)
    {
        adt->array_ptr[i+j] = adt->array_ptr[i+j+1];
    }
    adt->element_last_index = adt->element_last_index-1;
    return adt;

}

//delete array
struct Array_ADT* Delete_Array(struct Array_ADT *adt)
{
    if(adt == NULL)
    {
        printf("Array Not Initilized Yet!\n");
        return NULL;
    }
    free(adt->array_ptr);
    return NULL;

}

//find data in array
int Find(struct Array_ADT *adt, int data)
{
    if(adt == NULL)
    {
        printf("Array Not Initilized Yet!\n");
        return NULL;
    }
    if(adt->element_last_index == -1)
    {
        printf("Array is Empty\n");
        return 0;
    }
    for(int i=0;i<=adt->element_last_index;i++)
    {
        if(adt->array_ptr[i] == data)
        return 1;
    }
    return 0;

}

//Show array
void Show_array(struct Array_ADT *a_adt)
{
    if(a_adt == NULL)
    {
        printf("Array Not Initilized Yet!\n");
        return NULL;
    }
    if(a_adt->element_last_index == -1)
        printf("Array is Emtpy\n");
    else
        for(int i=0;i<=a_adt->element_last_index;i++)
            printf("%d ",a_adt->array_ptr[i]);
        printf("\n");
}


//driver code
main()
{
    struct Array_ADT *arr_adt = NULL;
    int sel = 0, data = 0 , index = 0;

   while(1)
   {
       system("cls");
       printf("\n************** Array ADT ************ \n");
       printf(" \n1. Create Array");
       printf(" \n2. Insert Element");
       printf(" \n3. Replace ");
       printf(" \n4. Find ");
       printf(" \n5. Count Elements");
       printf(" \n6. Get Element");
       printf(" \n7. Show Array");
       printf(" \n8. Delete Elements");
       printf(" \n9. Delete At");
       printf(" \n10. Delete Array");
       printf(" \n11. Exit \n");
       printf("\nEnter selection ");
       scanf("%d",&sel);

       switch(sel)
       {
       case 1:
            printf("Enter Capacity of Array\n");
            scanf("%d",&data);
            arr_adt = Create_array(data);
            break;
       case 2:
            printf("Enter Element ");
            scanf("%d",&data);
            arr_adt = Insert_element(arr_adt,data);
            break;
       case 3:
            printf("Enter Element ");
            scanf("%d",&data);
            printf("Enter index ");
            scanf("%d",&index);
            arr_adt = replace_at(arr_adt,data,index);
            break;
       case 4:
            printf("Enter element ");
            scanf("%d",&data);
            if(Find(arr_adt,data))
                printf("Element is Available\n");
            else
                printf("Element is not Available\n");
            break;
       case 5:
            printf("Total number of Elements  %d\n",get_count(arr_adt));
            break;
       case 6:
            printf("Enter index ");
            scanf("%d",&index);
            printf("Element is %d\n",get_element(arr_adt,index));
            break;
       case 7:
            Show_array(arr_adt);
            break;
       case 8:
            arr_adt = Delete_element(arr_adt);
            break;
       case 9:
            printf("Enter index ");
            scanf("%d",&index);
            arr_adt = Delete_at(arr_adt,index);
            break;
       case 10:
            arr_adt = Delete_Array(arr_adt);
            break;
       case 11:
            exit(0);
       default:
            printf("Invalid Selection\n");
            break;

       }
    system("pause");
   }

}
