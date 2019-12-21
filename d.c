#include "ft_printf.h"

void ft_ppchar( int p, char c)
{
	while( 1 < p)
	{
		ft_putchar_fd(c, 1);
		p--;
	}
}

void ft_pp(char *l, int p, char c)
{   
	while( ft_strlen2(l) < p)
	{
		ft_putchar_fd(c, 1);
		p--;
	}
}
void ft_pp1(int n, int p)
{
	while (p < n) 
	{
		ft_putchar_fd(' ',1);
		n--;
	}
}
void ft_pp6(int p, int n)
{
	while (p > n )
	{
		ft_putchar_fd(' ',1);
		p--;
	}
}
void ft_pp2(int p, int n, char *l)
{
	while (p > n && p > ft_strlen2(l))
	{
		ft_putchar_fd(' ',1);
		p--;
	}
}
void ft_pp3(int p, int n , char *l, int d)
{
	int r;

	if ( p < n)
	p = -p;
	if (p > n)
	{
		r = n;
		ft_pp(l,r, '0');
		ft_putnbr_fd(d,1);
		ft_pp1(p, n);
	}
	else{
		ft_pp(l,n, '0');
				ft_putnbr_fd(d,1);
	}
}
void ft_moinsetoilepoint(va_list ap)
{
	int p;
	int d;
	char *l;

	p = va_arg(ap , int);
	d = va_arg(ap , int);
	l = ft_itoa(d);
	ft_putnbr_fd(d,1);
	ft_pp(l,p, ' ');
}
void ft_moinsetoilepluspoint( char *j,char *o, va_list ap)
{
	int d;
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
			if(j[d++] != '\0')
				o = ft_strdup1(j, d);
		}
		d++;
	}
	if (j[3] == '*')
		n = va_arg(ap , int);
	else 
		n = ft_atoi(o);
	d = va_arg(ap , int);
	l = ft_itoa(d);
	ft_pp3(p,  n, l, d);
	//ft_putnbr_fd(d,1);
}
void ft_etoile(va_list ap)
{
	int p;
	int d;
	char *l;

	p = va_arg(ap , int);
	d = va_arg(ap , int);
	l = ft_itoa(d);
	ft_pp(l,p, ' ');
	ft_putnbr_fd(d,1);
}
void ft_etoile_point(va_list ap, int p, char *j, char *o)
{
	char *l;
	int r;
	int d;
	int n;

	r = 0;
	while (j[r] != '\0')
	{
		if (j[r] == '.')
		{
			if(j[r++] != '\0')
				o = ft_strdup1(j, r);
		}
		r++;
	}
	if (j[2] == '*')
		n = va_arg(ap , int);
	if(o[0] >= 48 && o[0] <= 57)
		n = ft_atoi(o);
	d = va_arg(ap , int);
	l = ft_itoa(d);
	if (p > n)
	{
		if (n < 0)
		n = 0;
		ft_pp2(p, n, l);
		ft_pp(l,n, '0');   
		ft_putnbr_fd(d,1);    
	}
	else 
	{
	if (p == 0 && d == 0)
			ft_pp(l,n + 1 , '0');
	else
	{
	ft_pp(l,n  , '0');
	ft_putnbr_fd(d,1);
	}
	}
			
}
void ft_etoile_point_else(va_list ap, int p)
{
	int d;
	char *l;
d = va_arg(ap , int);
l = ft_itoa(d);
	if ( d== 0 && p == 0)
	{
		ft_pp(l,0, ' ');
	}
	else if ( d == 0 && p != 0)
	{
		if (p < 0)
		p = -p;
		ft_pp(l,p + 1, ' ');
	}
	else 
	{
		if ( p < 0)
		{
			p = -p;
			ft_putnbr_fd(d,1);
			ft_pp(l,p, ' '); 
		}
		else 
		{
	ft_pp(l,p, ' ');     
	ft_putnbr_fd(d,1);
		}
	}
}
char  *ft_searching_point(char *j)
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
				{
					r--;
				}
				
		}
		r++;
	}
	return(dst);
}
int ft_number_ando(char *j, int n, va_list ap, int p)
{
	int d;
	char *l;

		d= va_arg(ap ,int);
		if ((j[0] == '.' && d == 0) || (j[1] == '.' && d == 0 && j[0] != '*'))
					return(0);   
	else if  (p < 0 && j[0] == '0')
	{
		if (d < 0)
		{
			ft_putchar_fd('-',1);
			n = n - 1;
			d = -d;
		}
		l = ft_itoa(d);
		ft_pp(l,n, '0');
		ft_putnbr_fd(d, 1);
		return(1);
	}
	else 
	{
		
	
		if (d < 0)
		{
			ft_putchar_fd('-',1);
			n = n - 1;
			d = -d;
		}
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

void etoile1(va_list ap, char *j, char *o)
{
	int p;

	p = va_arg(ap , int);
	if (j[2] != '\0') 
		ft_etoile_point(ap,  p, j, o);	
	else
		ft_etoile_point_else(ap,  p);
}

void zeroetoilepoint(char *j,char *o, va_list ap)
{
	int n;
	int p;
	int r;
	char *l;

	r = 0;
	
	if (j[0] == '.' && j[1] == '*')
	{
			n = va_arg(ap, int);
			p= va_arg(ap ,int);
			l = ft_itoa(p);
			if (n < 0)
			ft_putnbr_fd(p,1);
			else
			{	
				if ( p < 0)
				{
					ft_putchar_fd('-',1);
					p = -p;
					ft_pp(l , n + 1, '0');

				}
				else
				{
					ft_pp(l , n , '0');
				
				}
				ft_putnbr_fd(p,1);
				
				
			}
	}
	else
	{
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
}

void  numberpointnumber( char *o, int p, va_list ap)
{
	int n;
	int d;
	char *l;
	if (p < 0)
	{
		p = -p;
		d= va_arg(ap ,int);
		l = ft_itoa(d);
		n = ft_atoi(o);
		if (n == 0 && d == 0)
	{
		ft_pp(l,n, '0');
		ft_pp2( p + 1, n, l);
	}
	else
	{
		ft_pp(l,n, '0');
		ft_putnbr_fd(d, 1);
		ft_pp6( p, n);

	}
	}
	else
	{
		d= va_arg(ap ,int);
	l = ft_itoa(d);
	n = ft_atoi(o);
	if (n == 0 && d == 0)
	{
		ft_pp2( p + 1, n, l);
		ft_pp(l,n, '0');
	}
	else
		{
		if (d < 0 )
		{
		d= -d;
		if ( p < n)
		{
		
		ft_pp2( p, n, l);
		ft_putchar_fd('-',1);
	ft_pp(l,n +1 , '0');
	ft_putnbr_fd(d, 1);
		}
		else 
		{
				ft_pp2( p, n +1, l);
				ft_putchar_fd('-',1);
	ft_pp(l,n +1 , '0');
	ft_putnbr_fd(d, 1);
		}
	}
	else if( d >= 0)
	{
		if ( p < n)
		{
		
		ft_pp2( p, n, l);
	ft_pp(l,n  , '0');
	ft_putnbr_fd(d, 1);
		}
		else 
		{
				ft_pp2( p, n , l);
	ft_pp(l,n  , '0');
	ft_putnbr_fd(d, 1);
		}
	}

	}
	
	
}
}
void numberpointetoile( int p,va_list ap)
{
	int n;
	int d;
	char *l;

	n = va_arg(ap ,int);
	d= va_arg(ap ,int);
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
void numberpointnumberelse(va_list ap, int p ,char *temp)
{
	int d;
	char *l;
	int i;

	i = 0;
	d= va_arg(ap ,int);
	l = ft_itoa(d);
	while (temp[i] != '\0')
	{
		i++;
	}
	if (temp[--i] == '.' && d == 0)
	{
		if (p < 0)
		p = -p;
		ft_pp(l,p + 1, ' ');
	}
	else if (p >= 0  )
	{
		ft_pp(l,p, ' ');
		ft_putnbr_fd(d, 1);
	}
	else if (p < 0 )
	{
		ft_putnbr_fd(d, 1);
		p = -p;
		ft_pp(l,p, ' ');
	}
}

void ft_nopointnozero(char *j,char *o, va_list ap)
{
    int r;
    int p;
	char *temp;

    p = ft_atoi(j);
				r = 0;
				temp = o;
				o = ft_searching_point(j);

				if ((j[0] >= 48 && j[0] <= 57) || (j[0] == '-' && (j[1] >= 48 && j[1] <= 57)))
				{
					if ((o[0] >= 48 && o[0] <= 57))
						numberpointnumber(o, p, ap);
					else if(o[0] == '*')
						numberpointetoile(p, ap);
					else
					{
						numberpointnumberelse(ap, p, j);
					}
						
						
				}
}
