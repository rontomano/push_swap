/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:39:00 by drontome          #+#    #+#             */
/*   Updated: 2022/10/26 21:29:25 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_var
{
	char		*line;
	char		*aux;
	char		*eln;
	size_t		i;
	int			flag;
	ssize_t		size;
}				t_var;

char	*get_next_line(int fd);
void	ft_init_var(t_var *var);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen_gnl(const char *s);
void	ft_cpy(char *dst, char *src, size_t n);
char	*ft_new_line(t_var *var, char *buf);

#endif
