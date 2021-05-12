/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_addons.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 13:34:40 by okruitho      #+#    #+#                 */
/*   Updated: 2021/03/05 15:11:06 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../tokens.h"

int	ft_exprt_valid_check(char *str)
{
	int	x;

	x = 0;
	if (ft_isdigit(str[0]) || str[0] == '=' || ft_strlen(str) == 0)
		return (0);
	while (str[x] && str[x] != '=')
	{
		if (!ft_isalnum(str[x]) && str[x] != '_')
			return (0);
		x++;
	}
	return (1);
}
