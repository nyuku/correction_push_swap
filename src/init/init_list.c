/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:18:53 by angela            #+#    #+#             */
/*   Updated: 2023/10/06 14:33:34 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*node_init(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	return (node);
}

void	init_list(t_pushswap *ps)
{
	int		i;
	t_node	*previous_node_a;
	t_node	*current_node_a;

	i = 0;
	previous_node_a = NULL;
	while (i < ps->number_numbers)
	{
		current_node_a = node_init();
		if (previous_node_a == NULL)
			ps->head_a = current_node_a;
		else
			previous_node_a->next = current_node_a;
		previous_node_a = current_node_a;
		i++;
	}
}

int	fill_list_multi(t_pushswap *ps, char **av)
{
	t_node	*current_node_a;
	int		i;
	long	nb;

	i = 1;
	current_node_a = ps->head_a;
	while (current_node_a != NULL && i <= ps->number_numbers)
	{
		nb = ft_atol(av[i]);
		if (check_int_limit(nb) == ERROR)
			return (ERROR);
		current_node_a->data = (int)nb ;
		current_node_a = current_node_a->next;
		i++;
	}
	return (SUCCESS);
}

int	fill_list_mono(t_pushswap *ps)
{
	t_node	*current_node_a;
	int		i;
	long	nb;

	i = 0;
	current_node_a = ps->head_a;
	while (current_node_a != NULL && i <= ps->number_numbers)
	{
		nb = ft_atol(ps->tab_args_number[i]);
		if (check_int_limit(nb) == 0)
			return (ERROR);
		current_node_a->data = (int)nb;
		current_node_a = current_node_a->next;
		i++;
	}
	return (SUCCESS);
}
