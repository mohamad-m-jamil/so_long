/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:34:02 by mjamil            #+#    #+#             */
/*   Updated: 2024/06/13 15:43:21 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	reslen;
	char	*a;
	char	*new_str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	a = (char *)s + start;
	if (len >= ft_strlen(a))
		reslen = ft_strlen(a) + 1;
	else
		reslen = len + 1;
	new_str = (char *)malloc(reslen);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, a, reslen);
	return (new_str);
}
