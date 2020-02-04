/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:50:09 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 02:13:02 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static unsigned long long	ft_pow(int nbr, int i)
{
	unsigned long long		nb;

	nb = 1;
	while (i)
	{
		nb *= nbr;
		i--;
	}
	return (nb);
}

void						reverse(char *str, int len)
{
	int						i;
	int						j;
	char					tmp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int							int_to_str(unsigned long long nbr, char *str, int d)
{
	int						i;

	i = 0;
	if (nbr == 0)
		str[i++] = '0';
	while (nbr)
	{
		str[i++] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

void						pf_round(char *str, int focus)
{
	int						i;

	i = ft_strlen(str) - 1;
	if (str[i] - '0' >= 5)
	{
		str[i] = '\0';
		i--;
		while (str[i] == '9' || str[i] == '.')
		{
			if (str[i] != '.')
				str[i] = '0';
			i--;
		}
		str[i]++;
	}
	else
		str[i] = '\0';
	if (focus == 1)
	{
		i = 0;
		while (str[i] != '.')
			i++;
		str[i] = '\0';
	}
}

char						*pf_ftoa(long double nbr, int focus)
{
	unsigned long long		int_part;
	int						i;
	long double				fl_part;
	char					*str;

	focus++;
	int_part = (unsigned long long)nbr;
	fl_part = nbr - (long double)int_part;
	if ((str = ft_strnew(itoa_len(int_part, 10) + 1 + focus)) == NULL)
		ft_strdup("0");
	i = int_to_str(int_part, str, 0);
	if (focus)
	{
		str[i] = '.';
		fl_part = fl_part * ft_pow(10, focus);
		int_to_str((unsigned long long)fl_part, str + i + 1, focus);
	}
	pf_round(str, focus);
	return (str);
}
