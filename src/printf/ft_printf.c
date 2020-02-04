/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:47:52 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 04:12:55 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	t_pf_env	env;

	pf_reset_buff(&env);
	env.fd = fd;
	env.format = format;
	env.ret = 0;
	va_start(ap, format);
	env.i = 0;
	while (env.format[env.i] != '\0')
	{
		if (env.format[env.i] == '%')
		{
			env.i++;
			pf_catch(&env, &ap);
		}
		else
		{
			ft_putchar(env.format[env.i]);
			env.i++;
		}
	}
	va_end(ap);
	return (env.ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_pf_env	env;

	pf_reset_buff(&env);
	env.format = format;
	env.fd = 1;
	env.i = 0;
	env.ret = 0;
	va_start(ap, format);
	while (env.format[env.i] != '\0')
	{
		if (env.format[env.i] == '%')
		{
			env.i++;
			pf_catch(&env, &ap);
		}
		else
		{
			pf_char_buff(&env, env.format[env.i]);
			env.i++;
		}
	}
	va_end(ap);
	pf_flush(&env);
	return (env.ret);
}
