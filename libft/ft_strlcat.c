/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:45:40 by mjamil            #+#    #+#             */
/*   Updated: 2024/06/12 19:21:48 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;
	size_t	j;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	i = 0;
	j = 0;
	if (size == 0)
		return (len_s);
	if (size <= len_d)
		return (size + len_s);
	while (dst[i] != '\0' && i < size - 1)
		i++;
	while (src[j] && i < size -1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_d + len_s);
}
