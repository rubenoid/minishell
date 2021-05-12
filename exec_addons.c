/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_addons.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 13:44:48 by okruitho      #+#    #+#                 */
/*   Updated: 2021/03/05 15:13:07 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static char	*ft_isrelabs(char *path)
{
	char		*rval;
	struct stat	path_stat;

	rval = 0;
	if (!path)
		return (0);
	if (path[0] == '.' && path[1] == '/')
		rval = ft_strsjoin(ft_pwd(0, 0), path + 1, 0, 1);
	else if (ft_strclen(path, '/') != (int)ft_strlen(path))
		rval = path;
	if (rval == 0)
		return (0);
	if (stat(rval, &path_stat) < 0)
	{
		ft_printf("%s: %s: No such file or directory\n", SHELL, path);
		exit(127);
	}
	if (S_ISDIR(path_stat.st_mode))
	{
		ft_printf("%s: %s: is a directory\n", SHELL, path);
		exit(126);
	}
	return (rval);
}

static char	*ft_path_match(char *path, char *command)
{
	DIR				*d;
	struct dirent	*dir;
	char			*rval;

	d = opendir(path);
	if (d)
	{
		dir = readdir(d);
		dir = readdir(d);
		dir = readdir(d);
		while (dir != NULL)
		{
			if (!ft_strncmp(command, dir->d_name, ft_strlen(dir->d_name) + 1))
			{
				rval = ft_strsjoin(path, dir->d_name, '/', 0);
				closedir(d);
				return (rval);
			}
			dir = readdir(d);
		}
		closedir(d);
	}
	return (0);
}

char	*find_exec(t_shell *sh, char *str)
{
	char	**path;
	int		x;
	char	*rval;

	x = 0;
	rval = ft_isrelabs(str);
	if (rval != 0)
		return (rval);
	if (str == 0 || ft_isbuiltin(str))
		return (0);
	path = ft_split(ft_export_findn(sh, "PATH", 4), ':');
	if (path == 0)
		return (0);
	while (path[x] != 0)
	{
		if (rval == 0)
			rval = ft_path_match(path[x], str);
		free(path[x]);
		x++;
	}
	free(path);
	return (rval);
}

void	ft_free_fd(int **fd, t_commands *com)
{
	int	x;

	x = 0;
	while (fd != 0 && x < com->amount_commands + 1)
	{
		free(fd[x]);
		x++;
	}
	free(fd);
}
