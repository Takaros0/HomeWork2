#include "Item.h"

typedef struct STnode *link;
struct STnode
{
	int count;
	Item item[3];
	link child[4];
};

link STinit(void);
int STcount(link);
void STinsert(link*, Item);
Item STsearch(link, Key);
void STdelete(link*, Key);
void STdeleteAll(link*, Key);
Item STselect(link, int);
void STsort(link,void (*visit)(Item));