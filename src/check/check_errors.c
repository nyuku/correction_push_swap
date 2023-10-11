/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:13:27 by angela            #+#    #+#             */
/*   Updated: 2023/10/06 13:50:23 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_double(t_node *head)
{
	t_node	*temp;
	t_node	*compare;

	temp = head;
	while (temp != NULL)
	{
		compare = temp;
		while (compare != NULL)
		{
			if (temp->data == compare->data && temp != compare)
			{
				return(ERROR);
			}
			compare = compare->next;
		}
		temp = temp->next;
	}
	return (SUCCESS);
}

int	check_int_limit(long l)
{
	if (l < INT_MIN || l > INT_MAX) // change >=
		return (ERROR);
	return (SUCCESS);//change
}
