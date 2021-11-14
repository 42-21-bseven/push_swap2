#include "push_swap.h"

int init_args(t_all *all)
{
	all->start_len = all->argc - 1;
	all->a_stack = NULL;
	all->b_stack = NULL;
	all->mass = NULL;
}