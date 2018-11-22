/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:05:17 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/22 17:53:13 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define ERROR -42
#define OK 0

ssize_t		ft_getline_test(FILE *stream, char **line)
{
	size_t linecap = 0;

	return (getline(line, &linecap, stream));
}

void		ft_print_not_equals(char *line, int ret, char *test_line)
{
	printf("ERROR:\nYour function return: %d\nDiff:\nYours:\n%s\nReal:\n%s\n", ret, line, test_line);
}

int			ft_test(const char *file, int number)
{
	char	*line;
	int		fd;
	int		ret;
	int		count_line;

	printf("Test %d:\n\n", number);

	if (!(fd = open(file, O_RDONLY)))
		return (-42);

	count_line = 0;
	while ((ret = get_next_line(0, &line)) != RET_ERR)
	{
		count_line++;
		printf("%d: Ret: %d\n%s\n",count_line, ret, line);
		if (ret == RET_DONE)
			break;
	}
	close(fd);
	return (OK);
}

int		main(int argc, char **argv)
{
	argc = -argc;
	argv[0][0] = '3';
	// ft_test("./tests/txt1", 1);
	ft_test("./tests/txt2", 2);
	return (0);
}