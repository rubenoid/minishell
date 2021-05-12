/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executing.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 20:57:07 by anonymous     #+#    #+#                 */
/*   Updated: 2021/03/29 17:48:58 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "libft/libft.h"

static int	**load_pipes(int len)
{
	int		**fd;
	int		x;

	x = 1;
	if (len == 0)
		return (0);
	fd = malloc(sizeof(int *) * (len + 1));
	if (fd == 0)
		return (0);
	fd[0] = 0;
	while (x < len)
	{
		fd[x] = malloc(sizeof(int) * 2);
		if (fd[x] == 0)
			return (0);
		if (pipe(fd[x]) == -1)
		{
			ft_printf("%s\npipe fail", strerror(errno));
			return (0);
		}
		x++;
	}
	fd[x] = 0;
	return (fd);
}

static void	ft_dup(int *fdin, int *fdout, t_redirect *rd)
{
	if (rd && rd[STD_IN].type == '<')
		dup2(rd[STD_IN].fd, 0);
	else if (fdin != 0)
		dup2(fdin[STD_IN], 0);
	if (rd && (rd[STD_OUT].type == '>' || rd[STD_OUT].type == '^'))
		dup2(rd[STD_OUT].fd, 1);
	else if (fdout != 0)
		dup2(fdout[STD_OUT], 1);
	if (fdin)
	{
		close(fdin[STD_IN]);
		close(fdin[STD_OUT]);
	}
	if (fdout)
	{
		close(fdout[STD_IN]);
		close(fdout[STD_OUT]);
	}
}

static int	can_exec(const char *file)
{
	struct stat		st;
	struct stat		stl;

	if (file == 0)
		return (1);
	if (lstat(file, &stl) < 0 || stat(file, &st) < 0)
		return (0);
	if (S_ISLNK(st.st_mode) || S_ISDIR(st.st_mode) || S_ISLNK(stl.st_mode))
		return (1);
	if ((st.st_mode & S_IEXEC) != 0 && (st.st_mode & S_IREAD) != 0)
		return (1);
	return (0);
}

static void	execute2(int **fd, int x, t_shell *sh, t_commands *c)
{
	char	*p;

	if (c->tokens[x][0] == 0 || c->tokens[x][0][0] == 0)
		return ;
	ft_dup(fd[x], fd[x + 1], c->redirect[x]);
	if (ft_isbuiltin(c->tokens[x][0]))
		exit(ft_run_builtin(c->tokens[x], sh, 0));
	p = find_exec(sh, c->tokens[x][0]);
	if (can_exec(p) == 0)
	{
		ft_printf("%s: %s: Permission denied\n", SHELL, c->tokens[x][0]);
		exit(126);
	}
	execve(p, c->tokens[x], sh->env_arr);
	if (errno == 2 || p == 0)
	{
		ft_printf("%s: %s: command not found\n", SHELL, c->tokens[x][0]);
		exit(127);
	}
	else if (errno != ENOEXEC)
	{
		ft_printf("%s: %s: %s\n", SHELL, c->tokens[x][0], strerror(errno));
		exit(126);
	}
	exit(0);
}

void	ft_start_executing(t_commands *com, t_shell *sh, int x)
{
	int		**fd;
	pid_t	pid;

	fd = load_pipes(com->amount_commands);
	while (x < com->amount_commands)
	{
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			execute2(fd, x, sh, com);
		if (ft_isbuiltin(com->tokens[x][0]) && pid != 0 && \
			x == com->amount_commands - 1)
			ft_run_builtin(com->tokens[x], sh, 1);
		if (x > 0)
		{
			close(fd[x][0]);
			close(fd[x][1]);
		}
		x++;
	}
	waitpid(pid, &sh->rval, 0);
	sh->rval = WEXITSTATUS(sh->rval);
	ft_free_fd(fd, com);
}
