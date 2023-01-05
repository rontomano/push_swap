/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:15:09 by drontome          #+#    #+#             */
/*   Updated: 2023/01/03 19:44:08 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void sort_first_pos(t_list **top, int pos);

void	quick_sort(t_list **top)
{
	t_num		min;
	t_num		max;

	min = get_min(*top);
	max = get_max(*top);
	if(min.ord == 2 && max.ord == 3)
		mov_swap(top, 'a');
	else if(min.ord == 2 && max.ord == 1)
		mov_rev(top, 'a');
	else if(min.ord == 3 && max.ord == 2)
		mov_rrev(top, 'a');
	else if(min.ord == 3 && max.ord == 1)
	{
		mov_swap(top, 'a');
		mov_rrev(top, 'a');
	}
	else if(min.ord == 1 && max.ord == 2)
	{
		mov_swap(top, 'a');
		mov_rev(top, 'a');
	}
	return ;
}

void	small_sort(t_list **top_a, t_list **top_b)
{
	int	pos;

	mov_push(top_a, top_b, 'b');
	mov_push(top_a, top_b, 'b');
	quick_sort(top_a);
	mov_push(top_b, top_a, 'a');
	pos = get_right_pos(*top_a);
	sort_first_pos(top_a, pos);
	if (pos == 4)
		mov_rev(top_a, 'a');
	mov_push(top_b, top_a, 'a');
	pos = get_right_pos(*top_a);
	sort_first_pos(top_a, pos);
	if (pos == 4)
	{
		mov_rrev(top_a, 'a');
		mov_swap(top_a, 'a');
		mov_rev(top_a, 'a');
		mov_rev(top_a, 'a');
	}
	else if (pos == 5)
		mov_rev(top_a, 'a');
}

static void sort_first_pos(t_list **top, int pos)
{
	if (pos == 2)
		mov_swap(top, 'a');
	else if (pos == 3)
	{
		mov_swap(top, 'a');
		mov_rev(top, 'a');
		mov_swap(top, 'a');
		mov_rrev(top, 'a');
	}
	return ;
}
