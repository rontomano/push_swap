/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:32:10 by drontome          #+#    #+#             */
/*   Updated: 2023/01/05 20:18:25 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_swap(t_list **top, char c)
{
	if (top)
	{
		ft_lstswap(*top, (*top)->next);
		if (c == 'a')
			ft_putstr("sa\n");
		else if (c == 'b')
			ft_putstr("sb\n");
		else if (c == 's')
			ft_putstr("ss\n");
	}
	return ;
}

void	mov_rev(t_list **top, char c)
{
	t_list	*aux;

	if (top)
	{
		aux = *top;
		*top = (*top)->next;
		aux->next = NULL;
		ft_lstadd_back(top, aux);
		if (c == 'a')
			ft_putstr("ra\n");
		else if (c == 'b')
			ft_putstr("rb\n");
		else if (c == 'r')
			ft_putstr("rr\n");
	}
	return ;
}

void	mov_rrev(t_list **top, char c)
{
	t_list	*aux;
	t_list	*new_last;

	if (top)
	{
		aux = ft_lstlast(*top);
		new_last = ft_lstpenult(*top);
		new_last->next = NULL;
		ft_lstadd_front(top, aux);
		if (c == 'a')
			ft_putstr("rra\n");
		else if (c == 'b')
			ft_putstr("rrb\n");
		else if (c == 'r')
			ft_putstr("rrr\n");
	}
	return ;
}

void	mov_push(t_list **out, t_list **in, char c)
{
	t_list	*aux;

	if (out && in)
	{
		aux = *out;
		*out = (*out)->next;
		ft_lstadd_front(in, aux);
		if (c == 'a')
			ft_putstr("pa\n");
		else if (c == 'b')
			ft_putstr("pb\n");
	}
}
