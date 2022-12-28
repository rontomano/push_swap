/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:23:34 by drontome          #+#    #+#             */
/*   Updated: 2022/12/28 17:02:27 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int size, char **args, t_stack *st_a)
{
	int i;

	if (size < 1)
		exit(EXIT_FAILURE);
	while (args[i])
		check_and_get(args[i], st_a);

}

static void	check_and_get(char *arg, t_stack *st_a)
{
	char **sp_args;

	sp_args = ft_split(arg, ' ');
	if (sp_args == NULL)
		ft_free_exit(st_a);
	while (sp_args)
	{
		ft_atoi_in_swp(*sp_args, st_a);
		sp_args;
	}

}
