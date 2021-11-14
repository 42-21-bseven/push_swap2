#include "push_swap.h"


void short_sort(t_list **steak)
{
	int	last_a;

	last_a = max_index(*steak);
	while (is_stack_sorted(*steak) != 1)
	{
		if ((*steak)->index > (*steak)->next->index && (*steak)->index > last_a)
			rotate_stack(steak, 'a');
		else if ((*steak)->index > (*steak)->next->index)
			swap_stack(steak, 'a');
		else if (last_a < (*steak)->index)
			rev_rotate_stack(steak, 'a');
		else if (last_a < (*steak)->next->index)
			rev_rotate_stack(steak, 'a');
		last_a = max_index(*steak);
	}
}

void small_sort(t_all *all)
{
	int len;

	len = all->start_len;
	if (len > 3)
	{
		while (len != 3)
		{
			while (all->a_stack->index != min_index(all->a_stack))
			{
				if (how_location(min_index(all->a_stack), all->a_stack) <= 3)
					rotate_stack(&all->a_stack, 'a');
				else
					rev_rotate_stack(&all->a_stack, 'a');
			}
			if (is_stack_sorted(all->a_stack) == 1 && all->b_stack == NULL)
				break;
			push_stack(&all->b_stack, &all->a_stack, 'b');
			len--;
		}
	}
	short_sort(&all->a_stack);
	while (all->b_stack != NULL)
		push_stack(&all->a_stack, &all->b_stack, 'a');
}

void sort_ver_two(t_all *all)
{
	bub_sort(&all->mass, all->start_len);
	get_index(all, all->a_stack);

	if (all->start_len <= 5)
		small_sort(all);
	else
		sort_alg(all);
}

int main(int ac, char **av)
{
	t_all all;
	t_list *curr;

	all.argc = ac;
//	int flag;
//	t_list *test;
//
//	flag = 33;

	if (ac < 2)
		return (1);

	init_args(&all);

	if (init_list(&all, ac, av))
		return (1);

	init_array(&all, all.a_stack, av);

	sort_ver_two(&all);






//	sort(&all);


//	all.current_len = current_len(all.a_stack);

/*	while (flag)
	{
		while (test)
		{
			if (test->next && test->vol > test->next->vol)
				rotate_stack(&test);
			else
				push_stack(&all.b_stack, &test);
		}
		if (test == NULL)
			flag = 0;
	}
*/
//	curr = all.a_stack;
//	printf("\nstack A:\t");
//	while (curr)
//	{
//		printf("%d\t", curr->vol);
//		curr = curr->next;
//	}
//	curr = all.b_stack;
//	printf("\nstack B:\t");
//	while (curr)
//	{
//		printf("%d\t", curr->vol);
//		curr = curr->next;
//	}
//	printf("\n");
//	return (0);
}