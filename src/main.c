/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:24:44 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 15:25:56 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack *stack, int *input, char id, int size)
{
	int	i;

	i = 0;
	stack->num_elems = 0;
	stack->bottom = 0;
	stack->top = 0;
	stack->name = id;
	while (i < size)
	{
		push_top(stack, new_node(input[i]));
		i++;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*ptr;
	t_node	*prev;

	ptr = stack->bottom;
	while (ptr)
	{
		prev = ptr;
		ptr = ptr->next;
		free(prev);
	}
	free(stack);
}

void	init(t_stack *a, t_stack *b, int *input, int counter)
{
	char	*moves;

	if (!input || !a || !b)
	{
		free(input);
		return ;
	}
	init_stack(a, input, 'a', counter);
	init_stack(b, 0, 'b', 0);
	moves = push_swap(a, b);
	print_moves(moves);
	if (moves)
	{
		free(moves);
		moves = NULL;
	}
}

int	main(int c, char **v)
{
	t_stack	*a;
	t_stack	*b;
	int		*input;
	int		counter;

	if (c > 1)
	{
		a = (t_stack *)ft_calloc(1, sizeof(t_stack));
		b = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (!a || !b)
			return (0);
		counter = 0;
		input = parse_input(c, v, &counter);
		if (input)
			init(a, b, input, counter);
		free(input);
		free_stack(a);
		free_stack(b);
	}
	return (0);
}

/*
	print_stacks(a, b);
 */
