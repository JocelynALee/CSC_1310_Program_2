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
// task:          Display the user menu.
//
//****************************************************************************

void menuDisplay()
{
	cout << "What Would You Like to Do?" << endl
     	cout << "1. Display the best superHero Catalogue" << endl;
	cout << "2. Display the worst superHero Catalogue" << endl;
	cout << "3. Add to Catalogue" << endl;
	cout << "4. Remove from Cataloge" << endl;
	cout << "5. Exit" << endl;
	cin >> userInput;
	
	switch(userInput){
		//Displays Superhero Catalogue
		case 1:
		    printSuperHero();
		    break;
		//Adds New Hero to Catalogue
		case 2:
		    addSuperhero();
		    break;
		//deletes hero
		case 3:
		    int heroDelete;
	            printSuperHero();
	            cout << "Which hero entry would you like to delete?" << endl;
	        	cin >> heroDelete;
	            removeSuperHero(index, heroDelete);
		    break;
		//Ends Program
		case 4:
		    endProgram = 1;
		    break;
	    }
	    }while (endProgram != 1);
	
	    cout << "Up, Up, and Away!" << endl;
	    cout << endl;
	    
	    return 0;
	
	}
