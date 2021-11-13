#include "push_swap.h"

void swap_stack(t_list **list, char ab)
{
	int	temp;

	if (*list)
	{
		temp = (*list)->vol;
		if ((*list)->next)
		{
			(*list)->vol = (*list)->next->vol;
			(*list)->next->vol = temp;
			temp = (*list)->stage;
			(*list)->stage = (*list)->next->stage;
			(*list)->next->stage = temp;
		}
	}
	ft_write("s", ab);
}

void push_stack(t_list **dest, t_list **srcs, char ab)
{
	t_list *temp;

	if(*srcs)
	{
		temp = *srcs;
		if ((*srcs)->next)
			(*srcs) = (*srcs)->next;
		else
			(*srcs) = NULL;
		temp->next = NULL;
		ft_lstadd_front(dest, temp);
	}
	ft_write("p", ab);
}

void rotate_stack(t_list **list, char ab)
{
	t_list *temp;

	if (*list)
	{
		temp = (*list);
		if ((*list)->next)
		{
			(*list) = (*list)->next;
			temp->next = NULL;
			ft_lstadd_back(list, temp);
		}
//		else
//			(*list) = NULL;
	}
	ft_write("r", ab);
}

void rev_rotate_stack(t_list **list, char ab)
{
	t_list *temp;
	t_list *curr;

	if (*list && (*list)->next)
	{
		temp = ft_lstlast(*list);
		curr = *list;
		while (curr->next && curr->next->next)
			curr = curr->next;
		curr->next = NULL;
		temp->next = *list;
		*list = temp;
	}
	ft_write("rr", ab);
}