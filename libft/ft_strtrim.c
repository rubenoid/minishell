/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 20:54:04 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:54:04 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		p1;

	i = 0;
	p1 = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				p1++;
				break ;
			}
			if (j == (int)ft_strlen(set) - 1 && s1[i] != set[j])
				return (p1);
			j++;
		}
		i++;
	}
	return (p1);
}

static int	find_end(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		p2;

	i = (int)ft_strlen(s1) - 1;
	p2 = (int)ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				p2--;
				break ;
			}
			if (j == (int)ft_strlen(set) - 1 && s1[i] != set[j])
				return (p2);
			j++;
		}
		i--;
	}
	return (p2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		p1;
	int		p2;
	char	*trim;

	if (s1 == 0 || set == 0)
		return (0);
	p1 = find_start(s1, set);
	p2 = find_end(s1, set);
	if (p1 > p2)
	{
		trim = (char *)malloc(sizeof(char));
		trim[0] = '\0';
		return (trim);
	}
	trim = (char *)malloc((p2 - p1 + 2) * sizeof(char));
	if (!trim)
		return (NULL);
	trim = ft_memcpy(trim, s1 + p1, p2 - p1 + 1);
	trim[p2 - p1 + 1] = '\0';
	return (trim);
}
