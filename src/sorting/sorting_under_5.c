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

void	small_sorting(t_pushswap *ps)
{
	if (ps->number_numbers == 2)
		duo(ps);
	if (ps->number_numbers == 3)
		threesome(ps, 0);
	if (ps->number_numbers == 4)
		sorting_for(ps, 0);
	if (ps->number_numbers == 5)
		sorting_five(ps);
}

void	duo(t_pushswap *ps)
{
	if (ps->head_a->index != 1)
		swap(&(ps->head_a), ps, 'a');
}

static void	threesome_bis(t_pushswap *ps, int sorting_for)
{
	if (ps->head_a->index == (2 + sorting_for) && ps->head_a->next->index == (3 + sorting_for) && ps->head_a->next->next->index == (1 + sorting_for))
		reverse_rotate(&(ps->head_a), ps, 'a');
}

void	threesome(t_pushswap *ps, int sorting_for)
{
	if (ps->head_a->index == (1 + sorting_for) && \
		ps->head_a->next->index == (3 + sorting_for) && \
			ps->head_a->next->next->index == (2 + sorting_for))
	{
		swap(&(ps->head_a), ps, 'a');
		rotate_up(&(ps->head_a), ps, 'a');
	}
	else if (ps->head_a->index == (2 + sorting_for) && \
		ps->head_a->next->index == (1 + sorting_for) && \
		ps->head_a->next->next->index == (3 + sorting_for))
		swap(&(ps->head_a), ps, 'a');
	else if (ps->head_a->index == (3 + sorting_for) && \
		ps->head_a->next->index == (2 + sorting_for) && \
		ps->head_a->next->next->index == (1 + sorting_for))
	{
		swap(&(ps->head_a), ps, 'a');
		reverse_rotate(&(ps->head_a), ps, 'a');
	}
	else if (ps->head_a->index == (3 + sorting_for) && \
		ps->head_a->next->index == (1 + sorting_for) && \
		ps->head_a->next->next->index == (2 + sorting_for))
		rotate_up(&(ps->head_a), ps, 'a');
	else
		threesome_bis(ps, sorting_for);
}

void	sorting_for(t_pushswap *ps, int five_sort)
{
	t_node	*prout;

	prout = last_node(ps->head_a);
	if (prout->index == 1) // possible de faire list size - (list size-1)
		reverse_rotate(&(ps->head_a), ps, 'a');
	else
	{
		while ((five_sort == 0 && ps->head_a->index != 1) \
			|| (five_sort == 1 && ps->head_a->index != 2))
			rotate_up(&ps->head_a, ps, 'a');
	}
	push(&(ps->head_a), &(ps->head_b), ps, 'b');
	threesome(ps, 2);// changer en 2 au lieu de 1
	push(&(ps->head_b), &(ps->head_a), ps, 'a');
}
