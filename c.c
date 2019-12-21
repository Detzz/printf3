#include "ft_printf.h"

void ft_ifegalec(char *j, va_list ap)
{
    int p;
    char c;

    if (j[0] == '*' || (j[0] == '-' && j[1] =='*'))
				p = va_arg(ap, int);
			else	
				p = ft_atoi(j);
			if (p > 0 && j[0] != '-')
			{
				c = va_arg(ap , int);
				ft_ppchar(p, ' ');
				ft_putchar_fd(c,1);
			}
			else if (p < 0 || j[0] == '-')
			{
				c = va_arg(ap , int);
				ft_putchar_fd(c,1);
				if(p < 0)
					p = -p;
				ft_ppchar(p, ' ');
			}
}
void ft_ifegalepourcentage(char *j, va_list ap)
{
    int p;
	int n;	

    if (j[0] == '*' || (j[0] == '-' && j[1] =='*') || (j[0] == '0' && j[1] =='*') ||(j[0] == '-' && j[1] =='0' && j[2] == '*'))
				p = va_arg(ap, int);
			else	
				p = ft_atoi(j);
			if ( p == 0)
			{
				ft_putchar_fd('%',1);
			}
			if (p > 0 && (j[0] == '-' && j[1] == '0')) 
			{
				ft_putchar_fd('%',1);
				ft_ppchar(p, ' ');
				
			}
			if (p > 0 && (j[0] != '-' && j[0] != '0')) 
			{
				ft_ppchar(p, ' ');
				ft_putchar_fd('%',1);
			}
			else if ((p < 0 && j[0] != '0')|| (j[0] == '-' && j[1] != '0'))
			{
				ft_putchar_fd('%',1);
				n = -p;
				if(p < 0)
					n = -p;
				ft_ppchar(n, ' ');
			}
			if (p > 0  && j[0] == '0')
			{
				ft_ppchar(p, '0');
				ft_putchar_fd('%',1);
			}
			else if (p < 0 && j[0] == '0') 
			{
				ft_putchar_fd('%',1);
				if(p < 0)
					p = -p;
				ft_ppchar(p, ' ');
			}
}

