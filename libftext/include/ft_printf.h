/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drontome <drontome@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:12:11 by drontome          #+#    #+#             */
/*   Updated: 2022/10/26 21:14:20 by drontome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(char const *s, ...);
int	ft_putchar(int ap);
int	ft_putstr(char *ap);
int	ft_getformat(char c, va_list ap);
int	ft_put_ptr(void *ap);
int	ft_putnbr_hex(unsigned int nbr, char c);
int	ft_putnbr_int(int ap);
int	ft_putnbr_uns(unsigned int ap);
#endif
