/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:17:48 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/19 17:58:03 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*counter;

	counter = s + ft_strlen(s);
	while (counter >= s)
	{
		if (*counter == (char)c)
			return ((char *)counter);
		counter--;
	}
	return ((void *)0);
}
