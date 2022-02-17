/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:57:45 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/16 15:23:41 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	num_parser(int arg_num, char *str)
{
	int						i;
	unsigned long long		nb;

	nb = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		error(2);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > 2147483647)
			error(4);
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (str[i])
		error(3);
	if (nb > 512 && arg_num == 1)
		error(5);
	return (nb);
}
