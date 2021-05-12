/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 04:33:53 by okruitho      #+#    #+#                 */
/*   Updated: 2021/03/05 17:58:42 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../tokens.h"

int	ft_identifier_check(char *str)
{
	int	x;

	x = 0;
	if (str[0] == 0)
		return (0);
	while (str[x])
	{
		if (!ft_isalnum(str[x]) && str[x] != '_')
			return (0);
		x++;
	}
	return (1);
}

void	ft_unsetter(char *str, t_shell *sh, t_var *lst, int lt)
{
	t_var	*old;
	t_var	*cur;

	cur = lst;
	old = 0;
	while (cur != 0)
	{
		if (ft_strncmp(cur->val, str, ft_strlen(str)) == 0 && \
			(cur->val[ft_strlen(str)] == '=' || cur->val[ft_strlen(str)] == 0))
		{
			if (old != 0)
				old->next = cur->next;
			else if (!lt)
				sh->exprt = cur->next;
			else if (lt)
				sh->env = cur->next;
			free(cur->val);
			free(cur);
			return ;
		}
		old = cur;
		cur = cur->next;
	}
}

/*
** if str[x] == 0, return 0;
*/

int	ft_unset(char **str, t_shell *sh, int quiet)
{
	int	x;

	x = 0;
	sh->rval = 0;
	while (str[x])
	{
		if (ft_identifier_check(str[x]) == 0)
		{
			if (!quiet)
			{
				ft_printf("%s: unset: `%s'", SHELL, str[x]);
				ft_printf(": not a valid identifier\n");
			}
			sh->rval = 1;
		}
		else
		{
			ft_unsetter(str[x], sh, sh->exprt, 0);
			ft_unsetter(str[x], sh, sh->env, 1);
			ft_env_recompile(sh);
		}
		x++;
	}
	return (sh->rval);
}
