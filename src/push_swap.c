/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:07:21 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 15:25:56 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*sort_2(t_stack *a, t_stack *b, char *moves)
{
	if (a->bottom->index == 0)
		moves = make_move(a, b, moves, SA);
	return (moves);
}

char	*sort_3(t_stack *a, t_stack *b, char *moves)
{
	if (a->bottom->index == 2
		&& a->bottom->next->index == 1 && a->top->index == 0)
		return (moves);
	else if (a->bottom->index == 2)
		moves = make_move(a, b, moves, SA);
	else if (a->bottom->index == 1
		&& a->bottom->next->index == 2 && a->top->index == 0)
	{
		moves = make_move(a, b, moves, RRA);
		moves = make_move(a, b, moves, SA);
	}
	else if (a->bottom->index == 1)
		moves = make_move(a, b, moves, RA);
	else if (a->bottom->index == 0
		&& a->bottom->next->index == 1 && a->top->index == 2)
	{
		moves = make_move(a, b, moves, RA);
		moves = make_move(a, b, moves, SA);
	}
	else if (a->bottom->index == 0)
		moves = make_move(a, b, moves, RRA);
	return (moves);
}

char	*sort_5(t_stack *a, t_stack *b, char *moves)
{
	while (a->top->index != 0)
		moves = make_move(a, b, moves, closest_rotation(a, 0));
	moves = make_move(a, b, moves, PB);
	if (a->num_elems > 3)
	{
		while (a->top->index != 1)
			moves = make_move(a, b, moves, closest_rotation(a, 1));
		moves = make_move(a, b, moves, PB);
	}
	assign_indeces(a);
	moves = sort_3(a, b, moves);
	if (b->top->index == 0)
		moves = make_move(a, b, moves, SB);
	moves = make_move(a, b, moves, PA);
	moves = make_move(a, b, moves, PA);
	return (moves);
}

char	*push_swap(t_stack *a, t_stack *b)
{
	char	*moves;

	assign_indeces(a);
	if (is_sorted(a) || a->num_elems == 1)
		return (0);
	moves = (char *)ft_calloc(1, sizeof(char));
	if (a->num_elems == 2)
		moves = sort_2(a, b, moves);
	else if (a->num_elems == 3)
		moves = sort_3(a, b, moves);
	else if (a->num_elems <= 5)
		moves = sort_5(a, b, moves);
	else if (a->num_elems <= 100)
		moves = sort_n(a, b, moves, 19);
	else
		moves = sort_n(a, b, moves, 64);
	return (moves);
}
