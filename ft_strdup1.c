/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:04:55 by aali-mou          #+#    #+#             */
/*   Updated: 2019/11/22 23:04:56 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*ft_strcpy2(char *dest, const char *src, int i)
{
	int x;

	x = 0;
	while (src[i] != '\0')
	{
		dest[x] = src[i];
		i++;
        x++;
	}
	dest[x] = '\0';
	return (dest);
}

char	*ft_strdup1(const char *s1, int i)
{
	int		x;
	int		n;
	char	*dest;

    x = i;
	n = 0;
	while (s1[x] != '\0')
	{
		x++;
		n++;
	}
	n++;
	if (!(dest = malloc(n * sizeof(char))))
		return (0);
	ft_strcpy2(dest, s1 , i);
	return (dest);
}
