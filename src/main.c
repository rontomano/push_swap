/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:01:43 by drontome          #+#    #+#             */
/*   Updated: 2023/01/07 16:56:52 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	st_a;
	t_stack st_b;

	ft_bzero(&st_a, sizeof(t_stack));
	ft_bzero(&st_b, sizeof(t_stack));
	check_args(argc - 1, argv + 1, &st_a);
	if (is_sorted(st_a.top))
	{
		ft_lstclear(&st_a.top, free);
		exit(EXIT_SUCCESS);
	}
	else
		push_swap(&st_a, &st_b);
	ft_lstclear(&st_a.top, free);
	ft_lstclear(&st_b.top, free);
	return (0);
}
/*
//	ft_printf("EL TAMAÑO ES: %d\n", st_a.size);
	while(st_a.top)
		mov_push(&st_a.top, &st_b.top, 'b');
	ft_printf("EL STACK A ES:\n");
	ft_lstiter(st_a.top, ft_printf_void);
	ft_printf("EL STACK B ES:\n");
	ft_lstiter(st_b.top, ft_printf_void);
//	ft_printf("EL TAMAÑO ES: %d\n", st_a.size);
*/
