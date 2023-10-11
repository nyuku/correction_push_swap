/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_under_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:24:36 by angela            #+#    #+#             */
/*   Updated: 2023/09/04 11:01:00 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sorting_five(t_pushswap *ps)
{
	t_node	*prout;

	prout = last_node(ps->head_a);
	if (prout->index == 1)
		reverse_rotate(&(ps->head_a), ps, 'a');
	else if (ps->head_a->index != 1)
	{
		while (ps->head_a->index != 1)
			rotate_up(&ps->head_a, ps, 'a');
	}
	push(&(ps->head_a), &(ps->head_b), ps, 'b');
	sorting_for(ps, 1);
	push(&(ps->head_b), &(ps->head_a), ps, 'a');
}
