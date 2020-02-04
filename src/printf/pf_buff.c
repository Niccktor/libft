/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 03:03:46 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 03:58:40 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	pf_flush(t_pf_env *env)
{
	env->ret += write(env->fd, env->buff, env->i_buff);
	pf_reset_buff(env);
}

void	pf_reset_buff(t_pf_env *env)
{
	ft_bzero(env->buff, BUFF_SIZE);
	env->i_buff = 0;
}

void	pf_str_buff(t_pf_env *env, char *str)
{
	while (*str)
	{
		env->buff[env->i_buff] = *str++;
		env->i_buff++;
		if (env->i_buff == BUFF_SIZE)
			pf_flush(env);
	}
}

void	pf_nstr_buff(t_pf_env *env, char *str, int n)
{
	while (*str && n > 0)
	{
		env->buff[env->i_buff] = *str++;
		env->i_buff++;
		n--;
		if (env->i_buff == BUFF_SIZE)
			pf_flush(env);
	}
}

void	pf_char_buff(t_pf_env *env, char c)
{
	env->buff[env->i_buff] = c;
	env->i_buff++;
	if (env->i_buff == BUFF_SIZE)
		pf_flush(env);
}
