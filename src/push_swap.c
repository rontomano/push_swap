/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:37:59 by drontome          #+#    #+#             */
/*   Updated: 2023/01/05 21:37:37 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *st_a, t_stack *st_b)
{
	if (st_a->size == 2)
		mov_swap(&st_a->top, 'a');
	else if (st_a->size == 3)
		quick_sort(&st_a->top);
	else if (st_a->size == 5)
		small_sort(&st_a->top, &st_b->top);
	else if (st_a->size > 5)
	{
		rearrange(st_a);
		big_sort(st_a, st_b);
	}
	return ;
}
