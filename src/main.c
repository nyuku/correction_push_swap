/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:19:08 by angela            #+#    #+#             */
/*   Updated: 2023/10/08 12:59:07 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_nodes(t_node **node, char c) {
	t_node* current = *node;

	printf("Contenu de la liste %c: ", c);
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void	deal_with_args(t_pushswap *ps, char **av)
{
	if (ps->mono_arg != 0)
	{
		init_list(ps);
		if (fill_list_mono(ps) == ERROR)
		{
			p_error();
			free_nodes(&(ps->head_a));
			free_structure(ps);
			exit(0);
		}
	}
	else
	{
		ps->number_numbers = ps->multi_arg;
		init_list(ps);
		if (fill_list_multi(ps, av) == ERROR)
		{
			p_error();
			free_nodes(&(ps->head_a));
			free_structure(ps);
			exit(0);
		}
	}
}

static void	init_main(t_pushswap *ps, int ac)
{
	if (ac <= 1)
		exit (1);
	ps->nombre_op = 0;
	ps->multi_arg = 0;
	ps->mono_arg = 0;
	ps->tab_args_number = NULL;
}

static	void	check_args_parsed(t_pushswap *ps)
{
	if (check_double(ps->head_a) == ERROR)
	{
		p_error();
		free_nodes(&(ps->head_a));
		free_structure(ps);
		exit(1);
	}
	index_node(ps);
	if (is_already__sorted(&(ps->head_a)) != 0)
	{
		free_nodes(&(ps->head_a));
		free_structure(ps);
		exit(0);
	}
	ps->head_b = node_init();
}

int	main(int ac, char **av)
{
	t_pushswap	ps;

	init_main(&ps, ac);
	check_all_arg(av, ac, &ps);
	deal_with_args(&ps, av);
	check_args_parsed(&ps);
	if (ps.number_numbers > 5)
		big_sort(&ps);
	else
		small_sorting(&ps);
//	printf("nombre de chiffre %d\n", list_size((ps.head_a)));
//	print_nodes(&(ps.head_a), 'A');
//	printf("\n\n----------------------\n\n");

	free_nodes(&(ps.head_a));
	free_nodes(&(ps.head_b));
//	print_nodes(&(ps.head_b), 'B');
	free_structure(&ps);
	return (0);
}
