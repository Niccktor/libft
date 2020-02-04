/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_unknow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:05:41 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 04:00:08 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void			pf_handeler_unknow(t_pf_env *env)
{
	int len;

	len = 1;
	while (env->flag[10] > len && env->flag[7] == 0)
	{
		len++;
		if (env->flag[6] == 1)
			pf_char_buff(env, '0');
		else
			pf_char_buff(env, ' ');
	}
	pf_char_buff(env, '%');
	while (env->flag[10] > len && env->flag[7] == 1)
	{
		len++;
		pf_char_buff(env, ' ');
	}
	env->i++;
}
