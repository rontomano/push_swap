/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:18:18 by drontome          #+#    #+#             */
/*   Updated: 2023/01/01 21:47:35 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_and_get(char *arg, t_stack *st_a);
static void		fill_stack(t_stack *st_a, int num);
static int		is_dup(t_stack *st_a, int num);
static char		*atoi_to_stack(char *str, t_stack *st_a);

void	check_args(int size, char **args, t_stack *st_a)
{
	int	i;

	i = 0;
	if (size < 1)
		exit(EXIT_FAILURE);
	while (args && args[i])
	{
		check_and_get(args[i], st_a);
		i++;
	}
	return ;
}

static void	check_and_get(char *arg, t_stack *st_a)
{
	while (arg && *arg)
	{
		while (arg && ft_isspace(*arg))
			arg++;
		if (arg && (ft_isdigit(*arg) || ((*arg == '+' || *arg == '-') \
			&& ft_isdigit(*(arg + 1)))))
		{
			arg = atoi_to_stack(arg, st_a);
			st_a->size++;
		}
		if (!arg || *arg == '\0')
		{
			if (st_a == 0)
				arg_error(st_a);
			else
				break ;
		}
		else if (ft_isspace(*arg))
			continue ;
		else
			arg_error(st_a);
	}
	return ;
}

static char	*atoi_to_stack(char *str, t_stack *st_a)
{
	size_t	num;
	int		neg;

	num = 0;
	neg = 1;

	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	if (!(*str >= 48 && *str <= 57))
		arg_error(st_a);
	while (str && *str >= 48 && *str <= 57)
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	if (num > (size_t)INT_MAX && neg == 1)
		arg_error(st_a);
	else if (num > (size_t)INT_MIN * -1 && neg == -1)
		arg_error(st_a);
	else
		fill_stack(st_a, num * neg);
	return (str);
}

static void	fill_stack(t_stack *st_a, int num)
{
	void	*n;
	t_list	*node;

	if (is_dup(st_a, num))
		arg_error(st_a);
	n = malloc(sizeof(num));
	if (!n)
		mem_error(st_a);
	if (!st_a->top)
	{
		st_a->top = ft_lstnew(n);
		if (st_a->top == NULL)
		{
			free (n);
			mem_error(st_a);
		}
	}
	else
	{
		node = ft_lstnew(n);
		if (!node)
			mem_error(st_a);
		ft_lstadd_back(&st_a->top, node);
	}
	ft_memcpy(n, &num, sizeof(num));
	return ;
}

static int is_dup(t_stack *st_a, int num)
{
	t_list	*aux;

	aux = st_a->top;
	if (!aux)
		return (0);
	while(aux && aux->content != NULL)
	{
		if (ft_memcmp(aux->content, &num, sizeof(num)) == 0)
			return (1);
		aux = aux->next;
	}
	return (0);
}
