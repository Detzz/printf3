#include "ft_printf.h"
void if_s(va_list ap, char *j,char *o)
{
    char *s;
    int n;
	char * temp;

		if (j[0] == '\0')
			{
				s = va_arg(ap,char *);
				if (s == NULL)
					ft_putstr_fd("(null)",1);
				else
				ft_putstr_fd(s,1);
			}
			else
			{	
				while (1)
				{
			if(j[0] == '.' || j[0] == '0')
			{
				temp = o;
				o = ft_strdup1(j, 1);
				free(temp);
				break;
			}
			n = ft_atoi(o);
			if (j[0] == '-' && j[1] == '*' && j[2] != '.')
			{
				ft_moinsetoilepointstring( ap);
				break;
			}
			if(j[0] == '-' && j[1] == '*' && j[2] == '.')
			{
				ft_moinsetoilepluspointstring(j,o , ap);
				break;
			}
			if (j[0] == '*' && j[1] != '.')
			{
				ft_etoilestring( ap);
				break;
			}
			if (j[0] == '*' && j[1] == '.')
				{
									etoile1string(ap, j, o);
									break;
									}
			if (j[0] == '.' || (j[0] == '-' && j[1] == '*') || (j[0] == '-' && j[1] == '.'))                                                                  
					{
					zeroetoilepointstring(j,o,ap);
					break;
					}
			if (j[0] != '0' && j[0] != '.')
			{
				ft_nopointnozerostring(j,o, ap);
				break;
			}
				}
			}
}
void if_c(va_list ap, char *j)
{
    int d;

    if (j[0] == '\0')
			{
				d = va_arg(ap, int);
				ft_putchar_fd(d,1);
			}
			else
			ft_ifegalec(j,ap);
}
void if_u(va_list ap, char *j, char *o)
{
    unsigned int t;
    int n;
         if (j[0] == '\0')
			{
				t = va_arg(ap, unsigned int);
				ft_putnbr_fd1(t,1);
			}
			else
			{
			if(j[0] == '.' || j[0] == '0')
				o = ft_strdup1(j, 1);
			n = ft_atoi(o);
			if (j[0] == '-' && j[1] == '*' && j[2] != '.')
				ft_moinsetoilepointun( ap);
			if(j[0] == '-' && j[1] == '*' && j[2] == '.')
				ft_moinsetoilepluspointun( j,o , ap);
			if (j[0] == '*' && j[1] != '.')
				ft_etoileun( ap);
			if (j[0] == '*' && j[1] == '.')
				etoile1un(ap, j, o);
			if (j[0] == '0' || j[0] == '.')
				/*iuf (j[0] == '.' && d == 0)
					break;*/                          
				if ((j[0] >= 48 && j[0] <= 57) || j[0] == '.' || j[0] == '+' )                                                               
					zeroetoilepointun(j,o,ap);

			if (j[0] != '0' && j[0] != '.')

				ft_nopointnozeroun(j,o, ap);
			}
}
void if_d(va_list ap, char *j, char *o)
{
    int d;
    int n;
    if (j[0] == '\0')
			{
				d = va_arg(ap, int);
				ft_putnbr_fd(d,1);
			}
			else
			{
				while (1)
				{
			if(j[0] == '.' || j[0] == '0')
			{
				o = ft_strdup1(j, 1);
			}
			n = ft_atoi(o);
			if (j[0] == '-' && j[1] == '*' && j[2] != '.')
			{
				ft_moinsetoilepoint( ap);
				break;
			}
			if(j[0] == '-' && j[1] == '*' && j[2] == '.')
			{
				ft_moinsetoilepluspoint( j,o , ap);
				break;
			}
			if (j[0] == '*' && j[1] != '.')
			{
				ft_etoile( ap);
				break;
			}
			if (j[0] == '*' && j[1] == '.')
			{
				etoile1(ap, j, o);
				break;
			}
			if (j[0] == '0' || j[0] == '.')
			{
				
				 if ((j[0] >= 48 && j[0] <= 57) || j[0] == '.' || j[0] == '+' )                                                               
					zeroetoilepoint(j,o,ap);
				break;
			}

			if (j[0] != '0' && j[0] != '.')
			{
				ft_nopointnozero(j,o, ap);
				break;
			}
			}
}
}
void if_x(va_list ap, char *j, char *o)
{
    unsigned int d;
    int n;
    if (j[0] == '\0')
			{
				d = va_arg(ap, unsigned int);
				hexa(d);
			}
			else
			{
			if(j[0] == '.' || j[0] == '0')
				o = ft_strdup1(j, 1);
			n = ft_atoi(o);
			if (j[0] == '-' && j[1] == '*' && j[2] != '.')
				ft_moinsetoilepointhexa1( ap);
			if(j[0] == '-' && j[1] == '*' && j[2] == '.')
				ft_moinsetoilepluspointhexa1( j,o , ap);
			if (j[0] == '*' && j[1] != '.')
				ft_etoilehexa1( ap);
			if (j[0] == '*' && j[1] == '.')
				etoile1hexa1(ap, j, o);
			if (j[0] == '0' || j[0] == '.')
				/*if (j[0] == '.' && d == 0)
					break;*/                          
				if ((j[0] >= 48 && j[0] <= 57) || j[0] == '.' || j[0] == '+' )                                                               
					zeroetoilepointhexa1(j,o,ap);
			if (j[0] != '0' && j[0] != '.')
				ft_nopointnozerohexa1(j,o, ap);
				}
}
void if_X(va_list ap, char *j, char *o)
{
    int d;
    int n;
    if (j[0] == '\0')
			{
				d = va_arg(ap, int);
				ft_hexa2(d);
			}
			else
			{
			if(j[0] == '.' || j[0] == '0')
				o = ft_strdup1(j, 1);
			n = ft_atoi(o);
			if (j[0] == '-' && j[1] == '*' && j[2] != '.')
				ft_moinsetoilepointhexa2( ap);
			if(j[0] == '-' && j[1] == '*' && j[2] == '.')
				ft_moinsetoilepluspointhexa2( j,o , ap);
			if (j[0] == '*' && j[1] != '.')
				ft_etoilehexa2( ap);
			if (j[0] == '*' && j[1] == '.')
				etoile1hexa2(ap, j, o);

			if (j[0] == '0' || j[0] == '.')
				/*if ((j[0] == '.' && d == 0) || (j[1] == '.' && d == 0))
					break;*/                          
				if ((j[0] >= 48 && j[0] <= 57) || j[0] == '.' || j[0] == '+' )                                                              
					zeroetoilepointhexa2(j,o,ap);

			if (j[0] != '0' && j[0] != '.')
				ft_nopointnozerohexa2(j,o, ap);

		}
}
void if_p(va_list ap,char *j,char *o)
{
    
        void *p;
        int n;
		if (j[0] == '\0')
			{
				p = va_arg(ap, void *);
				pointer(p);
			}
			else
			{
		
			if(j[0] == '.' || j[0] == '0')
				o = ft_strdup1(j, 1);
			n = ft_atoi(o);
			if (j[0] == '-' && j[1] == '*' && j[2] != '.')
				ft_moinsetoilepointpoint( ap);
			if(j[0] == '-' && j[1] == '*' && j[2] == '.')
				ft_moinsetoilepluspointpoint(  j,o , ap);
			if (j[0] == '*' && j[1] != '.')
				ft_etoilepoint( ap);
			if (j[0] == '*' && j[1] == '.')
				etoile1point(ap, j, o);
			if (j[0] == '0' || j[0] == '.')
			/*if (j[0] == '.' && d == 0)
					break;*/                          
				if ((j[0] >= 48 && j[0] <= 57) || j[0] == '.' || j[0] == '+' )                                                            
					zeroetoilepointpoint(j,o,ap);
			if (j[0] != '0' && j[0] != '.')
				ft_nopointnozeropoint(j,o, ap);
			}
}
void if_po(char *j, va_list ap)
{
    if (j[0] == '\0')
				ft_putchar_fd('%',1);
			else
			 ft_ifegalepourcentage(j,ap);
}

void	ft_putnbr_fd1(unsigned int n, int fd)
{
	unsigned int	nouvar;

	nouvar = n;

	if (nouvar <= 9)
	{
		ft_putchar_fd(nouvar + 48, fd);
	}
	if (nouvar > 9)
	{
		ft_putnbr_fd(nouvar / 10, fd);
		ft_putchar_fd(nouvar % 10 + 48, fd);
	}
}