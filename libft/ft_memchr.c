/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:24:12 by mjamil            #+#    #+#             */
/*   Updated: 2024/06/12 16:52:43 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a1;

	a1 = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (a1[i] == (unsigned char) c)
		{
			return ((void *)a1 + i);
		}
		i++;
	}
	return (NULL);
}
