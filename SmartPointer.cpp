/********************************************************************************
	Title: 	  SmartPointer.cpp
	Authors:  Jocelyn Lee & Kylie Truong
	Date:  	  11/01/2024
	Purpose:  Implements SmartPointer 
*********************************************************************************/
#include "SmartPointer.h"

/*********************************************/
/*               Constructor                 */
/*********************************************/
template<typename T>
SmartPointer<T>::SmartPointer(T* p) : ptr(p) {}

/*********************************************/
/*            Copy Constructor               */
/*********************************************/
template<typename T>
SmartPointer<T>::SmartPointer(const SmartPointer& sp) 
{
    if (sp.ptr) {
        ptr = new T(*(sp.ptr)); // Deep copy
    } else {
        ptr = nullptr; // Handle nullptr
    }
}

/*********************************************/
/*             Move Constructor              */
/*********************************************/
template<typename T>
SmartPointer<T>::SmartPointer(SmartPointer&& sp) noexcept : ptr(sp.ptr) 
{
    sp.ptr = nullptr;
}

/*********************************************/
/*                Destructor                 */
/*********************************************/
template<typename T>
SmartPointer<T>::~SmartPointer() 
{
    delete ptr;
}

/*********************************************/
/*                Operators                  */
/*********************************************/
template<typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& sp) 
{
    if (this != &sp) 
	{
        delete ptr; 
        if (sp.ptr) 
		{
            ptr = new T(*(sp.ptr));
        } 
		else 
		{
            ptr = nullptr; 
        }
    }
    return *this;
}


template<typename T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer&& sp) noexcept 
{
    if (this != &sp) 
	{
        delete ptr; 
        ptr = sp.ptr; 
        sp.ptr = nullptr;
    }
    return *this;
}


template<typename T>
T& SmartPointer<T>::operator*() const 
{
    return *ptr;
}


template<typename T>
T* SmartPointer<T>::operator->() const 
{
    return ptr;
}


template<typename T>
bool SmartPointer<T>::operator==(const SmartPointer& sp) const 
{
    return ptr == sp.ptr;
}

template<typename T>
bool SmartPointer<T>::operator!=(const SmartPointer& sp) const 
{
    return ptr != sp.ptr;
}
