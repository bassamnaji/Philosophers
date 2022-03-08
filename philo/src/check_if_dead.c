/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:58:22 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/08 13:37:28 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_it_dead(t_philo *philo)
{
	if (updated_current_time(philo, 'r') - philo->ref_time
		> (unsigned long)philo->t_2_die)
	{
		pthread_mutex_lock(philo->death_lock);
		if (*philo->is_dead)
		{
			pthread_mutex_unlock(philo->death_lock);
			pthread_mutex_lock(philo->l_lock);
			*philo->l_fork = 1;
			pthread_mutex_unlock(philo->l_lock);
			pthread_mutex_lock(philo->r_lock);
			*philo->r_fork = 1;
			pthread_mutex_unlock(philo->r_lock);
			return (1);
		}
		pthread_mutex_unlock(philo->death_lock);
		ft_die(philo);
		return (1);
	}
	return (0);
}

int	is_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (*philo->is_dead)
	{
		pthread_mutex_unlock(philo->death_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}
