/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:49:16 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/19 17:58:46 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp_addr;
	size_t			i;

	i = 0;
	temp_addr = s;
	while (i < n)
	{
		temp_addr[i] = c;
		i++;
	}
	return (temp_addr);
}
