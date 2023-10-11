/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:25:21 by angela            #+#    #+#             */
/*   Updated: 2023/09/03 17:42:55 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_node **node, t_pushswap *ps, char stack_c)
{
	t_node	*node1;
	t_node	*node2;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	node1 = *node;
	node2 = (*node)->next;
	node1->next = node2->next;
	node2->next = node1;
	*node = node2;
	ps->nombre_op++;
	ft_printf("s%c\n", stack_c);
}

void	double_swap(t_node **node_a, t_node **node_b, t_pushswap *ps)
{
	swap(node_a, ps, 'a');
	swap(node_b, ps, 'b');
}
