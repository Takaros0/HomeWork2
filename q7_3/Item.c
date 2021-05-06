#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"

int ITEMrand(void)
{
	srand(time(NULL));
	return rand();
}

int ITEMscan(Item x)
{
	scanf("%s", x->first);
	return scanf("%s", x->last);
}

void ITEMshow(Item x)
{
	printf("id:%d, First:%s, Last:%s \n", key(x), x->first, x->last);
}