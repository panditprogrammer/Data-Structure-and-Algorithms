//implement two way stack
#include <iostream>

using namespace std;

//main class
class Two_Way_Stack
{
private:
    int capacity;
    int top_left;
    int top_right;
    int *arr_ptr;

public:
//    constructor for this class
    Two_Way_Stack(int capacity)
    {
        this->capacity = capacity;

        top_left = -1;
        top_right = capacity;

//        main pointer for array
        arr_ptr = new int[capacity];


    }

//    all functions for actions

//    inserting the value in stack
    void push_left(int value);
    void push_right(int value);

//    delete and get the value from stack
    int pop_left();
    int pop_right();

//    getting the value from stack
    int pick_left();
    int pick_right();

//    checking the stack is empty
    int is_Empty_left();
    int is_Empty_right();

//    checking if the stack is full
    int is_stack_full();

//    destructor for this class

    ~Two_Way_Stack()
    {
        delete []arr_ptr;
    }


};


//checking is full

int Two_Way_Stack::is_stack_full()
{
    if(top_left +1 == top_right)
        return 1;
    else
        return 0;
}

//checking is the right_stack is empty

int Two_Way_Stack::is_Empty_right()
{
    if(top_right == capacity)
        return 1;
    else
        return 0;
}
//checking is the left_stack is empty

int Two_Way_Stack::is_Empty_left()
{
    if(top_left == -1)
        return 1;
    else
        return 0;
}

//getting the value from stack right

int Two_Way_Stack::pick_right()
{
    if(is_Empty_right())
    {
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    else
    {
        return (arr_ptr[top_right]);
    }
}

//getting the value from stack left

int Two_Way_Stack::pick_left()
{
    if(is_Empty_left())
    {
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    else
    {
        return (arr_ptr[top_left]);
    }
}


//pop value from right stack
int Two_Way_Stack::pop_right()
{
    int value;
    if(is_Empty_right())
    {
        cout<<"stack underflow";
        return -1;
    }
    else
    {
        value = arr_ptr[top_right];
        top_right++;
        return value;
    }
}
//pop value from left stack
int Two_Way_Stack::pop_left()
{
    int value;
    if(is_Empty_left())
    {
        cout<<"stack underflow";
        return -1;
    }
    else
    {
        value = arr_ptr[top_left];
        top_left--;
        return value;
    }
}

//pushing the value in right stack
void Two_Way_Stack::push_right(int value)
{
    if(is_stack_full())
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        top_right--;
        arr_ptr[top_right] = value;
    }
}

//pushing the value in left stack
void Two_Way_Stack::push_left(int value)
{
    if(is_stack_full())
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        top_left++;
        arr_ptr[top_left] = value;
    }
}




//main function
int main()
{
    system("cls");

//    class using
    Two_Way_Stack stack1(5);


//    pushing the value in the stack
    stack1.push_right(70);
    stack1.push_left(10);
    stack1.push_left(20);
    stack1.push_left(30);
    stack1.push_right(50);

//    getting value
    cout<<"Poped value from stack left "<<stack1.pop_left()<<endl;
    cout<<"Poped value from stack right "<<stack1.pop_right()<<endl;

//    checking empty stack
    if(stack1.is_Empty_left())
    {
        cout<<"left stack is empty"<<endl;
    }
    else
    {
        cout<<"left stack is not empty"<<endl;
    }

    if(stack1.is_Empty_right())
    {
        cout<<"right stack is empty"<<endl;
    }
    else
    {
        cout<<"right stack is not empty"<<endl;
    }

//        pick the value from stack if available
    cout<<"left stack top value is "<<stack1.pick_left()<<endl;
    cout<<"right stack top value is "<<stack1.pick_right()<<endl;

}
