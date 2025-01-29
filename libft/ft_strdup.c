/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:47 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/19 17:58:23 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_ptr;
	int		len;

	len = ft_strlen(s);
	dup_ptr = (void *)malloc (len + 1);
	if (!dup_ptr)
		return ((void *)0);
	ft_memcpy (dup_ptr, s, len);
	dup_ptr[len] = '\0';
	return (dup_ptr);
}
