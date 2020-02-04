/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_xup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:06:57 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/23 06:32:14 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static char				*pf_to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

static int				pf_check_null(t_pf_env *env, unsigned long long nbr)
{
	if (nbr == 0
			&& env->flag[9] <= -10
			&& env->flag[0] != 1
			&& env->flag[1] != 1
			&& env->flag[2] != 1
			&& env->flag[3] != 1)
		return (1);
	return (0);
}

static void				pf_flag_set(t_pf_env *env)
{
	if (env->flag[6] == 1 && env->flag[9] > 0)
		env->flag[6] = 0;
	if (env->flag[6] == 1 && env->flag[7] == 1)
		env->flag[6] = 0;
	if (env->flag[8] == 1 && env->flag[11] == 1)
		env->flag[11] = 0;
}

void					pf_handeler_x_up(t_pf_env *env, va_list *ap)
{
	unsigned long long	nbr;

	pf_flag_set(env);
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
	if (nbr == 0)
		env->flag[5] = 0;
	else if (nbr > 0 && env->flag[5] == 1)
		env->flag[10] -= 2;
	if (pf_check_null(env, nbr) == 1)
		pf_print_dx(ft_strdup("\0"), 0, env);
	else
		pf_print_dx(pf_to_upper(pf_itoa_base(nbr, 16)), 0, env);
}
