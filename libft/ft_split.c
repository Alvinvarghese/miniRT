/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:04:18 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/22 18:16:11 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	wrd_cntr(char const *s, char c)
{
	size_t	wrds;

	wrds = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			wrds++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (wrds);
}

static	void	free_arr(char **s, int index)
{
	while (index)
	{
		free(s[index]);
		index--;
	}
	free(s);
}

static int	ft_word_size(const char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	int		size;
	char	**str;

	i = 0;
	j = -1;
	word = wrd_cntr(s, c);
	str = (char **)malloc(sizeof(char *) * (word + 1));
	if (!str)
		return ((void *)0);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_word_size(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str[j])
			free_arr(str, j);
		i = size + i;
	}
	str[j] = ((void *)0);
	return (str);
}
