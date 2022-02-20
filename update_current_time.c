/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_current_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:20:52 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/20 19:49:35 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	updated_current_time(t_philo *philo)
{
	gettimeofday(&philo->current_time, NULL);
	philo->c_time = philo->current_time.tv_usec / 1000 - philo->useless_time;
	return (philo->c_time);
	// printf("time was %d\n", philo->current_time.tv_usec / 1000);
	// usleep(1000);
	// gettimeofday(&philo->current_time, NULL);
	// printf("time now %d\n", philo->current_time.tv_usec / 1000);
	// printf("difference %d\n", philo->current_time.tv_usec / 1000 - philo->c_time);
}

void	set_timer(t_philo *philo)
{
	gettimeofday(&philo->current_time, NULL);
	philo->ref_time = philo->current_time.tv_usec / 1000;
}

int	check_time_for(t_philo *philo, char c)
{
	updated_current_time(philo);
	if (c == 'e')
	{
		if (philo->c_time >= philo->ref_time + philo->t_2_eat)
			return (1);
	}
	else if (c == 's')
	{
		if (philo->c_time >= philo->ref_time + philo->t_2_sleep)
			return (1);
	}
	else if (c == 'd')
	{
		if (philo->c_time >= philo->ref_time + philo->t_2_die)
			return (1);
	}
	return (0);
}
