#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

static link z;

link NEW(void)
{
	link x = malloc(sizeof(*x));
	x->count = 0;
	x->item[0] = x->item[1] = x->item[2] = NULLitem;
	x->child[0] = x->child[1] = x->child[2] = x->child[3] = NULL;
	return x;
}

link STinit(void)
{
	link head = (z = NEW());
	return head;
}

//Search given node for key
//Return 1 if i found key
//Return 0 if key wasnt found
int searchNode(Key v, link curr, int *pos)
{
	if (v < key(curr->item[0]))
	{
		*pos = 0;
		return 0;
	}
	else
	{
		*pos = curr->count - 1;

		while ((v < key(curr->item[*pos]) && *pos > 0))
			(*pos)--;
		if (v == key(curr->item[*pos]))
			return 1;
		else
			return 0;
	}
}

link search(Key v, link h, int *pos)
{
	if (h == z)
	{
		return NULL;
	}
	else
	{
		if (searchNode(v, h, pos))
		{
			return h;
		}
		else
		{
			return search(v, h->child[*pos], pos);
		}
	}
}

Item STsearch(link head, Key v)
{
	int pos;
	link searchResult = search(head, v, &pos);
	if (searchResult == z)
		return NULL;
	else
		return searchResult->child[pos];
}