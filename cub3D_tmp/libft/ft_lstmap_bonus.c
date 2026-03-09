/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:23:38 by khuk              #+#    #+#             */
/*   Updated: 2024/04/21 14:26:33 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*result;
	t_list	*new_element;	

	new_list = NULL;
	while (lst != NULL)
	{
		result = (*f)(lst->content);
		if (!result)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_element = ft_lstnew(result);
		if (!new_element)
		{
			ft_lstclear(&new_list, del);
			(*del)(result);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*result;	
	
	new_list = NULL;
	while (lst != NULL)			//проходимось по усьому списку
	{
		result = (*f)(lst->content);	//зберігаємо результат
		if (!result)			//якщо результат негативний (null)
		{
			ft_lstclear(&new_list, del); 	//очищаємо список що вже
			встигли створити 
			return (NULL);			//виходимо з програми
		}
		ft_lstadd_back(&new_list, ft_lstnew(result));	
		//створюємо новий елемент списку 
		з результатом який нам повернула функція 
		(*f) і додаємо його в кінець списку 
		lst = lst->next;		
	}
	return (new_list);
}*/
