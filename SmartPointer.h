/********************************************************************************
	Title: 	  SmartPointer.h
	Authors:  Jocelyn Lee & Kylie Truong
	Date:  	  11/01/2024
	Purpose:  Header file for SmartPointer.cpp 
*********************************************************************************/
#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
using namespace std;

/*********************************************/
/*           SmartPointer Class              */
/*********************************************/
template<typename T>
class SmartPointer {
	private:
		T* ptr; 

public:
    /*Constructor*/
    explicit SmartPointer(T* p = nullptr); 

    /*Copy Constructor*/
    SmartPointer(const SmartPointer& sp);

    /*Destructor*/
    ~SmartPointer();

	/*Operators*/
    SmartPointer& operator=(const SmartPointer& sp);
    T& operator*() const;
    T* operator->() const;
    bool operator==(const SmartPointer& sp) const;
    bool operator!=(const SmartPointer& sp) const;
};

#endif
