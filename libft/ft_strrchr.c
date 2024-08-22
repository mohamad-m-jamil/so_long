/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:50:32 by mjamil            #+#    #+#             */
/*   Updated: 2024/06/12 18:49:40 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if (s[i] == (unsigned char)c)
	{
		return ((char *)s + i);
	}
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (NULL);
}
