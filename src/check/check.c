/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:03:46 by angela            #+#    #+#             */
/*   Updated: 2023/10/09 10:03:47 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_if_number_str(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0') // new
		return(0);
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

int count_words(char const *s, char c, char tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c || s[i] == tab)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] && s[i] != tab)
				i++;
		}
	}
	return (count);
}

void	check_all_arg(char **av, int ac, t_pushswap *ps)
{
	if (ac == 2)
	{
		ps->mono_arg = check_mono_arg(av, ps);
		if (ps->mono_arg == ERROR_NO_NUMBER) // 0
			error_exit(ps);
		if (ps->mono_arg == 2)
		{
			if ((check_int_limit(ft_atol(av[1]))) == ERROR)
				p_error();
			exit (0);
		}
	}
	else if (ac > 2)
	{
		ps->multi_arg = check_multi_arg(av, ac);
		if (ps->multi_arg == 0)
		{
			p_error();
			exit (0);
		}
	}
}

int	check_mono_arg(char **av, t_pushswap *ps)
{
	int	i;

	i = 0;
	ps->number_numbers = count_words(av[1], ' ', '\t');
	if (ps->number_numbers == 1 && check_if_number_str(av[1]))// test sur que c'est que un nombre
		return (2);
	ps->tab_args_number = ft_split(av[1], ' ');
	while (i < ps->number_numbers)
	{
		if (!check_if_number_str(ps->tab_args_number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_multi_arg(char **argv, int argc)
{
	int	result;
	int	i;

	result = 0;
	i = 1;
	while (i < argc)
	{
		if (check_if_number_str(argv[i]) == 1)
		{
			result++;
			i++;
		}
		else
			return (0);
	}
	return (result);
}
