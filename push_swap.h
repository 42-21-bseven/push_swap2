/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseven <bseven@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:36:04 by bseven            #+#    #+#             */
/*   Updated: 2021/11/14 18:36:07 by bseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				vol;
	struct s_list	*next;
	int				index;
	int				stage;
}							t_list;

typedef struct s_all
{
	t_list			*a_stack;
	t_list			*b_stack;
	int				argc;
	int				start_len;
	int				*mass;
}							t_all;

int		put_err(char *str);
size_t	ft_strlen(const char *s);
void	ft_write(char *psr, char ab);
void	bub_sort(int **arr, int len);

void	init_args(t_all *all);
int		init_list(t_all *all, int ac, char **av);
int		init_array(t_all *all, t_list *steak, char **av);

void	sort_alg(t_all *all);

int		get_index(t_all *all, t_list *steak);
int		min_index(t_list *steak);
int		max_index(t_list *steak);
int		is_sorted(t_list *steak);
int		how_location(int index, t_list *steak);
int		is_stack_sorted(t_list *steak);

long	ft_atoi(const char *str);

void	swap_stack(t_list **list, char ab);
void	push_stack(t_list **dest, t_list **srcs, char ab);
void	rotate_stack(t_list **list, char ab);
void	rev_rotate_stack(t_list **list, char ab);

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **list, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	sort(t_all *all);

#endif
