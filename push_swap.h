
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack_a[STACK_SIZE];
int stack_b[STACK_SIZE];
int top_a = -1;
int top_b = -1;

typedef struct s_list
{
	char * content;
	struct s_list *next;
} t_list;

#endif