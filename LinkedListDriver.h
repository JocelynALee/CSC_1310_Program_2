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

        /*Help functions for mergeSort & printHeroesBottom*/
        listNode * split(listNode* top) /*Split Function*/
        {
            listNode * best = start;
            listNode * worst = start;
            while(best -> next != nullptr && best -> next -> next != nullptr)
            {
                best = best -> next -> next;
                worst = worst -> next;
            }
            listNode * middle = worst -> next;
            worst -> next = nullptr;

            return middle;
        }

        /*merge function*/
        listNode * merge(listNode* left, listNode* right);
        {
            if(left == nullptr) 
                return right;
            if(right == nullptr) 
                return left;

            if(left -> data <= right -> data)
            {
                left -> next = merge(left -> next, right);
                left -> next -> previous = left;
                left -> previous = nullptr;
                return left;
            }
                else
                {
                    right -> next = merge(left, right -> next);
                    right -> next -> previous = right;
                    right -> previous = nullptr;
                    return right;
                }
        }

        /*printHeroesBottomCheck*/
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

/*********************************************/
/*              printHeroesTop
/*********************************************/
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

/*********************************************/
/*             printHeroesBottom
/*********************************************/
template<typename T>
void SuperList<T>::printHeroesBottom(listNode* bottomNode)
{
    printHeroesBottomCheck(head);
    cout << "\nThe only list you wouldn't want to be top of!\n";
}

/*********************************************/
/*                 mergeSort
/*********************************************/
template<typename T>
void SuperList<T>::mergeSort()
{
    if (head == nullptr || head -> next == nullptr)
        return;
    head = mergeSort(head);
    listNode* temp = head;
    while (temp -> next != nullptr)
    {
        temp = temp->next;
    }
    tail = temp;
}

template<typename T>
typename SuperList<T>::listNode* SuperList<T>::mergeSort(listNode* node)
{
    if (node == nullptr || node -> next == nullptr)
    {
        return node;
    }
    listNode* mid = split(node);
    listNode* left = mergeSort(node);
    listNode* right = mergeSort(mid);

    return merge(left, right);
}

/*********************************************/
/*                 removeHero
/*********************************************/
#endif
