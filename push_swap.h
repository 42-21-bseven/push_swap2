#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int 			vol;
	struct s_list	*next;
	int 			stage;
}							t_list;

typedef struct s_all
{
	t_list 			*a_stack;
	t_list 			*b_stack;
	int 			start_len;
	int				current_len;
	int 			min_vol;
	int 			average;
	int 			chang_len;
	int				*mass;
}							t_all;

int	put_err(char *str);
size_t	ft_strlen(const char *s);
void ft_write(char *psr, char ab);
void bub_sort(int **arr, int len);

int init_args(t_all *all);
int init_list(t_all *all, int ac, char **av);

void swap_stack(t_list **list, char ab);
void push_stack(t_list **dest, t_list **srcs, char ab);
void rotate_stack(t_list **list, char ab);
void rev_rotate_stack(t_list **list, char ab);

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **list, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);


void sort(t_all *all);

#endif