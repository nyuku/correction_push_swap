/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:21:27 by angela            #+#    #+#             */
/*   Updated: 2023/10/13 00:36:39 by angnguye         ###   ########.fr       */
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
	while (i >= 1)
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
