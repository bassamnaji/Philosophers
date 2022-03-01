/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:11:16 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/26 19:22:40 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(int n, t_info *info)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error: ", 2);
	if (n == 1)
		ft_putstr_fd("Wrong number of arguments\n", 2);
	else if (n == 2)
		ft_putstr_fd("arguments must not be negative\n", 2);
	else if (n == 3)
		ft_putstr_fd("arguments must contain positive numbers only\n", 2);
	else if (n == 4)
		ft_putstr_fd("arguments must not exceed INT_MAX\n", 2);
	else if (n == 5)
		ft_putstr_fd("number of philosopher must not exceed 512\n", 2);
	else if (n == 6)
	{
		ft_putstr_fd("Failed malloc\n", 2);
		main_free(info);
	}
	ft_putstr_fd(NO_COLOR, 2);
	exit(n);
}
