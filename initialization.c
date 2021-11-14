#include "push_swap.h"

long ft_atoi(const char *str)
{
	long res;
	int sign;

	res = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
		{
			sign *= -1;
			str++;
		}
		res = res * 10 + (*str++ - '0');
	}
	return (res * sign);
}

int	chk_int(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '-'))
			return (1);
		else if (str[i] == '-' && i != 0)
			return (1);
		else
			i++;
	}
	return (0);
}

int check_unique(t_list *steak, int num)
{
	while (steak)
	{
		if (steak->vol == num)
			return (1);

		steak = steak->next;
	}
	return (0);
}

int init_list(t_all *all, int ac, char **av)
{
	int i;
	long num;

	i = 1;
	while (i < ac)
	{
		if (chk_int(av[i]))
			return (put_err(""));
		else
		{
			num = ft_atoi(av[i]);
			if (check_unique(all->a_stack, (int)num))
				return (put_err(""));
			if (num > 2147483647 || num < -2147483648)
				return (put_err(""));;
			ft_lstadd_back(&all->a_stack, ft_lstnew((int)num));
		}
		i++;
	}
	return (0);
}