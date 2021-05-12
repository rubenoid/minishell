/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 19:54:45 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:13:57 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static void	ft_free_tokens(char ***tokens)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tokens[x] != 0)
	{
		y = 0;
		while (tokens[x][y] != 0)
		{
			free(tokens[x][y]);
			y++;
		}
		free(tokens[x]);
		x++;
	}
	free(tokens);
}

static void	ft_free_redirs(t_redirect **rdirs)
{
	int	x;

	x = 0;
	while (rdirs[x] != 0)
	{
		if (rdirs[x][0].fd > 1)
			close(rdirs[x][0].fd);
		if (rdirs[x][1].fd > 1)
			close(rdirs[x][1].fd);
		free(rdirs[x]);
		x++;
	}
	free(rdirs);
}

void	ft_free_commands(t_commands *com)
{
	ft_free_tokens(com->tokens);
	ft_free_redirs(com->redirect);
}
