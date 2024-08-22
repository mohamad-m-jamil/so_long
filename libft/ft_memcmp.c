/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:57:10 by mjamil            #+#    #+#             */
/*   Updated: 2024/06/12 18:03:10 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	i = 0;
	while (n > i)
	{
		if (a1[i] != a2[i])
		{
			return (a1[i] - a2[i]);
		}
		i++;
	}
	return (0);
}
