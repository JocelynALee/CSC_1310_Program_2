/********************************************************************************
	Title: 	    LinkedListDriver.h
	Authors:    Jocelyn Lee & Kylie Truong
	Date:  	    11/1/2024
	Purpose:    header file for Linked List and Driver
*********************************************************************************/
#ifndef LINKEDLISTDRIVER_H
#define LINKEDLISTDRIVER_H

#include <iostream>
using namespace std;

/*********************************************/
/*              SuperList Class              */
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

    /*Helper functions for mergeSort & printHeroesBottom*/
    listNode * split(listNode* top)
    {
        listNode * fast = top;
        listNode * slow = top;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        listNode * middle = slow->next;
        slow->next = nullptr;

        return middle;
    }

    listNode * merge(listNode* left, listNode* right)
    {
        if (left == nullptr) 
            return right;
        if (right == nullptr) 
            return left;

        if (left->data <= right->data)
        {
            left->next = merge(left->next, right);
            left->next->previous = left;
            left->previous = nullptr;
            return left;
        }
        else
        {
            right->next = merge(left, right->next);
            right->next->previous = right;
            right->previous = nullptr;
            return right;
        }
    }

    void printHeroesBottomCheck(listNode* node) const
    {
        if (node == nullptr)
        {
            return;
        }
        printHeroesBottomCheck(node->next);
        cout << node->data << endl;
    }

public:
    /*Constructor*/
    SuperList()
    {
        head = nullptr;
        tail = nullptr;
    }

    /*Destructor*/
    ~SuperList(); 

    /*Function Prototypes*/
    void appendSuperHero(T);
    void printHeroesTop() const;
    void printHeroesBottom() const;
    void mergeSort();
    void removeHero(T);
    bool getAtHero(int index, T& value) const;
    friend ostream& operator<<(ostream& os, const SuperList<T>& list);
};

/*********************************************/
/*                 ~SuperList                */
/*********************************************/
template<typename T>
SuperList<T>::~SuperList()
{
    listNode * nodePtr = head;
    listNode * nextNode; 
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

/*********************************************/
/*              appendSuperHero              */
/*********************************************/
template<typename T>
void SuperList<T>::appendSuperHero(T power)
{
    listNode * newNode = new listNode; 
    newNode->data = power;
    newNode->next = nullptr;
    newNode->previous = nullptr; 
    if (!head)
    { 
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->previous = tail; 
        tail = newNode; 
    }
}

/*********************************************/
/*              printHeroesTop               */
/*********************************************/
template <typename T>
void SuperList<T>::printHeroesTop() const
{
    listNode * nodePointer = head;
    int counter = 1;
    if (head != nullptr)
    {
        while (nodePointer != nullptr)
        {
            cout << "RANK " << counter << ": " << nodePointer->data << endl;
            nodePointer = nodePointer->next;
            counter++;
        }
    }
    else
    {
        cout << "\nThere are no SuperHeroes in the list.\n\n";
    }
}

/*********************************************/
/*             printHeroesBottom             */
/*********************************************/
template<typename T>
void SuperList<T>::printHeroesBottom() const
{
    printHeroesBottomCheck(head);
    cout << "\nThe only list you wouldn't want to be top of!\n";
}

/*********************************************/
/*                 mergeSort                 */
/*********************************************/
template<typename T>
void SuperList<T>::mergeSort()
{
    if (head == nullptr || head->next == nullptr)
        return;
    head = mergeSort(head);
    
    // Update tail pointer
    listNode* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    tail = temp;
}

template<typename T>
typename SuperList<T>::listNode* SuperList<T>::mergeSort(listNode* node)
{
    if (node == nullptr || node->next == nullptr)
    {
        return node;
    }
    listNode* mid = split(node);
    listNode* left = mergeSort(node);
    listNode* right = mergeSort(mid);

    return merge(left, right);
}

/*********************************************/
/*                 removeHero                */
/*********************************************/
template<typename T>
void SuperList<T>::removeHero(T hero)
{
    if (!head)  // List is empty
    {
        cout << "There are no heroes in the list.\n";
        return;
    }
    listNode* superHero = head;

    /*Search for hero*/
    while (superHero != nullptr && superHero->data != hero)
    {
        superHero = superHero->next;
    }

    /*If hero cannot be found*/
    if (!superHero) 
    {
        cout << "This superhero is not in the list.\n";
        return;
    }

    if (superHero == head)
    {
        head = head->next;
        if (head)
            head->previous = nullptr;
        else
            tail = nullptr;
    }
    else if (superHero == tail)
    {
        tail = tail->previous;
        tail->next = nullptr;
    }
    else
    {
        superHero->previous->next = superHero->next;
        superHero->next->previous = superHero->previous;
    }
    delete superHero;
    cout << "The superhero " << hero << " has been deleted from the list.\n";
}

/*********************************************/
/*                getAtHero                  */
/*********************************************/
template<typename T>
bool SuperList<T>::getAtHero(int index, T& value) const 
{
    if (index < 0) {
        return false;
    }
    listNode * current = head;
    int count = 0;

    while (current != nullptr) 
    {
        if (count == index) {
            value = current -> data;
            return true;
        }
        current = current -> next;
        count++;
    }

    return false;
}

/*********************************************/
/*                operator<<                 */
/*********************************************/
template<typename T>
ostream& operator<<(ostream& os, const SuperList<T>& list) 
{
    typename SuperList<T>::listNode* current = list.head;
    if (!current) {
        os << "The list is empty." << endl;
        return os;
    }

    while (current) {
        os << current->data << " " << endl; 
        current = current -> next;
    }
    return os;
}

#endif
