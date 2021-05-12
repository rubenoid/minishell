/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 20:13:24 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:53:44 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_length;

	needle_length = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (i + needle_length <= len && haystack[i] != '\0')
	{
		if (!ft_strncmp(&haystack[i], needle, needle_length))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
