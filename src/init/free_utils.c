/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:04:08 by angela            #+#    #+#             */
/*   Updated: 2023/10/09 10:04:09 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_structure(t_pushswap *ps)
{
	int	i;

	i = 0;
	if (ps->tab_args_number == NULL || ps->tab_args_number[i] == NULL)
	{
		return ;
	}
	i = -1;
	while (++i < ps->number_numbers)
	{
		if (ps->tab_args_number[i] != NULL)
		{
			free(ps->tab_args_number[i]);
			ps->tab_args_number[i] = NULL;
		}
	}
	if (ps->tab_args_number != NULL)
		free(ps->tab_args_number);
}

void	free_nodes(t_node **head)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = *head;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*head = NULL;
}
