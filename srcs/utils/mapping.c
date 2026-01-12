/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:34:24 by tseche            #+#    #+#             */
/*   Updated: 2026/01/09 17:30:45 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	mapping(t_info *a)
{
	size_t	i;
	size_t	j;

	if (a->size == 0)
		return ;
	i = 0;
	a->data[0].index = 0;
	while (i < a->size - 1)
	{
		i++;
		a->data[i].index = 0;
		j = 0;
		while (j < i)
		{
			if (a->data[i].value > a->data[j].value)
				a->data[i].index++;
			else
				a->data[j].index++;
			j++;
		}
	}
}
