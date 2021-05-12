/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 20:55:04 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/12/08 20:27:48 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

void	ft_init_sh(t_shell *sh, char **env)
{
	ft_bzero(sh, sizeof(sh));
	sh->cur_path = ft_pwd(0, 0);
	sh->exprt = 0;
	ft_export_load(sh, env);
	if (ft_export_findn(sh, "PWD", 3) == 0)
		ft_export_add(ft_strjoin("PWD=", sh->cur_path), sh, 0);
	if (ft_export_findn(sh, "SHLVL", 6) == 0)
		ft_export_add("SHLVL=1", sh, 1);
	sh->env_arr = ft_lst2arr(sh->env);
	sh->rval = 0;
	sh->rval_malloced = ft_itoa(0);
	sh->init = 1;
}
