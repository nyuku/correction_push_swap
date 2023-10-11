/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:25:21 by angela            #+#    #+#             */
/*   Updated: 2023/09/03 17:43:27 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_node **head, t_pushswap *ps, char stack_c)
{
	t_node	*node_1;
	t_node	*end;
	t_node	*prev_last;
	t_node	*temp;

	end = last_node(*head);
	temp = *head;
	while (temp->next != NULL)
	{
		prev_last = temp;
		temp = temp->next;
	}
	node_1 = *head;
	*head = end;
	(*head)->next = node_1;
	prev_last->next = NULL;
	ps->nombre_op++;
	ft_printf("rr%c\n", stack_c);
}

void	double_reverse_rotate(t_node **node_a, t_node **node_b, t_pushswap *ps)
{
	reverse_rotate(node_a, ps, 'a');
	reverse_rotate(node_b, ps, 'b');
}
