/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 21:00:18 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/29 17:48:48 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/stat.h>
# include <limits.h>

# define STD_IN 0
# define STD_OUT 1
# define SHELL "minishell"

typedef struct s_redirect
{
	char		type;
	int			fd;
}				t_redirect;

typedef struct s_commands
{
	char		***tokens;
	int			amount_commands;
	t_redirect	**redirect;
	int			amount_redirects;
}				t_commands;

typedef struct s_var
{
	char		*val;
	void		*next;
}				t_var;

typedef struct s_shell
{
	char		*cur_path;
	t_var		*exprt;
	t_var		*env;
	char		**env_arr;
	int			rval;
	char		*rval_malloced;
	int			init;
}				t_shell;

void			ft_init_sh(t_shell *sh, char **env);
/*
** PARSING
*/
void			ft_split_shell(char *line, t_commands *com);
char			**ft_split_to_tok(const char *s, char c);
int				ft_fill_rorp(t_shell *sh, t_commands *com);
int				ft_find_semicolon(char *str);
int				get_next_line_ext(int fd, char **line);
void			ft_clean_quotes(t_commands *com);
void			ft_set_rval(t_shell *sh);
int				ft_validity_check(char *s, t_shell *sh, int freeable);
int				ft_ispermitted(char *name, char type);
void			ft_align_array(char **arr, int len);
int				ft_find_begin(char *s, size_t *i);
int				ft_find_end(char *s, size_t *i);
int				ft_arr_len(char **arr);
char			*ft_exchanger(t_shell *sh, char *str);
int				ft_length_for_rorp(const char *s, size_t *i);
/*
** EXECUTING
*/
void			ft_start_executing(t_commands *com, t_shell *sh, int x);
int				ft_isbuiltin(char *str);
int				ft_run_builtin(char **str, t_shell *sh, int quiet);
int				ft_is_redorpipe(char c);
char			*find_exec(t_shell *sh, char *str);
/*
** FREE
*/
void			ft_free_commands(t_commands *com);
void			ft_free_fd(int **fd, t_commands *com);

/*
** BUILTINS
*/
int				ft_exit(char **str, t_shell *sh, int quiet);
char			*ft_pwd(char **s, t_shell *sh);
int				ft_pwd_nl(char **s, t_shell *sh, int quiet);
int				ft_echo(char **str, t_shell *sh, int quiet);
int				ft_env(char **str, t_shell *sh, int quiet);
void			ft_env_add(char *str, t_shell *sh, int dup);
void			ft_env_recompile(t_shell *sh);
int				ft_cd(char **str, t_shell *sh, int quiet);
int				ft_export(char **str, t_shell *sh, int quiet);
int				ft_export_read(char **str, t_shell *sh, int quiet);
void			ft_export_load(t_shell *sh, char **e);
void			ft_export_add(char *str, t_shell *sh, int dup);
char			*ft_export_findn(t_shell *sh, char *s, int n);
int				ft_unset(char **str, t_shell *sh, int quiet);

/*
** LIST
*/
void			ft_vlstadd_backr(t_var **alst, t_var *new);
t_var			*ft_vlstnew(char *c);
int				ft_vlst_len(t_var *l);
char			**ft_lst2arr(t_var *lst);

/*
** ADDONS
*/
int				ft_iscempty(char *str, char c);
int				ft_strclen(char *str, char c);
char			*ft_strsjoin(char *s1, char *s2, int seperator, int freeable);
int				ft_exprt_valid_check(char *str);

#endif
