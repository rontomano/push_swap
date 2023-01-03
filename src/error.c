/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:13:19 by drontome          #+#    #+#             */
/*   Updated: 2023/01/01 12:49:45 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_error(t_stack *st_a)
{
	ft_lstclear(&st_a->top, free);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	mem_error(t_stack *st_a)
{
	ft_lstclear(&st_a->top, free);
	ft_putstr_fd("Error in malloc\n", 2);
	exit(EXIT_FAILURE);
}
