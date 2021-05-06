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
	return scanf("%d", &x->value);
}

void ITEMshow(Item x)
{
	printf("key:%d, value:%d \n", x->key, x->value);
}