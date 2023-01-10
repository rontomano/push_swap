	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:44:37 by drontome          #+#    #+#             */
/*   Updated: 2023/01/07 20:50:34 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_mov	get_moves_first(t_stack *st_a, t_stack *st_b, int range);
static t_mov	get_moves_last(t_stack *st_a, t_stack *st_b, int range);
static void		get_mov_b(t_stack *st_b, t_mov *mov);
static void		up_or_down(int size, t_mov *mov);


void	get_moves(t_stack *st_a, t_stack *st_b, t_mov *right_movs, int range)
{
	t_mov	first;
	t_mov	last;

	first = get_moves_first(st_a, st_b, range);
	last = get_moves_last(st_a, st_b, range);
	if (first.mov_tot > last.mov_tot)
		*right_movs = last;
	else
		*right_movs = first;
	return ;
}

static t_mov	get_moves_first(t_stack *st_a, t_stack *st_b, int range)
{
	int	chunk;
	t_mov	first;
	t_list	*aux;

	chunk = st_a->size / CHUNK;
	if (chunk < 10)
		chunk = 10;
	aux = st_a->top;
	first.mov_a = 0;
	while (aux)
	{
		if (*(int *)aux->content >= range && *(int *)aux->content < range + chunk)
		{
			first.n_a = *(int *)aux->content;
			break;
		}
		first.mov_a++;
		aux = aux->next;
	}
	get_mov_b(st_b, &first);
	if (first.mov_b < 0)
		first.mov_tot = first.mov_a + (first.mov_b * -1);
	else
	{
		if (first.mov_a >= first.mov_b)
			first.mov_tot = first.mov_a;
		else if (first.mov_a < first.mov_b)
			first.mov_tot = first.mov_b;
	}
	return(first);
}


static t_mov	get_moves_last(t_stack *st_a, t_stack *st_b, int range)
{
	int		chunk;
	int		c;
	t_mov	last;
	t_list	*aux;

	chunk = st_a->size / CHUNK;
	if (chunk < 10)
		chunk = 10;
	aux = st_a->top;
	last.mov_a = 0;
	c = 0;
	while (aux)
	{
		if (*(int *)aux->content >= range && *(int *)aux->content < range + chunk)
		{
			last.n_a = *(int *)aux->content;
			last.mov_a = c;
		}
		c++;
		aux = aux->next;
	}
	if (st_b->size < st_a->size - 1)
		last.mov_a = st_a->size - st_b->size - last.mov_a;
	get_mov_b(st_b, &last);
	last.mov_a *= -1;
	if (last.mov_b > 0)
		last.mov_tot = (last.mov_a - last.mov_b) * -1;
	else
	{
		if (last.mov_a <= last.mov_b)
			last.mov_tot = last.mov_a * -1;
		else if (last.mov_a > last.mov_b)
			last.mov_tot = last.mov_b * -1;
	}
	return(last);
}

static void	get_mov_b(t_stack *st_b, t_mov *mov)
{
	t_list	*aux;
	int		c;

	aux = st_b->top;
	if (!aux || aux->next == NULL)
	{
		mov->mov_b = 0;
		return ;
	}
	c = 0;
	while (TRUE)
	{
		aux = st_b->top;
		mov->mov_b = 0;
		c++;
		while(aux)
		{

			if (*(int *)aux->content == mov->n_a - c)
			{
				mov->n_b = *(int *)aux->content;
				return (up_or_down(st_b->size, mov));
			}
			else if (*(int *)aux->content == mov->n_a + c)
			{
				mov->n_b = *(int *)aux->content;
				return (up_or_down(st_b->size, mov));
			}
			aux = aux->next;
			mov->mov_b++;
		}
	}
}

static void	up_or_down(int size, t_mov *mov)
{
	int	up;
	int	down;

	up = 0;
	down = 0;
	if (mov->n_a < mov->n_b)
	{
		up = 1;
		down = 1;
	}
	if (size / 2 >= mov->mov_b + up)
		mov->mov_b += up;
	else
		mov->mov_b = (size - mov->mov_b - down) * -1;
	return ;
}
