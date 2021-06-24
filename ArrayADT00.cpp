//array ADT part 00
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//create class
class Array_ADT
{
private:
    int capacity;  //array's length
    int last_index; //last_index count position of last item
    int *ptr;  // ptr is pointer to an array

//    constructor for this class
public:

    Array_ADT()
    {
        capacity = 0;
        last_index = -1; // -1 indicates array is empty
        ptr = NULL;
    }

//    method for create new array
    void create_array(int capacity);

//    getting an item from array if array is not empty
    int get_item(int index);

//    set item in array list

    void set_item(int index, int value);

//    edit item in array

    void edit_item(int index, int value);

//    couting the array element

    int cout_item();

//    remove item from array

    void remove_item(int index);

//    search_item from array

    int search_item(int value);

//    sorting the item

    void sort_item();

//    friend function for overloading of insertion operator

    friend ostream& operator<<(ostream &, Array_ADT);

//    destructor for this class

    ~Array_ADT()
    {
        delete []ptr;  //delete the array
    }

//    copy constructor

    Array_ADT(Array_ADT &list)
    {
        capacity = list.capacity;
        last_index = list.last_index ;

//        create new array
        ptr = new int[capacity];

//        copying the element
        for(int i=0;i<=list.last_index;i++)
        {
            ptr[i] = list.ptr[i];
        }
    }

};




//create array method
void Array_ADT::create_array(int capacity)
{
    this->capacity = capacity;
    last_index = -1;
    ptr = new int[capacity]; //create array with size getting address in pointer
}



//getting item from array

int Array_ADT::get_item(int index)
{
    if(last_index == -1)
    {
        cout<<"Array is empty!";
        return -1;
    }

//    check if index is out of range

    if(index > last_index || index <0)
    {
        cout<<"Invalid index ";
        return -1;
    }

//    returning if index is available

    return (ptr[index]);

}



//set item function defining

    void Array_ADT::set_item(int index, int value)
    {
        int i;
//        checking valid index
        if(last_index == capacity-1)
        {
            cout<<"array is Full";
        }
        else if(index < 0 || index > capacity-1)
        {
            cout<<"invalid index";
        }
        else if(index > last_index+1)
        {
            cout<<"invalid index";
        }
        else if(index <= last_index)
        {
            last_index++;
            i = last_index;
            while(i != index)
            {
                ptr[i] = ptr[i-1];
                i--;
            }
            ptr[index] = value;
        }
        else if(index == last_index+1)
        {
            last_index++; // last_index is for counting position
            ptr[index] = value;
        }


    }



//    edit item in array or replace the existing value

    void Array_ADT::edit_item(int index, int value)
    {
        if(index < 0 || index > last_index)
        {
            cout<<"invalid index";
        }
        else
        {
            ptr[index] = value;
        }
    }

//    couting the element in array

    int Array_ADT::cout_item()
    {
        return last_index+1;
    }


//    remove item from array

    void Array_ADT::remove_item(int index)
    {

        int i;
        if(index < 0 || index > last_index)
        {
            cout<<"Index invalid ";
        }
        else if(index < last_index)
        {
            i = index;
            while(i != last_index)  //ends if last_index is index
            {
                ptr[i] = ptr[i+1];
                i++;
            }
            last_index--;
        }
        else if(index == last_index)
        {
            last_index--;
        }

    }


//    search_item from array

    int Array_ADT::search_item(int value)
    {
        if(last_index == -1)
        {
            cout<<"List is empty";
            return -1;
        }
        else
        {
            int i;
            for(i=0;i<=last_index;i++)
            {
                if(ptr[i]== value)
                    return i; //return is value is available
            }
            return -1;  // if value is not available
        }


    }


//    sorting the array

    void Array_ADT::sort_item()     //maybe an error
    {
        int round, i, temp;

        for(round = 1;round <=cout_item();round++)
        {
            for(i=0;i<=cout_item();i++)
            {
                if(ptr[i] > ptr[i+1])  //swap if left is greater in case of increasing order
                {
                    temp = ptr[i];
                    ptr[i] = ptr[i+1];
                    ptr[i+1] = temp;
                }
            }
        }
    }



//    overloading of insertion operator

    ostream& operator<<(ostream &c_out, Array_ADT list)
    {
        if(list.last_index == -1)
        {
            cout<<"Array List is empty!"<<endl;
        }

//        printing the item from array
        for(int i=0;i< list.cout_item();i++)
        {
            cout<<"\n"<<list.get_item(i);
        }
        return c_out;
    }




//    main program function

int main()
{
    system("cls");
    Array_ADT adt_list;


    adt_list.create_array(5);
    adt_list.set_item(0,10);
    adt_list.set_item(1,20);
    adt_list.set_item(2,28);
    adt_list.edit_item(1,50);

//    couting the value
    cout<<"\nTotal elements in array is "<<adt_list.cout_item()<<endl;

//    searching item
    cout<<"\nElement found at index "<<adt_list.search_item(50)<<endl;

    cout<<"Element is at index 1 is "<<adt_list.get_item(1)<<endl;

//    adt_list.sort_item();

//    printing all elements from items
    cout<<adt_list;

    system("pause");
}
