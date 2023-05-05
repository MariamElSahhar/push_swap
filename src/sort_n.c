/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:40:52 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 15:25:56 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*push_to_a(t_stack *a, t_stack *b, char *moves)
{
	int	i;

	i = b->num_elems - 1;
	while (b->num_elems)
	{
		while (b->top->index != i)
			moves = make_move(a, b, moves, closest_rotation(b, i));
		moves = make_move(a, b, moves, PA);
		i --;
	}
	return (moves);
}

int	closest_rotation(t_stack *stack, int index)
{
	t_node	*i;
	int		distance;

	i = stack->bottom;
	distance = 0;
	while (i->index != index)
	{
		distance ++;
		i = i->next;
	}
	if (stack->name == 'a' && distance <= stack->num_elems / 2)
		return (RRA);
	else if (stack->name == 'a')
		return (RA);
	else if (stack->name == 'b' && distance <= stack->num_elems / 2)
		return (RRB);
	else if (stack->name == 'b')
		return (RB);
	else
		return (NA);
}

int	calc_chunk_size(int num_elems, int chunk_size)
{
	chunk_size = num_elems / 7 + 17;
	return (chunk_size);
}

char	*sort_n(t_stack *a, t_stack *b, char *moves, int chunk_size)
{
	int	curr_chunk;
	int	moved;
	int	counter;

	curr_chunk = 1;
	counter = 0;
	while (a->num_elems)
	{
		moved = 0;
		while (a->num_elems && moved < chunk_size)
		{
			while (a->top->index >= counter + chunk_size)
				moves = make_move(a, b, moves, RA);
			moves = make_move(a, b, moves, PB);
			if (b->top->index < (chunk_size / 2) + counter)
				moves = make_move(a, b, moves, RB);
			moved ++;
		}
		counter += chunk_size;
		curr_chunk ++;
		chunk_size = calc_chunk_size(a->num_elems, chunk_size);
	}
	return (push_to_a(a, b, moves));
}
