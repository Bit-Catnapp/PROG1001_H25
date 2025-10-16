/**
 *  Skjelett/grunnlag for oblig nr 3 i GrProg, høsten 2025.
 *
 * @file    Oblig3.tpl
 * @author  Malin Foss, William Eide Seiner & FrodeH
 */


#include <stdio.h>    //  printf, scanf
#include <stdbool.h>  //  bool
#include <ctype.h>    //  toupper


#define ANTRUTER 9  ///<  Antall ruter på brettet
#define STRLEN 80   ///<  Tekstlengde

void nullstillBrett();
bool sjekkBrett(const int n);
bool sjekkVinner();
void skrivBrett();
int  spillSpillet();


char gBrett[ANTRUTER];  ///<  Spillebrettet.


/**
 * Hovedprogrammet.
 */
int main() {
	char spiller1[STRLEN];   //  Begge spillernes navn.
	char spiller2[STRLEN];
	char nyttSpill;          //  Kjøre programmet/spillet EN gang til.
	int  vinner;             //  Evt. spillernummer som har vunnet.

	do {
		nullstillBrett();

		skrivBrett();

		printf("\n\nNavn på spiller 1:  ");     gets(spiller1);
		printf("Navn på spiller 2:  ");         gets(spiller2);  printf("\n");

		vinner = spillSpillet();

		if (vinner == 1) printf("\nGratulerer %s!!\n\n", spiller1);
		else if (vinner == 2) printf("\nGratulerer %s!!\n\n", spiller2);
		//  'vinner' == 0:
		else    printf("\nIngen vinner denne gangen dessverre.\n\n");

		printf("\n\nEn ny runde (N/j):  ");
		scanf_s(" %c", &nyttSpill, 1);  nyttSpill = toupper(nyttSpill);
		while(getchar() != '\n');
		
	} while (nyttSpill == 'J');

	return 0;
}


/**
 *  Nullstiller/blanker ut alle brettets ruter.
 */
void nullstillBrett() {

	//     Lag innmaten

	for (int i = 0; i < ANTRUTER; i++)
	{
		gBrett[i] = ' ';
	}
}


/**
 *  Finner ut om et trekk er gyldig eller ei.
 *
 *  @param    n   - Ruten (0-8) det forsøkes å sette en brikke i
 *  @return	  Om det var mulig å sette brikken der (true) eller ei (false)
 */
bool sjekkBrett(const int n) {

	//     Lag innmaten
}


/**
 *  Sjekker om noen har tre på rad i en eller annen retning.
 *
 *  @return   Om noen har tre på rad (true) eller ei (false) i noen retning
 */
bool sjekkVinner() {

	//     Lag innmaten
}


/**
 *  Skriver ut spillebrettet.
 */
void skrivBrett() {

	//     Lag innmaten
	const int rekke = 3;
	const int rad = 6;
	int num = 1;

	// Nummererte linjer
	for (int i = 0; i < rad; i++)
	{
		if(i%2 == 0) ///Flag:handles even number logic
		{
			printf("-");
			for (int j = 0; j < rekke; j++)
			{
				printf("--%d--", num);
				printf("-");
				num += 1;
			}
			printf("\n");
		}
		else ///Flag:handles odd number logic
		{
			printf("|");
			for (int k = 0; k < rekke; k++)
			{
				printf("     |");
			}
			printf("\n");
		}
	}

	for (int j = 0; j < rekke; j++)
	{
		printf("-");
	}
	num = 0;
}

/**
 *  Lar spillerne sette brikker, og finner evt en vinner.
 *
 *  @return   Spillernummeret som har vunnet (1, 2), evt. 0 (ingen vinner)
 *  @see      sjekkBrett(...)
 *  @see      skrivBrett(...)
 *  @see      sjekkVinner(...)
 */
int spillSpillet() {

	//     Lag innmaten
}

