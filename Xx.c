#include "ft_printf.h"

void ft_moinsetoilepointhexa2(va_list ap)
{
	int p;
	unsigned int d;
	char *l;

	p = va_arg(ap , int);
	d = va_arg(ap , unsigned int);
	l = decToHexa(d);
	ft_hexa2(d);
	ft_pp(l,p, ' ');
}
void ft_moinsetoilepluspointhexa2( char *j,char *o, va_list ap)
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
				{
					d--;
				}
				
		}
		d++;
	}
	if (j[3] == '*')
		n = va_arg(ap , int);
	else if (o[0] >= 48 && o[0] <= 57)
		n = ft_atoi(o);
	d = va_arg(ap , unsigned int);
	l = decToHexa(d);
	ft_pp3hexa(p, l, n,d);
	//hexa(d);
}
void ft_etoilehexa2(va_list ap)
{
	int p;
	unsigned int d;
	char *l;

	p = va_arg(ap , int);
	d = va_arg(ap , unsigned int);
	l = decToHexa(d);
	ft_pp(l,p, ' ');
ft_hexa2(d);
}
void ft_etoile_pointhexa2(va_list ap, int p, char *j, char *o)
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
	l = decToHexa(d);
	if (p > n)
	{
		ft_pp1(p, n);
		ft_pp(l,n, '0');          
	}
	else 
		ft_pp(l,n, '0');
ft_hexa2(d);}
void ft_etoile_point_elsehexa2(va_list ap, int p)
{
	unsigned int d;
	char *l;

	d = va_arg(ap , unsigned int);
	l = decToHexa(d);
	ft_pp(l,p, ' ');     
ft_hexa2(d);
}
char  *ft_searching_pointhexa2(char *j)
{
	int r;
	char *dst;

	dst = ft_strdup("\0");
	r = 0;
	while (j[r] != '\0')
	{
		if (j[r] == '.')
		{
			if(j[++r] != '\0')
				dst = ft_strdup1(j, r);
			else
				r--;
		}
		r++;
	}
	return(dst);
}
int ft_number_andohexa2(char *j, int n, va_list ap, int p)
{
	unsigned int d;
	char *l;

	if (p < 0 && j[0] == '0')
	{
		d= va_arg(ap ,unsigned int);
		l = decToHexa(d);
		ft_pp(l,n, '0');
	ft_hexa2(d);
		return(1);
	}
	else 
	{
		d= va_arg(ap ,unsigned int);
		l = decToHexa(d);
		if (p > n)
		{
			ft_pp(l,p, '0');
	ft_hexa2(d);
			return(1);
		}
		else
		{
			ft_pp1(n, p);
			ft_pp(l,p, ' ');
	ft_hexa2(d);
		}
		return(1);
	}
	return(0);
}

void etoile1hexa2(va_list ap, char *j, char *o)
{
	int p;

	p = va_arg(ap , int);
	if (j[2] != '\0') 
		ft_etoile_pointhexa2(ap,  p, j, o);	
	else
		ft_etoile_point_elsehexa2(ap,  p);
}

void zeroetoilepointhexa2(char *j,char *o, va_list ap)
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
	ft_number_andohexa2(j,  n, ap,  p);

}

void  numberpointnumberhexa2( char *o, int p, va_list ap)
{
	int n;
	unsigned int d;
	char *l;
	if (p < 0)
	{
		p = -p;
	d= va_arg(ap ,unsigned int);
	l = decToHexa(d);
	n = ft_atoi(o);
	ft_pp(l,n, '0');
	ft_hexa2(d);
	ft_pp2( p, n, l);
	}
	else
	{
		d= va_arg(ap ,unsigned int);
	l = decToHexa(d);
	n = ft_atoi(o);
	ft_pp2( p, n, l);
	ft_pp(l,n, '0');
	ft_hexa2(d);
	}
	
	
}
void numberpointetoilehexa2( int p,va_list ap)
{
	int n;
	unsigned int d;
	char *l;

	n = va_arg(ap ,unsigned int);
	d= va_arg(ap ,unsigned int);
	l = decToHexa(d);
	if ( n > 0)
	{	
		ft_pp2( p,  n, l);
		ft_pp(l,n, '0');
	ft_hexa2(d);
	}
	else if (n < 0)
	{
	ft_hexa2(d);
		n = -n;
		ft_pp(l,n, ' ');
	}					
}
void numberpointnumberelsehexa2(va_list ap, int p)
{
	unsigned int d;
	char *l;
	if (p > 0)
	{
		d= va_arg(ap ,unsigned int);
		l = decToHexa(d);
		ft_pp(l,p, ' ');
ft_hexa2(d);	}
	else if (p < 0)
	{
		d= va_arg(ap ,unsigned int);
		l = decToHexa(d);
	ft_hexa2(d);
		p = -p;
		ft_pp(l,p, ' ');
	}
}

void ft_nopointnozerohexa2(char *j,char *o, va_list ap)
{
    int r;
    int p;

    p = ft_atoi(j);
				r = 0;
				o = ft_searching_point(j);

				if ((j[0] >= 48 && j[0] <= 57) || (j[0] == '-' && (j[1] >= 48 && j[1] <= 57)))
				{
					if ((o[0] >= 48 && o[0] <= 57))
						numberpointnumberhexa2( o, p, ap);
					else if(o[0] == '*')
						numberpointetoilehexa2(p, ap);
					else
						
						numberpointnumberelsehexa2(ap, p);
				}
}

void ft_pp3hexa2(int p, int n , char *l, int d)
{
	int r;
	if ( p < 0)
	p = -p;
	if (p > n)
	{
		r = n;
		ft_pp(l,r, '0');
		ft_hexa2(d);
		ft_pp1(p, n);
	}
	else
	{
		ft_pp(l,n, '0');
		ft_hexa2(d);
	}
}