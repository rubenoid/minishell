/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpha <alpha@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 03:24:10 by alpha         #+#    #+#                 */
/*   Updated: 2021/03/05 17:30:41 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../tokens.h"

int	ft_export(char **str, t_shell *sh, int quiet)
{
	int	x;

	x = 1;
	if (str[1] != 0 && ft_strlen(str[1]) != 0)
	{
		while (str[x])
		{
			if (ft_exprt_valid_check(str[x]) == 0)
			{
				if (!quiet)
				{
					ft_printf("%s: export: `%s'", SHELL, str[x]);
					ft_printf(": not a valid identifier\n");
				}
				sh->rval = 1;
			}
			else
				ft_export_add(str[x], sh, 1);
			x++;
		}
	}
	else
		return (ft_export_read(str, sh, quiet));
	return (sh->rval);
}

void	ft_export_add(char *str, t_shell *sh, int dup)
{
	ft_env_add(str, sh, 1);
	if (sh->exprt == 0 && dup == 1)
		sh->exprt = ft_vlstnew(ft_strdup(str));
	else if (sh->exprt == 0 && dup == 0)
		sh->exprt = ft_vlstnew(str);
	else if (dup == 1)
		ft_vlstadd_backr(&sh->exprt, ft_vlstnew(ft_strdup(str)));
	else if (dup == 0)
		ft_vlstadd_backr(&sh->exprt, ft_vlstnew(str));
}

int	ft_export_read(char **str, t_shell *sh, int quiet)
{
	t_var	*lst;

	(void)str;
	if (quiet)
		return (0);
	lst = sh->exprt;
	while (lst != 0)
	{
		ft_printf("declare -x ");
		write(1, lst->val, ft_strclen(lst->val, '=') + 1);
		if (ft_strclen(lst->val, '=') != (int)ft_strlen(lst->val))
		{
			write(1, "\"", 1);
			write(1, lst->val + ft_strclen(lst->val, '=') + 1, \
				ft_strlen(lst->val) - ft_strclen(lst->val, '=') - 1);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		lst = lst->next;
	}
	return (0);
}

void	ft_export_load(t_shell *sh, char **e)
{
	int	x;

	x = 0;
	while (e[x] != 0)
	{
		ft_export_add(e[x], sh, 1);
		x++;
	}
}

char	*ft_export_findn(t_shell *sh, char *s, int n)
{
	t_var	*lst;

	lst = sh->exprt;
	if (ft_strncmp("?", s, 2) == 0 || s[0] == '?')
		return (sh->rval_malloced);
	while (lst != 0)
	{
		if (ft_strncmp(s, lst->val, n) == 0 && lst->val[n] == '=')
		{
			return (lst->val + n + 1);
		}
		lst = lst->next;
	}
	return (0);
}
