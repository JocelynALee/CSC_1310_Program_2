/*****************************************************************
	Title:  	LinkedList.h
	Date:           10/08/2024
	Author: 	Jocelyn Lee & Kylie Truong
	Purpose:	Header file for Linked List
******************************************************************/
#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include "OtherClass.h"
#include "DataClass.h"
using namespace std;

/*****************************************
*             SuperList Class
*****************************************/
template <typename T>
class SuperList
{
	private:
    //struct for list node data and pointers to next and prev
		struct ListNode
		{
			T data;
			ListNode * next;
			ListNode * prev;
		}; 
		ListNode *head;	
		ListNode *tail;		

	public:
        //sets to NULL
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}
        //destructor
		~LinkedList()
        //functions
		void addSuperHero(T);
		void deleteNode(int position);
		void displayTopList();
        void displayBottomList();
        void printSuperHero();
        void removeSuperHero();
        friend void mergeSort();
        friend void selectionSort();
};

/*****************************************
*        Deconstructor Function
*****************************************/
SuperList<T>::~SuperList()
{
    ListNode * newNode = head;
    ListNode * temp;
    while(newNode != NULL)
    {
        temp = newNode -> next;
        delete newNode;
        newNode = temp;
    }
}

/*****************************************
*        addSuperHero Function
*        appendNode
*****************************************/
template <typename T>
void SuperList<T>::addSuperHero(T newValue)
{
    ListNode * newNode = new ListNode;
    newNode -> value = newValue; 
    if (!head)
    {
        head = newNode;
        tail = newNode;
        newNode -> next = NULL;
        newNode -> prev = NULL;
    }
        else
        {
            tail -> next = newNode; 
            newNode -> prev = tail;
            newNode -> next = NULL;
            tail = newNode;
        }
}

/*****************************************
*        removeSuperHero Function
*****************************************/
template <typename T>
void SuperList<T>::removeSuperHero(int position)
 {
    ListNode * nodePtr;
    ListNode *priorNode;
    if(!head)
    {
        cout << "There's no superheroes in this list.\n";
        return;
    }
    else if(head -> value == position)
    {
        nodePtr = head -> next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head; 
        while((nodePtr != NULL) && (nodePtr -> value != position))
        {
            priorNode = nodePtr;
            nodePtr = nodePtr -> next;
        }
        if(nodePtr)
        {
            if(nodePtr == tail)
            {
                tail = priorNode;
            }
            priorNode -> next = nodePtr -> next;
            delete nodePtr;
        }
    }     
}

/*****************************************
*        printSuperHero Function
*****************************************/ 
template <typename T>
void SuperList<T>::printSuperHero()
{
    ListNode * nodePointer = head;
	int counter = 1;

    if(head!= NULL)
    {
        nodePointer = head;

		while(nodePointer != NULL)
		{
			cout << "RANK " << counter << nodePointer -> data << endl;
			nodePointer = nodePointer->next;
			counter++;
		}
	}
    else
    {
        cout << endl << "There are no SuperHeroes in the list." << endl << endl;
    }
 }

/*****************************************
*        mergeSort Function
*****************************************/ 
template<typename T>
void DList<T>::mergesort()
{
    head = mergesort(head,tail);
    listNode * newNode = head; 
    while(newNode -> next)
    {
        newNode = newNode -> next;
    }
    tail = newNode;
}
#endif
