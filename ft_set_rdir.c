/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_rdir.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 20:02:18 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/29 17:46:53 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "libft/libft.h"

static int	load_fd(char type, char *name, t_shell *sh)
{
	int	rv;

	rv = -1;
	if (type == '>')
		rv = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (type == '^')
		rv = open(name, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else if (type == '<')
		rv = open(name, O_RDONLY);
	if (!ft_ispermitted(name, type))
	{
		ft_printf("%s: %s: Permission denied\n", SHELL, name);
		sh->rval = 1;
	}
	else if (rv == -1 || (read(rv, 0, 0) < 0 && type == '<'))
	{
		ft_printf("%s: %s: No such file or directory\n", SHELL, name);
		sh->rval = 1;
	}
	return (rv);
}

static void	ft_set_rdir(t_shell *sh, t_commands *com, int x, int i)
{
	if (com->tokens[x][i][0] == '<')
	{
		if (com->redirect[x][0].fd != 0)
			close(com->redirect[x][0].fd);
		com->redirect[x][0].type = com->tokens[x][i][0];
		com->redirect[x][0].fd = load_fd(com->redirect[x][0].type, \
			com->tokens[x][i + 1], sh);
	}
	else
	{
		if (com->redirect[x][1].fd != 0)
			close(com->redirect[x][1].fd);
		if (com->tokens[x][i][0] == com->tokens[x][i][1])
			com->redirect[x][1].type = '^';
		else
			com->redirect[x][1].type = '>';
		com->redirect[x][1].fd = load_fd(com->redirect[x][1].type, \
			com->tokens[x][i + 1], sh);
	}
	free(com->tokens[x][i]);
	free(com->tokens[x][i + 1]);
	com->tokens[x][i] = 0;
	com->tokens[x][i + 1] = 0;
	ft_align_array(com->tokens[x], ft_arr_len(com->tokens[x]));
}

int	ft_fill_rorp(t_shell *sh, t_commands *com)
{
	int	x;
	int	i;

	x = 0;
	while (com->tokens[x] != 0 && sh->rval == 0)
	{
		i = 0;
		while (com->tokens[x][i] && sh->rval == 0)
		{
			if (ft_strncmp(">>>", com->tokens[x][i], 3) == 0 \
				 || ft_strncmp("<<", com->tokens[x][i], 2) == 0)
			{
				sh->rval = 2;
				return (2);
			}
			if (!ft_strncmp("<", com->tokens[x][i], 2) || \
			(!ft_strncmp(">", com->tokens[x][i], 2) || \
			!ft_strncmp(">>", com->tokens[x][i], 3)))
				ft_set_rdir(sh, com, x, i);
			else
				i++;
		}
		x++;
	}
	return (sh->rval);
}
