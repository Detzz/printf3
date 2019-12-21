/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:12:43 by aali-mou          #+#    #+#             */
/*   Updated: 2019/12/07 22:51:03 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int   ft_while(va_list ap, const char* fmt ,int i)
{
	char *j;
	int r;
	char *temp;
	char *o;



	r = 0;
	j = ft_calloc(1,20);
	o = ft_calloc(1,20);
	while (fmt[i] != '\0')
	{
		i++;
		if (fmt[i] == '%')
		{
			if ( r > 0)
			{
			temp = j;
			j = ft_substr(fmt , i - r , r);
			free(temp);
			}
			else
			{
				temp = j;
				j = ft_strdup("\0");
				free(temp);
			}
			if_po(j, ap);
			break;
		}
		if (fmt[i] == 's')
		{
			if ( r > 0)
			{
			temp = j;
			j = ft_substr(fmt , i - r , r);
			free(temp);
			}
			else
			{
				temp = j;
				j = ft_strdup("\0");
				free(temp);
			}
		//	j = ft_strdup1(j,r);
			if_s(ap, j,o);
			free(j);
			break;
		}
		if (fmt[i] == 'c')
		{
			if ( r > 0)
			{
			temp = j;
			j = ft_substr(fmt , i - r , r);
			free(temp);
			}
			else
			{
				temp = j;
				j = ft_strdup("\0");
				free(temp);
			}
			 if_c(ap, j);
			break;
		}
		if ( fmt[i] == 'u')
		{
			if ( r > 0)
			{
			temp = j;
			j = ft_substr(fmt , i - r , r);
			free(temp);
			}
			else
			{
				temp = j;
				j = ft_strdup("\0");
				free(temp);
			}
			if_u(ap, j,o);
			break;
		}
		if (fmt[i] == 'd' || fmt[i] == 'i' )
		{
			
			if ( r > 0)
			{
			temp = j;
			j = ft_substr(fmt , i - r , r);
			free(temp);
			}
			else
			{
				temp = j;
				j = ft_strdup("\0");
				free(temp);
			}
			if_d(ap, j, o);
			free (j);
			free(o);
			break;
		}
		if (fmt[i] == 'x')
		{
			if ( r > 0)
			{
			temp = j;
			j = ft_substr(fmt , i - r , r);
			free(temp);
			}
			else
			{
				temp = j;
				j = ft_strdup("\0");
				free(temp);
			}
			if_x(ap,j,o);
				break;
		}
		if (fmt[i] == 'X')
		{
			if ( r > 0)
			{
			temp = j;
			j = ft_substr(fmt , i - r , r);
			free(temp);
			}
			else
			{
				temp = j;
				j = ft_strdup("\0");
				free(temp);
			}
			if_X( ap, j, o);
			break;
		}
		if (fmt[i]== 'p')
		{
			if ( r > 0)
			{
			temp = j;
			j = ft_substr(fmt , i - r , r);
			free(temp);
			}
			else
			{
				temp = j;
				j = ft_strdup("\0");
				free(temp);
			}
		 if_p(ap, j, o);
			break;
		} 
		else
		{
			r++;
		} 
		//ree (j);
		//free (o);    
	}
	return(i);                 
}

int     ft_printf(const char *fmt, ...)
{
	va_list ap;
	char c;
	int x;
	int i;

	g_count = 0;
	x = 0;
	i = 0;
	c = '\0';
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		x = i;
		while (fmt[x] != '%' && fmt[x] != '\0')
			x++;
		while (i < x)
		{
			ft_putchar_fd(fmt[i],1);
			i++;
		}
		if (fmt[i] == '%')
			x = ft_while(ap ,fmt , i);
		if (x == 0)
			return (g_count);
		i = x;
		if (fmt[i] == '\0')
			return(g_count);
		i++;
	}
	va_end(ap);
	return(g_count);
}

/*int main()
{
	int i;
	i = ft_printf("%*.*d", 0, -1, -1);
	printf ("    %d",i);
	i = printf("\n%*.*d", 0, -1, -1);
	printf ("    %d",i);
}*/