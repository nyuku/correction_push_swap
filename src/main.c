/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:19:08 by angela            #+#    #+#             */
/*   Updated: 2023/10/13 00:30:36 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	deal_with_args(t_pushswap *ps, char **av)
{
	if (ps->mono_arg != 0)
	{
		init_list(ps);
		if (fill_list_mono(ps) == ERROR)
		{
			p_error();
			free_nodes(&(ps->head_a));
			free_structure(ps);
			exit(0);
		}
	}
	else
	{
		ps->number_numbers = ps->multi_arg;
		init_list(ps);
		if (fill_list_multi(ps, av) == ERROR)
		{
			p_error();
			free_nodes(&(ps->head_a));
			free_structure(ps);
			exit(0);
		}
	}
}

static void	init_main(t_pushswap *ps, int ac)
{
	if (ac <= 1)
		exit (1);
	ps->nombre_op = 0;
	ps->multi_arg = 0;
	ps->mono_arg = 0;
	ps->tab_args_number = NULL;
}

static	void	check_args_parsed(t_pushswap *ps)
{
	if (check_double(ps->head_a) == ERROR)
	{
		p_error();
		free_nodes(&(ps->head_a));
		free_structure(ps);
		exit(1);
	}
	index_node(ps);
	if (is_already__sorted(&(ps->head_a)) != 0)
	{
		free_nodes(&(ps->head_a));
		free_structure(ps);
		exit(0);
	}
	ps->head_b = NULL;
}

int	main(int ac, char **av)
{
	t_pushswap	ps;

	if (ac == 1)
		return (0);
	init_main(&ps, ac);
	check_all_arg(av, ac, &ps);
	deal_with_args(&ps, av);
	check_args_parsed(&ps);
	if (ps.number_numbers > 5)
		big_sort(&ps);
	else
		small_sorting(&ps);
	//print_nodes(&(ps.head_a), 'a');
	free_nodes(&(ps.head_a));
	free_nodes(&(ps.head_b));
	free_structure(&ps);
	return (0);
}



//
//
//int main(int ac, char **av) {
//	t_pushswap ps;
//	int min_operations = INT_MAX;
//	int best_chunk_size = 0;
//
//	 // 500 chiffres + le nom du programme
//		for (int chunk_size = 5; chunk_size <= 100; chunk_size += 5) {
//			init_main(&ps, ac);
//			check_all_arg(av, ac, &ps);
//			deal_with_args(&ps, av);
//			check_args_parsed(&ps);
//			ps.nombre_op = 0;  // Réinitialisation du compteur d'opérations
//
//			big_sort(&ps, chunk_size);
//
//			if (ps.nombre_op < min_operations) {
//				min_operations = ps.nombre_op;
//				best_chunk_size = chunk_size;
//			}
//
//			// Libération de la mémoire
//			free_nodes(&(ps.head_a));
//			free_nodes(&(ps.head_b));
//			free_structure(&ps);
//		}
//
//		// Écrire la meilleure option dans un fichier
//		FILE *file = fopen("chunk_results.txt", "w");
//		fprintf(file, "Meilleure taille de chunk: %d avec le plus petit nombre d'opérations: %d\n", best_chunk_size, min_operations);
//		fclose(file);
//
//
//	return 0;
//}
