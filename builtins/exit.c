/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/25 04:51:12 by okruitho      #+#    #+#                 */
/*   Updated: 2021/03/05 15:08:35 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../tokens.h"

void	ft_lst_delall(t_var *lst)
{
	t_var	*nxt;

	if (!lst)
		return ;
	nxt = lst;
	while (nxt)
	{
		lst = nxt;
		free(lst->val);
		nxt = lst->next;
	}
}

int	ft_isnumeric(char *s)
{
	int	x;

	x = 0;
	if (!s)
		return (1);
	while (s[x] == ' ' || (s[x] >= 9 && s[x] <= 13))
		x++;
	while (s[x])
	{
		if ((!ft_isdigit(s[x]) && s[x] != ' ' && s[x] != '-' && s[x] != '+' \
			 && s[x] != '-' && s[x] != '\t') || (s[x] == '+' && s[x + 1] == '+') \
			 || (s[x] == '-' && s[x + 1] == '-'))
			return (0);
		x++;
	}
	return (1);
}

void	ft_exit_val(long rval, char **s)
{
	if ((rval > INT_MAX && rval != LONG_MAX) || \
		(rval < INT_MIN && rval != LONG_MIN))
	{
		if (rval % 2 == 0)
			exit(0);
		else
			exit(255);
	}
	if (!ft_isnumeric(s[1]) || (rval == LONG_MAX || rval == LONG_MIN))
	{
		ft_printf("%s: exit: %s: numeric argument required\n", SHELL, s[1]);
		exit(255);
	}
	if (s[1] && s[2])
	{
		if (!ft_isnumeric(s[1]))
			ft_printf("%s: exit: %s: too many arguments\n", SHELL, s[1]);
		else
			ft_printf("%s: exit: too many arguments\n", SHELL);
		exit(1);
	}
	else
		exit((unsigned char)rval);
}

int	ft_exit(char **s, t_shell *sh, int quiet)
{
	long	rval;
	int		x;

	free(sh->cur_path);
	ft_lst_delall(sh->exprt);
	ft_lst_delall(sh->env);
	if (s[1] == 0 || !quiet)
		exit(0);
	rval = atol(s[1]);
	x = 0;
	while (s[1][x] == ' ' || (s[1][x] >= 9 && s[1][x] <= 13))
		x++;
	if (ft_strncmp(&s[1][x], "-9223372036854775808", 20) == 0)
		exit(0);
	if (ft_strncmp(&s[1][x], "9223372036854775807", 19) == 0)
		exit(255);
	ft_exit_val(rval, s);
	return (0);
}
