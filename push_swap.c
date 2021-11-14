#include "push_swap.h"


int chk_unique(t_all *all, int arg, int len)
{
	while (len > 0)
	{
		if (arg == *all->mass)
			return (1);
		all->mass++;
		len--;
	}
	return (0);
}

int init_array(t_all *all, t_list *steak, char **av)
{
	int i;

	i = 0;
	all->mass = malloc(sizeof (int) * all->start_len);
	while (steak)
	{
		all->mass[i++] = steak->vol;
		steak = steak->next;
	}
	return (0);

}

int get_index(t_all *all, t_list *steak)
{
	int i;

	while (steak)
	{
		i = 0;
		while (i < all->start_len)
		{
			if (all->mass[i] == steak->vol)
			{
				steak->index = i;
				break;
			}
			i++;
		}
		steak = steak->next;
	}
	return (0);
}

//void markup_head(t_all all)
//{
//	int best_continuity_grt_then;
//	int best_continuity_pls_one;
//
//	while ()
//
//
//}

int is_sorted(t_list *steak)
{
	while (steak->next)
	{
		if (steak->next->index != steak->index + 1)
			return (0);
		steak = steak->next;
	}
	return (1);
}

void push_from_a_to_b(t_all *all, int bit)
{
	int label;

	while (((all->a_stack->index) >> bit & 1) == 0)
		push_stack(&all->b_stack, &all->a_stack, 'b');
	label = all->a_stack->index;
	rotate_stack(&all->a_stack, 'a');
	while (all->a_stack->index != label)
		if (((all->a_stack->index) >> bit & 1) == 0)
			push_stack(&all->b_stack, &all->a_stack, 'b');
		else
			rotate_stack(&all->a_stack, 'a');
}

void push_from_b_to_a(t_all *all)
{
	while (all->b_stack)
		push_stack(&all->a_stack, &all->b_stack, 'a');
}

void sort_alg(t_all *all)
{
	int bit;

	bit = 0;
	while (!(is_sorted(all->a_stack)))
	{
		push_from_a_to_b(all, bit);
		push_from_b_to_a(all);
		bit++;
	}
}

int	min_index(t_list *steak)
{
	int min_order;

	min_order = steak->index;
	while (steak != NULL) {
		if (steak->index < min_order)
			min_order = steak->index;
		steak = steak->next;
	}
	return (min_order);
}

int	how_location(int index, t_list *steak)
{
	int	i;

	i = 1;
	while (steak->index != index)
	{
		steak = steak->next;
		i++;
	}
	return (i);
}

int	is_stack_sorted(t_list *steak)
{
	while (steak->next != NULL)
	{
		if (steak->vol > steak->next->vol)
			return (0);
		steak = steak->next;
	}
	return (1);
}

int max_index(t_list *steak)
{
//	while (steak->next != NULL)
//		steak = steak->next;
//	return (steak->index);
	ft_lstlast(steak);
	return (steak->index);
}

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