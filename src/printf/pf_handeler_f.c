/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:24:04 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 02:00:20 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void				pf_flag_set(t_pf_env *env)
{
	if (env->flag[11] == 1 && env->flag[8] == 1)
		env->flag[11] = 0;
	if (env->flag[6] == 1 && env->flag[7] == 1)
		env->flag[6] = 0;
	if (env->flag[9] == -1)
		env->flag[9] = 6;
	if (env->flag[9] == -11)
		env->flag[9] = 0;
	if (env->flag[9] == -10)
		env->flag[9] = 6;
}

void					pf_handeler_f(t_pf_env *env, va_list *ap)
{
	long double			nbr;
	char				*str;
	int					sign;

	sign = 0;
	pf_flag_set(env);
	if (env->flag[4] == 1)
		nbr = (long double)va_arg(*ap, long double);
	else if (env->flag[0] == 1)
		nbr = (long double)va_arg(*ap, double);
	else
		nbr = (long double)va_arg(*ap, double);
	sign = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	str = pf_ftoa(nbr, env->flag[9]);
	if (env->flag[5] == 1 && env->flag[9] == 0)
		str[ft_strlen(str)] = '.';
	pf_print_dx(str, sign, env);
}
