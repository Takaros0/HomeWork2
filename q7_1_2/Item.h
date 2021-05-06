#pragma once

#define key(A)          (A->key)
#define less(A,B)       (key(A) < key(B))
#define lesskey(A,B)    (A < B)
#define eq(A,B)         (key(A) == key(B))
#define eqkey(A,B)      (A == B)

#define NULLitem NULL

typedef int Key;
typedef int Value;

typedef struct {
	Key  key;
	Value value;
} *Item;


Key ITEMrand(void);
int ITEMscan(Item);
void ITEMshow(Item);