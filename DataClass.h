/********************************************************************************
	Title: 	  dataClass.h
	Authors:  Jocelyn Lee & Kylie Truong
	Date:  	  11/01/2024
	Purpose:  Header file for dataClass.cpp
    Included: Necessary attributes, getters, setters & operator overloads 
*********************************************************************************/
#ifndef DATACLASS_H
#define DATACLASS_H
#include <string>
#include <iostream>
using namespace std;

/*********************************************/
/*              DataClass Class              */
/*********************************************/
class DataClass 
{
private:
    /* Variables */
    string name;
    int powerLevel;
    string superpower;
    int rank;

public:
    /* Constructor */
    DataClass(const string& name = "", int powerLevel = 0, const string& superpower = "");

    /* Setters */
    void setName(const string& n);
    void setPowerLevel(int p);
    void setSuperPower(const string& s);

    /* Getters */
    string getName() const { return name; }
    int getPowerLevel() const { return powerLevel; }
    string getSuperPower() const { return superpower; }
    char getRank() const 
    {
        if (powerLevel >= 100) return 'S'; // Top rank
        else if (powerLevel >= 80) return 'A'; // Second rank
        else if (powerLevel >= 60) return 'B'; // Third rank
        else if (powerLevel >= 40) return 'C'; // Fourth rank
        else if (powerLevel >= 20) return 'D'; // Fifth rank
        else return 'F'; // Lowest rank
    }

    /* Operators */
    friend ostream& operator<<(ostream& os, const DataClass& hero) 
    {
        os << "Name: " << hero.name << ", Power Level: " << hero.powerLevel 
           << ", Superpower: " << hero.superpower;
        return os;
    }
    
    bool operator==(const DataClass& other) const 
    {
        return name == other.name; 
    }

    bool operator<(const DataClass& other) const 
    {
        return powerLevel < other.powerLevel;
    }

    bool operator!=(const DataClass& other) const 
    {
        return !(*this == other);
    }

    bool operator<=(const DataClass& other) const 
    {
        if (getRank() < other.getRank()) 
        {
            return true;
        }
        if (getRank() > other.getRank())
        { 
            return false;
        }
        return name <= other.name;
    }

    bool operator>(const DataClass& other) const 
    {
        if (getRank() > other.getRank()) 
        {
            return true;
        }
        if (getRank() < other.getRank()) 
        {
            return false;
        }
        return name > other.name;   
    } 
};

#endif
