/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:59:47 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 16:54:14 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include <unistd.h>
# include <wchar.h>

void				ft_putchar(char c);

void				ft_putwchar(wchar_t wc);

void				ft_putchar_fd(char c, int fd);

void				ft_putwchar_fd(wchar_t wc, int fd);

void				ft_putstr(char const *s);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl(char const *s);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr(int n);

void				ft_putnbr_fd(int n, int fd);

#endif
