#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
using namespace std;


template <typename T>
class SuperList
{
	private:
		struct ListNode
		{
			//STRUCTURE MEMBERS NEED TO BE ADDED HERE
			T data;
			struct ListNode * next;
		}; 

		ListNode *head;	
		ListNode *tail;		

	public:
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}

		~LinkedList()
		{
			ListNode * nodePointer;
			ListNode * nextNode;
			nodePointer = head;

			while(nodePointer)
			{
				nextNode = nodePointer->next;
				cout << "**** DELETING the node with address: " << nodePointer << endl;
				delete nodePointer;
				nodePointer = nextNode;
			}
			cout << "Have fun!";

		}


		void appendNode(T value);
		void deleteNode(int position);
		void displayList() const;
};

//DEFINE ALL OTHER LinkedList class FUNCTIONS BELOW THIS LINE--------------------------------

//Append Node Function 
template <typename T>
void SuperList<T>::appendNode(T value)
{
    ListNode * newNode = new ListNode;
	ListNode * nodePointer;

    newNode->data = value;
    newNode->next = NULL;

    if(!head)
    {
        head = newNode;   
    } 
    else 
    {
        nodePointer = head;
		int counter = 0;

		while( nodePointer->next != NULL)
		{
			cout << "- node " << counter++;
			nodePointer = nodePointer->next; 
		}

		nodePointer->next = newNode;
    }
}

//Delete Node Function 
template <typename T>
void SuperList<T>::deleteNode(int position)
 {
    ListNode * nodePointer = head;
	ListNode * deleteNode;
	int i = 0;

	if( head == NULL)
	{

	}
	else if( position == 0)
	{
		cout << "Deleting " ;
		nodePointer = head->next;
		delete head;
		head = nodePointer;
	}
	else 
	{
		while(i+1 != position && nodePointer != NULL)
		{
			nodePointer = nodePointer->next;
			i++;
		}
		
		deleteNode = nodePointer->next;
		nodePointer->next = nodePointer->next->next;
		delete deleteNode;

	}
       
}

//Display List Function 
template <typename T>
void SuperList<T>::displayList() const
{
    ListNode * nodePointer = head;
	int counter = 1;

    if(head!= NULL)
    {
        nodePointer = head;

		while(nodePointer != NULL)
		{
			cout << "---- NODE " << counter << " with memory address " << nodePointer << endl;

			cout << nodePointer->data;
			nodePointer = nodePointer->next;

			counter++;
		}
	}
    else
    {
        cout << endl << "There are no nodes in the list." << endl << endl;
    }
 

}



#endif
