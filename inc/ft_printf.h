/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:25:33 by tbeguin           #+#    #+#             */
/*   Updated: 2020/02/04 02:27:00 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft.h"
#include <stdarg.h>

typedef struct		s_pf_env
{
	int			fd;
	int			ret;
	int			i;
	int			i_buff;
	const char	*format;
	char		buff[BUFF_SIZE];
	int			flag[13];
	va_list		*ap;
}					t_pf_env;

typedef struct		s_pf_handel
{
	char		c;
	void		(*fnc)();
}					t_pf_handel;

int					ft_printf(const char *format, ...);
void				pf_print_dx(char *str, int sign, t_pf_env *env);
void				pf_catch(t_pf_env *env, va_list *ap);
int					pf_check(t_pf_env *env);
void				pf_set_handel(t_pf_handel *handel);
void				pf_reset_flag(t_pf_env *env);
void				pf_handeler_b(t_pf_env *env, va_list *ap);
void				pf_handeler_c(t_pf_env *env, va_list *ap);
void				pf_handeler_f(t_pf_env *env, va_list *ap);
void				pf_handeler_s(t_pf_env *env, va_list *ap);
void				pf_handeler_p(t_pf_env *env, va_list *ap);
void				pf_handeler_d(t_pf_env *env, va_list *ap);
void				pf_handeler_o(t_pf_env *env, va_list *ap);
void				pf_handeler_u(t_pf_env *env, va_list *ap);
void				pf_handeler_x(t_pf_env *env, va_list *ap);
void				pf_handeler_x_up(t_pf_env *env, va_list *ap);
void				pf_handeler_unknow(t_pf_env *env);
void				pf_flush(t_pf_env *env);
void				pf_reset_buff(t_pf_env *env);
void				pf_str_buff(t_pf_env *env, char *str);
void				pf_nstr_buff(t_pf_env *env, char *str, int n);
void				pf_char_buff(t_pf_env *env, char c);
char				*pf_itoa_base(unsigned long long nbr, int base);
ssize_t				itoa_len(unsigned long long nbr, int focus);
char				*pf_ftoa(long double nbr, int focus);

#endif
