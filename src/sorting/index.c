/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:21:27 by angela            #+#    #+#             */
/*   Updated: 2023/09/03 17:43:56 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_biggest(t_pushswap *ps)
{
	t_node	*temp;

	ps->biggest = ps->head_a;
	temp = ps->head_a;
	while (temp != NULL)
	{
		if (temp->data > ps->biggest->data)
			ps->biggest = temp;
		temp = temp->next;
	}
}

void	index_node(t_pushswap *ps)
{
	t_node	*temp_big;
	t_node	*temp;
	int		i;

	i = ps->number_numbers;
	find_biggest(ps);
	ps->biggest->index = i;
	i--;
	while (i >= 1) // change patate
	{
		temp = ps->head_a;
		temp_big = NULL;
		while (temp != NULL)
		{
			if (temp->index < 1 && (temp_big == NULL || \
				temp->data > temp_big->data))
				temp_big = temp;
			temp = temp->next;
		}
		temp_big->index = i;
		i--;
	}
}
