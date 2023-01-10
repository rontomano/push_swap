/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:22:23 by drontome          #+#    #+#             */
/*   Updated: 2023/01/10 11:46:43 by drontome         ###   ########.fr       */
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
# define CHUNK 10


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

typedef struct s_num
{
	int 	num;
	size_t	ord;
}				t_num;

typedef struct s_mov
{
	int 	mov_a;
	int		mov_b;
	int		mov_tot;
	int		n_a;
	int		n_b;
}				t_mov;

void	check_args(int size, char **args, t_stack *st_a);
int		is_sorted(t_list *top);
void	mov_swap(t_list **top, char c);
void	mov_rev(t_list **top, char c);
void	mov_rrev(t_list **top, char c);
void	mov_push(t_list **out, t_list **in, char c);
void	push_swap(t_stack *st_a, t_stack *st_b);
t_num	get_max(t_list *top);
t_num	get_min(t_list *top);
void	arg_error(t_stack *st_a);
void	mem_error(t_stack *st_a);
void 	ft_printf_void(void *p);
void	quick_sort(t_list **top);
void	small_sort(t_list **top_a, t_list **top_b);
void	big_sort(t_stack *st_a, t_stack *st_b);
void	rearrange(t_stack *st);
int		get_right_pos(t_list *top);
void	get_moves(t_stack *st_a, t_stack *st_b, t_mov *right_movs, int range);
#endif
