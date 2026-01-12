/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:59:23 by tseche            #+#    #+#             */
/*   Updated: 2026/01/10 19:37:31 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_info	*stack_init_fill(char *s, size_t size)
{
	static int		n;
	t_info			*stack;

	stack = malloc(sizeof(t_info));
	if (!stack)
		return (NULL);
	if (!s)
	{
		stack->data = ft_calloc(sizeof(t_data), n);
		if (!stack->data)
			return (NULL);
		stack->max_size = n;
		stack->size = 0;
		return (stack);
	}
	n = 0;
	stack->data = char_to_data(s, &n, size);
	if (!stack->data)
		return (NULL);
	stack->size = n;
	stack->max_size = n;
	mapping(stack);
	return (stack);
}
