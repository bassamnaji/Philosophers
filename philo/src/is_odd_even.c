/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_odd_even.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 08:59:56 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/08 12:18:29 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_even(t_philo *philo)
{
	pthread_mutex_lock(philo->l_lock);
	if (*philo->l_fork)
	{
		*philo->l_fork = 0;
		pthread_mutex_unlock(philo->l_lock);
		lock_n_print(philo, 'f');
		// pthread_mutex_lock(philo->death_lock);
		if (*philo->is_dead)
			return (1);
		// pthread_mutex_unlock(philo->death_lock);
		pthread_mutex_lock(philo->r_lock);
		if (!(*philo->r_fork))
			while (!(*philo->r_fork))
				if (is_it_dead(philo))
					return (1);
		*philo->r_fork = 0;
		pthread_mutex_unlock(philo->r_lock);
		lock_n_print(philo, 'f');
		// pthread_mutex_lock(philo->death_lock);
		if (*philo->is_dead)
			return (1);
		// pthread_mutex_unlock(philo->death_lock);
		philo->is_ready = 1;
	}
	else
		pthread_mutex_unlock(philo->l_lock);
	return (0);
}

int	is_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->r_lock);
	if (*philo->r_fork)
	{
		*philo->r_fork = 0;
		pthread_mutex_unlock(philo->r_lock);
		lock_n_print(philo, 'f');
		// pthread_mutex_lock(philo->death_lock);
		if (*philo->is_dead)
			return (1);
		// pthread_mutex_unlock(philo->death_lock);
		pthread_mutex_lock(philo->l_lock);
		if (!(*philo->l_fork))
		{
			while (!(*philo->l_fork))
			{
				// pthread_mutex_unlock(philo->l_lock);
				if (is_it_dead(philo))
					return (1);
				// pthread_mutex_lock(philo->l_lock);
			}		
		}
		*philo->l_fork = 0;
		pthread_mutex_unlock(philo->l_lock);
		lock_n_print(philo, 'f');
		// pthread_mutex_lock(philo->death_lock);
		if (*philo->is_dead)
			return (1);
		// pthread_mutex_unlock(philo->death_lock);
		philo->is_ready = 1;
	}
	else
		pthread_mutex_unlock(philo->r_lock);
	return (0);
}
