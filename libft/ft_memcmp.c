/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:05:45 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/19 17:58:57 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					counter;
	const unsigned char		*mem_1;
	const unsigned char		*mem_2;

	counter = 0;
	mem_1 = (unsigned char *) s1;
	mem_2 = (unsigned char *)s2;
	while (counter < n)
	{
		if (mem_1[counter] != mem_2[counter])
			return (mem_1[counter] - mem_2[counter]);
		counter++;
	}
	return (0);
}
