/**
*Obligatorisk oppgave 1
*
*Oppgave: Bibliotek
*
*Fremgang
*1.Globale variabler og funksjoner
*2.Metoder/funksjoner. 
*3.Kjore program, debug
*4.Forklaring og kommentere
*5.Optimaliser og husk minnefrigjoring!
*/

/**
*Interne includes
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
*Eksterne includes
*/



/**
* Definisjoner statiske verdier
*/
#define STRLEN_MAX 25


/**
* Enum for handteringav  switch caser
*/
enum HANDLING
{
	NY, /**< enum verdi NY */
	LES, /**< enum verdi LES */
	AVSLUTT /**< enum verdi AVSLUTT */
};


/**
* @struct Bok 
* @brief struct for Boker:
*En bok ineholder data en vanlig bok ville hat.
*/
struct Bok
{
	char mTittel[STRLEN_MAX]; /**< char array mTittel */
	char mSjanger[STRLEN_MAX]; /**< char array mSjanger */
	int mSider; /**< integer lokal variabel mSider */
};


/**
* For deklarasjon av funksjoner
*/
void Init();
void legg_til_bok();
void print_boker();
void fri_minne();

/**
*Globale variabler
*/
struct Bok** Bibliotek = NULL; /** Array av boker */
int antall_boker = 0;

/**
* main funksjon:
* Kjorer programmet.
*/
int main()
{
	printf("_______Init: Oblig1_______\n\n");
	Init();
	return 0;
}

/**
* Initialiserings funksjon:
* Kjorer terminalen og tar imot input fra bruker.
*/
void Init()
{
	/**
	   Init sorger for at terminalen gir riktig alternativer.
	   Kjorer dermed valgt alternativ.
	*/

	enum HANDLING tilstand = 0;
	printf("Handlinger:\n");
	printf("0 = legg til ny bok.\n");
	printf("1 = printer alle bokene.\n");
	printf("2 = avslutt.\n");
	printf("Velg Handling:");
	scanf_s("%d", &tilstand);
	while (getchar() != '\n'); //Tommer buffer
	printf("\n");
	switch (tilstand)
	{
	case NY:
	{
		legg_til_bok();
		break;
	}
	case LES:
	{
		print_boker();
		break;
	}
	case AVSLUTT:
	{
		fri_minne();
		exit(0);
		break;
	}
	default:
	{
		printf("Velg ett gyldig alternativ:\n");
		Init();
		printf("\n");
		break;
	}
	}
	tilstand = 0;
}

/**
* Legg til bok funksjon:
* Lager en ny bok og legger den til i biblioteket
*/
void legg_til_bok()
{
	// Lokale variabler for parameter verdier til bok
	char tittel[STRLEN_MAX] = "\0";
	char sjanger[STRLEN_MAX] = "\0";
	int sider = 0;

	//Ber om at bruker skriver inn info
	printf("[LOG]:Legger til Bok\n-----------------\n");
	printf("Legg til tittel:");
	gets_s(tittel, (unsigned)_countof(tittel));
	printf("Legg til sjanger:");
	scanf_s("%s", sjanger, (unsigned)_countof(sjanger));
	printf("Legg til antall sider:");
	scanf_s("%d",  &sider);
	while (getchar() != '\n'); //Tommer buffer

	/*Ny bok med allokert minne(allokerer minne :
	gjor klar en peker med samme antall bytes som parameteren) */
	struct Bok* ny_bok = malloc(sizeof(struct Bok));

	//Flag som sjekker om Bok-structen har storresle 0
	if (ny_bok == NULL)
	{
		printf("[WARNING]: Feil med minneallokering..\nReturnerer\n");
		exit(0);
	}

	//Kopier string fra parameter bok til lokal bok
	strcpy_s(ny_bok->mTittel,STRLEN_MAX, tittel);
	strcpy_s(ny_bok->mSjanger,STRLEN_MAX, sjanger);
	ny_bok->mSider = sider;

	//Bibliotek med oppdatert minne
	struct Bok** temp_lib = realloc(Bibliotek, sizeof(struct Bok*) * (antall_boker + 1)); 
	if (temp_lib == NULL)
	{
		printf("[WARNING]: Feil med minneallokering..\nReturnerer\n");  
		exit(0);
	}

	Bibliotek = temp_lib; //Oppdaterer arrayet sin storrelse
	Bibliotek[antall_boker] = ny_bok; //Oppdaterer elementet for gjeldende indeks
	antall_boker++; // Oppdaterer antall boker

	printf("-----------------\n[LOG]:Bok Lagt til\n\n");
	Init();
}

/**
* print boker funksjon:
* Printer ut alle boker i biblioteket.
* Printer i tillegg ut antall sider og boker lest totalt
*/
void print_boker()
{

	//Deklarerer midlertidige variabler
	int totalt_sider_lest = 0;

	printf("[LOG]:Printer info\n-----------------\n");

	//Flag som sjekker om arrayet er en null-peker eller ikke inneholder noen boker
	if (Bibliotek == NULL || antall_boker == 0)
	{
		printf("[WARNING]: Ingen boker lagt til. Legg til boker\n");
		printf("-----------------\n\n");
		Init();
		return;
	}

	//Itterer over alle bokene
	for (int i = 0; i < antall_boker; ++i)
	{
		totalt_sider_lest += Bibliotek[i]->mSider;
		printf("Navn: \x1b[1m\x1b[4m%s\x1b[0m \nSjanger: \x1b[1m\x1b[4m%s\x1b[0m\n\n", Bibliotek[i]->mTittel, Bibliotek[i]->mSjanger);
	}
	printf("Boker lest: \x1b[1m\x1b[4m%d\x1b[0m \nSider lest totalt: \x1b[1m\x1b[4m%d\x1b[0m\n", antall_boker, totalt_sider_lest);
	printf("-----------------\n[LOG]:Printing ferdig\n\n");

	Init();
}

/**
* fri minne funksjon:
* Frigjor minne for alle boker.
* Frigjor minne for arrayet av bok-pekere
*/
void fri_minne()
{
	// Frigjor minne: forst hver enkelt bok, dermed arrayet av Bok-pekere
	for (int i = 0; i < antall_boker; ++i)
	{
		free(Bibliotek[i]); 
	}
	free(Bibliotek);

	Bibliotek = NULL;
}