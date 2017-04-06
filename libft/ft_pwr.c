/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:22:23 by rqueverd          #+#    #+#             */
/*   Updated: 2016/11/15 15:50:30 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pwr(long int nb, int pwr)
{
	int tmp_nb;

	tmp_nb = nb;
	if (nb < -2147483647)
		return (0);
	if (nb < 0)
		nb = -nb;
	while (pwr > 1)
	{
		nb = nb * tmp_nb;
		pwr--;
	}
	if (nb > 2147483646)
		return (0);
	return (nb);
}
