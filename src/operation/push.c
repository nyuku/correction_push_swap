/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:52:58 by angela            #+#    #+#             */
/*   Updated: 2023/09/03 17:43:24 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_node **origin, t_node **destination, t_pushswap *ps, char dest_c)
{
	t_node	*temp;

	if (list_size(*origin) != 0)
	{
		temp = *origin;
		*origin = (*origin)->next;
		temp->next = *destination;
		*destination = temp;
		ps->nombre_op++;
		ft_printf("p%c\n", dest_c);
	}
}
