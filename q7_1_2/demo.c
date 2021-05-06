/* code for the main program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Item.h"
#include "ST.h"

int main(void)
{
	Item x;
	srand(time(NULL));

	STinit();

	for (int i = 0; i < 9; i++)
	{
		x = malloc(sizeof(*x));
		x->key = i;
		x->value = rand() % 100;
		STinsert(x);
	}
	//Make sure that we have a duplicate with key=5
	x = malloc(sizeof(*x));
	x->key = 5;
	x->value = rand() % 100;
	STinsert(x);

	printf("Current count: %i\n", STcount());
	STsort(ITEMshow);

	Item y = STsearch(4);
	if (y != NULL)
	{
		printf("Found node with key=4\n");
		ITEMshow(y);
	}

	Item z = STselect(3);
	if (z != NULL)
	{
		printf("\nFound node with the 4rth (zero-index) smallest key / (select)\n");
		ITEMshow(z);
	}

	printf("\nDeleting node with key=1\n");
	STdelete(1);
	// STsort(ITEMshow);
	printf("\nDeleting all nodes with key=5\n");
	STdeleteAll(5);
	STsort(ITEMshow);

	printf("Current count: %i\n", STcount());

	return 0;
}