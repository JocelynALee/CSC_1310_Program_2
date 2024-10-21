#ifndef LIST_H
#define LIST_H 

#include <iostream>

using namespace std;

//List Class
class List
{
    private:
    
    struct ListNode
    {
        string data;
        ListNode * next;
    
    };
    ListNode * head;
    ListNode * tail;

    public:
    //constructor
    List()
    {
        head = NULL;
        tail = NULL;
        cout << endl << endl << "The linked list has been created.";
    }
    //destructor 
    ~List()
    {
        ListNode * nodePointer = head;
        ListNode * newNode;

        while(nodePointer != NULL)
        {
            newNode = nodePointer->next;
            delete nodePointer;
            nodePointer = newNode;
        }
        
    }
    //append
    void appendNode(string);
    //insert
    void insertNode(string);
    //delete 
    void deleteNode(string);
    //display 
    void displayList();
};

//appendNode function 
void List::appendNode(string newString)
{
    ListNode * newNode = new ListNode;

    newNode->data = newString;
    newNode->next = NULL;

    if(!head)
    {
        head = newNode;
        tail = newNode;    
    } 
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
}


void List::insertNode(string newString)
{
    ListNode * newNode = new ListNode;
    newNode->data = newString;
    ListNode * current = head;
    ListNode * previous = NULL;

    while((current != NULL) && (current->data < newString))
    {
        previous = current;
        current = current->next;
    }

    if(previous == NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        newNode->next = current;
        previous->next = newNode;
    }

    if(newNode->next == NULL)
    {
        tail = newNode;
    }
}

 void List::deleteNode(string string)
 {
     ListNode * current = head;

     while((current->next != nullptr) && (current->next->data != string))
     {
         current = current->next;
     }
     if(current->next != nullptr)
     {
         ListNode * deleteNode = current->next;
         current->next = deleteNode->next;

         if(deleteNode == tail)
         {
             tail = current;
         }

        delete deleteNode;
     }
        
}


//displayList function 
void List::displayList()
{
    ListNode * nodeptr = head;

    if(head!= nullptr)
    {
        nodeptr = head;

        while(nodeptr != nullptr)
        {
            cout << nodeptr->data << endl;
            nodeptr = nodeptr->next;
        }
    }
    else
    {
        cout << endl << "All list nodes have been removed.";
    }
 

}


#endif

