/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:18:59 by tseche            #+#    #+#             */
/*   Updated: 2026/01/10 19:05:49 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_info *a)
{
	size_t	i;

	i = 0;
	while (i < a->size -1)
	{
		if (a->data[i].value > a->data[i + 1].value)
			return (1);
		i++;
	}
	return (0);
}
