/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_odd_even.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 08:59:56 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/08 13:46:21 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	loop_4_r_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_lock);
	if (!(*philo->r_fork))
	{
		while (!(*philo->r_fork))
		{
			pthread_mutex_unlock(philo->r_lock);
			if (is_it_dead(philo))
				return (1);
			pthread_mutex_lock(philo->r_lock);
		}
	}
	*philo->r_fork = 0;
	pthread_mutex_unlock(philo->r_lock);
	return (0);
}

int	is_even(t_philo *philo)
{
	pthread_mutex_lock(philo->l_lock);
	if (*philo->l_fork)
	{
		*philo->l_fork = 0;
		pthread_mutex_unlock(philo->l_lock);
		lock_n_print(philo, 'f');
		if (is_dead_flag(philo))
			return (1);
		if (loop_4_r_fork(philo))
			return (1);
		lock_n_print(philo, 'f');
		if (is_dead_flag(philo))
			return (1);
		philo->is_ready = 1;
	}
	else
		pthread_mutex_unlock(philo->l_lock);
	return (0);
}

static int	loop_4_l_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_lock);
	if (!(*philo->l_fork))
	{
		while (!(*philo->l_fork))
		{
			pthread_mutex_unlock(philo->l_lock);
			if (is_it_dead(philo))
				return (1);
			pthread_mutex_lock(philo->l_lock);
		}		
	}
	*philo->l_fork = 0;
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
		if (is_dead_flag(philo))
			return (1);
		if (loop_4_l_fork(philo))
			return (1);
		lock_n_print(philo, 'f');
		if (is_dead_flag(philo))
			return (1);
		philo->is_ready = 1;
	}
	else
		pthread_mutex_unlock(philo->r_lock);
	return (0);
}
