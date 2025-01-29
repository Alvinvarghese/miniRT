/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:06:59 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/19 17:58:50 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*src_ptr;
	char			*dest_ptr;
	size_t			i;

	src_ptr = (char *) src;
	dest_ptr = (char *) dest;
	i = 0;
	if (src_ptr == dest_ptr || n == 0)
		return (dest);
	else if (dest_ptr > src_ptr)
		while (n-- > 0)
			dest_ptr[n] = src_ptr[n];
	else
	{
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dest);
}
