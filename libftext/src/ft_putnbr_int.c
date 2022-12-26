/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:39:19 by drontome          #+#    #+#             */
/*   Updated: 2022/08/09 13:53:03 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_int(int ap)
{
	int		c;
	char	*p;

	p = ft_itoa(ap);
	c = ft_putstr(p);
	free(p);
	return (c);
}
