/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:25:21 by angela            #+#    #+#             */
/*   Updated: 2023/09/03 17:43:19 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_up(t_node **head, t_pushswap *ps, char stack_c)
{
	t_node	*node_1;
	t_node	*end;

	end = last_node(*head);
	node_1 = *head;
	*head = (*head)->next;
	end->next = node_1;
	node_1->next = NULL;
	ps->nombre_op++;
	ft_printf("r%c\n", stack_c);
}

void	double_rotate(t_node **node_a, t_node **node_b, t_pushswap *ps)
{
	rotate_up(node_a, ps, 'a');
	rotate_up(node_b, ps, 'b');
}
