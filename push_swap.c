#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void sa(int *array, int size)
{
	if(!array || size < 1)
		return ;
	if(size > 1)
	{
		int temp;
		temp = array[0];
		array[0] = array[1];
		array[1] = temp;
	}

}
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void sb(int *array, int size)
{
	if(!array || size < 1)
		return ;
	if(size > 1)
	{
		int temp;
		temp = array[0];
		array[0] = array[1];
		array[1] = temp;
	}
}
// ss : sa and sb at the same time.
void ss(int * array_a, int * array_b, int size_a, int size_b)
{
	if(!array_a || !array_b || size_a < 1 || size_b < 1)
		return ;
	if(size_a > 1)
	{
		int temp;
		temp = array_a[0];
		array_a[0] = array_a[1];
		array_a[1] = temp;
	}
	if(size_b > 1)
	{
		int temp;
		temp = array_b[0];
		array_b[0] = array_b[1];
		array_b[1] = temp;
	}
}
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void pa(int *array_a , int * array_b, int *size_a, int *size_b)
{
	int	i;
	int	j;

	if(!array_a || !array_b || *size_b < 1)
		return ;
	i = 0;
	j = 0;
	if(*size_b >= 1)
	{
		j = *size_a;
		while(j > 0)
		{
			array_a[j] = array_a[j - 1];
			j--;
		}
		array_a[0] = array_b[0];

		while(i < *size_b - 1)
		{
			array_b[i] = array_b[i + 1];
			i++;
		}
	}
	(*size_a)++;
	(*size_b)--;
}
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void pb(int *array_a , int * array_b, int *size_a, int *size_b)
{
	int	i;
	int	j;

	if(!array_a || !array_b || *size_a < 1)
		return ;
	i = 0;
	j = 0;
	if(*size_a >= 1)
	{
		j = *size_b;
		while(j > 0)
		{
			array_b[j] = array_b[j - 1];
			j--;
		}
		array_b[0] = array_a[0];

		while(i < *size_a - 1)
		{
			array_a[i] = array_a[i + 1];
			i++;
		}
	}
	(*size_b)++;
	(*size_a)--;
}
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void ra(int *array_a, int size)
{
	int temp;
	int 	i;
	
	if(!array_a || size < 1)
		return ;
	i = 0;
	if(size > 1)
	{
		temp = array_a[i];
		while(i < size - 1)
		{
			array_a[i] = array_a[i + 1];
			i++;
		}
		array_a[size - 1] = temp;
	}
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void rb(int *array_b, int size)
{
	ra(array_b, size);
}
// rr : ra and rb at the same time.

void rr(int *array_a,int *array_b, int size_a, int size_b)
{
	ra(array_a, size_a);
	rb(array_b, size_b);
}
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

void rra(int *array_a, int size_a)
{
	int temp;
	int 	i;

	if(!array_a || size_a < 1)
		return ;
	
	i = 0;
	if(size_a > 1)
	{
		temp = array_a[size_a - 1];
		i = size_a - 1;
		while(i > 0)
		{
			array_a[i] = array_a[i - 1];
			i--;
		}
		array_a[0] = temp;
	}
}
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void rrb(int *array_b, int size_b)
{
	rra(array_b, size_b);
}
// rrr : rra and rrb at the same time.
void rrr(int *array_a, int *array_b, int size_a, int size_b)
{
	rra(array_a, size_a);
	rrb(array_b, size_b);
}
