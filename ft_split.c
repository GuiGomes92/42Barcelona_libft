/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:43:50 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/24 15:57:41 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_is_separator(char c, char sep)
{
	int i;

	i = 0;
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static	int	ft_get_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (ft_is_separator(s[i + 1], c) == 1 && ft_is_separator(s[i], c) == 0)
			words++;
		i++;
	}
	return (words);
}

static void write_word(char *list, char *s, char c)
{
	int i;

	i = 0;
	while (ft_is_separator(s[i], c) == 0)
	{
		list[i] = s[i];
		i++;
	}
	list[i] = '\0';
}

static void	*write_split(char **list, char *s, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_is_separator(s[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_separator(s[i + j], c) == 0)
				j++;
			list[word] = (char*)malloc(sizeof(char) * (j + 1));
			if (!list[word])
			{
				while (word > 0)
					free(list[--word]);
				return (NULL);
			}
			write_word(list[word], s + i, c);
			i += j;
			word++;
		}
	}
	return((void*)1);
}

char    **ft_split(char const *s, char c)
{
	char    **list;
	int     words;
	
	if (s == NULL)
		return (NULL);
	words = ft_get_words(s, c);
	list = (char **)malloc((words + 1)  * sizeof(char *));
	if (!list)
		return (NULL);
	list[words] = NULL;
	write_split(list, (char *)s, c);
	return (list);
}
