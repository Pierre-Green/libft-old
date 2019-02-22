/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:59:47 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/22 13:44:42 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include <dirent.h>
# include "ft_bool.h"
# include <sys/types.h>

typedef struct		s_dfiles
{
	struct dirent	*file;
	struct s_dfiles	*next;
}					t_dfiles;

t_dfiles			*ft_get_dir_files(DIR *dir, const char *ext, size_t *count);

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

void				ft_putnbrl(int n, size_t len);

void				ft_putnbrl_fd(int n, int fd, size_t l);

void				ft_put_uint(uintmax_t i);

void				ft_put_uint_fd(uintmax_t i, int fd);

void				ft_putl_uint(uintmax_t i, size_t l);

void				ft_putl_uint_fd(uintmax_t i, int fd, size_t l);

#endif
