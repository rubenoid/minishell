/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 21:11:23 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:52:43 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s_copy;
	int		i;

	if (s1 == 0)
		return (0);
	s_copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s_copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_copy[i] = s1[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
