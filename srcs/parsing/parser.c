/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:50:44 by tseche            #+#    #+#             */
/*   Updated: 2026/01/10 20:03:49 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	skip_nbr(char *s)
{
	char	*src;

	src = s;
	while (*s == '+' || *s == '-' || skip_spaces(s))
	{
		if (*s == '+' || *s == '-')
			s++;
		else
			s += skip_spaces(s);
	}
	s += skip_digits(s);
	return (s - src);
}

t_data	*char_to_data(char *s, int *n, size_t size)
{
	t_data	*array;

	array = malloc(sizeof(t_data) * size);
	if (!array)
		return (NULL);
	while (*s && has_digits(s))
	{
		s += skip_spaces(s);
		array[*n].value = ft_atoi(s);
		(*n)++;
		s += skip_nbr(s);
	}
	return (array);
}
