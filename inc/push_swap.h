/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:22:23 by drontome          #+#    #+#             */
/*   Updated: 2022/12/22 11:11:57 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# define RED "\033[0;91m"
# define GREEN "\033[0;32m"
# define CEND "\033[0;39m"
# define EXIT_FAILURE 1
# define FALSE 0
# define TRUE 1

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"


typedef struct s_stack
{
	int	size;
	t_list *top;
}				t_stack;

#endif
