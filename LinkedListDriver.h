/*************************************************************************
	Title: 	 LinkedListDriver.h
	Authors: Jocelyn Lee & Kylie Truong
	Date:  	 11/1/2024
	Purpose: Everything needed for class SuperList
*************************************************************************/
#ifndef LINKEDLISTDRIVER_H
#define LINKEDLISTDRIVER_H

#include<iostream>
using namespace std;

/*********************************************/
/*              SuperList Class
/*********************************************/
template<typename T>
class SuperList
{
    private:
        /*listNode struct*/
        struct listNode
        { 
            T data;
            listNode * next;
            listNode * previous;
        };
        listNode * head;
        listNode * tail; 
        void printHeroesBottomCheck(listNode*) const
        {
            if(listNode == nullptr)
            {
                return;
            }
            printHeroesBottomCheck(listNode -> next);
            cout << listNode -> data << endl;
        }

    public:
        /*Constructor*/
        SuperList()
        {
            head = NULL;
            tail = NULL;
        }

        /*Deconstructor*/
        ~SuperList(); 

        /*Function Prototypes*/
        void appendSuperHero(T);
        void printHeroesTop() const;
        void printHeroesBottom() const;
        void mergeSort();
        void removeHero(T);
};

/*********************************************/
/*                 ~SuperList
/*********************************************/
template<typename T>
SuperList<T>::~SuperList()
{
    ListNode * nodePtr = head;
	ListNode * nextNode; 
    while(nodePtr != NULL)
    {
        nextNode = nodePtr -> next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

/*********************************************/
/*              appendSuperHero
/*********************************************/
template<typename T>
void SuperList<T>::appendSuperHero(T power){
    listNode * newNode = new listNode; 
    newNode -> data = power;
    newNode -> next = NULL;
    newNode -> previous = NULL; 
    if (!head)
    { 
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next = newNode;
        newNode -> previous = tail; 
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
