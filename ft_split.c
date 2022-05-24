/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:43:50 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/23 19:24:24 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static	int	ft_getlen(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			j++;
		}
		i++;
	}
	return (j);
}
char    **ft_split(char const *s, char c)
{
	char    **list;
	int     i;
	int     j;

	i = 0;
	j = ft_getlen(s, c);
	list = (char **)malloc(j + 1  * sizeof(char *));
	list[j + 1] = NULL;
	char    *ptr;
	while (s[i] != '\0' && list)
	{
		if (s[i] == c)
		{
			ptr = (char *)malloc(i + 1 * sizeof(char));
			while (*s != c)
			{
				*ptr = *s;
				s++; 
				ptr++;
			}
			*ptr = '\0';
			*list = ptr - i;
			s++;
			list++; 
			i = 0;
		}
		else
			i++;
	}
	return (list);
}
