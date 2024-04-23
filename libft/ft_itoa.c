/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:02:20 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:10:46 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	char_from_int(int nbr)
{
	return (nbr + 48);
}

char	*ft_itoa(int n)
{
	int		signal;
	int		i_num;
	char	*num;

	num = (char *)malloc(sizeof(char) * 12);
	if (!num)
		return (NULL);
	signal = 1;
	i_num = 0;
	if (n < 0)
		signal = ft_add_signal_if_negative(num, i_num++);
	while (n / 10 != 0)
	{
		num[i_num++] = char_from_int(signal * (n % 10));
		n = n / 10;
	}
	num[i_num++] = char_from_int(signal * (n % 10));
	num[i_num] = '\0';
	ft_strrev(num);
	num = ft_realloc(num);
	if (!num)
		return (NULL);
	return (num);
}
