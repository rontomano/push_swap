/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:23:34 by drontome          #+#    #+#             */
/*   Updated: 2022/12/22 11:19:49 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_exit(t_stack st)
{

}

char	*ft_atoi_swp(const char *str, t_stack *st_a)
{
	size_t	num;
	int		neg;

	num = 0;
	neg = 1;
	//a not necessary while
	while (*str == 32 || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	if (!(*str >= 48 && *str <= 57))
		return (0);
	while (str && *str >= 48 && *str <= 57)
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	if (str && *str != NULL)
		return (0);
	if (num > INT_MAX && neg == 1)
		return (-1);
	else if (num > INT_MIN && neg == -1)
		return (0);
	return (num * neg);
}
