/********************************************************************************
	Title: 	    PokedexDriver.cpp
	Authors:    Jocelyn Lee & Kylie Truong
	Date:  	    11/1/2024
	Purpose:    Contains full program flow, all classes used, all 
                    functions can be tested, takes user input & ends naturally
*********************************************************************************/
#include "LinkedListDriver.h"
#include "OtherClass.h"
#include "OtherClass.cpp"
#include "DataClass.cpp"
#include "DataClass.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>

int main()
{
	superPrint();
	cout << "\n***Welcome to Superhero Super Sort!***";
	cout << "\nSee who's the best of the best or even who's the worst!" << endl;
	menuDisplay();
return 0;
}


//******************************************************************
//                      superPrint() Function
//******************************************************************
void superPrint()
{
	cout << "░▒▓███████▓▒ ░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓████████▓▒░▒▓███████▓▒░        ░▒▓███████▓▒░░▒▓██████▓▒░░▒▓███████▓▒░▒▓████████▓▒░" << endl; 
        cout << "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░" << endl;     
        cout << "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░" << endl;     
        cout << " ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓██████▓▒░ ░▒▓███████▓▒░        ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░  ░▒▓█▓▒░" << endl;  
        cout << "       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░             ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░" << endl;     
        cout << "       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░             ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░" << endl;     
        cout << "░▒▓███████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░      ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓███████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░" << endl;     
}
