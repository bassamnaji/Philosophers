/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_current_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:20:52 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/06 08:37:35 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	updated_current_time(t_philo *philo, char c)
{
	gettimeofday(&philo->current_time, NULL);
	if (c == 'r')
		philo->c_time = philo->current_time.tv_sec * 1000
			+ philo->current_time.tv_usec / 1000;
	else if (c == 'c')
		philo->c_time = (philo->current_time.tv_sec * 1000
				+ philo->current_time.tv_usec / 1000) - *philo->useless_time;
	return (philo->c_time);
}
