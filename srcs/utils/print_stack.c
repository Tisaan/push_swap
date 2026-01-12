/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:08:02 by tseche            #+#    #+#             */
/*   Updated: 2026/01/10 17:13:49 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/push_swap.h"

void	print_stack(t_info *a, t_info *b)
{
	size_t	i;

	i = 0;
	printf("[\n\ta->size:%zu\t\tb->size:%zu\n", a->size, b->size);
	while (i < a->size || i < b->size)
	{
		if (i < a->size)
		{
			printf("\ta->data[%zu]:%d",
				i, a->data[i].value);
		}
		else
			printf("\ta->data[%zu]:%s",
				i, "NULL");
		printf("\t\t");
		if (i < b->size)
		{
			printf("\tb->data[%zu]:%d\n",
				i, b->data[i].value);
		}
		else
			printf("\tb->data[%zu]:%s\n", i, "NULL");
		i++;
	}
	ft_printf("]\n");
}
