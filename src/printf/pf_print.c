/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:05:40 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 03:57:39 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		pf_print_sign(t_pf_env *env, int sign)
{
	if (sign == 1)
		pf_char_buff(env, '-');
	else if (env->flag[8] == 1)
		pf_char_buff(env, '+');
	else if (env->flag[11] == 1)
		pf_char_buff(env, ' ');
	else if (env->flag[5] == 1 && env->format[env->i] == 'x')
		pf_str_buff(env, "0x");
	else if (env->flag[5] == 1 && env->format[env->i] == 'X')
		pf_str_buff(env, "0X");
	else if (env->flag[5] >= 1 && env->format[env->i] == 'o')
		pf_char_buff(env, '0');
}

static void		pf_print_focus(t_pf_env *env, char *str, int sign, int len)
{
	int			focus;
	int			width;

	focus = env->flag[9] - len + sign + env->flag[11] + env->flag[8];
	width = env->flag[10] - len;
	pf_print_sign(env, sign);
	while (focus > 0)
	{
		pf_char_buff(env, '0');
		focus--;
		width--;
	}
	pf_str_buff(env, str);
	while (width > 0)
	{
		if (env->flag[6] == 1)
			pf_char_buff(env, '0');
		else
			pf_char_buff(env, ' ');
		width--;
	}
}

static void		pf_print_width(t_pf_env *env, char *str, int sign, int len)
{
	int			focus;
	int			width;

	focus = env->flag[9] - len + sign + env->flag[11] + env->flag[8];
	width = env->flag[10] - len;
	if (focus > 0)
		width -= focus;
	if (env->flag[6] == 1)
		pf_print_sign(env, sign);
	while (width > 0)
	{
		if (env->flag[6] == 1 && focus < 0)
			pf_char_buff(env, '0');
		else
			pf_char_buff(env, ' ');
		width--;
	}
	if (env->flag[6] == 0)
		pf_print_sign(env, sign);
	while (focus > 0)
	{
		pf_char_buff(env, '0');
		focus--;
	}
	pf_str_buff(env, str);
}

void			pf_print_dx(char *str, int sign, t_pf_env *env)
{
	int			len;

	len = ft_strlen(str);
	if (env->flag[8] == 1 || env->flag[11] == 1 || sign == 1)
		len++;
	if (env->flag[7] == 1)
		pf_print_focus(env, str, sign, len);
	else
		pf_print_width(env, str, sign, len);
	env->i++;
	free(str);
}
