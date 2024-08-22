/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:14:15 by mjamil            #+#    #+#             */
/*   Updated: 2024/06/18 12:16:57 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	aa(char c, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(set);
	while (i < len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	len;

	start = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	while (aa(s1[start], set))
		start++;
	while (aa(s1[len -1], set))
		len--;
	return (ft_substr(s1, start, len - start));
}
