/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:55:52 by tseche            #+#    #+#             */
/*   Updated: 2026/01/10 19:14:06 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_info *a, t_info *b)
{
	size_t	i;

	if (!b->size)
		return ;
	i = a->size;
	while (i)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = b->data[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_info *a, t_info *b)
{
	size_t	i;

	if (!a->size)
		return ;
	i = b->size;
	while (i)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = a->data[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}

void	ra(t_info *a)
{
	t_data	tmp;
	size_t	i;

	if (a->size <= 1)
		return ;
	tmp = a->data[0];
	i = 0;
	while (i < a->size -1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->size - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rra(t_info *a)
{
	t_data	tmp;
	size_t	i;

	if (a->size <= 1)
		return ;
	tmp = a->data[a->size - 1];
	i = a->size - 1;
	while (i)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = tmp;
	write(1, "rra\n", 4);
}
