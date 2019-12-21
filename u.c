#include "ft_printf.h"
void ft_moinsetoilepointun(va_list ap)
{
	int p;
	unsigned int d;
	char *l;

	p = va_arg(ap , int);
	d = va_arg(ap , unsigned int);
	l = ft_itoa(d);
	ft_putnbr_fd(d,1);
	ft_pp(l,p, ' ');
}
void ft_moinsetoilepluspointun( char *j,char *o, va_list ap)
{
	unsigned int d;
	char *l;
	int p;
	int n;

	d = 0;
	n = 0;
	p = va_arg(ap , int);
	while (j[d] != '\0')
	{
		if (j[d] == '.')
		{
			if(j[++d] != '\0')
				o = ft_strdup1(j, d);
			else 
			d--;
		}
		d++;
	}
	if (j[3] == '*')
		n = va_arg(ap , int);
	else 
		n = ft_atoi(o);
	d = va_arg(ap , unsigned int);
	l = ft_itoa(d);
	ft_pp3(p,  n, l, d);
	//ft_putnbr_fd(d,1);
}
void ft_etoileun(va_list ap)
{
	int p;
	unsigned int d;
	char *l;

	p = va_arg(ap , int);
	d = va_arg(ap , unsigned int);
	l = ft_itoa(d);
	ft_pp(l,p, ' ');
	ft_putnbr_fd(d,1);
}
void ft_etoile_pointun(va_list ap, int p, char *j, char *o)
{
	char *l;
	int r;
	unsigned int d;
	int n;

	r = 0;
	while (j[r] != '\0')
	{
		if (j[r] == '.')
		{
			if(j[++r] != '\0')
				o = ft_strdup1(j, r);
				else 
				r--;
		}
		r++;
	}
	if (j[2] == '*')
		n = va_arg(ap , int);
	if(o[0] >= 48 && o[0] <= 57)
		n = ft_atoi(o);
	d = va_arg(ap , unsigned int);
	l = ft_itoa(d);
	if (p > n)
	{
		ft_pp1(p, n);
		ft_pp(l,n, '0');          
	}
	else 
		ft_pp(l,n, '0');
	ft_putnbr_fd(d,1);			
}
void ft_etoile_point_elseun(va_list ap, int p)
{
	unsigned int d;
	char *l;

	d = va_arg(ap , unsigned int);
	l = ft_itoa(d);
	ft_pp(l,p, ' ');     
	ft_putnbr_fd(d,1);

}

int ft_number_andoun(char *j, int n, va_list ap, int p)
{
	unsigned int d;
	char *l;

	if (p < 0 && j[0] == '0')
	{
		d= va_arg(ap ,unsigned int);
		/*if (d < 0)
		{
			ft_putchar_fd('-',1);
			n = n - 1;
			d = -d;
		}*/
		l = ft_itoa(d);
		ft_pp(l,n, '0');
		ft_putnbr_fd(d, 1);
		return(1);
	}
	else 
	{
		
		d= va_arg(ap ,unsigned int);
		/*if (d < 0)
		{
			ft_putchar_fd('-',1);
			n = n - 1;
			d = -d;
		}*/
		l = ft_itoa(d);
		if (p > n)
		{
			ft_pp(l,p, '0');
			ft_putnbr_fd(d,1);
			return(1);
		}
		else
		{
			ft_pp(l, p,'0');
			ft_pp(l,n, '0');
			ft_putnbr_fd(d,1);
		}
		return(1);
	}
	return(0);
}

void etoile1un(va_list ap, char *j, char *o)
{
	int p;

	p = va_arg(ap , int);
	if (j[2] != '\0') 
		ft_etoile_point(ap,  p, j, o);	
	else
		ft_etoile_point_else(ap,  p);
}

void zeroetoilepointun(char *j,char *o, va_list ap)
{
	int n;
	int p;
	int r;

	r = 0;
	n = ft_atoi(o);
	if (j[1] == '*')
		n = va_arg(ap, int);
	r = 0;
	o = ft_searching_point(j);
	if (o[0] >= 48 && o[0] <= 57)
		p = ft_atoi(o);
	if (o[0] == '*')
		p = va_arg(ap, int);
	ft_number_ando(j,  n, ap,  p);

}

void  numberpointnumberun( char *o, int p, va_list ap)
{
	int n;
	unsigned int d;
	char *l;
	if (p < 0)
	{
		p = -p;
		d= va_arg(ap ,unsigned int);
		l = ft_itoa(d);
		n = ft_atoi(o);
		ft_pp(l,n, '0');
		ft_putnbr_fd(d, 1);
		ft_pp6( p, n);


	}
	else
	{
		d= va_arg(ap ,unsigned int);
	l = ft_itoa(d);
	n = ft_atoi(o);
	ft_pp6( p, n);
	ft_pp(l,n, '0');
	ft_putnbr_fd(d, 1);
	}
	
	
}
void numberpointetoileun( int p,va_list ap)
{
	int n;
	unsigned int d;
	char *l;

	n = va_arg(ap ,int);
	d= va_arg(ap ,unsigned int);
	l = ft_itoa(d);
	if ( n > 0)
	{	
		ft_pp2( p,  n, l);
		ft_pp(l,n, '0');
		ft_putnbr_fd(d, 1);
	}
	else if (n < 0)
	{
		ft_putnbr_fd(d, 1);
		n = -n;
		ft_pp(l,n, ' ');
	}					
}
void numberpointnumberelseun(va_list ap, int p)
{
	unsigned int d;
	char *l;
	if (p > 0)
	{
		d= va_arg(ap ,unsigned int);
		l = ft_itoa(d);
		ft_pp(l,p, ' ');
		ft_putnbr_fd(d, 1);
	}
	else if (p < 0)
	{
		d= va_arg(ap ,unsigned int);
		l = ft_itoa(d);
		ft_putnbr_fd(d, 1);
		p = -p;
		ft_pp(l,p, ' ');
	}
}

void ft_nopointnozeroun(char *j,char *o, va_list ap)
{
    int r;
    int p;

    p = ft_atoi(j);
				r = 0;
				o = ft_searching_point(j);

				if ((j[0] >= 48 && j[0] <= 57) || (j[0] == '-' && (j[1] >= 48 && j[1] <= 57)))
				{
					if ((o[0] >= 48 && o[0] <= 57))
						numberpointnumberun(o, p, ap);
					else if(o[0] == '*')
						numberpointetoileun(p, ap);
					else
						
						numberpointnumberelseun(ap, p);
				}
}
