/* code for the main program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Item.h"
#include "ST.h"

int main(void)
{
	char first[10][20] = {"Takaros", "Panagiotis", "Takis", "Panos", "Giannis", "Dinos", "Achilles", "Akis", "Jason", "The"};
	char last[10][20] = {"Kakalis", "Kakalis", "Kakalis", "Kakalis", "Papadopoulos", "Kakalis", "Kakalis", "Petretzikis", "Statham", "Rock"};
	Item x;
	srand(time(NULL));
	STinit();

	for (size_t i = 0; i < 10; i++)
	{
		x = malloc(sizeof(*x));
		x->id = i;
		x->first = strdup(first[i]);
		x->last = strdup(last[i]);
		STinsert(x);
	}
	//Make sure that we have a student with a duplicateid=5
	x = malloc(sizeof(*x));
	x->id = 5;
	x->first = strdup(first[5]);
	x->last = strdup(last[5]);
	STinsert(x);

	printf("Current count: %i\n", STcount());
	STsort(ITEMshow);

	Item y = STsearch(4);
	if (y != NULL)
	{
		printf("Found student with id=4\n");
		ITEMshow(y);
	}

	Item z = STselect(3);
	if (z != NULL)
	{
		printf("\nFound student with the 4rth (zero-index) smallest id / (select)\n");
		ITEMshow(z);
	}

	printf("\nDeleting student with id=1\n");
	STdelete(1);
	// STsort(ITEMshow);
	printf("\nDeleting all students with id=5\n");
	STdeleteAll(5);
	STsort(ITEMshow);

	printf("Current count: %i\n", STcount());

	return 0;
}