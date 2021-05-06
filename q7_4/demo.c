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

	link head = STinit();

	for (int i = 0; i < 6; i++)
	{
		x = malloc(sizeof(*x));
		x->key = i;
		x->value = rand() % 100;
		STinsert(&head, x);
	}
	//Make sure that we have a duplicate with key=5
	x = malloc(sizeof(*x));
	x->key = 5;
	x->value = rand() % 100;
	STinsert(&head, x);

	printf("Current count: %i\n", STcount(head));
	STsort(head, ITEMshow);

	Item y = STsearch(head, 4);
	if (y != NULL)
	{
		printf("Found node with key=4\n");
		ITEMshow(y);
	}

	Item z = STselect(head, 3);
	if (z != NULL)
	{
		printf("\nFound node with the 4rth (zero-index) smallest key / (select)\n");
		ITEMshow(z);
	}

	printf("\nDeleting node with key=1\n");
	STdelete(&head, 1);
	// STsort(ITEMshow);
	printf("\nDeleting all nodes with key=5\n");
	STdeleteAll(&head, 5);
	STsort(head, ITEMshow);
	printf("Current count: %i\n", STcount(head));


	// SECOND SYMBOL TABLE
	printf("\n\n~~~SECOND SYMBOL TABLE~~~\n");
	link head_2 = STinit();

	for (int i = 0; i < 6; i++)
	{
		x = malloc(sizeof(*x));
		x->key = i;
		x->value = rand() % 100;
		STinsert(&head_2, x);
	}
	//Make sure that we have a duplicate with key=5
	x = malloc(sizeof(*x));
	x->key = 5;
	x->value = rand() % 100;
	STinsert(&head_2, x);

	printf("Current count: %i\n", STcount(head_2));
	STsort(head_2, ITEMshow);

	Item a = STsearch(head_2, 4);
	if (a != NULL)
	{
		printf("Found node with key=4\n");
		ITEMshow(a);
	}

	Item b = STselect(head_2, 3);
	if (b != NULL)
	{
		printf("\nFound node with the 4rth (zero-index) smallest key / (select)\n");
		ITEMshow(b);
	}

	printf("\nDeleting node with key=1\n");
	STdelete(&head_2, 1);
	// STsort(ITEMshow);
	printf("\nDeleting all nodes with key=5\n");
	STdeleteAll(&head_2, 5);
	STsort(head_2, ITEMshow);
	printf("Current count: %i\n", STcount(head_2));

	return 0;
}