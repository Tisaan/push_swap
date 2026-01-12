/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:37:04 by tseche            #+#    #+#             */
/*   Updated: 2026/01/12 16:39:05 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min(t_info *a)
{
	size_t	i;
	int		min;

	min = a->data[0].value;
	i = 1;
	while (i < a->size)
	{
		if (a->data[i].value < min)
			min = a->data[i].value;
		i++;
	}
	return (min);
}

void	sa(t_info *a)
{
	t_data	tmp;

	tmp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = tmp;
	write(1, "sa\n", 3);
}

void	tiny_sort(t_info *a, t_info *b)
{
	if (!is_sorted(a))
		return ;
	if (a->size <= 3)
		sort_3(a);
	else
		sort_4_5(a, b);
}

void	sort_3(t_info *a)
{
	while (is_sorted(a))
	{
		if (a->data[0].value > a->data[1].value
			&& a->data[0].value > a->data[a->size - 1].value)
			ra(a);
		else if (a->data[0].value > a->data[1].value)
			sa(a);
		else
			rra(a);
	}
}

void	sort_4_5(t_info *a, t_info *b)
{
	int	nb_op;

	nb_op = a->size - 3;
	while (a->size - 3)
	{
		if (a->data[0].value == min(a))
			pb(a, b);
		else
			ra(a);
	}
	sort_3(a);
	while (nb_op--)
		pa(a, b);
}
