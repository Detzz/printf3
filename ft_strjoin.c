/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:21:59 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/30 23:36:45 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned long	i;
	unsigned long	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(dest = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	i = 0;
	j = 0;
	if (s1 == 0 && s2 == 0)
		return (0);
	while (i < ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
