/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_rdir_addons.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 20:10:08 by anonymous     #+#    #+#                 */
/*   Updated: 2021/03/05 15:17:33 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

int	ft_arr_len(char **arr)
{
	int	x;

	x = 0;
	while (arr[x])
	{
		x++;
	}
	return (x);
}

void	ft_align_array(char **arr, int len)
{
	int	x;
	int	altered;

	x = 0;
	altered = 0;
	while (x < len)
	{
		if (arr[x] == 0 && arr[x + 1] != 0)
		{
			arr[x] = ft_strdup(arr[x + 1]);
			free(arr[x + 1]);
			arr[x + 1] = 0;
			altered = 1;
		}
		x++;
	}
	if (altered)
		ft_align_array(arr, len);
}

int	ft_ispermitted(char *name, char type)
{
	struct stat	st;

	if (stat(name, &st) < 0)
		return (1);
	if (type == '<' && (st.st_mode & S_IREAD) != 0)
		return (1);
	else if (type != '<')
		return (1);
	return (0);
}
