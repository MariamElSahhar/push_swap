/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:03:42 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/06 18:28:30 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	arr_length(int *arr)
{
	int	count;

	count = 0;
	while (arr[count] != 0)
		count++;
	return (count);
}

int	is_int(char *word)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	if (word[i] == '-')
	{
		i++;
		sign = sign * -1;
	}
	if (!word[i] || !ft_isdigit(word[i]))
		return (0);
	while (word[i] <= '9' && word[i] >= '0')
	{
		res = res * 10 + (int) word[i] - 48;
		i++;
	}
	res = res * sign;
	if ((word[i] && !ft_isdigit(word[i]))
		|| res < -2147483648 || res > 2147483647)
		return (0);
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*ptr;
	int		i;

	ptr = stack->top;
	i = 0;
	while (ptr)
	{
		if (ptr->index != i)
			return (0);
		ptr = ptr->prev;
		i ++;
	}
	return (1);
}
