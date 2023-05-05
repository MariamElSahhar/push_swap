/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:06:38 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/05 16:42:26 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*old_top;
	t_node	*new_top;

	if (stack->num_elems < 2)
		return ;
	old_top = pop_top(stack);
	new_top = pop_top(stack);
	push_top(stack, old_top);
	push_top(stack, new_top);
}

void	push(t_stack *take, t_stack *put)
{
	t_node	*move;

	move = pop_top(take);
	if (move)
		push_top(put, move);
}

void	rotate(t_stack *stack)
{
	t_node	*old_top;

	old_top = pop_top(stack);
	if (old_top)
		push_bottom(stack, old_top);
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*old_bottom;

	if (stack->num_elems < 2)
		return ;
	old_bottom = pop_bottom(stack);
	push_top(stack, old_bottom);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;
	int		i;

	i = a->num_elems;
	if (i < b->num_elems)
		i = b->num_elems;
	node_a = a->bottom;
	ft_printf("a (%i): ", a->num_elems);
	while (node_a)
	{
		ft_printf("%i ", node_a->nbr);
		node_a = node_a->next;
	}
	node_b = b->bottom;
	ft_printf("\n");
	ft_printf("b (%i): ", b->num_elems);
	while (node_b)
	{
		ft_printf("%i ", node_b->nbr);
		node_b = node_b->next;
	}
	ft_printf("\n");
}
