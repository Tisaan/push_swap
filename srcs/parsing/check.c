/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:55:56 by tseche            #+#    #+#             */
/*   Updated: 2026/01/12 16:37:34 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_check_nbr(char *s, char sign)
{
	long	nbr;
	int		occ_sign;
	int		err;

	occ_sign = 0;
	err = 1;
	s += skip_spaces(s);
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = *s;
		if (occ_sign == 1)
			return (err);
		occ_sign++;
		s++;
	}
	if (((*s >= '\t' && *s <= '\r') || *s == ' ' || !*s))
		return (err);
	nbr = atol(s);
	if (sign == '-')
		nbr *= -1;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (err);
	err = 0;
	return (err);
}

int	*check(char *s)
{
	char	sign;
	int		*ret;

	ret = calloc(sizeof(int), 2);
	if (!ret)
		return (NULL);
	ret[0] = 1;
	if (!is_diff_than(s, "\\a\\b\\n\\r\\t\\v\\f 0123456789+-"))
		return (ret);
	sign = '\0';
	while (*s)
	{
		if (get_check_nbr(s, sign))
			return (ret);
		s += skip_pattern(s, "\a\b\n\r\t\v\f +-");
		s += skip_digits(s);
		if (!((*s >= '\t' && *s <= '\r') || *s == ' ' || !*s))
			return (ret);
		ret[1]++;
	}
	ret[0] = 0;
	return (ret);
}

int	duplicate(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->size - 1)
	{
		j = i + 1;
		while (j < info->size)
		{
			if (info->data[i].value == info->data[j].value)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
