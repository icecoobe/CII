
#include "stack.h"

#include <assert.h>
#include <stdlib.h>

#define T stack_t
typedef struct T *T;
struct T {
	int count;
	struct element {
		void *x;
		struct element *link;
	} *head;
};

typedef struct element item_t;

T stack_new(void)
{
	T stk = (T)malloc(sizeof(struct T));
	stk->count = 0;
	stk->head = NULL;
	return stk;
}

int stack_empty(T stk)
{
	assert(stk);
	return stk->count == 0;
}

void stack_push(T stk, void *x)
{
	assert(stk);

	item_t *item = (item_t*)malloc(sizeof(item_t));
	item->x = x;
	item->link = NULL;

	if (stk->count == 0) // stack_empty(stk))
	{
		stk->head = item;
	}
	else
	{
		item_t *p = stk->head;
		while (p->link)
		{
			p = p->link;
		}
		p->link = item;
	}

	stk->count++;
}

void* stack_pop(T stk)
{
	assert(stk);

	if (stk->count == 0)
		return NULL;

	item_t *cur = stk->head;
	item_t *prev = stk->head;
	while (cur->link)
	{
		prev = cur;
		cur = cur->link;
	}

	
	void *x = cur->x;
	free(cur);
	prev->link = NULL;

	stk->count--;

	if (stk->count == 0)
		stk->head = NULL;

	return x;
}

void stack_free(T stk)
{
	assert(stk);
	
	item_t *p = stk->head;

	while (p)
	{
		item_t *next = p->link;
		free(p);
		p = next;
	}

	stk->count = 0;
	stk->head = NULL;
	free(stk);
}