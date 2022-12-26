/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:13:19 by drontome          #+#    #+#             */
/*   Updated: 2022/11/22 12:06:42 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(int argc char **argv)
{
	int x;
	int y;
	if argc < 3
		ft_error();
	x = 0;
	while ((argv[x]))
	{
		y = x + 1;
		while (argv[y])
		{
			if (!ft_strncmp(argv[x], argv[y], ft_strlen(argv[x]) == NULL))
				ft_error;
			y++;
		}

			argv++;
	}

}
