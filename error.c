/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:11:16 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/08 16:11:14 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(int n)
{
	if (n == 1)
		ft_putstr_fd("Wrong number of arguments", 2);
	else if (n == 2)
		ft_putstr_fd("arguments must not be negative", 2);
	else if (n == 3)
		ft_putstr_fd("arguments must contain positive numbers only", 2);
	else if (n == 4)
		ft_putstr_fd("arguments must not exceed INT_MAX", 2);
	else if (n == 5)
		ft_putstr_fd("number of philosopher must not exceed 512", 2);
	else if (n == 6)
		ft_putstr_fd("Failed malloc", 2);
	exit(n);
}
