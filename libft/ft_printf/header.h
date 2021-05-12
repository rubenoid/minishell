/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 20:55:19 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:58:29 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>

# include "../libft.h"

typedef struct s_flag
{
	short int	dot;
	short int	dash;
	short int	zero;
	short int	space;
	short int	hash;
	short int	mod_el;
	short int	mod_ha;
	short int	sign;
	int			width;
	int			prec;
}				t_flag;

typedef struct s_conv
{
	short int	c;
	short int	s;
	short int	p;
	short int	d;
	short int	i;
	short int	u;
	short int	x;
	short int	big_x;
	short int	n;
	short int	prc;
	short int	f;
}				t_conv;

void			print_digit_other(t_flag *flag, t_conv *conv, int d_len,
					unsigned long long d);
void			print_digit_set_edges(t_flag *flag, t_conv *conv,
					unsigned long long d);
int				ft_isconv(t_conv *conv, char c);
int				ft_printf(const char *format, ...);
int				ft_putchar_amount(char c, int size);
int				get_flag_all(t_flag *flag, const char *format,
					va_list *arg, int i);
int				ft_len_hex(unsigned long long d);
int				ft_abs(int n);
int				ft_len_dec(unsigned long long d);
void			ft_conv_d(va_list *arg, t_flag *flag, t_conv *conv);
void			ft_clear_flags(t_flag *flag);
void			ft_clear_isconv(t_conv *conv);
void			ft_conv_c(va_list *arg, t_flag *flag);
void			ft_conv_s(va_list *arg, t_flag *flag);
void			ft_conv_xup(va_list *arg, t_flag *flag, t_conv *conv);
void			ft_putchar(int c);
void			ft_putchars_str(char c, int amount, char *s);
void			ft_putnbr_hex(unsigned long n, t_conv *conv);
void			ft_putnbr_ull(unsigned long long n);
void			ft_putstr(char *s);
void			ft_putstr_chars(char *s, char c, int amount);
void			print_char(t_flag *flag, int c);
void			print_digit(t_flag *flag, t_conv *conv, unsigned long long d);
void			print_str(t_flag *flag, char *s);
#endif
