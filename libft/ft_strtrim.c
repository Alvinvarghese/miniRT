/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:38:56 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/19 18:24:34 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_str;
	size_t	front;
	size_t	rear;

	trim_str = ((void *)0);
	if (s1 == 0 || set == 0)
		return ((void *)0);
	front = 0;
	rear = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (s1[rear - 1] && ft_strchr(set, s1[rear - 1]) && rear > front)
		rear--;
	trim_str = (char *) malloc (rear - front + 1);
	if (trim_str)
		ft_strlcpy(trim_str, &s1[front], rear - front + 1);
	return (trim_str);
}
