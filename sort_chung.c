#include "push_swap.h"

int ft_search_min_vol(t_list *steak)
{
	int min_vol;

	min_vol = steak->vol;
	while (steak)
	{
		if (steak->vol < min_vol)
		{
			min_vol = steak->vol;
			steak = steak->next;
		}
		else
			steak = steak->next;
//		printf("%p\t%d\n", steak, min_vol);
//		steak = steak->next;
	}
	return (min_vol);
}

int current_len(t_list *steak)
{
	int i;

	i = 0;
	while (steak)
	{
		steak = steak->next;
		i++;
	}
	return (i);
}

void ft_average_index(t_all *all, t_list *steak, int stage)
{
	int i;

	i = 0;
	all->mass = malloc(sizeof(int) * all->current_len);
	while (steak)
	{
		if (steak->stage == stage)
			all->mass[i++] = steak->vol;
		steak = steak->next;
	}
	bub_sort(&all->mass, all->current_len);
	all->average = all->mass[i / 2];
	if (all->mass)
		free(all->mass);
}

int ft_search_average(t_all *all, t_list *steak, int group)
{
	int i;
	int current_group;
	t_list *current;

	i = 0;
	current = steak;
	current_group = group;
	while (current)
	{
		if (current_group == current->stage)
			i++;
		current = current->next;
	}
	all->current_len = i;
	ft_average_index(all, steak, current_group);
}

int search_stage(t_list *steak)
{
	int i;

	i = 0;
	if (steak)
		i = steak->stage;
	while (steak)
	{
		if (steak->stage < i)
			i = steak->stage;
		steak = steak->next;
	}
	return (i);
}

int rev_search_stage(t_list *steak)
{
	int i;

	i = 0;
	if (steak)
		i = steak->stage;
	while (steak)
	{
		if (steak->stage > i)
			i = steak->stage;
		steak = steak->next;
	}
	return (i);
}

int ft_search_stage_elements(t_list *steak, int average)
{
	while (steak)
	{
		if (steak->vol < average)
			return (1);
		steak = steak->next;
	}
	return (0);
}

int	ft_rev_search_stage_elements(t_list *steak, int average)
{
	while (steak)
	{
		if (steak->vol >= average)
			return (1);
		steak = steak->next;
	}
	return (0);
}

int	push_chang(t_all *all, int stage)
{
//	printf("average=> %d\tSTAGE=> %d\tCUR_LEN=> %d\n", all->average, stage, all->current_len);

	while (ft_search_stage_elements(all->a_stack, all->average))
	{
		if (all->b_stack && all->b_stack->next && all->b_stack->vol < all->b_stack->next->vol)
			swap_stack(&all->b_stack, 'b');
		if (all->a_stack->vol < all->average)
		{
			all->a_stack->stage = stage;
			push_stack(&all->b_stack, &all->a_stack, 'b');
		}
		else
		if ((ft_lstlast(all->a_stack))->vol < all->average)
		{
			rev_rotate_stack(&all->a_stack, 'a');
			all->a_stack->stage = stage;
			push_stack(&all->b_stack, &all->a_stack, 'b');
		}
		else
			rotate_stack(&all->a_stack, 'a');
	}
	return (0);
}

int rev_push_chang(t_all *all, int stage)
{
	while (ft_rev_search_stage_elements(all->b_stack, all->average))
	{
		if (all->a_stack && all->a_stack->next && all->a_stack->vol > all->a_stack->next->vol)
			swap_stack(&all->a_stack, 'a');
		if (all->b_stack->next && all->b_stack->vol > all->average)
		{
			rotate_stack(&all->b_stack, 'b');
			all->b_stack->stage = stage;
			push_stack(&all->a_stack, &all->b_stack, 'a');
			rev_rotate_stack(&all->b_stack, 'b');
		}
		if (all->b_stack->vol >= all->average)
		{
			all->b_stack->stage = stage;
			push_stack(&all->a_stack, &all->b_stack, 'a');
		}
		else
			rotate_stack(&all->b_stack, 'b');
	}
	return (0);
}

int ft_check(t_list *steak)
{
	t_list *head;
	t_list *current;

	head = steak;
	while (steak)
	{
		current = head;
		while (current != steak)
		{
			if (current->vol > steak->vol)
				return (1);
			current = current->next;
		}
		steak = steak->next;
	}
	return (0);
}

void sort(t_all *all)
{
	int stage;

	stage = 0;
	while (ft_check(all->a_stack)
		   && ft_check(all->a_stack))
	{
		while (current_len(all->a_stack)
			   && current_len(all->a_stack) > 2)
		{
			ft_search_average(all, all->a_stack, search_stage(all->a_stack));
			push_chang(all, stage++);
			if (current_len(all->a_stack) < 3)
			{
				if(all->a_stack && all->a_stack->next && all->a_stack->vol > all->a_stack->next->vol)
					swap_stack(&all->a_stack, 'a');
				break;
			}
		}
		while (current_len(all->b_stack) > 1)
		{
			ft_search_average(all, all->b_stack, rev_search_stage(all->b_stack));
			rev_push_chang(all, stage++);
		}
		push_stack(&all->a_stack, &all->b_stack, 'a');
		if (all->a_stack && all->a_stack->next && all->a_stack->vol > all->a_stack->next->vol)
			swap_stack(&all->a_stack, 'a');
	}
}