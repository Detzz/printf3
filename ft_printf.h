/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:31:27 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/30 14:00:22 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
#include <stdio.h>

int g_count;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
int				ft_atoi( char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *str);
char			*ft_itoa(int nbr);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
int     ft_printf(const char *fmt, ...);
void	ft_putstrrev_fd(char *s, int fd);
void        hexa(int n);
void        ft_hexa2(size_t n);
void        pointer(void *n);
int 		ft_strlen2(char *str);
char	*ft_strdup1(const char *s1, int i);
char	*ft_strcpy2(char *dest, const char *src, int i);
void ft_pp(char *l, int p, char c);
void ft_pp1(int n, int p);
void ft_pp2(int p, int n, char *l);
void ft_pp3(int p, int n, char *l, int d);
void ft_moinsetoilepoint(va_list ap);
void ft_moinsetoilepluspoint( char *j,char *o, va_list ap);
void ft_etoile(va_list ap);
void ft_etoile_point(va_list ap, int p, char *j, char *o);
void ft_etoile_point_else(va_list ap, int p);
char  *ft_searching_point(char *j);
int  ft_number_ando(char *j, int n, va_list ap, int p);
void etoile1(va_list ap, char *j, char *o);
void zeroetoilepoint(char *j,char *o, va_list ap);
void  numberpointnumber( char *o, int p, va_list ap);
void numberpointetoile( int p,va_list ap);
void numberpointnumberelse(va_list ap, int p);
void ft_nopointnozero(char *j,char *o, va_list ap);
void ft_ppchar( int p, char c);
void ft_ifegalec(char *j, va_list ap);
void ft_moinsetoilepointstring(va_list ap);
void ft_pp3string(int p, int n , char *l);
void ft_moinsetoilepluspointstring(char *j,char *o, va_list ap);
void ft_etoilestring(va_list ap);
void etoile1string(va_list ap, char *j, char *o);
void ft_etoile_pointstring(va_list ap, int p, char *j, char *o);
void ft_etoile_point_elsestring(va_list ap, int p);
void zeroetoilepointstring(char *j,char *o, va_list ap);
int ft_number_andostring(int n, va_list ap);
void ft_nopointnozerostring(char *j,char *o, va_list ap);
void  numberpointnumberstring( char *o, int p, va_list ap);
void numberpointetoilestring( int p,va_list ap);
void numberpointnumberelsestring(va_list ap, int p);
void ft_pp6(int p, int n);
char  *decToHexa(int n) ;
void ft_pp3hexa(int p, char *l, int n,int d);
void ft_nopointnozerohexa1(char *j,char *o, va_list ap);
void numberpointnumberelsehexa1(va_list ap, int p);
void numberpointetoilehexa1( int p,va_list ap);
void  numberpointnumberhexa1( char *o, int p, va_list ap);
void zeroetoilepointhexa1(char *j,char *o, va_list ap);
void etoile1hexa1(va_list ap, char *j, char *o);
int ft_number_andohexa1(char *j, int n, va_list ap, int p);
char  *ft_searching_pointhexa1(char *j);
void ft_etoile_point_elsehexa1(va_list ap, int p);
void ft_etoile_pointhexa1(va_list ap, int p, char *j, char *o);
void ft_etoilehexa1(va_list ap);
void ft_moinsetoilepluspointhexa1( char *j,char *o, va_list ap);
void ft_moinsetoilepointhexa1(va_list ap);
void ft_moinsetoilepointhexa2(va_list ap);
void ft_moinsetoilepluspointhexa2( char *j,char *o, va_list ap);
void ft_etoilehexa2(va_list ap);
void ft_etoile_pointhexa2(va_list ap, int p, char *j, char *o);
void ft_etoile_point_elsehexa2(va_list ap, int p);
char  *ft_searching_pointhexa2(char *j);
int ft_number_andohexa2(char *j, int n, va_list ap, int p);
void etoile1hexa2(va_list ap, char *j, char *o);
void zeroetoilepointhexa2(char *j,char *o, va_list ap);
void  numberpointnumberhexa2( char *o, int p, va_list ap);
void numberpointetoilehexa2( int p,va_list ap);
void numberpointnumberelsehexa2(va_list ap, int p);
void ft_nopointnozerohexa2(char *j,char *o, va_list ap);
void ft_pp3hexa2(int p, int n , char *l, int d);	
void        hexapointer(size_t n);
void ft_moinsetoilepointpoint(va_list ap);
void ft_moinsetoilepluspointpoint( char *j,char *o, va_list ap);
void ft_etoilepoint(va_list ap);
void ft_etoile_pointpoint(va_list ap, int p, char *j, char *o);
void ft_etoile_point_elsepoint(va_list ap, int p);
char  *ft_searching_pointpoint(char *j);
int ft_number_andopoint(char *j, int n, va_list ap, int p);
void etoile1point(va_list ap, char *j, char *o);
void zeroetoilepointpoint(char *j,char *o, va_list ap);
void  numberpointnumberpoint( char *o, int p, va_list ap);
void numberpointetoilepoint( int p,va_list ap);
void numberpointnumberelsepoint(va_list ap, int p);
void ft_nopointnozeropoint(char *j,char *o, va_list ap);
char  *poinToHexa(size_t n) ;
void ft_pp3point(int p, int n , char *l, void  *d);
void ft_ifegalepourcentage(char *j, va_list ap);
void ft_moinsetoilepointun(va_list ap);
void ft_moinsetoilepluspointun( char *j,char *o, va_list ap);
void ft_etoileun(va_list ap);
void ft_etoile_pointun(va_list ap, int p, char *j, char *o);
void ft_etoile_point_elseun(va_list ap, int p);
int ft_number_andoun(char *j, int n, va_list ap, int p);
void etoile1un(va_list ap, char *j, char *o);
void zeroetoilepointun(char *j,char *o, va_list ap);
void  numberpointnumberun( char *o, int p, va_list ap);
void numberpointetoileun( int p,va_list ap);
void numberpointnumberelseun(va_list ap, int p);
void ft_nopointnozeroun(char *j,char *o, va_list ap);
void if_s(va_list ap, char *j,char *o);
void if_c(va_list ap, char *j);
void if_u(va_list ap, char *j, char *o);
void if_d(va_list ap, char *j, char *o);
void if_x(va_list ap, char *j, char *o);
void if_X(va_list ap, char *j, char *o);
void if_p(va_list ap,char *j,char *o);
void if_po(char *j, va_list ap);









#endif
