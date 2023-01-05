/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:44:37 by drontome          #+#    #+#             */
/*   Updated: 2023/01/05 20:48:36 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_mov	get_moves_up(t_stack *st_a, t_stack *st_b, int range);
static t_mov	get_moves_down(t_stack *st_a, t_stack *st_b, int range);
static int	get_mov_b(t_stack *st_b, t_mov up);


int	get_moves(t_stack *st_a, t_stack *st_b, t_mov *movs, int range)
{
	t_mov	up;
	t_mov	down;

	up = get_moves_up(st_a, st_b, range);
	down = get_moves_down(st_a, st_b, range);
	if (up.mov_tot > down.mov_tot)
	{
		*movs = down;
		return (FALSE);
	}
	else
	{
		*movs = up;
		return (TRUE);
	}
}

static t_mov	get_moves_up(t_stack *st_a, t_stack *st_b, int range)
{
	int chunk;
	t_mov	up;
	t_list	*aux;

	chunk = st_a->size / CHUNK;
	if (chunk < 10)
		chunk = 10;
	aux = st_a->top;
	up.mov_a = 0;
	while (aux)
	{
		if (*(int *)aux->content >= range && *(int *)aux->content < range + chunk)
		{
			up.num = *(int *)aux->content;
			break;
		}
		ft_printf_void(aux->content);
		up.mov_a++;
		aux = aux->next;
	}
	up.mov_b = get_mov_b(st_b, up);
	if (up.mov_a >= up.mov_b)
		up.mov_tot = up.mov_a;
	else if (up.mov_a < up.mov_b)
		up.mov_tot = up.mov_b;
	return(up);
}


static t_mov	get_moves_down(t_stack *st_a, t_stack *st_b, int range)
{
	int		chunk;
	int		c;
	t_mov	down;
	t_list	*aux;

	chunk = st_a->size / CHUNK;
	if (chunk < 10)
		chunk = 10;
	aux = st_a->top;
	down.mov_a = 0;
	c = 0;
	while (aux)
	{
		if (*(int *)aux->content >= range && *(int *)aux->content < range + chunk)
		{
			down.num = *(int *)aux->content;
			down.mov_a = c;
		}
		c++;
		aux = aux->next;
	}
	down.mov_a = st_a->size - down.mov_a;
	down.mov_b = st_b->size - get_mov_b(st_b, down);
	if (down.mov_a >= down.mov_b)
		down.mov_tot = down.mov_a;
	else if (down.mov_a < down.mov_b)
		down.mov_tot = down.mov_b;
	return(down);
}

static int	get_mov_b(t_stack *st_b, t_mov up)
{
	t_list	*aux;
	int		c;

	aux = st_b->top;
	if (!aux || aux->next == NULL)
		return (0);
	c = 0;
	while (TRUE)
	{
		aux = st_b->top;
		up.mov_b = 0;
		c++;
		while(aux)
		{
			if (*(int *)aux->content == up.num - c)
				return (up.mov_b);
			else if (*(int *)aux->content == up.num + c)
				return (up.mov_b + 1);
			aux = aux->next;
			up.mov_b++;
		}
	}
}
