/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:17:08 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/06 14:17:17 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*last;

	if (!head || !new)
		return ;
	if (*head)
	{
		last = ft_lstlast(*head);
		last->next = new;
	}
	else
		*head = new;
}
