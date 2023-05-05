/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:16:55 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 15:25:56 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	are_ints(int c, char **v)
{
	int		i;
	int		j;
	char	**sep;

	i = 0;
	while (++i < c)
	{
		sep = ft_split(v[i], ' ');
		j = -1;
		while (sep[++j])
		{
			if (!is_int(sep[j]))
			{
				free_double_ptr((void **) sep);
				return (0);
			}
		}
		free_double_ptr((void **) sep);
	}
	return (1);
}

int	no_duplicates(int *input, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (input[i] == input[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*add_int(int *old_input, int new_int, int old_size)
{
	int	i;
	int	*new_input;

	new_input = (int *)ft_calloc(old_size + 2, sizeof(int));
	i = 0;
	while (i < old_size)
	{
		new_input[i] = old_input[i];
		i++;
	}
	new_input[i] = new_int;
	free(old_input);
	return (new_input);
}

int	*get_ints(int c, char **v, int *counter)
{
	char	**line;
	int		*input;
	int		i;
	int		j;

	i = c - 1;
	input = (int *)ft_calloc(1, sizeof(int));
	if (!input)
		return (0);
	while (v && i > 0)
	{
		line = ft_split(v[i], ' ');
		j = 0;
		while (line[j])
			j++;
		j --;
		while (j >= 0)
			input = add_int(input, ft_atoi(line[j--]), (*counter)++);
		free_double_ptr((void **) line);
		i--;
	}
	return (input);
}

int	*parse_input(int c, char **v, int *counter)
{
	int	*input;

	if (!are_ints(c, v))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	input = get_ints(c, v, counter);
	if (*counter == 0 || *counter == 1 || !input)
	{
		free(input);
		return (0);
	}
	if (!no_duplicates(input, *counter))
	{
		free(input);
		write(2, "Error\n", 6);
		return (0);
	}
	return (input);
}
