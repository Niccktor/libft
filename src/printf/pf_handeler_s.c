/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:04:47 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 04:29:11 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	pf_print_str(t_pf_env *env, char *str)
{
	int		width;

	width = env->flag[10] - ft_strlen(str);
	if ((int)ft_strlen(str) > env->flag[9] && env->flag[9] > -1)
		width = env->flag[10] - env->flag[9];
	else if (env->flag[9] == -10)
		width = env->flag[10];
	while (env->flag[7] == 0 && --width >= 0)
	{
		if (env->flag[11] == 0 && env->flag[6] == 1)
			pf_char_buff(env, '0');
		else
			pf_char_buff(env, ' ');
	}
	if (env->flag[9] == -1)
		pf_str_buff(env, str);
	else if (env->flag[9] > 0)
	{
		if ((int)ft_strlen(str) > env->flag[9] && env->flag[9] > 0)
			pf_nstr_buff(env, str, env->flag[9]);
		else
			pf_str_buff(env, str);
	}
	while (env->flag[7] == 1 && --width >= 0)
		pf_char_buff(env, ' ');
}

void		pf_handeler_s(t_pf_env *env, va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (str == NULL)
		pf_print_str(env, "(null)");
	else
		pf_print_str(env, str);
	env->i++;
}
