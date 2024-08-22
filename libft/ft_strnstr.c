/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:31:09 by mjamil            #+#    #+#             */
/*   Updated: 2024/06/19 19:40:46 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && len == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && (i + j) < len)
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
