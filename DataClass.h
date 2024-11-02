/********************************************************************************
	Title: 	  dataClass.h
	Authors:  Jocelyn Lee & Kylie Truong
	Date:  	  11/01/2024
	Purpose:  Header file for dataClass.cpp 
*********************************************************************************/
#include <string>
#include <ostream>
using namespace std;

/*********************************************/
/*              DataClass Class              */
/*********************************************/

class DataClass 
{
private:
    string name;
    int powerLevel;
    string superpower;

public:
    /* Constructor */
    DataClass(string n, int p, string s);

    /* Setters */
    void setName(const string& n);
    void setPowerLevel(int p);
    void setSuperPower(const string& s);

    /* Getters */
    string getName() const;
    int getPowerLevel() const;
    string getSuperPower() const;

    /* Operators */
    bool operator<(const DataClass& other) const;
    bool operator>(const DataClass& other) const;
    bool operator==(const DataClass& other) const;

    /* Friend function for output */
    friend std::ostream& operator<<(ostream& os, const DataClass& data);
};

#endif
