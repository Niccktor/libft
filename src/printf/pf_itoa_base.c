/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:01:59 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 02:13:35 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

ssize_t					itoa_len(unsigned long long nbr, int base)
{
	ssize_t				i;

	i = 0;
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char					*pf_itoa_base(unsigned long long nbr, int base)
{
	char				*str;
	int					len;
	int					i;

	if (nbr == 0)
		return (ft_strdup("0\0"));
	len = itoa_len(nbr, base);
	if ((str = (char *)ft_memalloc(sizeof(char) * len + 1)) == NULL)
		return (ft_strdup("0x0\0"));
	i = 0;
	while (nbr)
	{
		if (nbr % base > 9)
			str[len - i - 1] = 'a' + nbr % base - 10;
		else
			str[len - i - 1] = '0' + nbr % base;
		nbr /= base;
		i++;
	}
	return (str);
}
