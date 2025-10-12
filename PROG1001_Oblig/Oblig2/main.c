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
* @date 13.10.25
* @version 2.0
* @author Daniel AG
*
* Includes:
* - stdio.h for displaying and feeding data
* - stdbool.h for using booleans
* - ctype.h for toupper
*/

// Internal Includes :
#include <stdio.h> // printf,scanf
#include <stdbool.h> // bool
#include <ctype.h> // toupper
#include <string.h> // strcpy,strcspn

// Constants:
#define MAXLANES 18 ///< Maximum number of lanes
#define MAXLANELENGTH 100 ///< Maximum lane length
#define MAXPARS 8 ///< Maximum Pars
#define MAXSTRLEN 100 ///< Maximum string length

//Declarations
void Add_Lane(int* in_numLanes, int* in_laneLengt,
	int* in_lanePar, bool* in_laneOB,
	char (*in_laneDescription)[MAXSTRLEN]);

void Display_Lane(int* in_numLanes, int* in_laneLengt,
	int* in_lanePar, bool* in_laneOB,
	char (*in_laneDescription)[MAXSTRLEN]);

/**
* main program:
*/
int main()
{
	// Internal Includes :
	char laneDescription[MAXLANES][MAXSTRLEN] = { 0,0 }; // lane description 
	int laneLength[MAXLANES] = { 0 }; // lane length
	int lanePar[MAXLANES] = { 0 }; // lane Par
	bool laneOB[MAXLANES] = { 0 }; // lane OB
	int numLanes = 0; // number of lanes


	
    // Default values :
	laneLength[0] = 62;
	lanePar[0] = 3;
	laneOB[0] = true;
	strcpy_s(laneDescription[0], MAXSTRLEN,
		"Lane with a lot of trees and scrub");

	laneLength[1] = 94;
	lanePar[1] = 3;
	laneOB[1] = false;
	strcpy_s(laneDescription[1], MAXSTRLEN,
		"Flat terrain thourgout the map");
	numLanes = 2;

	char choice; // User choice for input
	do /// conditional logic in while loop
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

		switch (choice) /// steps into corresponding case
		{
		case 'A': 
		{
			Add_Lane(&numLanes, laneLength, lanePar, laneOB, laneDescription);
			break;
		}
		case 'D':
		{
			Display_Lane(&numLanes, laneLength, lanePar, laneOB, laneDescription);
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

/**
* @def Add_Lane
* @brief Displays all lanes
* @param in_numLanes Pointer to number of lanes
* @param in_laneLengt Pointer to lane lengths
* @param in_lanePar Pointer to lane Pars
* @param in_laneOB Pointer to lane OB
* @param in_laneDescription Pointer to lane descriptions
* @return void
*/
void Add_Lane(int* in_numLanes, int* in_laneLengt,
	int* in_lanePar, bool* in_laneOB,
	char (*in_laneDescription)[MAXSTRLEN])
{
	if (MAXLANES <= *in_numLanes) // is the maximum number of lanes reached?
	{
		printf("[LOG]:Max Number of lanes created\n");
		return;
	}

	// Temporary variables for user input
	int currentLane = *in_numLanes;
	int qLaneLength = 0;
	int qLanePar = 0;
	char qLaneOB;
	char qLaneDescription[MAXSTRLEN];

	printf("How long is lane %i: ", currentLane + 1);

	/// Flag if length is less or equal to 0
	if (!scanf_s(" %d", &qLaneLength) || qLaneLength <= 0)
	{
		printf("Illegal argument..\nReturning\n\n");
		while (getchar() != '\n');
		return;
	}
	in_laneLengt[currentLane] = qLaneLength; // Update lane length,
	                                         // -for current lane

    // Take input for lane Pars
	printf("Pars on the field. Choose a number bwteen (2-8):");
	if (!scanf_s(" %d", &qLanePar)) /// Flag if invalid input
	{
		printf("Invalid input. Returning...\n");
		while (getchar() != '\n');
		return;
	}
	if (MAXPARS < qLanePar) /// Flag if max Pars is overreached
	{
		printf("Max Pars, set to MAXPARS\n");
		qLanePar = MAXPARS;
	}
	if (qLanePar < 2) ///Flag if illegal argument
	{
		printf("Illegal argument..\nReturning\n\n");
		while (getchar() != '\n');
		return;
	}
	in_lanePar[currentLane] = qLanePar; // Update lane Pars for current lane

	// Take input for lane OB
	printf("Does the lane have OB (y = yes or n = no):");
	while (getchar() != '\n');
	scanf_s(" %c", &qLaneOB, 1);
	qLaneOB = toupper(qLaneOB);
	if (qLaneOB != 'Y' && qLaneOB != 'N') // Flag if illegal argument
	{
		printf("Illegal argument..\nReturning\n\n");
		while (getchar() != '\n');
		return;
	}
	in_laneOB[currentLane] = (qLaneOB == 'Y');	// Update lane OB for current lane

	printf("Write a description:"); // Take input for lane description
	while (getchar() != '\n');
	fgets(qLaneDescription, MAXSTRLEN, stdin); // Read string with spaces

	// Remove newline character from string "\n"
	qLaneDescription[strcspn(qLaneDescription, "\n")] = 0;

	// Copy the content of qLaneDescription to laneDescription
	strcpy_s(in_laneDescription[*in_numLanes], MAXSTRLEN, qLaneDescription);

	in_numLanes++; // Increment number of lanes
	printf("Lane %i added\n\n", currentLane); // Confirm lane added
}

/**
* @def Display_Lane
* @brief Displays all lanes
* @param in_numLanes Pointer to number of lanes
* @param in_laneLengt Pointer to lane lengths
* @param in_lanePar Pointer to lane Pars
* @param in_laneOB Pointer to lane OB
* @param in_laneDescription Pointer to lane descriptions
* @return void
*/
void Display_Lane(int* in_numLanes, int* in_laneLengt, int* in_lanePar, bool* in_laneOB, char (*in_laneDescription)[MAXSTRLEN])
{
	int totNumPars = 0; // Total number of Pars

	for (int i = 0; i < *in_numLanes; i++) // Iterate through all lanes
	{
		if (*in_numLanes == 0) /// Flag if no lanes are available
		{
			printf("No lanes available\n\n");
			return; 
		}
		else if (in_laneLengt[i] == 0) /// Flag if no data on lane
		{
			printf("No data on lane %d\n\n", i);
			return;
		}
		printf("Lane \033[1;4m%d\033[0m:\n", i + 1);
		printf("     Length: \033[1;4m%d meters\033[0m\n", in_laneLengt[i]);
		printf("     Pars: \033[1;4m%d\033[0m\n", in_lanePar[i]);
		printf("     OB: %s\n", in_laneOB[i] ?
			"\033[1;4m With \033[0m" : "\033[1;4m Without \033[0m");
		if (in_laneDescription[i])
			printf("     Description: \033[1;4m%s\033[0m\n\n",
				in_laneDescription[i]);

		totNumPars += in_lanePar[i]; // Sum up total number of Pars
	}

	printf("Summary\n");
	printf("Total number of lanes: \033[1;4m%d\033[0m\n", *in_numLanes);
	printf("To get to Par, it requires number of throws:\033[1;4m%d\033[0m\n\n",
		totNumPars);
}
