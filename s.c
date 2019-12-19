#include "ft_printf.h"

void ft_moinsetoilepointstring(va_list ap)
{
	int p;
	char *d;
	
	p = va_arg(ap , int);
    if (p < 0)
     p = -p;
	d = va_arg(ap , char*);
	ft_putstr_fd(d,1);
	ft_pp(d,p, ' ');
}
void ft_pp3string(int p, int n , char *l)
{
	int r;
    int i;

    i = 0;
	if (p > n)
	{
		r = n;
		while (r > 0)
        {
            ft_putchar_fd(l[i],1);
            i++;
            r--;
        }
		ft_pp1(p, n);
	}
	else
		{
            while (n > 0)
			{
            ft_putchar_fd(l[i],1);
            i++;
            n--;
			}
        }
}
void ft_moinsetoilepluspointstring(char *j,char *o, va_list ap)
{
	char *d;
	int r;
	int p;
	int n;

	r = 0;
	n = 0;
	p = va_arg(ap , int);
	if (p < 0)
	p = -p;
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
	if (j[3] == '*')
		n = va_arg(ap , int);
	else 
		n = ft_atoi(o);
	d = va_arg(ap , char *);
	if (n < 0)
	n = ft_strlen2(d);
	
	ft_pp3string(p,  n, d);
	//llft_putstr_fd(d,1);
}
void ft_etoilestring(va_list ap)
{
	int p;
	char *d;
	
	p = va_arg(ap , int);
    d = va_arg(ap , char *);
    if (p < 0)
    {
        p = -p;
        ft_putstr_fd(d,1);
        	ft_pp(d,p, ' ');
    }
    else 
    {
        ft_pp(d,p, ' ');
	ft_putstr_fd(d,1);
    }
}

void etoile1string(va_list ap, char *j, char *o)
{
	int p;

	p = va_arg(ap , int);
	//if (p < 0)
	//p = -p;
	if (j[2] != '\0') 
		ft_etoile_pointstring(ap,  p, j, o);	
	else
		ft_etoile_point_elsestring(ap,  p);
}
void ft_etoile_pointstring(va_list ap, int p, char *j, char *o)
{
	int r;
	char  *d;
	int n;
    int i;
	char *temp;

	r = 0;
    i = 0;
	while (j[r] != '\0')
	{
		if (j[r] == '.')
		{
			if(j[++r] != '\0')
			{
				temp = o;
				o = ft_strdup1(j, r);
				free (temp);
			}
			else 
			r--;
		}
		r++;
	}
	if (j[2] == '*')
		n = va_arg(ap , int);
	if(o[0] >= 48 && o[0] <= 57)
		n = ft_atoi(o);
	d = va_arg(ap , char *);
	if (n < 0)
	n = ft_strlen2(d);
	if (n > p && p > 0)
		ft_pp6(p, ft_strlen2(d));
	else if (p > n)
		ft_pp6(p, n);
	else if (n == p && (n > ft_strlen2(d)))
			ft_pp6( p, ft_strlen2(d));
			r = n;
            while (n > 0 && d[i] != '\0')
        {
            ft_putchar_fd(d[i],1);
            i++;
            n--;
        }
	if (p < 0)
	{
		p = -p;
		ft_pp6(p, r);
	}	
}
void ft_etoile_point_elsestring(va_list ap, int p)
{
	char *d;

	d = va_arg(ap , char *);
	ft_pp(d,p, ' ');     
	ft_putstr_fd(d,1);

}
void zeroetoilepointstring(char *j,char *o, va_list ap)
{
	int n;
	int r;

	r = 0;
	while (j[r] != '\0')
	{
		if (j[r] == '.')
		{
			if(j[++r] != '\0')
				o = ft_strdup1(j, r);
			else
			{
				r--;
			}
			
		}
		r++;
	}
	n = ft_atoi(o);
	if (o[0] == '*')
		n = va_arg(ap, int);
	r = 0;
	ft_number_andostring(n, ap);

}
int ft_number_andostring(int n, va_list ap)
{
	char *d;
    int i;

    i = 0;
			d= va_arg(ap ,char *);

    if (n < 0)
	{
		 while (d[i] != '\0')
        {
            ft_putchar_fd(d[i],1);
            i++;
        }
	}
			  else
			  while (n > 0 && d[i] != '\0')
        {
            ft_putchar_fd(d[i],1);
            i++;
            n--;
        }
        /*while (n > 0)
        {
            ft_putchar_fd(' ',1);
            n--;
        }*/
			return(1);
		
	}

void ft_nopointnozerostring(char *j,char *o, va_list ap)
{
    int r;
    int p;

                p = ft_atoi(j);
				r = 0;
				o = ft_searching_point(j);

				if ((j[0] >= 48 && j[0] <= 57) || (j[0] == '-' && (j[1] >= 48 && j[1] <= 57)))
				{
					if ((o[0] >= 48 && o[0] <= 57))
						numberpointnumberstring(o, p, ap);
					else if(o[0] == '*')
						numberpointetoilestring(p, ap);
					else
						numberpointnumberelsestring(ap, p);
				}
}
void  numberpointnumberstring( char *o, int p, va_list ap)
{
	int n;
	char *d;
    int i;

	i = 0;
    if (p < 0)
		p = -p;
	d= va_arg(ap ,char *);
	n = ft_atoi(o);
	if (n > p)
		ft_pp6( p, ft_strlen2(d));
	else if (n < p) 
		ft_pp6( p, n);
	else if (n == p && (n > ft_strlen2(d)))
			ft_pp6( p, ft_strlen2(d));
	while (n > 0 && d[i] != '\0')
        {
            ft_putchar_fd(d[i],1);
            i++;
            n--;
        }
}
void numberpointetoilestring( int p,va_list ap)
{
	int n;
    char *d;
    int i;

	i = 0;
    n = va_arg(ap ,int);
	d= va_arg(ap ,char *);
	if ( n > 0)
	{	
		ft_pp6( p,  n);
		while (n > 0 && d[i] != '\0')
        {
            ft_putchar_fd(d[i],1);
            i++;
            n--;
        }
	}
	else if (n < 0)
	{
		ft_putstr_fd(d, 1);
		n = -n;
		ft_pp(d,n, ' ');
	}					
}
void numberpointnumberelsestring(va_list ap, int p)
{
	char *d;
	if (p > 0)
	{
		d= va_arg(ap ,char *);
        ft_pp(d,p, ' ');
		ft_putstr_fd(d, 1);
	}
	else if (p < 0)
	{
		d= va_arg(ap ,char *);
		ft_putstr_fd(d, 1);
		p = -p;
		ft_pp(d,p, ' ');
	}
}