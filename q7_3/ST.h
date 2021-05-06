#include "Item.h"

void STinit(void);
 int STcount();
void STinsert(Item);
Item STsearch(Key);
void STdelete(Key);
void STdeleteAll(Key);
Item STselect(int);
void STsort(void (*visit)(Item));