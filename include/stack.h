#pragma once

#define T stack_t
typedef struct T *T;

extern T stack_new(void);
extern int stack_empty(T);
extern void stack_push(T, void *);
extern void* stack_pop(T);
extern void stack_free(T);

#undef T