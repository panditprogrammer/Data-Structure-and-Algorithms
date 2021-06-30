//program to implement link list ADT all operations
#include <iostream>
#include <stdio.h>
using namespace std;

//main class for array link list ADT
class Link_list_ADT
{
private:
    struct Node
    {
        int item;
        Node *next;
    };

//    start pointer for link list
    Node *start;

//    search for an item
    Node* search_item(int data)
    {
        Node *temp;
        if(start == NULL)
        {
            return NULL;
        }

        temp = start;
        while(temp != NULL)
        {
            if(temp->item == data)
            {
                return temp;
            }
//            check for next item
            temp = temp->next;
        }
        return NULL;
    }

public:
    Link_list_ADT()
    {
        start = NULL;
    }

//    destructor for this class
    ~Link_list_ADT()
    {
        while(start != NULL) //for release link list
        {
             delete_item_start();
        }
    }

//    insert function C
    void insert_at_start(int data);

//    insert at last
    void insert_at_last(int data);

//    insert after
    void insert_after(int current_data,int data);

//     delete item from start
    int delete_item_start();

//    delete item from last

    int delete_item_end();

//    delete current item from link list
    int delete_current_item(int current_data);

//    edit value in link list
    void edit_item_list(int current_data,int data);

//    count item in link list
    int count_item_in_list();

//    get first item from list
    int get_first_item();

//    get last item from list
    int get_last_item();

//    show the link list
    void show_list();

//    search item from list
    int search_item_from_list(int);

//    sorting the list
    void sort_list();



};


//insert function for first item at start
    void Link_list_ADT::insert_at_start(int data)
    {
        Node *new_node = new Node;

        new_node->item = data;
        new_node->next = start;
        start = new_node;

    }

//    insert item at last
    void Link_list_ADT::insert_at_last(int data)
    {
        Node *temp, *new_node = new Node;

        new_node->item = data;
        new_node->next = NULL;

        if(start == NULL)
            {
                start = new_node;
            }
        else
            {
                temp = start;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = new_node;
            }

    }



//insert after TODO//
    void Link_list_ADT::insert_after(int current_data,int data)
    {
       Node *temp = search_item(current_data);

       if(temp == NULL)
       {
           cout<<"No such value exists";
       }
       else
       {
           Node *new_node = new Node;

           new_node->item = data;
           new_node->next = temp->next;
           temp->next = new_node;
       }
    }


//  delete node from start
    int Link_list_ADT::delete_item_start()
    {
        if(start == NULL)
        {
            cout<<"Link list is empty"<<endl;
            return 0;
        }

        Node *temp;
        temp = start;
        start = start->next;
        delete(temp);  //release pointer
        return 1;
    }

//    delete last item from link list
    int Link_list_ADT::delete_item_end()
    {
        if(start == NULL)
        {
            cout<<"\nUnderflow";
            return 0;
        }

//        check if node is second node
        if(start->next == NULL)
        {
            delete start;
            start = NULL;
            return 1;
        }
//        finding the last node
        Node *temp1,*temp2;

        temp1 = temp2 = start;
        do{
            temp2 = temp1;
            temp1 = temp1->next;

        }while(temp1->next != NULL);

        temp2->next = NULL;
        delete temp1;
        return 1;
    }

//    delete current item from link list

    int Link_list_ADT::delete_current_item(int current_data)
    {
//        search item for delete
        Node *temp = search_item(current_data);

//        if not item exist
        if(temp == NULL)
        {
            cout<<"Data not available"<<endl;
            return 0;
        }

//        check if node is last node and delete it
        while(temp->next != NULL)
        {
            temp->item = temp->next->item;
            temp = temp->next;
        }
        delete_item_end();
        return 1;

    }

//    edit item in list
    void Link_list_ADT::edit_item_list(int current_data,int data)
    {
//        search item for edit
        Node *temp = search_item(current_data);

        if(temp == NULL)
        {
            cout<<"Item not found"<<endl;
        }
        else
        {
            temp->item = data;
        }

    }

//    couting item in list
    int Link_list_ADT::count_item_in_list()
    {
        int count_item = 0;
        Node *temp;
        temp = start;
        while(temp != NULL)
        {
            count_item++;
            temp = temp->next;
        }
        return count_item;

    }

//    getting first item form link listC
    int Link_list_ADT::get_first_item()
    {
        if(start == NULL)
        {
            cout<<"list is empty"<<endl;
            return -1;
        }
        else
        {
            return start->item;
        }

    }

//    getting last item from link list
    int Link_list_ADT::get_last_item()
    {
        if(start == NULL)
        {
            cout<<"list is empty"<<endl;
            return -1;
        }
        else
        {
            Node *temp;

            temp = start;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            return temp->item;

        }

    }

//    show the link list
    void Link_list_ADT::show_list()
    {
        Node *temp;
        temp = start;
        if(start == NULL)
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            while(temp != NULL)
            {
            cout<<" "<<temp->item;
            temp = temp->next;
            }

        }

    }


//    search item from list
    int Link_list_ADT::search_item_from_list(int item)
    {
        Node *temp;
        temp = start;
        while(temp->next == NULL)
        {
            if(temp->item == item)
                return 1;
            temp = temp->next;

        }
        return 0;
    }

//    sorting the link list
    void Link_list_ADT::sort_list()
    {
        Node *temp;
        int temp_item,num_of_node,i,round;
        num_of_node = count_item_in_list();

        for(round = 1;round <= num_of_node-1;round++)
        {
            temp = start;
            for(i=0;i<=num_of_node-1-round;i++)
            {
                if(temp->item > temp->next->item)
                {
                    temp_item = temp->item;
                    temp->item = temp->next->item;
                    temp->next->item = temp_item;
                }
//                increase the address by one node
                temp = temp->next;
            }
        }
    }




//main function
main()
{
    system("cls");
    cout<<"complete Link List ADT operations"<<endl;

    Link_list_ADT list1;

    cout<<list1.get_first_item()<<endl;
    list1.insert_at_start(10);
    list1.insert_at_start(20);
    list1.insert_at_start(30);
    cout<<list1.count_item_in_list()<<endl;
    cout<<list1.get_first_item()<<endl;

    cout<<list1.get_last_item()<<endl;

    cout<<"all elements in listed here"<<endl;
    list1.insert_after(20,25);
    list1.show_list();
    cout<<endl;
    list1.sort_list();
    cout<<endl;
    list1.show_list();

    cout<<endl;
    list1.delete_item_start();

    list1.edit_item_list(20,200);

    list1.show_list();


        cout<<endl;    system("pause");
}
