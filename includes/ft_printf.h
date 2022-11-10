/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:13:37 by itan              #+#    #+#             */
/*   Updated: 2022/10/28 04:56:42 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flagdata
{
	unsigned char	space;
	unsigned char	sign;
	unsigned char	prefix;
	int				head;
	int				zerof;
	int				tail;
	int				preci;
}					t_flagdata;

int					ft_printf(const char *s, ...);

/* -------------------------------- formating ------------------------------- */
char				*ft_formating(char *s, va_list args, int *size);
void				ft_flagdata_init(t_flagdata *data);

/* --------------------------------- handle --------------------------------- */
size_t				ft_h_char(va_list args, t_flagdata *data);
size_t				ft_h_hex(char *check, va_list args, t_flagdata *data);
size_t				ft_h_int(va_list args, t_flagdata *data);
size_t				ft_h_nosym(char *s, char *check);
size_t				ft_h_percent(void);
size_t				ft_h_str(va_list args, t_flagdata *data);
size_t				ft_h_uint(va_list args, t_flagdata *data);
size_t				ft_h_void(va_list args, t_flagdata *data);

/* --------------------------------- prints --------------------------------- */
size_t				ft_printchrs(char c, int size);
size_t				hexlen(unsigned long n);
size_t				ft_printhex(unsigned long n, unsigned char cap);
size_t				numsize(int n);
size_t				ft_printint(int n);
size_t				ft_printstr(char *s);
size_t				unintsize(unsigned int n);
size_t				ft_printuint(unsigned int n);
#endif