/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:40:48 by angela            #+#    #+#             */
/*   Updated: 2023/10/13 01:25:33 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

# include "../libft/libft.h"
# include "ft_printf.h"

/*◇───────────────────────────────────────────────────────────────◇*\
*	Macro
\*◇───────────────────────────────────────────────────────────────◇*/
# define ERROR				0
# define SUCCESS			1
# define ERROR_NO_NUMBER	0

/*◇───────────────────────────────────────────────────────────────◇*\
*	Structure
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;

}					t_node;

typedef struct s_pushswap
{
	char		**tab_args_number;
	int			multi_arg;
	int			mono_arg;
	int			number_numbers;
	int			nombre_op;
	t_node		*head_a;
	t_node		*head_b;
	t_node		*biggest;
}				t_pushswap;

/*◇───────────────────────────────────────────────────────────────◇*\
* 	Check arguments - Parsing
\*◇───────────────────────────────────────────────────────────────◇*/

/* --	check.c	  --*/
void		check_all_arg(char **av, int ac, t_pushswap *ps);
int			check_mono_arg(char **av, t_pushswap *ps);
int			check_multi_arg(char **argv, int argc);

/* --check_errors --*/
int			check_double(t_node *head);
int			check_int_limit(long l);
int			check_is_number_int(char *str);
int			check_if_number_str(char *str);

/*◇───────────────────────────────────────────────────────────────◇*\
* 	Init list 
\*◇───────────────────────────────────────────────────────────────◇*/

/* --init_list.c --*/
t_node		*node_init(void);
void		init_list(t_pushswap *ps);
int			fill_list_multi(t_pushswap *ps, char **av);
int			fill_list_mono(t_pushswap *ps);

/*	free_utils.c */
void		free_structure(t_pushswap *ps);
void		free_nodes(t_node **head);

/*◇───────────────────────────────────────────────────────────────◇*\
* 	Operations- game
\*◇───────────────────────────────────────────────────────────────◇*/

void		push(t_node **origin, t_node **destination, \
t_pushswap *ps, char dest_c);
void		reverse_rotate(t_node **head, t_pushswap *ps, char stack_c);
void		swap(t_node **node, t_pushswap *ps, char stack_c);
void		rotate(t_node **head, t_pushswap *ps, char stack_c);
void		double_swap(t_node **node_a, t_node **node_b, t_pushswap *ps);
void		double_rotate(t_node **node_a, t_node **node_b, t_pushswap *ps);
void		double_reverse_rotate(t_node **node_a, \
t_node **node_b, t_pushswap *ps);

/*◇───────────────────────────────────────────────────────────────◇*\
* 	Algorithm
\*◇───────────────────────────────────────────────────────────────◇*/

/*	index.c */
void		index_node(t_pushswap *ps);
void		find_biggest(t_pushswap *ps);

/*	sorting_more.c */
void		big_sort(t_pushswap *ps);
void		push_b_chunks(t_pushswap *ps, int chunks, int round);
void		b_to_a(t_pushswap *ps);
int			get_max_index(t_node *head);
int			get_min_index(t_node *head);

/*	sorting_under_5.c */
void		small_sorting(t_pushswap *ps);
void		duo(t_pushswap *ps);
void		threesome(t_pushswap *ps, int sorting_for);
void		sorting_for(t_pushswap *ps, int five_sort);
void		sorting_five(t_pushswap *ps);

/*◇───────────────────────────────────────────────────────────────◇*\
*	Utils
\*◇───────────────────────────────────────────────────────────────◇*/

/* --	utils.c	  --*/
int			find_index(t_node *head, int target_index);
int			is_already__sorted(t_node **stack);
int			is_in_upper_half(t_node *head, int index_position);
int			list_size(t_node *node);
void		print_nodes(t_node **node, char c);

/* --	utils_bis.c	  --*/
t_node		*last_node(t_node *head);
int			p_error(void);
long		ft_atol(char *nptr);
void		error_exit(t_pushswap *ps);
int			count_words(char const *s, char c, char tab);

/*◇───────────────────────────────────────────────────────────────◇*\
*	Main
\*◇───────────────────────────────────────────────────────────────◇*/

void		deal_with_args(t_pushswap *ps, char **av);

#endif