/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:01:39 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/06 14:36:52 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		n;
	size_t		i;
	char		*res;

	n = 0;
	while (src[n])
		n++;
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (i++, i < n)
		res[i] = src[i];
	res[i] = '\0';
	return (res);
}
