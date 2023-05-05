/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:00:15 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/07 14:23:33 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef enum moves
{
	NA,
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
}	t_moves;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				nbr;
	int				index;
}	t_node;

typedef struct s_stack
{
	t_node	*bottom;
	t_node	*top;
	int		num_elems;
	char	name;
}	t_stack;

void	push_bottom(t_stack *stack, t_node *new);
void	push_top(t_stack *stack, t_node *node);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);
t_node	*new_node(int content);

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push(t_stack *take, t_stack *put);

int		*parse_input(int c, char **v, int *counter);
char	*make_move(t_stack	*a, t_stack *b, char *moves, int id);
void	print_moves(char *moves);

char	*append_free(char *s1, char *s2);
void	assign_indeces(t_stack *stack);
int		divide_round_up(int a, int b);

char	*push_swap(t_stack *a, t_stack *b);
char	*sort_n(t_stack *a, t_stack *b, char *moves, int chunk_size);
int		closest_rotation(t_stack *stack, int index);

void	print_stacks(t_stack *a, t_stack *b);
void	free_double_ptr(void **ptr);
void	free_stack(t_stack *stack);
int		arr_length(int *arr);
int		is_int(char *word);
int		is_sorted(t_stack *stack);

#endif
