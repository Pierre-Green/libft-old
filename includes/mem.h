/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:58:21 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:19:50 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H
# include <stdlib.h>

void				*ft_memchr(const void *b, int c, size_t len);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memset(void *s, int c, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				ft_bzero(void *s, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

#endif