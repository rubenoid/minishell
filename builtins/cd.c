/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpha <alpha@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 02:18:40 by alpha         #+#    #+#                 */
/*   Updated: 2021/03/05 16:27:27 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../tokens.h"

int	ft_update_pwd(t_shell *sh, int quiet)
{
	if (!quiet)
		return (0);
	ft_export_add(ft_strsjoin("OLDPWD=", ft_export_findn(sh, "PWD", 3) \
		, 0, 0), sh, 0);
	free(sh->cur_path);
	sh->cur_path = ft_pwd(0, 0);
	ft_export_add(ft_strjoin("PWD=", sh->cur_path), sh, 0);
	return (0);
}

void	ft_print_error(char *str, int quiet)
{
	if (quiet)
		return ;
	if (errno == EACCES)
		ft_printf("%s: cd: %s: Permission denied\n", SHELL, str);
	else
		ft_printf("%s: cd: %s: No such file or directory\n", SHELL, str);
	errno = 0;
	exit(0);
}

int	ft_cd(char **str, t_shell *sh, int quiet)
{
	char	*dir;

	dir = 0;
	if (str[1] == 0)
	{
		dir = ft_export_findn(sh, "HOME", 4);
		chdir(dir);
		if (dir == 0)
		{
			if (!quiet)
				ft_printf("%s: cd: HOME not set\n", SHELL);
			return (0);
		}
		return (ft_update_pwd(sh, quiet));
	}
	if (chdir(str[1]) == 0 || str[1][0] == '\0')
		return (ft_update_pwd(sh, quiet));
	sh->rval = 1;
	ft_print_error(str[1], quiet);
	if (!quiet)
	{
		ft_printf("%s: cd: %s: No such file or directory\n", SHELL, str[1]);
		exit(0);
	}
	return (0);
}
