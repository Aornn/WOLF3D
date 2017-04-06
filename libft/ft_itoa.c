/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:45:21 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/27 12:26:03 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cpt_nbr(long int nbis, int cpt_nbr)
{
	while (nbis > 0)
	{
		cpt_nbr++;
		nbis = nbis / 10;
	}
	return (cpt_nbr);
}

static char		*ft_except(int n)
{
	if ((long int)n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((long int)n == -0)
		return (ft_strdup("0"));
	return (0);
}

static char		*ft_alloc_tab(int n, char *nbr, int i)
{
	while (n > 0)
	{
		nbr[i] = ((n % 10) + '0');
		n = n / 10;
		i--;
	}
	return (nbr);
}

char			*ft_itoa(int n)
{
	int			cpt_nbr;
	size_t		i;
	char		*nbr;
	size_t		neg;
	long int	nbis;

	neg = 0;
	cpt_nbr = 0;
	if (((long int)n == -0) || ((long int)n == -2147483648))
		return (ft_except(n));
	if (n < 0)
	{
		neg = 1;
		n = n * (-1);
	}
	nbis = (long int)n;
	cpt_nbr = ft_cpt_nbr(nbis, cpt_nbr);
	nbr = ft_strnew(cpt_nbr + neg);
	i = cpt_nbr + neg - 1;
	if (nbr == NULL)
		return (NULL);
	if (neg > 0)
		nbr[0] = '-';
	return (ft_alloc_tab(n, nbr, i));
}
