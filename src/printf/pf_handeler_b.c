/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:06:56 by tbeguin           #+#    #+#             */
/*   Updated: 2020/03/03 15:19:12 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void					pf_handeler_b(t_pf_env *env, va_list *ap)
{
	unsigned long long	nbr;
	int					sign;

	sign = 0;
	if (env->flag[0] == 1)
		nbr = (unsigned long long int)va_arg(*ap, unsigned long int);
	else if (env->flag[1] == 1)
		nbr = (unsigned long long int)va_arg(*ap, unsigned long long int);
	else if (env->flag[2] == 1)
		nbr = (unsigned long long int)(unsigned short)va_arg(*ap, unsigned int);
	else if (env->flag[3] == 1)
		nbr = (unsigned long long int)(unsigned char)va_arg(*ap, unsigned int);
	else
		nbr = (unsigned long long int)va_arg(*ap, unsigned int);
	if (env->flag[5] == 1)
		pf_char_buff(env, '0');
	if (nbr == 0
			&& (env->flag[9] <= -10 || env->flag[5] == 1)
			&& env->flag[0] != 1
			&& env->flag[1] != 1
			&& env->flag[2] != 1
			&& env->flag[3] != 1)
		env->i++;
	else
		pf_print_dx(pf_itoa_base(nbr, 2), sign, env);
}
