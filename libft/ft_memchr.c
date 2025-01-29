/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:06:08 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/19 17:59:00 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t						counter;
	const unsigned char			*src_ptr;

	counter = 0;
	src_ptr = (const unsigned char *)s;
	while (counter < n)
	{
		if (src_ptr[counter] == (unsigned char)c)
			return ((void *) &src_ptr[counter]);
		counter++;
	}
	return ((void *)0);
}
