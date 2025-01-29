/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:56:12 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/19 18:15:44 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	pos;
	size_t	i;

	pos = 0;
	if (!*little)
		return ((char *) big);
	while (big[pos] != '\0' && pos < len)
	{
		if (big[pos] == little[0])
		{
			i = 1;
			while (little[i] != '\0' && big[pos + i] == little[i] && \
			(pos + i) < len)
				i++;
			if (little[i] == '\0')
				return ((char *) &big[pos]);
		}
		pos++;
	}
	return ((void *)0);
}
