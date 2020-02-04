/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_catch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:51:52 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/14 20:34:33 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void		pf_catch(t_pf_env *env, va_list *ap)
{
	t_pf_handel		handel[16];
	int				i;

	pf_check(env);
	pf_set_handel(handel);
	i = 0;
	while (handel[i].c != '\0' && handel[i].c != env->format[env->i])
		i++;
	if (handel[i].c == '%')
		handel[i].fnc(env);
	else if (handel[i].c != '\0')
		handel[i].fnc(env, ap);
}
