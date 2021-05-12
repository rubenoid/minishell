/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 00:41:29 by okruitho      #+#    #+#                 */
/*   Updated: 2021/03/05 15:07:04 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../tokens.h"

void	ft_env_recompile(t_shell *sh)
{
	int	x;

	x = 0;
	while (sh->env_arr && sh->env_arr[x])
	{
		free(sh->env_arr[x]);
		x++;
	}
	free(sh->env_arr);
	sh->env_arr = ft_lst2arr(sh->env);
}

int	ft_env(char **str, t_shell *sh, int quiet)
{
	t_var	*lst;

	(void)(str);
	lst = sh->env;
	if (quiet)
		return (0);
	while (lst)
	{
		ft_printf("%s\n", lst->val);
		lst = lst->next;
	}
	return (0);
}

void	ft_env_add(char *str, t_shell *sh, int dup)
{
	if (!str || str[0] == 0)
		return ;
	if (sh->env == 0 && dup == 1)
		sh->env = ft_vlstnew(ft_strdup(str));
	else if (sh->env == 0 && dup == 0)
		sh->env = ft_vlstnew(str);
	else if (dup == 1)
		ft_vlstadd_backr(&sh->env, ft_vlstnew(ft_strdup(str)));
	else if (dup == 0)
		ft_vlstadd_backr(&sh->env, ft_vlstnew(str));
}
