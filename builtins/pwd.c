/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpha <alpha@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 02:05:36 by alpha         #+#    #+#                 */
/*   Updated: 2021/03/05 15:10:23 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../tokens.h"

int	ft_pwd_nl(char **s, t_shell *sh, int quiet)
{
	char	*pwd;

	(void)s;
	(void)sh;
	if (quiet)
		return (0);
	pwd = ft_pwd(0, 0);
	ft_printf("%s\n", pwd);
	free(pwd);
	return (0);
}

char	*ft_pwd(char **str, t_shell *sh)
{
	(void)str;
	(void)sh;
	return (getcwd(NULL, 0));
}
