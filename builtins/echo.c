/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpha <alpha@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 02:13:48 by alpha         #+#    #+#                 */
/*   Updated: 2021/03/05 15:06:01 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../tokens.h"

void	ft_echo_loop(char **str)
{
	int	x;
	int	nflag;
	int	atstart;

	atstart = 1;
	nflag = 0;
	x = 1;
	while (str[x] != 0)
	{
		if ((ft_strncmp(str[x], "-n", 3) == 0 || \
			ft_strncmp(str[x], "-n", 3) == 'n') && atstart)
			nflag = 1;
		else
		{
			if (str[x + 1] != 0)
				ft_printf("%s ", str[x]);
			else
				ft_printf("%s", str[x]);
			atstart = 0;
		}
		x++;
	}
	if (nflag == 0)
		ft_printf("\n");
}

int	ft_echo(char **str, t_shell *sh, int quiet)
{
	(void)sh;
	if (quiet)
		return (0);
	ft_echo_loop(str);
	return (0);
}
