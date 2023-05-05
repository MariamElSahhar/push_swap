/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:39:22 by melsahha          #+#    #+#             */
/*   Updated: 2023/03/25 13:29:34 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	push_bottom(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->num_elems == 0)
		stack->top = node;
	else
	{
		stack->bottom->prev = node;
		node->next = stack->bottom;
	}
	stack->bottom = node;
	stack->num_elems++;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*old_top;

	if (stack->num_elems == 0)
		return (0);
	else if (stack->num_elems == 1)
	{
		old_top = stack->top;
		stack->bottom = 0;
		stack->top = 0;
	}
	else
	{
		old_top = stack->top;
		stack->top = stack->top->prev;
		stack->top->next = 0;
		old_top->prev = 0;
	}
	stack->num_elems --;
	return (old_top);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*old_bottom;

	if (stack->num_elems == 0)
		return (0);
	if (stack->num_elems == 1)
	{
		old_bottom = stack->bottom;
		stack->bottom = 0;
		stack->top = 0;
	}
	else
	{
		old_bottom = stack->bottom;
		stack->bottom = stack->bottom->next;
		stack->bottom->prev = 0;
		old_bottom->next = 0;
	}
	stack->num_elems --;
	return (old_bottom);
}

void	push_top(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	if (stack->num_elems == 0)
		stack->bottom = node;
	else
	{
		node->prev = stack->top;
		stack->top->next = node;
	}
	stack->top = node;
	stack->num_elems ++;
}

t_node	*new_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->nbr = content;
	node->next = 0;
	node->prev = 0;
	node->index = -1;
	return (node);
}
