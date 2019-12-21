#include "ft_printf.h"

void ft_moinsetoilepointpoint(va_list ap)
{
	int p;
	void *d;
	char *l;

	p = va_arg(ap , int);
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
			pointer(d);
	ft_pp(l,p, ' ');    
}
void ft_moinsetoilepluspointpoint( char *j,char *o, va_list ap)
{
void *d;
char *l;
	int p;
	int n;


	n = 0;
	p = va_arg(ap , int);
	while (j[n] != '\0')
	{
		if (j[n] == '.')
		{
			if(j[++n] != '\0')
				o = ft_strdup1(j, n);
			else 
			n--;
		}
		n++;
	}
	if (j[3] == '*')
		n = va_arg(ap , int);
	else 
		n = ft_atoi(o);
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
	ft_pp3point(p,  n, l, d);
	//hexa(d);
}
void ft_etoilepoint(va_list ap)
{
	int p;
void *d;
	char *l;

	p = va_arg(ap , int);
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
	ft_pp(l,p, ' ');
			pointer(d);
}
void ft_etoile_pointpoint(va_list ap, int p, char *j, char *o)
{
	char *l;
	int r;
void *d;
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
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
	if (p > n)
	{
		ft_pp1(p, n);
		ft_pp(l,n, '0');          
	}
	else 
		ft_pp(l,n, '0');
			pointer(d);
}
void ft_etoile_point_elsepoint(va_list ap, int p)
{
void *d;
	char *l;

    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
	ft_pp(l,p, ' ');     
			pointer(d);

}
char  *ft_searching_pointpoint(char *j)
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
int ft_number_andopoint(char *j, int n, va_list ap, int p)
{
void *d;
	char *l;

	if (p < 0 && j[0] == '0')
	{
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
		ft_pp(l,n, '0');
			pointer(d);
		return(1);
	}
	else 
	{
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
		if (p > n)
		{
			ft_pp(l,p, '0');
			pointer(d);
			return(1);
		}
		else
		{
			ft_pp1(n, p);
			ft_pp(l,p, ' ');
			pointer(d);
		}
		return(1);
	}
	return(0);
}

void etoile1point(va_list ap, char *j, char *o)
{
	int p;

	p = va_arg(ap , int);
	if (j[2] != '\0') 
		ft_etoile_pointpoint(ap,  p, j, o);	
	else
		ft_etoile_point_elsepoint(ap,  p);
}

void zeroetoilepointpoint(char *j,char *o, va_list ap)
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
	ft_number_andopoint(j,  n, ap,  p);

}

void  numberpointnumberpoint(char *o, int p, va_list ap)
{
	int n;
void *d;
	char *l;

	n = 0;
	if (p < 0)
	{
		p = -p;
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
	n = ft_atoi(o);
	ft_pp(l,n, '0');
			pointer(d);
	ft_pp2( p, n, l);
	}
	else
	{
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
	n = ft_atoi(o);
	ft_pp2( p, n, l);
	ft_pp(l,n, '0');
			pointer(d);
	}
	
	
}
void numberpointetoilepoint( int p,va_list ap)
{
	int n;
void *d;
	char *l;

	n = va_arg(ap ,int);
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
	if ( n > 0)
	{	
		ft_pp2( p,  n, l);
		ft_pp(l,n, '0');
			pointer(d);
	}
	else if (n < 0)
	{
			pointer(d);
		n = -n;
		ft_pp(l,n, ' ');
	}					
}
void numberpointnumberelsepoint(va_list ap, int p)
{
void *d;
	char *l;
	if (p > 0)
	{
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
		ft_pp(l,p, ' ');
			pointer(d);
	}
	else if (p < 0)
	{
    d = va_arg(ap, void*);	
    l = poinToHexa((size_t)d);
			pointer(d);
		p = -p;
		ft_pp(l,p, ' ');
	}
}

void ft_nopointnozeropoint(char *j,char *o, va_list ap)
{
    int r;
    int p;

    p = ft_atoi(j);
				r = 0;
				o = ft_searching_point(j);

				if ((j[0] >= 48 && j[0] <= 57) || (j[0] == '-' && (j[1] >= 48 && j[1] <= 57)))
				{
					if ((o[0] >= 48 && o[0] <= 57))
						numberpointnumberpoint( o, p, ap);
					else if(o[0] == '*')
						numberpointetoilepoint(p, ap);
					else
						
						numberpointnumberelsepoint(ap, p);
				}
}
char  *poinToHexa(size_t n) 
{    
    
    char *hexaDeciNum;
      
    // counter for hexadecimal number array 
	hexaDeciNum = malloc(100 * sizeof(char));
    int i = 0; 
    hexaDeciNum[i] = '0';
    hexaDeciNum[++i] = 'x';
	if ( n == 0)
	{
		hexaDeciNum[++i] = '0';
		return(hexaDeciNum);
	}
    i++;
    while(n!=0) 
    {    
        // temporary variable to store remainder 
        int temp  = 0; 
          
        // storing remainder in temp variable. 
        temp = n % 16; 
          
        // check if temp < 10 
        if(temp < 10) 
        { 
            hexaDeciNum[i] = temp + 48; 
            i++; 
        } 
        else
        { 
            hexaDeciNum[i] = temp + 55; 
            i++; 
        } 
          
        n = n/16; 
    } 
	return(hexaDeciNum);
}
void ft_pp3point(int p, int n , char *l, void  *d)
{
	int r;
	if ( p < 0)
	p = -p;
	if (p > n)
	{
		r = n;
		ft_pp(l,r, '0');
			pointer(d);
		ft_pp1(p, n);
	}
	else
	{
		ft_pp(l,n, '0');
			pointer(d);
	}
}