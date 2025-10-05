/**
* OBLIG 2
*
* THE PROGRAM:
* -Set up variables and constants
* -Create methods and functions
* -Optimize code
* -Use comments and documentation
*
* @file main.c
* @author Daniel AG
*
* Includes:
* - stdio.h for displaying and feeding data
* - stdbool.h for using booleans
* - ctype.h for toupper
*/

///Internal Includes
#include <stdio.h> //printf,scanf
#include <stdbool.h> //bool
#include <ctype.h> //toupper
#include <string.h> //strcpy,strcspn


/**
* @def MAXLANES
* @brief Maximum number of lanes
*/
#define MAXLANES 18 

/**
* @def MAXLANELENGTH
* @brief Maximum length of a lane
*/
#define MAXLANELENGTH 100 

/**
* @def MAXPAIRS
* @brief Maximum number of pairs
*/
#define MAXPAIRS 8

/**
* @def STRLEN
* @brief Maximum length of a string (array of char)
*/
#define MAXSTRLEN 100 
/** @}*/


char laneDescription[MAXLANES][MAXSTRLEN] = { 0,0 }; // lane description 
int laneLength[MAXLANES] = { 0 }; // lane length
int lanePair[MAXLANES] = { 0 }; // lane pair
bool laneOB[MAXLANES] = { 0 }; // lane OB
int numLanes = 0; // number of lanes


/**
* @def Run
* @brief Runs the program
* @returns nothing
*/
void Run();

/**
* @def Add
* @brief Adds a new lane
* @returns true or false
*/
void Add_Lane();

/**
* @def Display
* @brief Displays all lanes
* @returns nothing
*/
void Display_Lane();

/**
* @def Dismainplay
* @brief executes the program
* @returns an integer. 0 if success, else error code
*/
int main()
{
	Run();
}

void Run()
{
	char choice; // User choice for input
	do // conditional logic in while loop
	{
		/**
        * 1. Printing the menu
		* 2. Getting user input
        * 3. Activate switch case
		* 4. Returning to menu unless Q is pressed
        */
		printf("Menu Choices:\n");
		printf("  A - Add lane:\n");
		printf("  D - Display alle lanes:\n");
		printf("  Q - Quit:\n");
		printf("  Select a choice:");
		scanf_s(" %c", &choice, 1);
		choice = toupper(choice);
		printf("\n");

		switch (choice) // Steps into switch case and activates the right case
		{
		case 'A':
		{
			Add_Lane();
			break;
		}
		case 'D':
		{
			Display_Lane();
			break;
		}
		case 'Q':
		{
			printf("Quit - selected:\nEXITING PROGRAM");
			break;
		}
		default:
			printf("Illegal argument");
		}
	} while (choice != 'Q');
}

void Add_Lane()
{
	if (MAXLANES <= numLanes) // is the maximum number of lanes reached?
	{
		printf("[LOG]:Max Number of lanes created\n");
		return;
	}

	///Utility
	int currentLane = numLanes;

	/// Lane data
	int qLaneLength = 0;
	int qLanePair = 0;
	char qLaneOB;
	char qLaneDescription[MAXSTRLEN];

	printf("How long is the lane %i:", currentLane); // Take inout for lane length
	scanf_s("%d", &qLaneLength);
	if (MAXLANELENGTH < qLaneLength) // flag if max length is overreached
	{
		printf("Max length overreached, set to MAXLANELENGTH\n");
		qLaneLength = MAXLANELENGTH;
	}
	if (qLaneLength <= 0) // flag if illegal argument
	{
		printf("Illegal argument..\nReturning\n\n");
		while (getchar() != '\n');
		return;
	}
	laneLength[currentLane] = qLaneLength; // update lane length for current lane

	printf("Pairs on the field. Choose a number bwteen (2-8):"); // Take input for lane pairs
	scanf_s("%d", &qLanePair);
	if (MAXPAIRS < qLanePair) // flag if max pairs is overreached
	{
		printf("Max pairs, set to MAXPAIRS\n");
		qLanePair = MAXPAIRS;
	}
	if (qLanePair < 2) //flag if illegal argument
	{
		printf("Illegal argument..\nReturning\n\n");
		while (getchar() != '\n');
		return;
	}
	lanePair[currentLane] = qLanePair; // update lane pairs for current lane

	printf("Does the lane have OB (y = yes or n = no):\n"); // Take input for lane OB
	while (getchar() != '\n');
	scanf_s(" %c", &qLaneOB, 1);
	qLaneOB = toupper(qLaneOB);
	if (qLaneOB != 'Y' && qLaneOB != 'N') // flag if illegal argument
	{
		printf("Illegal argument..\nReturning\n\n");
		while (getchar() != '\n');
		return;
	}
	laneOB[currentLane] = (qLaneOB == 'Y'); // update lane OB for current lane

	printf("Write a description:"); // Take input for lane description
	while (getchar() != '\n');
	fgets(qLaneDescription, MAXSTRLEN, stdin); // Read string with spaces
	qLaneDescription[strcspn(qLaneDescription, "\n")] = 0; // Remove newline character from string "\n"
	strcpy_s(laneDescription[numLanes], MAXSTRLEN, qLaneDescription); // copy the content of qLaneDescription to laneDescription

	numLanes++; //increment number of lanes
	printf("Lane %i added\n\n", currentLane); // confirm lane added
}

void Display_Lane()
{
	int totNumPairs = 0; // total number of pairs

	for (int i = 0; i <= numLanes; i++) // iterate through all lanes
	{
		if (numLanes == 0) // flag if no lanes are available
		{
			printf("No lanes available\n\n");
			continue; //skip empty lanes
		}
		else if (laneLength[i] == 0) //flag if no data on lane
		{
			printf("No data on lane %d\n\n", i);
			continue;
		}
		printf("Lane %d:\n", i+1);
		printf("     Length: %d km\n", laneLength[i]);
		printf("     Pairs: %d\n", lanePair[i]);
		printf("     %s: OB\n", laneOB[i] ? "With" : "Without");
		printf("     Description: %s\n\n", laneDescription[i]);

		totNumPairs += lanePair[i]; // sum up total number of pairs
	}

	printf("Summary\n");
	printf("Total number of lanes: %d\n", numLanes);
	printf("To get to pair, it requires number of throws: %d\n\n", totNumPairs);


}
