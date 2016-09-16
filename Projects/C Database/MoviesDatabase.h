/*
	MOVIES DATABASE IN C
	BY: SHAHOOD MIRZA
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ArraySize 30
#define StructSize 5
#define FileName "records.txt"

//Function Prototypes
int movieCounter();
void readFile(struct MovieDB *pMovies, int recCount);
void displayRec(struct MovieDB *pMovies, int count);
void insertRec(struct MovieDB *pMovies);
void getData(struct MovieDB *pMovies, int numRecords);
void saveData(struct MovieDB *pMovies, int numRecords);
void searchMovies(struct MovieDB *pMovies, int recCount);
void deleteLines(struct MovieDB *pMovies, int count);
void header();
void footer();

//Structure Types
struct MovieDB
{
	int year;
	char title[ArraySize];
	char genre[13];
	char actor[ArraySize];
	float rating;
};