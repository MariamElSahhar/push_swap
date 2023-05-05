/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:18:01 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/17 14:04:28 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**rules_list(char **rules)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		rules[i] = (char *)ft_calloc(4, sizeof(char));
		if (!rules[i])
			return (0);
		i++;
	}
	ft_strlcpy(rules[0], "sa", 3);
	ft_strlcpy(rules[1], "sb", 3);
	ft_strlcpy(rules[2], "pa", 3);
	ft_strlcpy(rules[3], "pb", 3);
	ft_strlcpy(rules[4], "ra", 3);
	ft_strlcpy(rules[5], "rb", 3);
	ft_strlcpy(rules[6], "rra", 4);
	ft_strlcpy(rules[7], "rrb", 4);
	return (rules);
}

void	print_moves(char *moves)
{
	int		i;
	char	**rules;

	i = 0;
	if (!moves)
		return ;
	rules = (char **)ft_calloc(10, sizeof(char *));
	if (!rules)
		return ;
	rules = rules_list(rules);
	while (moves && moves[i])
	{
		if (moves[i] >= '1' && moves[i] <= '9')
			ft_printf("%s", rules[(moves[i] - '1')]);
		ft_printf("\n");
		i++;
	}
	free_double_ptr((void **)rules);
}

int	check_dups(char *moves)
{
	int	i;
	int	changed;

	i = 0;
	changed = 0;
	while (moves && moves[i + 1])
	{
		if ((moves[i] == '1' && moves[i + 1] == '2')
			|| (moves[i] == '6' && moves[i + 1] == '7')
			|| (moves[i] == '9' && moves[i + 1] == 'a'))
		{
			if (moves[i] == '6' && moves[i + 1] == '7')
				moves[i] = '8';
			else if (moves[i] == '1' && moves[i + 1] == '2')
				moves[i] = '3';
			else if (moves[i] == '9' && moves[i + 1] == 'a')
				moves[i] = 'b';
			moves[i + 1] = '0';
			changed = 1;
		}
		i++;
	}
	return (changed);
}

int	check_neg(char *moves)
{
	int	i;
	int	changed;

	i = 0;
	changed = 0;
	while (moves && moves[i + 1])
	{
		if (((moves[i] == '1' || moves[i] == '2' || moves[i] == '3')
				&& moves[i] == moves[i + 1])
			|| ((moves[i] == '6' || moves[i] == '7' || moves[i] == '8')
				&& moves[i] == moves[i] + 3)
			|| ((moves[i] == '9' || moves[i] == 'a' || moves[i] == 'b')
				&& moves[i] == moves[i] - 3)
			|| (moves[i] == '4' && moves[i + 1] == '5')
			|| (moves[i] == '5' && moves[i + 1] == '4'))
		{
			moves[i] = '0';
			moves[i + 1] = '0';
			changed = 1;
		}
		i++;
	}
	return (changed);
}

char	*make_move(t_stack	*a, t_stack *b, char *moves, int id)
{
	char	*temp;

	if (id == SA)
		swap(a);
	if (id == SB)
		swap(b);
	if (id == PA)
		push(b, a);
	if (id == PB)
		push(a, b);
	if (id == RA)
		rotate(a);
	if (id == RB)
		rotate(b);
	if (id == RRA)
		reverse_rotate(a);
	if (id == RRB)
		reverse_rotate(b);
	temp = ft_itoa(id);
	moves = append_free(moves, temp);
	free(temp);
	temp = NULL;
	return (moves);
}
