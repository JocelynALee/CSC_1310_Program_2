/*************************************************************************
	Title: 	 DataClass.cpp
	Authors: Jocelyn Lee & Kylie Truong
	Date:  	 11/1/2024
	Purpose: Implements DataClass methods defined in the header
*************************************************************************/
#include "LinkedListDriver.h"
#include "SmartPointer.h"
#include "DataClass.h"

/* Setters */

//******************************************************************
//                           setName
//******************************************************************
void DataClass::setName(const string& n) 
{
    name = n;
}

//******************************************************************
//                          setPowerLevel
//******************************************************************
void DataClass::setPowerLevel(int p) 
{
    powerLevel = p;
}

//******************************************************************
//                          setSuperPower
//******************************************************************
void DataClass::setSuperPower(const string& s) 
{
    superpower = s;
}

/* Getters */

//******************************************************************
//                          getName
//******************************************************************
string DataClass::getName() const 
{
    return name;
}

//******************************************************************
//                          getPowerLevel
//******************************************************************
int DataClass::getPowerLevel() const 
{
    return powerLevel;
}

//******************************************************************
//                          getSuperPower
//******************************************************************
string DataClass::getSuperPower() const 
{
    return superpower;
}

/* Operators */

//******************************************************************
//                          operator <
//******************************************************************
bool DataClass::operator<(const DataClass& other) const 
{
    return powerLevel < other.powerLevel;
}

//******************************************************************
//                          operator >
//******************************************************************
bool DataClass::operator>(const DataClass& other) const 
{
    return powerLevel > other.powerLevel;
}

//******************************************************************
//                          operator =
//******************************************************************
bool DataClass::operator==(const DataClass& other) const 
{
    return name == other.name && powerLevel == other.powerLevel && superpower == other.superpower;
}


/* Stream Operator */
ostream& operator<<(ostream& os, const DataClass& data) {
    os << "Name: " << data.getName() << ", Power Level: " << data.getPowerLevel() << ", Superpower: " << data.getSuperPower();
    return os;
