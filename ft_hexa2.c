/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:49:53 by aali-mou          #+#    #+#             */
/*   Updated: 2019/11/18 17:56:51 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

/*void	ft_putstrrev_fd(char *s, int fd)
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
*/
void        ft_hexa2(size_t n)
{
    if (n / 16)
        ft_hexa2(n / 16);
    if ((n % 16) >= 10)
        ft_putchar_fd((n % 16) + 'A' - 10, 1);
    else
        ft_putchar_fd((n % 16) + '0', 1);
        
    
}


/*void        pointer(void *n)
{
    ft_hexa2((size_t)n);
}*/
