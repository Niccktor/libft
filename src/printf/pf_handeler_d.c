/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:57:26 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 02:41:17 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int						pf_check_null(t_pf_env *env, unsigned long long unbr)
{
	if ((unbr == 0 &&
			(env->flag[9] <= -10 || env->flag[9] == -1)
			&& env->flag[10] == 0
			&& env->flag[8] == 0
			&& env->flag[0] != 1
			&& env->flag[1] != 1
			&& env->flag[2] != 1
			&& env->flag[3] != 1))
		return (1);
	return (0);
}

static void				pf_flag_set(t_pf_env *env, int sign)
{
	if (env->flag[6] == 1 && env->flag[7] == 1)
		env->flag[6] = 0;
	if (env->flag[9] == -10 && env->flag[6] == 1)
		env->flag[6] = 0;
	if (env->flag[6] == 1 && env->flag[9] > 0)
		env->flag[6] = 0;
	if (env->flag[11] == 1 && env->flag[8] == 1)
		env->flag[11] = 0;
	if (sign == 1)
	{
		env->flag[11] = 0;
		env->flag[8] = 0;
	}
}

void					pf_handeler_d(t_pf_env *env, va_list *ap)
{
	long long int		nbr;
	unsigned long long	unbr;
	int					sign;

	sign = 0;
	if (env->flag[0] == 1)
		nbr = (long long int)va_arg(*ap, long int);
	else if (env->flag[1] == 1)
		nbr = (long long int)va_arg(*ap, long long int);
	else if (env->flag[2] == 1)
		nbr = (long long int)(short)va_arg(*ap, int);
	else if (env->flag[3] == 1)
		nbr = (long long int)(char)va_arg(*ap, int);
	else
		nbr = (long long int)va_arg(*ap, int);
	sign = (nbr < 0) ? 1 : 0;
	unbr = (nbr < 0) ? -nbr : nbr;
	pf_flag_set(env, sign);
	if (unbr == 0 && env->flag[9] <= -10)
		pf_print_dx(ft_strdup("\0"), sign, env);
	else
		pf_print_dx(pf_itoa_base(unbr, 10), sign, env);
}
