/*
	MOVIES DATABASE IN C
	BY: SHAHOOD MIRZA

	DESCRIPTION: Movie database that reads records from a file and stores into a structure
	the database allows for insert, search and delete functions
*/

#include "Main.h"

//===================================================================//

int main(void) {
	struct MovieDB *pMovies = NULL;
	int flag=TRUE, recCount;
	char choice = '0';

	recCount = movieCounter();	//counts number of movies in file

	//allocate memory for dynamic structure
	pMovies = (struct MovieDB*)malloc(recCount*sizeof(struct MovieDB));

	readFile(pMovies, recCount);	//reads file and updates structure
	
	while(choice != '5') {
		header();

		printf("1. Display All Records\n");
		printf("2. Insert Records\n");
		printf("3. Search Records\n");
		printf("4. Delete Records\n");
		printf("5. Exit Program\n\n");

		printf("Which task would you like to perform? ");
		
		choice = getch();

		switch(choice) {
			case '1': {
				system("cls");
				header();
				
				displayRec(pMovies, recCount);
				
				footer();
				break;
			}
			case '2': {
				header();
				
				insertRec(pMovies);

				recCount = movieCounter();

				free(pMovies);
				pMovies = (struct MovieDB*)malloc(recCount*sizeof(struct MovieDB));
				readFile(pMovies, recCount);
				
				footer();
				break;
			}
			case '3': {
				header();
				
				searchMovies(pMovies, recCount);
				
				footer();
				break;
			}
			case '4': {
				header();
				
				deleteLines(pMovies, recCount);

				recCount = movieCounter();

				free(pMovies);
				pMovies = (struct MovieDB*)malloc(recCount*sizeof(struct MovieDB));
				readFile(pMovies, recCount);
				
				footer();
				break;
			}
			case '5': {
				free(pMovies);
				break;				
			}
			default: {
				printf("\n\nInvalid Input. Please try again.");
				getch();
			}
		}
	}
	return 0;
}

//===================================================================//

int movieCounter()
{
	FILE *pRecords;
	char linecount;
	int i, count = 0;

	pRecords = fopen(FileName, "r");	//open file for reading

	while(!feof(pRecords))	//count lines in file
	{
		fscanf(pRecords, "%c", &linecount);
		if(linecount == '\n')
		{
			count++;
		}
	}

	count--;	//remove last blank line from count
	fclose(pRecords);	//close file

	return(count/StructSize);	//count divided by structsize gives number of records
}

//===================================================================//

void readFile(struct MovieDB *pMovies, int recCount)
{
	FILE *pRecords;
	int i;
	char mYear[6], mRating[5];

	pRecords = fopen(FileName, "r");	//open file for reading

	//fseek(pRecords, 0L, SEEK_SET);  //set pointer to beginning of file

	for(i=0; i<recCount; i++)
	{
		//read file lines into structure
		fgets((pMovies+i)->title, ArraySize, pRecords);
		fgets(mYear, 6, pRecords);
		fgets((pMovies+i)->genre, 13, pRecords);
		fgets((pMovies+i)->actor, ArraySize, pRecords);
		fgets(mRating, 5, pRecords);

		//remove trailing newline
		(pMovies+i)->title[strlen((pMovies+i)->title)-1] = '\0';
		mYear[strlen(mYear)-1] = '\0';
		(pMovies+i)->genre[strlen((pMovies+i)->genre)-1] = '\0';
		(pMovies+i)->actor[strlen((pMovies+i)->actor)-1] = '\0';
		mRating[strlen(mRating)-1] = '\0';

		(pMovies+i)->rating = (float)atof(mRating);
		(pMovies+i)->year = (int)atoi(mYear);
	}

	fclose(pRecords);	//close file
}

//===================================================================//

void displayRec(struct MovieDB *pMovies, int recCount)
{
	int i;

	printf("Title\t\t\t\tYear\tGenre\t\tStars\t\t\t\tRating\n");
	printf("----------------------------------------------------------------------------------------------\n");

	for(i=0; i<recCount; i++)
	{
		printf("%-30s\t", (pMovies+i)->title);
		printf("%d\t", (pMovies+i)->year);
		printf("%-13s\t", (pMovies+i)->genre);
		printf("%-30s\t", (pMovies+i)->actor);
		printf("%.1f/10\n", (pMovies+i)->rating);
	}

	printf("\n\nMovies in Database: %d\n", recCount);
	printf("Display Complete\n");
}

//===================================================================//

void insertRec(struct MovieDB *pMovies)
{
	int i, numRecords;

	printf("\nHow many records will be inserted? ");
	fflush(stdin);
	
	//ensures entered value is a number
	if(scanf_s("%d", &numRecords))
	{  
		if(pMovies!=NULL)
		{
			getData(pMovies, numRecords);
			saveData(pMovies, numRecords);

			printf("\nNumber of Records Inserted: %d\n", numRecords);
			printf("Insert Complete\n");
		}	
	}
	else printf("\nERROR: Invalid entry. Expecting numeric value.\n");
}

//===================================================================//

void getData(struct MovieDB *pMovies, int numRecords)
{
	int i, mYear = 0;
	float mRating = -1;

	//loop iterates accoridng to the number of records being inserted
	//structure is overwritten and will be updated with file contents
	for(i=0;i<numRecords;i++)
	{  
		printf("\n[Record: %d]\n\n", i+1);

		printf("Enter the Movie Title: ");
		fflush(stdin);
		fgets((pMovies+i)->title,ArraySize,stdin);
		
		//first movie was made in 1878
		while((mYear > 2015) || (mYear < 1878))
		{
			printf("Enter the Year of Release (Numeric Values Only): ");
			fflush(stdin);
			scanf_s("%d", &mYear);
		}
		(pMovies+i)->year = mYear;

		printf("Enter the Genre: ");
		fflush(stdin);
		fgets((pMovies+i)->genre,13,stdin);		

		printf("Enter the Star Actor/Actress: ");
		fflush(stdin);
		fgets((pMovies+i)->actor,ArraySize,stdin);

		while((mRating > 10.0) || (mRating < 0.0))
		{
			printf("Enter the IMDB Rating (Out of 10): ");
			fflush(stdin);
			scanf_s("%f", &mRating);
		}
		(pMovies+i)->rating = mRating;
	}
}

//===================================================================//

void saveData(struct MovieDB *pMovies, int numRecords)
{
	FILE *pRecords = NULL;
	int i;

	pRecords = fopen(FileName, "a");

	if(pRecords!=NULL)
	{
		//append the data into the file
		for(i=0;i<=numRecords-1;i++) {
			fprintf (pRecords, "%s", (pMovies+i)->title);
			fprintf (pRecords, "%d\n", (pMovies+i)->year);
			fprintf (pRecords, "%s", (pMovies+i)->genre);
			fprintf (pRecords, "%s", (pMovies+i)->actor);
			fprintf (pRecords, "%.1f\n", (pMovies+i)->rating);
		}
		fclose(pRecords);
	}
}

//===================================================================//

void searchMovies(struct MovieDB *pMovies, int recCount)
{	
	char gSearch[ArraySize];
	int ySearch;
	char choice;
	int i, flag = FALSE;

	printf("Search By: 1. Year  2. Year + Genre\n");	//searching menu
	choice = getch();

	switch(choice)
	{
		case '1':
		{
			printf("Enter Year to Search by: ");
			fflush(stdin);
			scanf_s("%d", &ySearch);

			printf("\nTitle\t\t\t\tYear\tGenre\t\tStars\t\t\t\tRating\n");
			printf("----------------------------------------------------------------------------------------------\n");
			
			for(i=0; i<recCount; i++)
			{
				//compare year to find a matching movie
				if((pMovies+i)->year == ySearch)
				{
					flag = TRUE;
					printf("%-30s\t", (pMovies+i)->title);
					printf("%d\t", (pMovies+i)->year);
					printf("%-13s\t", (pMovies+i)->genre);
					printf("%-30s\t", (pMovies+i)->actor);
					printf("%.1f/10\n", (pMovies+i)->rating);
				}
			}

			if(flag == FALSE)
			{
				printf("\nYour search \"%d\" did not return any results.\n", ySearch);
			}

			break;
		}
		case '2':
		{
			printf("Enter Year to Search by: ");
			fflush(stdin);
			scanf_s("%d", &ySearch);
			printf("Enter Genre to Search by: ");
			fflush(stdin);
			gets_s(gSearch, ArraySize);

			printf("\nTitle\t\t\t\tYear\tGenre\t\tStars\t\t\t\tRating\n");
			printf("----------------------------------------------------------------------------------------------\n");

			for(i=0; i<recCount; i++)
			{
				//compare genre ingnoring case
				if(((pMovies+i)->year == ySearch) && (stricmp((pMovies+i)->genre, gSearch) == 0))
				{
					flag = TRUE;
					printf("%-30s\t", (pMovies+i)->title);
					printf("%d\t", (pMovies+i)->year);
					printf("%-13s\t", (pMovies+i)->genre);
					printf("%-30s\t", (pMovies+i)->actor);
					printf("%.1f/10\n", (pMovies+i)->rating);
				}
			}

			if(flag == FALSE)
			{
				printf("\nYour search \"%d + %s\" did not return any results.\n", ySearch, gSearch);
			}

			break;
		}
		default:
		{
			printf("\nInvalid Input.\n");
		}
	}
}

//===================================================================//

void deleteLines(struct MovieDB *pMovies, int count)	//this function will delete directly from the file
{
	FILE *pFile;	//pointing to buffer
	char line[ArraySize], mDel[ArraySize];
	char *buffer;	//pointers are 4 bytes, better than creating a buffer array 
	char *ptr;
	int flag = FALSE;

	buffer = (char *)malloc(1000*sizeof(char)); //passes the type and returns the size of that type
												//you want this buffer to initialized to zero
	memset(buffer, 0, 1000*sizeof(char));
	//buffer is that start adress, the value you want to store in each element which is zero
	//The number of bytes which is the same as above. when you allocate a buffer you have to zero it
	ptr = buffer;

	printf("Enter Movie Name to Delete: ");
	fflush(stdin);
	fgets(mDel, ArraySize, stdin);

	//open the file
	pFile = fopen(FileName, "r");

	if (pFile != NULL)
	{
		while (fgets(line, 50, pFile))
		{
			if (stricmp(line, mDel) == 0)  // changed from != to ==
			{
				//read and discard next 4 lines
				flag = TRUE;
				fgets(line, ArraySize, pFile);
				fgets(line, ArraySize, pFile);
				fgets(line, ArraySize, pFile);
				fgets(line, ArraySize, pFile);
			}
			else
			{
				strcpy(ptr, line);
				ptr += strlen(line);
			}
		}

		fclose(pFile);

		if (flag == FALSE)
		{
			printf("\nCould not find movie: %s", mDel);
		}
		else
		{
			printf("The movie was successfully removed from the database");
		
			pFile = fopen(FileName, "w");
			fprintf(pFile, "%s", buffer);
			fclose(pFile);
		}
	}
	else
	{
			printf("Could not open the file.\n");
	}
}

//===================================================================//

void header()
{
	system("cls");
	printf("-- MOVIE DATABASE --\n\n");
}

//===================================================================//

void footer()
{
	char cIn = ' ';
	
	while(cIn != 27)
	{
		printf("\n\nPress 'Esc' to return to Main Menu.");
		cIn = getch();
	}
}

//===================================================================//