/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 22:03:13 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/20 16:23:18 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void				pf_flag_set(t_pf_env *env, unsigned long long nbr)
{
	env->flag[11] = 0;
	env->flag[8] = 0;
	if (env->flag[6] == 1 && env->flag[7] == 1)
		env->flag[6] = 0;
	if (env->flag[6] == 1 && env->flag[9] > 0)
		env->flag[6] = 0;
	if (nbr == 0 && env->flag[5] == 1)
		env->flag[5] = 2;
	if (env->flag[5] == 1 || env->flag[5] == 2)
	{
		env->flag[10]--;
		env->flag[9]--;
	}
}

void					pf_handeler_o(t_pf_env *env, va_list *ap)
{
	unsigned long long	nbr;

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
	pf_flag_set(env, nbr);
	if (env->flag[5] == 2
			|| (nbr == 0 && env->flag[9] <= -10))
		pf_print_dx(ft_strdup("\0"), 0, env);
	else
		pf_print_dx(pf_itoa_base(nbr, 8), 0, env);
}
