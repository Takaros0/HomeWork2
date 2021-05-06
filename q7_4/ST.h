#include "Item.h"

typedef struct STnode *link;
struct STnode
{
	Item item;
	link l, r;
	int N;
};

link STinit(void);
int STcount(link);
void STinsert(link*, Item);
Item STsearch(link, Key);
void STdelete(link*, Key);
void STdeleteAll(link*, Key);
Item STselect(link, int);
void STsort(link,void (*visit)(Item));