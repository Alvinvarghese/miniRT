/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:08:24 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/19 17:58:19 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*joined_str;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = (char *) malloc ((s1_len + s2_len + 1));
	if (! joined_str)
		return ((void *)0);
	ft_memcpy(joined_str, s1, s1_len);
	while (i < s2_len)
	{
		joined_str[s1_len + i] = s2[i];
		i++;
	}
	joined_str[s1_len + s2_len] = '\0';
	return (joined_str);
}
