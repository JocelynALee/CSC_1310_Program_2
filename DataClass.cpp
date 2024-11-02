/*************************************************************************
	Title: 	 DataClass.cpp
	Authors: Jocelyn Lee & Kylie Truong
	Date:  	 11/1/2024
	Purpose: Stores the information of superheroes, ___________________
*************************************************************************/
#include "LinkedListDriver.h"
#include "OtherClass.h"
#include "OtherClass.cpp"
#include "DataClass.cpp"
#include "DataClass.h"

//****************************************************************************
//                                 menuDisplay()
//
// task:                       Display the user menu.
//
//****************************************************************************

void menuDisplay()
{
    do{
	cout << "\n\nWhat Would You Like to Do?" << endl;
    cout << "1. Display the best superHero Catalogue!!" << endl;
	cout << "2. Display the worst superHero Catalogue!" << endl;
	cout << "3. Add to Catalogue" << endl;
	cout << "4. Remove from Cataloge" << endl;
	cout << "5. Exit" << endl;
	    cin >> userInput;
        switch(userInput)
        {
            //Displays Best Superhero Catalogue
            case 1:
                displayTopList();
                break;
            //Displays Worst Superhero Catalogue
            case 2:
                displayBottomList();
                break;
            //Adds New Hero to Catalogue
            case 3:
                addSuperhero();
                break;
            //deletes hero
            case 4:
                int heroDelete;
                printSuperHero();
                cout << "Which hero entry would you like to delete?" << endl;
                cin >> heroDelete;
                removeSuperHero(index, heroDelete);
                break;
            //Ends Program
            case 5:
                endProgram = 1;
                break;
        }
	}while (endProgram != 1);
    cout << "Up, Up, and Away!" << endl << endl;
    return 0;
}
