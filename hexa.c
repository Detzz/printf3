/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:22:52 by aali-mou          #+#    #+#             */
/*   Updated: 2019/11/17 16:22:53 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrrev_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (s)
		while (s[i] != '\0')
		{
			i++;
		}
    while (i >= 0)
    {
        ft_putchar_fd(s[i], fd);
        i--;
    }
}

void        hexa(unsigned int n)
{
    if (n / 16)
        hexa(n / 16);
    if ((n % 16) >= 10)
        ft_putchar_fd((n % 16) + 'a' - 10, 1);
    else
        ft_putchar_fd((n % 16) + '0', 1);
    
}


void        pointer(void *n)
{
    ft_putstr_fd("0x",1);
    hexapointer((size_t)n);
}
void        hexapointer(size_t n)
{
    if (n / 16)
        hexapointer(n / 16);
    if ((n % 16) >= 10)
        ft_putchar_fd((n % 16) + 'a' - 10, 1);
    else
        ft_putchar_fd((n % 16) + '0', 1);
    
}
/*
void        hexa(size_t n)
{
    char dst[100];
    int     i;
    int     temp;

    i = 0;
    while (n != 0)
    {
        temp = 0;
        //Divide the number by 16 now
        temp = n % 16;
        //Store the remainder when the number is divided by 16 in a temporary variable temp. If temp is less than 10,
        // insert (48 + temp) in a character array otherwise if temp is greater than or equals to 10, insert (55 + temp) in the character array.
        if (temp < 10)
        {
            dst[i] = temp + 48;
            i++;
        }
        else
        {
            dst[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
   //Repeat the above two steps until the number is not equal to 0.
    //Print the array in reverse order now.
    ft_putstrrev_fd(dst, 1);  
}

*/