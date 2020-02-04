/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:06:31 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/23 07:03:47 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	pf_set_handel_suite(t_pf_handel *handel)
{
	handel[12].c = '\0';
	handel[12].fnc = &pf_handeler_unknow;
}

void		pf_set_handel(t_pf_handel *handel)
{
	handel[0].c = 'c';
	handel[0].fnc = &pf_handeler_c;
	handel[1].c = 's';
	handel[1].fnc = &pf_handeler_s;
	handel[2].c = 'p';
	handel[2].fnc = &pf_handeler_p;
	handel[3].c = 'd';
	handel[3].fnc = &pf_handeler_d;
	handel[4].c = 'i';
	handel[4].fnc = &pf_handeler_d;
	handel[5].c = 'o';
	handel[5].fnc = &pf_handeler_o;
	handel[6].c = 'u';
	handel[6].fnc = &pf_handeler_u;
	handel[7].c = 'x';
	handel[7].fnc = &pf_handeler_x;
	handel[8].c = 'X';
	handel[8].fnc = &pf_handeler_x_up;
	handel[9].c = '%';
	handel[9].fnc = &pf_handeler_unknow;
	handel[10].c = 'b';
	handel[10].fnc = &pf_handeler_b;
	handel[11].c = 'f';
	handel[11].fnc = &pf_handeler_f;
	pf_set_handel_suite(handel);
}

void		pf_reset_flag(t_pf_env *env)
{
	int		i;

	i = -1;
	while (++i < 14)
		env->flag[i] = 0;
	env->flag[9] = -1;
	env->flag[i] = 0;
}
