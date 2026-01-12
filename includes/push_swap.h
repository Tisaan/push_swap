/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:07 by tseche            #+#    #+#             */
/*   Updated: 2026/01/11 20:30:46 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/lib_ft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int	value;
	int	index;
}				t_data;

typedef struct s_info
{
	t_data	*data;
	size_t	size;
	size_t	max_size;
}				t_info;

//           [parsing]
int		*check(char *s);
t_data	*char_to_data(char *s, int *n, size_t size);
int		duplicate(t_info *a);

//           [utils]
void	free_stack(t_info *stack);
int		is_sorted(t_info *a);
t_info	*stack_init_fill(char *s, size_t size);
void	mapping(t_info *a);
void	print_stack(t_info *a, t_info *b);
int		is_empty(char **av);

//           [move]
void	pa(t_info *a, t_info *b);
void	pb(t_info *a, t_info *b);
void	ra(t_info *a);
void	rra(t_info *a);

//           [tiny_sort.c]
void	tiny_sort(t_info *a, t_info *b);
void	sort_3(t_info *a);
void	sort_4_5(t_info *a, t_info *b);

#endif