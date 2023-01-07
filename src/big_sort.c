/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:39:44 by drontome          #+#    #+#             */
/*   Updated: 2023/01/07 18:14:20 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_up(t_stack *st_a, t_stack *st_b, t_mov movs);
static void	push_down(t_stack *st_a, t_stack *st_b, t_mov movs);
static int	last_is_top(t_list **top, int size);

void	big_sort(t_stack *st_a, t_stack *st_b)
{
	int 	chunk;
	int		range;
	t_mov	movs;

	chunk = st_a->size / CHUNK;
	if (chunk < 10)
		chunk = 10;
	range = 0;
	while (st_a->top) //&& !is_sorted(st_a->top))
	{
		if (get_moves(st_a, st_b, &movs, range))
			push_up(st_a, st_b, movs);
		else
			push_down(st_a, st_b, movs);
/*		if (st_b->size > 1 && *(int *)st_b->top->content > \
			*(int *)st_a->top->content)
			mov_rev;
*/		mov_push(&st_a->top, &st_b->top, 'b');
		st_b->size++;
		if (st_b->size == range + chunk)
			range = range + chunk;
	}
	if (last_is_top(&st_b->top, st_a->size))
	{
		while(st_b->top)
		{
			mov_push(&st_b->top, &st_a->top, 'a');
			st_b->size--;
		}
	}
}

static void	push_up(t_stack *st_a, t_stack *st_b, t_mov movs)
{
	while (movs.mov_tot)
	{
		if (movs.mov_a && movs.mov_b)
		{
			mov_rev(&st_a->top, 0);
			mov_rev(&st_b->top, 'r');
			movs.mov_a--;
			movs.mov_b--;
		}
		else if (movs.mov_a && *(int *)st_a->top->content != movs.n_a)
		{
			mov_rev(&st_a->top, 'a');
			movs.mov_a--;
		}
		else if (movs.mov_b)
		{
			mov_rev(&st_b->top, 'b');
			movs.mov_b--;
		}
		movs.mov_tot--;
	}
	return ;
}

static void	push_down(t_stack *st_a, t_stack *st_b, t_mov movs)
{
	while (movs.mov_tot)
	{
		if (movs.mov_a && movs.mov_b)
		{
			mov_rrev(&st_a->top, 0);
			mov_rrev(&st_b->top, 'r');
			movs.mov_a--;
			movs.mov_b--;
		}
		else if (movs.mov_a && *(int *)st_a->top->content != movs.n_a)
		{
			mov_rrev(&st_a->top, 'a');
			movs.mov_a--;
		}
		else if (movs.mov_b)
		{
			mov_rrev(&st_b->top, 'b');
			movs.mov_b--;
		}
		movs.mov_tot--;
	}
	return ;
}

static int	last_is_top(t_list **top, int size)
{
	t_list	*aux;
	int c;
	int last;

	aux = *top;
	c = 0;
	last = size - 1;
	while (aux && *(int *)aux->content != last)
	{
		c++;
		aux = aux->next;
	}
	if (*(int *)aux->content != last)
		return (0);
	else if (c <= size / 2)
	{
		while(*(int *)(*top)->content != last)
			mov_rev(top, 'b');
	}
	else if (c > size / 2)
	{
		while(*(int *)(*top)->content != last)
			mov_rrev(top, 'b');
	}
	return (1);
}

