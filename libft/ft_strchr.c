/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:21 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/06 14:36:45 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int x)
{
	int		i;
	char	c;

	i = 0;
	c = (char)x;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}
