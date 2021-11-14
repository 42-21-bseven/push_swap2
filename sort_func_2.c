#include "push_swap.h"

int	is_sorted(t_list *steak)
{
	while (steak->next)
	{
		if (steak->next->index != steak->index + 1)
			return (0);
		steak = steak->next;
	}
	return (1);
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
