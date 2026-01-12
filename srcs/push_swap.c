/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:33:11 by tseche            #+#    #+#             */
/*   Updated: 2026/01/12 16:39:38 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix(size_t bitmax, t_info *a, t_info *b)
{
	size_t	curr_bit;
	size_t	size;
	size_t	iter;

	if (!is_sorted(a))
		return ;
	curr_bit = 0;
	while (curr_bit < bitmax)
	{
		iter = 0;
		size = a->size;
		while (iter < size)
		{
			if (((a->data[0].index >> curr_bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			iter++;
		}
		while (b->size)
			pa(a, b);
		curr_bit++;
	}
}

size_t	get_bits_max(t_info *stack)
{
	size_t	max;
	size_t	i;
	size_t	bits;
	int		copy;

	max = 0;
	i = 0;
	while (i < stack->size)
	{
		copy = stack->data[i].index;
		bits = 0;
		while (copy)
		{
			copy >>= 1;
			bits++;
		}
		if (bits > max)
			max = bits;
		i++;
	}
	return (max);
}

int	algo(char *av, size_t size)
{
	t_info	*a;
	t_info	*b;
	size_t	bitmax;

	a = stack_init_fill(av, size);
	if (duplicate(a))
	{
		free_stack(a);
		return (1);
	}
	b = stack_init_fill(NULL, size);
	bitmax = get_bits_max(a);
	if (!a || !b)
		return (0);
	if (a->size <= 5)
		tiny_sort(a, b);
	else
		radix(bitmax, a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

int	start(char *arg, int *ret)
{
	int	err;

	err = algo(arg, ret[1]);
	if (err)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*arg;
	int		*ret;
	int		err;

	if (ac < 1 || is_empty(av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	arg = join_av(ac, av);
	if (!arg || !*arg)
		return (0);
	ret = check(arg);
	if (ret[0])
	{
		free(ret);
		write(2, "Error\n", 6);
		return (1);
	}
	err = start(arg, ret);
	free(ret);
	return (0);
}
