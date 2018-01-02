
#include <stddef.h>
#include <stdio.h>

#include "stack.h"

int check_div(int a, int b);

// #define isBadPtr(p) ((p == 0 || (size_t)p % 8) ? 1 : 0)
#define isBadPtr(p) (!p ? 1 : (size_t)p % 8 != 0) // bad

int main(void)
{
	stack_t stk = stack_new();
	double d = 0.02;
	int a = 5;
	double d2 = 0.02;
	int b = 4;

	printf("sizeof(unsigned long)=%d\nsizeof(size_t)=%d\n", sizeof(unsigned long), sizeof(size_t));
	if (sizeof(void*) == 8)
		printf("########### 64 bit machine!\n");

	printf("%d\n", isBadPtr(&d));
	printf("%d\n", isBadPtr(0));
	printf("%d\n", isBadPtr(1));
	printf("%d\n", isBadPtr(8));

	printf("%X, %X\n", (unsigned)&d, (unsigned)&d2);

	printf("%ld, %ld\n",sizeof(double *), sizeof(int ));
	printf("empty = %d\n", stack_empty(stk));
	stack_push(stk, &a);
	stack_push(stk, &b);

	printf("empty = %d\n", stack_empty(stk));
	void *p = stack_pop(stk);
	printf("top is =%d\n", *(int*)p);
	stack_free(stk);

	printf("stk address = %X\n", (unsigned)stk);

	a = -13;
	b = 5;

	int i = check_div(a, b);
	//printf("%d, %d\n", a / b == -2,  i == -2);
	printf("%d\n", i);
	return 0;
}

int check_div(int a, int b)
{
	return a / b;
}