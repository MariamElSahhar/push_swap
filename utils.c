/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:37:23 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/12 18:17:08 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

char	*append_free(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

void	free_double_ptr(void **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	init_index(t_stack *stack)
{
	t_node	*i;

	i = stack->bottom;
	while (i)
	{
		i->index = -1;
		i = i->next;
	}
}

void	assign_indeces(t_stack *stack)
{
	t_node	*curr_min;
	t_node	*i;
	int		counter;

	if (!stack->num_elems)
		return ;
	init_index(stack);
	counter = 0;
	while (counter != stack->num_elems)
	{
		curr_min = stack->bottom;
		while (curr_min->index != -1)
			curr_min = curr_min->next;
		i = curr_min;
		while (i)
		{
			if (i->index == -1 && i->nbr < curr_min->nbr)
				curr_min = i;
			i = i->next;
		}
		curr_min->index = counter++;
	}
}

int	divide_round_up(int a, int b)
{
	int	c;

	c = a / b;
	if (a % b)
		c++;
	return (c);
}
