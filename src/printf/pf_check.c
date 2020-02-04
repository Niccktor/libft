/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:54:34 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/23 06:28:57 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		pf_attribut(t_pf_env *env)
{
	while (env->format[env->i] == '#' || env->format[env->i] == '0'
		|| env->format[env->i] == '-' || env->format[env->i] == '+'
		|| env->format[env->i] == ' ')
	{
		if (env->format[env->i] == '#')
			env->flag[5] = 1;
		if (env->format[env->i] == '0' && env->flag[7] != 1)
			env->flag[6] = 1;
		if (env->format[env->i] == '-')
		{
			env->flag[7] = 1;
			env->flag[6] = 0;
		}
		if (env->format[env->i] == '+')
			env->flag[8] = 1;
		if (env->format[env->i] == ' ' && env->flag[8] != 1)
			env->flag[11] = 1;
		env->i++;
	}
}

static void		pf_width(t_pf_env *env)
{
	int			start;
	char		*str;

	start = -1;
	if (env->format[env->i] != '0' && ft_isdigit(env->format[env->i]))
	{
		while (ft_isdigit(env->format[env->i]))
		{
			if (start == -1)
				start = env->i;
			env->i++;
		}
		if (start != -1)
		{
			str = ft_strsub((const char*)env->format, start, env->i - 1);
			env->flag[10] = ft_atoi((const char*)str);
			free(str);
		}
	}
}

static void		pf_focus(t_pf_env *env)
{
	int			start;
	char		*str;

	start = -1;
	if (env->format[env->i] == '.')
	{
		env->i++;
		while (ft_isdigit(env->format[env->i]))
		{
			if (start == -1)
				start = env->i;
			env->i++;
		}
		if (start != -1)
		{
			str = ft_strsub((const char*)env->format, start, env->i - 1);
			env->flag[9] = ft_atoi((const char*)str);
			if (env->flag[9] == 0)
				env->flag[9] = -11;
			free(str);
		}
		else
			env->flag[9] = -10;
	}
}

static void		pf_modify(t_pf_env *env)
{
	if (env->format[env->i] == 'l' || env->format[env->i] == 'h'
		|| env->format[env->i] == 'L')
	{
		if (env->format[env->i] == 'L')
			env->flag[4] = 1;
		if (env->format[env->i] == 'l' && env->format[env->i + 1] == 'l')
		{
			env->flag[1] = 1;
			env->i++;
		}
		else if (env->format[env->i] == 'l')
			env->flag[0] = 1;
		if (env->format[env->i] == 'h' && env->format[env->i + 1] == 'h')
		{
			env->flag[3] = 1;
			env->i++;
		}
		else if (env->format[env->i] == 'h')
			env->flag[2] = 1;
		env->i++;
	}
}

int				pf_check(t_pf_env *env)
{
	pf_reset_flag(env);
	while (env->format[env->i] == '#' || env->format[env->i] == '0'
		|| env->format[env->i] == '-' || env->format[env->i] == '+'
		|| env->format[env->i] == ' ' || env->format[env->i] == 'h'
		|| env->format[env->i] == 'l' || env->format[env->i] == 'L'
		|| env->format[env->i] == '.' || ft_isdigit(env->format[env->i]))
	{
		pf_attribut(env);
		pf_width(env);
		pf_focus(env);
		pf_modify(env);
	}
	return (1);
}
