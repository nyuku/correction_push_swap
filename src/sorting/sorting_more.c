/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:09:12 by angela            #+#    #+#             */
/*   Updated: 2023/10/13 00:39:32 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	big_sort(t_pushswap *ps)
{
	int	chunk_done;
	int	chunk;

	chunk_done = 1;
	if (list_size((ps->head_a)) <= 100)
	chunk = 20;
	else
	chunk = 85;

	push_b_chunks(ps, chunk, chunk_done);
	b_to_a(ps);
}

void push_b_chunks(t_pushswap *ps, int chunks, int round)
{
	int i;
	int limit;
	// Align with Lolo's logic: condition for the external loop
	while (list_size(ps->head_a) > 0)  // > chunks
	{
		i = 1;
		limit = round * chunks;
		while (i <= chunks)
		{
			if (ps->head_a == NULL)
				break;
			// Align with Lolo's logic: condition for rotation
			while (ps->head_a->index > limit)
				rotate(&(ps->head_a), ps, 'a');
			// Align with Lolo's logic: condition for push
			if (ps->head_a->index <= (limit - (chunks / 2)))  // Make sure this condition is the same as Lolo's
				push(&(ps->head_a), &(ps->head_b), ps, 'b');
			else
			{
				push(&(ps->head_a), &(ps->head_b), ps, 'b');
				if (list_size(ps->head_b) > 1)
					rotate(&(ps->head_b), ps, 'b');
			}
			i++;
		}
		round++;  // Make sure this increment aligns with Lolo's logic
	}
}


void	b_to_a(t_pushswap *ps)
{
	int	max_index;
	int	upper;
	int	index_position;

	upper = 0;
	while (list_size(ps->head_b) > 0)
	{
		max_index = get_max_index(ps->head_b);
		index_position = find_index(ps->head_b, max_index);
		upper = is_in_upper_half(ps->head_b, index_position);
		while (ps->head_b->index != max_index)
		{
			if (upper == 1)
				rotate(&(ps->head_b), ps, 'b');
			else if (upper == 0)
				reverse_rotate(&(ps->head_b), ps, 'b');
		}
		upper = 0;
		push(&(ps->head_b), &(ps->head_a), ps, 'a');
	}
}

int	get_min_index(t_node *head)
{
	int		min_index;
	t_node	*current;

	min_index = head->index;
	current = head->next;
	while (current != NULL)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}

int	get_max_index(t_node *head)
{
	int		max_index;
	t_node	*current;

	current = head->next;
	max_index = head->index;
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
////version precedente
////
//void	big_sort(t_pushswap *ps)
//{
//	int	chunk_done;
//	int	chunk;
//
//	chunk_done = 1;
//	if (list_size((ps->head_a)) <= 100)
//		chunk = 20;
//	else
//		chunk = 38;
//	while (list_size(ps->head_a) > 0)
//	{
//		push_b_chunks(ps, chunk, chunk_done);
//		chunk_done++;
//	}
//	b_to_a(ps);
//}
//
//void	push_b_chunks(t_pushswap *ps, int chunks, int round)
//{
//	int	i;
//	int	limit;
//	int	border;
//
//	limit = round * chunks;
//	border = limit / 2;
//	i = 1;
//	while (i <= chunks)
//	{
//		if (ps->head_a == NULL)
//			break ;
//		if ((ps->head_a->index <= limit) && \
//			(ps->head_a->index >= (limit - (chunks - 1))))
//		{
//			push(&(ps->head_a), &(ps->head_b), ps, 'b');
//			if ((list_size(ps->head_b) >= 2) && (ps->head_b->index > border))
//			{
//				rotate(&(ps->head_b), ps, 'b');
//			}
//			i++;
//		}
//		else
//			rotate(&(ps->head_a), ps, 'a');
//	}
//}
//
//void	b_to_a(t_pushswap *ps)
//{
//	int	max_index;
//	int	upper;
//	int	index_position;
//
//	upper = 0;
//	while (list_size(ps->head_b) > 0)
//	{
//		max_index = get_max_index(ps->head_b);
//		index_position = find_index(ps->head_b, max_index);
//		upper = is_in_upper_half(ps->head_b, index_position);
//		while (ps->head_b->index != max_index)
//		{
//			if (upper == 1)
//				rotate(&(ps->head_b), ps, 'b');
//			else if (upper == 0)
//				reverse_rotate(&(ps->head_b), ps, 'b');
//		}
//		upper = 0;
//		push(&(ps->head_b), &(ps->head_a), ps, 'a');
//	}
//}
//
//int	get_min_index(t_node *head)
//{
//	int		min_index;
//	t_node	*current;
//
//	min_index = head->index;
//	current = head->next;
//	while (current != NULL)
//	{
//		if (current->index < min_index)
//			min_index = current->index;
//		current = current->next;
//	}
//	return (min_index);
//}
//
//int	get_max_index(t_node *head)
//{
//	int		max_index;
//	t_node	*current;
//
//	current = head->next;
//	max_index = head->index;
//	while (current != NULL)
//	{
//		if (current->index > max_index)
//			max_index = current->index;
//		current = current->next;
//	}
//	return (max_index);
//}
