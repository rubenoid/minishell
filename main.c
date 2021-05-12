/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 19:24:32 by anonymous     #+#    #+#                 */
/*   Updated: 2021/03/29 17:48:44 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

t_shell	g_sh;
int		g_escaped;

static void	ft_execute_commands(char *str, t_shell *sh)
{
	char		*line;
	t_commands	com;

	line = ft_substr(str, 0, ft_find_semicolon(str));
	if (line == 0)
		exit(0);
	line = ft_exchanger(sh, line);
	if (!line)
		exit(0);
	ft_split_shell(line, &com);
	ft_clean_quotes(&com);
	if (!ft_fill_rorp(sh, &com))
	{
		ft_start_executing(&com, sh, 0);
	}
	ft_free_commands(&com);
	free(line);
}

static void	ft_command_loop(char *str, t_shell *sh)
{
	if (str[0] == 0 || g_escaped == 1)
		return ;
	if (ft_iscempty(str, ';'))
	{
		sh->rval = 2;
		ft_set_rval(sh);
		return ;
	}
	ft_execute_commands(str, sh);
	str = str + ft_find_semicolon(str);
	if (str[0] == ';')
		str++;
	if (!g_escaped)
		ft_set_rval(sh);
	ft_command_loop(str, sh);
}

static void	ft_start_prompt(char **env)
{
	int		ret;
	char	*line;

	if (!g_sh.init)
		ft_init_sh(&g_sh, env);
	ret = 1;
	while (1)
	{
		if (!g_escaped)
			ft_printf("$ ");
		ret = get_next_line_ext(0, &line);
		g_escaped = 0;
		if (ft_validity_check(line, &g_sh, 1) || ret == -1)
			continue ;
		if (line != 0)
			ft_command_loop(line, &g_sh);
		if (ret <= 0 && ft_strncmp(line, "", 1) == 0)
			exit(0);
		free(line);
	}
}

static void	ft_restart_prompt(int sig)
{
	g_escaped = 1;
	if (g_sh.rval_malloced)
	{
		g_sh.rval = 0;
		free(g_sh.rval_malloced);
	}
	g_sh.rval_malloced = ft_itoa(128 + sig);
	ft_printf("\n$ ");
}

int	main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, ft_restart_prompt);
	signal(SIGQUIT, ft_restart_prompt);
	ft_start_prompt(env);
	return (0);
}
