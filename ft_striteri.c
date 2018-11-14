/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:07:42 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/14 16:58:55 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	current;

	if (s && f)
	{
		current = 0;
		while (s[current])
		{
			f(current, &s[current]);
			current++;
		}
	}
}
