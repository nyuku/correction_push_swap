/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c 	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:13:27 by angela            #+#    #+#             */
/*   Updated: 2023/06/25 16:40:16 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_index(t_node *head, int target_index)
{
	int		i;
	t_node	*current;

	current = head;
	i = 1;// change 0
	while (current != NULL)
	{
		if (current->index == target_index)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

int	is_already__sorted(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_in_upper_half(t_node *head, int index_position)
{
	int	size;

	size = list_size(head);
	if (index_position == -1)
		return (-1);
	if (index_position < size / 2)
		return (1);
	else
		return (0);
}

int	list_size(t_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	print_nodes(t_node **node, char c)
{
	t_node	*current;

	current = *node;
	ft_printf("Contenu de la liste %c: ", c);
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}
