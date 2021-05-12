/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 20:55:57 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 17:30:15 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static void	ft_lst_replace(t_var *begin, t_var *new)
{
	free(begin->val);
	begin->val = ft_strdup(new->val);
	free(new->val);
	free(new);
}

t_var	*ft_vlstnew(char *c)
{
	t_var	*list;

	list = (t_var *)malloc(sizeof(t_var));
	if (!list)
		return (NULL);
	list->val = c;
	list->next = NULL;
	return (list);
}

void	ft_vlstadd_backr(t_var **alst, t_var *new)
{
	t_var	*begin;

	if (ft_strclen(new->val, '=') == 0)
	{
		free(new->val);
		free(new);
		return ;
	}
	if (!alst || !(*alst) || !new)
		return ;
	begin = (*alst);
	if (begin == NULL)
		(*alst) = new;
	else
	{
		while (begin->next != 0 && ft_strncmp(begin->val, new->val, \
								ft_strclen(new->val, '=')) != 0)
			begin = begin->next;
		if (begin->next == 0 && ft_strncmp(begin->val, new->val, \
		ft_strclen(new->val, '=')) != 0)
			begin->next = new;
		else
			ft_lst_replace(begin, new);
	}
}

char	**ft_lst2arr(t_var *lst)
{
	char	**rval;
	t_var	*l;
	int		x;

	x = 0;
	l = lst;
	if (l == 0)
		return (0);
	rval = malloc(sizeof(char *) * (ft_vlst_len(lst) + 1));
	while (l != 0)
	{
		rval[x] = ft_strdup(l->val);
		l = l->next;
		x++;
	}
	rval[x] = 0;
	return (rval);
}

int	ft_vlst_len(t_var *l)
{
	t_var	*list;
	int		x;

	list = l;
	x = 0;
	if (list == 0)
		return (x);
	while (list)
	{
		list = list->next;
		x++;
	}
	return (x);
}
