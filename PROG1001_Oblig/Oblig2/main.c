/**
* OBLIG 4
* 
* HENSIKT:
*
*
*
* THE PROGRAM
*
* \file main.c
* \author Daniel AG
* 
* Includes:
* - stdio.h for displaying and feeding data
* - stdbool.h for using booleans
*/

//Internal Includes
#include <stdio.h> 
#include <stdbool.h> 


/**	
* \def MAXLANES 
* \brief Maximum number of lanes
*/ 
#define MAXLANES 18 

/**
* \def STRLEN
* \brief Maximum length of a string (array of char)
*/
#define STRLEN 100 
/** \}*/

/**
* \def CHOICES 
* \brief The choices diplayed in the terminal when running
*/
enum CHOICES
{
	ADD, ///< Generates a new Lane
	SEE, ///< Displays all Lanes and their data
	QUIT ///< Quits the program, terminates
};

int main()
{
	char laneDescription[MAXLANES][STRLEN] = {0,0}; // lane description 
	int laneLength[MAXLANES] = {0}; // lane length
	int lanePair[MAXLANES] = {0}; // lane pair

	bool laneOB = false; // lane OB

	int numLanes = 0; // number of lanes
}