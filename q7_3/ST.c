#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

typedef struct STnode *link;
struct STnode
{
	Item item;
	link l, r;
	int N;
};

static link head, z;

link NEW(Item item, link l, link r, int N)
{
	link x = malloc(sizeof(*x));
	x->item = item;
	x->l = l;
	x->r = r;
	x->N = N;
	return x;
}

void STinit(void)
{
	head = (z = NEW(NULLitem, NULL, NULL, 0));
}

int STcount(void)
{
	return head->N;
}

Item searchR(link h, Key v)
{
	Key t;
	if (h == z)
	{
		return NULLitem;
	}

	t = key(h->item);

	if (eqkey(v, t))
	{
		return h->item;
	}

	if (lesskey(v, t))
	{
		return searchR(h->l, v);
	}
	else
	{
		return searchR(h->r, v);
	}
}

Item STsearch(Key v)
{
	return searchR(head, v);
}

link insertR(link h, Item item)
{
	Key v, t;
	if (h == z)
	{
		return NEW(item, z, z, 1);
	}

	v = key(item);
	t = key(h->item);

	if (v < t)
	{
		h->l = insertR(h->l, item);
	}
	else
	{
		h->r = insertR(h->r, item);
	}

	(h->N)++;

	return h;
}

void STinsert(Item item)
{
	head = insertR(head, item);
}

void sortR(link h, void (*visit)(Item))
{
	if (h == z)
		return;
	sortR(h->l, visit);
	visit(h->item);
	sortR(h->r, visit);
}

void STsort(void (*visit)(Item))
{
	sortR(head, visit);
	printf("\n");
}

Item selectR(link h, int k)
{
	int t = h->l->N;
	if (h == z)
		return NULLitem;
	if (t > k)
		return selectR(h->l, k);
	if (t < k)
		return selectR(h->r, k - t - 1);
	return h->item;
}

Item STselect(int k)
{
	return selectR(head, k);
}

link rotR(link h)
{
	link x = h->l;
	h->l = x->r;
	x->r = h;
	return x;
}

link rotL(link h)
{
	link x = h->r;
	h->r = x->l;
	x->l = h;
	return x;
}

link partR(link h, int k)
{
	int t = h->l->N;
	if (t > k)
	{
		h->l = partR(h->l, k);
		h = rotR(h);
	}
	if (t < k)
	{
		h->r = partR(h->r, k - t - 1);
		h = rotL(h);
	}
	return h;
}

link joinLR(link a, link b)
{
	if (b == z)
	{
		return a;
	}
	b = partR(b, 0);
	b->l = a;
	return b;
}

link deleteR(link h, Key v)
{
	int p = 0;
	link x;
	Key t = key(h->item);

	if (h == z)
	{
		return z;
	}

	if (lesskey(v, t))
	{
		if (h->l != z)
		{
			p = 1;
		}
		h->l = deleteR(h->l, v);

		//check if we deleted a node
		if (h->l != z || (p == 1 && h->l == z))
		{
			--(h->N);
		}
	}

	if (lesskey(t, v))
	{
		if (h->r != z)
		{
			p = 1;
		}
		h->r = deleteR(h->r, v);

		//check if we deleted a node
		if (h->r != z || (p == 1 && h->r == z))
		{
			--(h->N);
		}
	}

	if (eqkey(v, t))
	{
		x = h;
		h = joinLR(h->l, h->r);
		free(x);
	}
	return h;
}

void STdelete(Key v)
{
	head = deleteR(head, v);
}

void keyAppearance(link h, Key v, int *count)
{
	if (h == z)
		return;
	keyAppearance(h->l, v, count);
	Key t = key(h->item);
	if (eqkey(t, v))
		(*count)++;
	keyAppearance(h->r, v, count);
}

void STdeleteAll(Key v)
{
	int count = 0;
	keyAppearance(head, v, &count);
	printf("\n\nkey %d occurs: %d\n\n", v, count);
	for (int i = 0; i < count; i++)
	{
		head = deleteR(head, v);
	}
}