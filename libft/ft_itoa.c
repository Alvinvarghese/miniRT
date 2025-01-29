/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:06:49 by avarghes          #+#    #+#             */
/*   Updated: 2022/12/19 17:59:03 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	num;
	char	*num_arr;

	len = num_len(n);
	num = n;
	num_arr = (char *) malloc(sizeof(char) * (len + 1));
	if (!num_arr)
		return ((void *)0);
	if (num < 0)
	{
		num_arr[0] = '-';
		num = num * -1;
	}		
	if (num == 0)
		num_arr[0] = '0';
	num_arr[len] = '\0';
	len--;
	while (num != 0)
	{
		num_arr[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (num_arr);
}
