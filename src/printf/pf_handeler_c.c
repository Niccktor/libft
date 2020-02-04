/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:56:39 by tbeguin           #+#    #+#             */
/*   Updated: 2020/02/04 01:22:35 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	pf_handeler_c(t_pf_env *env, va_list *ap)
{
	int len;

	len = env->flag[10] - 1;
	while (len > 0 && env->flag[7] == 0)
	{
		if (env->flag[6] == 1)
			pf_char_buff(env, '0');
		else
			pf_char_buff(env, ' ');
		len--;
	}
	env->i += 1;
	pf_char_buff(env, (char)va_arg(*ap, int));
	while (len > 0 && env->flag[7] == 1)
	{
		pf_char_buff(env, ' ');
		len--;
	}
}
