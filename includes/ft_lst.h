/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:56:10 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 20:58:38 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list				*ft_lstfold(t_list **lst, t_list *(*f)(t_list *elem));

int					ft_lstsize(t_list *begin_list);

t_list				*ft_lstlast(t_list *begin_list);

t_list				*ft_lstat(t_list *begin_list, unsigned int nbr);

#endif
