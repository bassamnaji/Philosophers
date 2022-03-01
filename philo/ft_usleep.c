/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:16:44 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/01 17:08:01 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(t_philo *philo, char c)
{
	int	t;

	t = 0;
	philo->cnt = 0;
	philo->tmp = 0;
	if (c == 'e')
		t = philo->t_2_eat;
	else if (c == 's')
		t = philo->t_2_sleep;
	while (philo->tmp < t)
	{
		if (*philo->is_dead)
			return (1);
		gettimeofday(&philo->current_time, NULL);
		if (c == 'e')
			philo->tmp = (philo->current_time.tv_sec * 1000
					+ philo->current_time.tv_usec / 1000) - philo->ref_time;
		else if (c == 's')
			philo->tmp = (philo->current_time.tv_sec * 1000
					+ philo->current_time.tv_usec / 1000) - philo->ref_time
				- philo->t_2_eat;
		if (updated_current_time(philo, 'r') - philo->ref_time
			> (unsigned long)philo->t_2_die)
		{
			if (*philo->is_dead)
				return (1);
			ft_die(philo);
			philo->just_died = 1;
			return (1);
		}
	}
	return (0);
}
