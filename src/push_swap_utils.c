/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:23:34 by drontome          #+#    #+#             */
/*   Updated: 2023/01/03 19:32:03 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_printf_void(void *p)
{
	ft_printf("%d\n", *(int *)p);
}

int	is_sorted(t_list *top)
{
	int min;
	t_list *aux;

	min = *(int *)top->content;
	aux = top->next;
	while (aux != NULL)
	{
		if (min < *(int *)aux->content)
		{
			min = *(int *)aux->content;
			aux = aux->next;
		}
		else
			return (0);
	}
	return (1);
}

t_num	get_min(t_list *top)
{
	size_t	cont;
	t_num	min;

	cont = 1;
	min.num = *(int *)top->content;
	min.ord = cont;
	while (top)
	{
		if (min.num > *(int*)top->content)
		{
			min.num = *(int*)top->content;
			min.ord = cont;
		}
		top = top->next;
		cont++;
	}
	return (min);
}

t_num	get_max(t_list *top)
{
	size_t	cont;
	t_num 	max;

	cont = 1;
	max.num = *(int *)top->content;
	max.ord = cont;
	while (top)
	{
		if (max.num < *(int*)top->content)
		{
			max.num = *(int*)top->content;
			max.ord = cont;
		}
		top = top->next;
		cont++;
	}
	return (max);
}

int	get_right_pos(t_list *top)
{
	int pos;
	int n;

	pos = 1;
	n = *(int *)top->content;
	top = top->next;
	while (top && n > *(int *)top->content)
	{
		pos++;
		top = top->next;
	}
	return(pos);
}
