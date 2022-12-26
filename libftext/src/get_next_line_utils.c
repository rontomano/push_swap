/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:39:08 by drontome          #+#    #+#             */
/*   Updated: 2022/10/18 16:54:44 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_init_var(t_var *var)
{
	var->line = NULL;
	var->aux = NULL;
	var->eln = NULL;
	var->i = 0;
	var->flag = 0;
	var->size = 0;
	return ;
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != 0)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	c;

	c = 0;
	if (!s)
		return (c);
	while (*(s + c) != 0)
		c++;
	return (c);
}

void	ft_cpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return ;
	while (i < n && *(src + i) != 0)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return ;
}

char	*ft_new_line(t_var *var, char *buf)
{
	var->aux = NULL;
	var->size = ft_strlen_gnl(var->eln + 1) + 1;
	var->aux = malloc(var->size);
	if (!var->aux)
		return (NULL);
	ft_cpy(var->aux, (var->eln + 1), var->size);
	free(buf);
	buf = NULL;
	return (var->aux);
}
