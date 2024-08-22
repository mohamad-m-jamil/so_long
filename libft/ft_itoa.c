/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:17:19 by mjamil            #+#    #+#             */
/*   Updated: 2024/06/18 13:20:43 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	getlen(int n)
{
	size_t	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;

	num = n;
	len = (getlen(n));
	str = (char *)malloc (len +1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		num = -n;
	while (len > 0)
	{
		len--;
		str[len] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
