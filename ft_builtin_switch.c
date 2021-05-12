/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_builtin_switch.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 19:57:54 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/19 16:36:00 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static char	*g_builtin_list[] = {
	"echo",
	"exit",
	"pwd",
	"cd",
	"env",
	"export",
	"unset",
	NULL,
};

static	int	(*g_builtin_func[])(char **s, t_shell *sh, int quiet) = {
	ft_echo,
	ft_exit,
	ft_pwd_nl,
	ft_cd,
	ft_env,
	ft_export,
	ft_unset,
};

int	ft_isbuiltin(char *str)
{
	int	x;

	x = 0;
	while (g_builtin_list[x] != 0 && str)
	{
		if (ft_strncmp(str, g_builtin_list[x], \
			ft_strlen(g_builtin_list[x]) + 1) == 0)
			return (x + 1);
		x++;
	}
	return (0);
}

int	ft_run_builtin(char **str, t_shell *sh, int quiet)
{
	return (g_builtin_func[ft_isbuiltin(str[0]) - 1](str, sh, quiet));
}
