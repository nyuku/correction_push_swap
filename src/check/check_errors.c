/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:13:27 by angela            #+#    #+#             */
/*   Updated: 2023/10/13 00:48:22 by angnguye         ###   ########.fr       */
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
				return (ERROR);
			}
			compare = compare->next;
		}
		temp = temp->next;
	}
	return (SUCCESS);
}

int	check_int_limit(long l)
{
	if (l < INT_MIN || l > INT_MAX)
		return (ERROR);
	return (SUCCESS);
}

int	check_if_number_str(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}
