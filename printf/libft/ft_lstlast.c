/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:23:02 by khuk              #+#    #+#             */
/*   Updated: 2024/04/21 13:27:35 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_elem;

	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		else
			lst = lst->next;
	}
	last_elem = lst;
	return (last_elem);
}

/*
	if (!lst)
		return (NULL);
	while(lst->next)
		lst = lst->next;
	return (lst);


*/