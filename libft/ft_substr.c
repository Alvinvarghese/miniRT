/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:22:19 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/22 18:08:21 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substr_calloc(size_t size)
{
	char	*str;

	str = ft_calloc(sizeof(char), size + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (start >= ft_strlen(s))
		str = ft_substr_calloc(0);
	else
	{
		if (len > ft_strlen(s) - start)
			size = ft_strlen(s) - start;
		else
			size = len;
		str = ft_substr_calloc(size);
	}
	if (!str)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str);
	ft_strlcpy(str, s + start, size + 1);
	return (str);
}
